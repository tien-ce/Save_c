#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <unordered_map>

using namespace std;

// Define an unordered_map with an int key and int value
typedef unordered_map<int, int> DenseHashMap;
DenseHashMap kTrussCheck;

// Function to read the edge list from a file
vector<vector<int>> StrArrayRead(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    vector<vector<int>> edgelist;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> row;
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        edgelist.push_back(row);
    }


    file.close();
    return edgelist;
}

// Function to set zero rows in a sparse matrix
void setZeroRows(vector<vector<int>>& sparray, const vector<int>& rowNum) {
    for (int row : rowNum) {
        fill(sparray[row].begin(), sparray[row].end(), 0);
    }
}

// Function to set diagonal value in a sparse matrix
void setDiagVal(vector<vector<int>>& sparray, int val) {
    for (size_t i = 0; i < sparray.size(); ++i) {
        sparray[i][i] = val;
    }
}

// Function to write the edge list to a file
void StrArrayWrite(const vector<vector<int>>& nparray, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    for (const auto& row : nparray) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << static_cast<float>(row[i]);
            if (i < row.size() - 1) {
                file << '\t';
            }
        }
        file << '\n';
    }

    file.close();
}

// Function to compute k-truss
vector<vector<int>> kTruss(const string& incMatFile, int k) {
    vector<vector<int>> ii = StrArrayRead(incMatFile);

    clock_t startTime = clock();

    // Create a CSR matrix from the edge list
    vector<vector<int>> E(ii.back()[0], vector<int>(ii.back()[1], 0));
    for (const auto& row : ii) {
        E[row[0] - 1][row[1] - 1] = row[2]; 
    }
for(auto i: E){
	for(auto j:i){
	cout<<j<< " ";	
	}
	cout<<endl;
}
    clock_t readTime = clock();

    vector<vector<int>> tmp(E[0].size(), vector<int>(E.size(), 0));
    for (size_t i = 0; i < E.size(); ++i) {
        for (size_t j = 0; j < E[i].size(); ++j) {
            tmp[j][i] = E[i][j];
        }
    }

    setDiagVal(tmp, 0);
    cout<<"tmp after setdiagval " << endl;
    for(auto i: tmp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout <<endl;
    }

    vector<vector<int>> R(E.size(), vector<int>(tmp[0].size(), 0));
    for (size_t i = 0; i < E.size(); ++i) {
        for (size_t j = 0; j < tmp[0].size(); ++j) {
            for (size_t k = 0; k < tmp.size(); ++k) {
                R[i][j] += E[i][k] * tmp[k][j];
            }
        }
    }
    
    DenseHashMap s;
    for (size_t i = 0; i < R.size(); ++i) {
        int sum = 0;
        for (size_t j = 0; j < R[i].size(); ++j) {
            sum += (R[i][j] == 2) ? 1 : 0;
        }
        s[i] = sum;
    }

    DenseHashMap xc;
    for (const auto& item : s) {
        xc[item.first] = (item.second >= k - 2) ? 1 : 0;
    }

    while (xc.size() != E.size()) {
        vector<int> x;
        for (const auto& item : xc) {
            if (item.second == 0) {
                x.push_back(item.first);
            }
        }

        setZeroRows(E, x);

        for (auto& row : E) {
            replace(row.begin(), row.end(), 0, 1);
        }

        vector<vector<int>> tmp(E[0].size(), vector<int>(E.size(), 0));
        for (size_t i = 0; i < E.size(); ++i) {
            for (size_t j = 0; j < E[i].size(); ++j) {
                tmp[j][i] = E[i][j];
            }
        }

        setDiagVal(tmp, 0);
        for (size_t i = 0; i < tmp.size(); ++i) {
            for (size_t j = 0; j < tmp[i].size(); ++j) {
                tmp[i][j] = max(0, tmp[i][j] - k + 2);
            }
        }

        for (size_t i = 0; i < R.size(); ++i) {
            fill(R[i].begin(), R[i].end(), 0);
        }

        for (size_t i = 0; i < E.size(); ++i) {
            for (size_t j = 0; j < tmp[0].size(); ++j) {
                for (size_t k = 0; k < tmp.size(); ++k) {
                    R[i][j] += E[i][k] * tmp[k][j];
                }
            }
        }

        s.clear();
        for (size_t i = 0; i < R.size(); ++i) {
            int sum = 0;
            for (size_t j = 0; j < R[i].size(); ++j) {
                sum += (R[i][j] == 2) ? 1 : 0;
            }
            s[i] = sum;
        }

        xc.clear();
        for (const auto& item : s) {
            xc[item.first] = (item.second >= k - 2) ? 1 : 0;
        }
    }

    cout<<"-----R1-----"<<endl;
    for(auto i:R){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }

    clock_t kTrussTime = clock();
    cout << "Time to Read Data: " << static_cast<double>(readTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    cout << "Time to Compute k=truss: " << static_cast<double>(kTrussTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    return E;
}

int main() {
    string incMatFile = "data.txt";
    int k = 3;

    vector<vector<int>> kTrussResult = kTruss(incMatFile, k);
for(auto i: kTrussResult){
	for(int j:i){
		cout<<j<<" ";
	}
	cout<<endl;
}
    // Process kTrussResult as needed

    return 0;
}
