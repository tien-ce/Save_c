#include <iostream>

#include <string>
#include <graph_tool/all.hpp>
using namespace std;
using namespace boost;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_filename> [ -p <parts> ]" << endl;
        return 1;
    }

    string input_filename = argv[1];
    int parts = 1;

    if (argc == 4 && string(argv[2]) == "-p") {
        parts = stoi(argv[3]);
    }

    if (!boost::filesystem::exists(input_filename + ".tsv") && !boost::filesystem::exists(input_filename + "_1.tsv")) {
        cerr << "File doesn't exist: '" << input_filename << "'!" << endl;
        return 1;
    }

    vector<vector<int>> out_neighbors;
    vector<vector<int>> in_neighbors;
    size_t N, E;
    vector<int> true_partition;

    if (parts != 1) {
        cout << "\nLoading partition 1 of " << parts << " (" << input_filename + "_1.tsv" << ") ..." << endl;
        load_graph(input_filename, true_partition, out_neighbors, in_neighbors, N, E, 1);

        for (int part = 2; part <= parts; ++part) {
            cout << "Loading partition " << part << " of " << parts << " (" << input_filename + "_" << part << ".tsv) ..." << endl;
            load_graph(input_filename, true_partition, out_neighbors, in_neighbors, N, E, part);
        }
    } else {
        cout << "\nLoading full graph (" << input_filename << ") ..." << endl;
        load_graph(input_filename, true_partition, out_neighbors, in_neighbors, N, E);
    }

    graph_tool::Graph input_graph;
    for (size_t i = 0; i < out_neighbors.size(); ++i) {
        for (size_t j = 0; j < out_neighbors[i].size(); ++j) {
            input_graph.add_edge(i, out_neighbors[i][j]);
        }
    }

    auto t0 = chrono::high_resolution_clock::now();
    graph_tool::minimize_blockmodel_dl(input_graph, mcmc_args={{"parallel", true}},
                                       mcmc_equilibrate_args={{"verbose", false}, {"epsilon", 1e-6}}, true);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "\nGraph partition took " << chrono::duration_cast<chrono::seconds>(t1 - t0).count() << " seconds" << endl;

    evaluate_partition(true_partition, graph_tool_partition.get_blocks().a);
    return 0;
}
