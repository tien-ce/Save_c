#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Tên c?a t?p tin b?n mu?n m?
    const std::string fileName = "example.txt";

    // M? t?p tin d? vi?t van b?n vào
    std::ofstream outFile;
    outFile.open(fileName);

    // Ki?m tra xem vi?c m? t?p có thành công không
    if (!outFile.is_open()) {
        std::cerr << "Không th? m? t?p " << fileName << " d? vi?t." << std::endl;
        return 1;
    }

    // Vi?t van b?n vào t?p
    outFile << "mxvccccccccccccccccccccccccccccccccccccccccccnaisjdsad;asdm,z,xz,xz,\nmxvccccccccccccccccccccccccccccccccccccccccccnaisjdsad;asdm,z,xz,xz,\nmxvccccccccccccccccccccccccccccccccccccccccccnaisjdsad;asdm,z,xz,xz," << std::endl;

    // Ðóng t?p
    outFile.close();

    std::cout << "Vi?t van b?n thành công vào t?p " << fileName << std::endl;

    return 0;
}
