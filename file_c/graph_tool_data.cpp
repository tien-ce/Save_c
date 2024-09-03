#include <iostream>
#include <fstream>
#include <vector>

void writeDataToFile(const std::vector<std::vector<int>>& data, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& row : data) {
        for (const auto& value : row) {
            file << value << '\t';  // S? d?ng k� t? tab '\t' d? t�ch gi?a c�c gi� tr?
        }
        file << '\n';  // Xu?ng d�ng sau m?i h�ng
    }

    file.close();
    std::cout << "Data has been written to " << filename << std::endl;
}

int main() {
    // D? li?u m?u
    std::vector<std::vector<int>> data = {
        {1, 1, 1},
        {3, 1, 1},
        {5, 1, 1},
        {1, 2, 1},
        {2, 2, 1},
        {6, 2, 1},
        {2, 3, 1},
        {4, 3, 1},
        {5, 3, 1},
        {3, 4, 1},
        {4, 4, 1},
        {6, 5, 1}
    };

    // G?i h�m d? ghi v�o file
    writeDataToFile(data, "data.tsv");

    return 0;
}
