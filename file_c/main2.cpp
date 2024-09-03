#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// H�m in ma tr?n
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(10) << elem << " ";
        }
        cout << endl;
    }
}

// H�m t�nh ma tr?n ngh?ch d?o b?ng phuong ph�p Gauss-Jordan
bool invertMatrix(vector<vector<double>>& matrix, vector<vector<double>>& inverse) {
    int n = matrix.size();
    inverse.assign(n, vector<double>(n, 0));

    // T?o ma tr?n don v?
    for (int i = 0; i < n; ++i) {
        inverse[i][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        // T�m ph?n t? l?n nh?t trong c?t i
        double maxEl = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(matrix[k][i]) > maxEl) {
                maxEl = abs(matrix[k][i]);
                maxRow = k;
            }
        }

        // Ho�n d?i h�ng
        if (i != maxRow) {
            swap(matrix[i], matrix[maxRow]);
            swap(inverse[i], inverse[maxRow]);
        }

        // Ki?m tra n?u ph?n t? ch�o ch�nh b?ng 0
        if (matrix[i][i] == 0) {
            return false;
        }

        // Chia h�ng d? ph?n t? ch�o ch�nh tr? th�nh 1
        double diag = matrix[i][i];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] /= diag;
            inverse[i][j] /= diag;
        }

        // C?p nh?t c�c h�ng kh�c
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
    int n = 3; // K�ch thu?c ma tr?n (thay d?i k�ch thu?c n?u c?n)

    vector<vector<double>> matrix = {
        {2, 1, 3},
        {1, 2, 1},
        {3, 4, 2}
    };

    vector<vector<double>> inverse;

    cout << "Ma tr?n g?c:" << endl;
    printMatrix(matrix);

    if (invertMatrix(matrix, inverse)) {
        cout << "Ma tr?n ngh?ch d?o l�:" << endl;
        printMatrix(inverse);
    } else {
        cout << "Ma tr?n kh�ng th? ngh?ch d?o." << endl;
    }

    return 0;
}
