#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <Eigen/Sparse>

using namespace std;
using namespace Eigen;

void set_zero_rows(SparseMatrix<int>& sparray, vector<int>& rowNum) {
    for (int row : rowNum) {
        for (int i = sparray.outerIndexPtr()[row]; i < sparray.outerIndexPtr()[row + 1]; ++i) {
            sparray.valuePtr()[i] = 0;
        }
    }
}
	
SparseMatrix<int> ktruss(const string& inc_mat_file, int k) {
    MatrixXd ii = StrArrayRead(inc_mat_file);

    clock_t startTime = clock();

    SparseMatrix<int> E(ii.rows(), ii.cols());
    for (int i = 0; i < ii.rows(); ++i) {
        E.coeffRef(ii(i, 0) - 1, ii(i, 1) - 1) = ii(i, 2);
    }

    clock_t readTime = clock();

    SparseMatrix<int> tmp = E.transpose() * E;
    int sizeX = tmp.rows();
    int sizeY = tmp.cols();

    cout << "Time to Read Data: " << static_cast<double>(readTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    cout << "Computing k-truss" << endl;

    tmp.diagonal().setZero();
    tmp.prune(0);
    SparseMatrix<int> R = E * tmp;

    SparseVector<int> s(R.rows());
    s = (R == 2).template cast<int>().rowwise().sum();
    SparseVector<int> xc = (s >= k - 2).template cast<int>();

    while (xc.sum() != xc.nonZeros()) {
        vector<int> x;
        for (int i = 0; i < xc.size(); ++i) {
            if (xc.coeff(i) == 0) {
                x.push_back(i);
            }
        }

        set_zero_rows(E, x);
        E = (E > 0).template cast<int>();
        tmp = E.transpose() * E;
        tmp.diagonal().setZero();
        tmp.prune(0);
        R = E * tmp;

        s = (R == 2).template cast<int>().rowwise().sum();
        xc = (s >= k - 2).template cast<int>();
    }

    clock_t ktrussTime = clock();
    cout << "Time to Compute k=truss: " << static_cast<double>(ktrussTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    return E;
}

int main() {
    string inc_mat_file = "your_input_file_path_here";
    int k = 3;

    SparseMatrix<int> result = ktruss(inc_mat_file, k);

    // Process the result as needed

    return 0;
}
