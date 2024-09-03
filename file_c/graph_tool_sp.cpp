#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> loadGraph(const string& filename, bool truePartitionAvailable) {
    vector<vector<pair<int, int>>> outNeighbors;
    vector<vector<pair<int, int>>> inNeighbors;

    ifstream file(filename + ".tsv");
    if (!file.is_open()) {
        cerr << "File doesn't exist: '" << filename << ".tsv'!" << endl;
        exit(1);
    }

    string line;
    int N = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        int from, to, weight = 1;
        iss >> from >> to;
        if (iss) {
            if (iss >> weight) {
                // Read the weight if available
            }
            N = max(N,max(from+1,to+1));

            outNeighbors.resize(N);
            inNeighbors.resize(N);

            outNeighbors[from].emplace_back(to, weight);
            inNeighbors[to].emplace_back(from, weight);
        }
    }

    file.close();

    int E = 0;
    for (const auto& neighbors : outNeighbors) {
        E += neighbors.size();
    }

    vector<int> truePartition;
    if (truePartitionAvailable) {
        truePartition.resize(N, 0);

        ifstream truePartitionFile(filename + "_truePartition.tsv");
        if (truePartitionFile.is_open()) {
            string truePartitionLine;
            while (getline(truePartitionFile, truePartitionLine)) {
                istringstream iss(truePartitionLine);
                int node, partition;
                iss >> node >> partition;
                if (iss) {
                    truePartition[node] = partition;
                }
            }
            truePartitionFile.close();
        }
    }

    return inNeighbors;
}

int main() {
    string inputFilename = "data";
    bool truePartitionAvailable = true;
    auto graphData = loadGraph(inputFilename, truePartitionAvailable);

    // Process the graph data as needed

    return 0;
}
