#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Hàm in ma tr?n
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(10) << elem << " ";
        }
        cout << endl;
    }
}

// Hàm tính ma tr?n ngh?ch d?o b?ng phuong pháp Gauss-Jordan
bool invertMatrix(vector<vector<double>>& matrix, vector<vector<double>>& inverse) {
    int n = matrix.size();
    inverse.assign(n, vector<double>(n, 0));

    // T?o ma tr?n don v?
    for (int i = 0; i < n; ++i) {
        inverse[i][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        // Tìm ph?n t? l?n nh?t trong c?t i
        double maxEl = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(matrix[k][i]) > maxEl) {
                maxEl = abs(matrix[k][i]);
                maxRow = k;
            }
        }

        // Hoán d?i hàng
        if (i != maxRow) {
            swap(matrix[i], matrix[maxRow]);
            swap(inverse[i], inverse[maxRow]);
        }

        // Ki?m tra n?u ph?n t? chéo chính b?ng 0
        if (matrix[i][i] == 0) {
            return false;
        }

        // Chia hàng d? ph?n t? chéo chính tr? thành 1
        double diag = matrix[i][i];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] /= diag;
            inverse[i][j] /= diag;
        }

        // C?p nh?t các hàng khác
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < n; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }

    return true;
}

int main() {
    int n = 3; // Kích thu?c ma tr?n (thay d?i kích thu?c n?u c?n)

    vector<vector<double>> matrix = {
        {2, 1, 3},
        {1, 2, 1},
        {3, 4, 2}
    };

    vector<vector<double>> inverse;

    cout << "Ma tr?n g?c:" << endl;
    printMatrix(matrix);

    if (invertMatrix(matrix, inverse)) {
        cout << "Ma tr?n ngh?ch d?o là:" << endl;
        printMatrix(inverse);
    } else {
        cout << "Ma tr?n không th? ngh?ch d?o." << endl;
    }

    return 0;
}
