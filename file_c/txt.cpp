#include <iostream>
#include <fstream>
#include <string>

int main() {
    // T�n c?a t?p tin b?n mu?n m?
    const std::string fileName = "example.txt";

    // M? t?p tin d? vi?t van b?n v�o
    std::ofstream outFile;
    outFile.open(fileName);

    // Ki?m tra xem vi?c m? t?p c� th�nh c�ng kh�ng
    if (!outFile.is_open()) {
        std::cerr << "Kh�ng th? m? t?p " << fileName << " d? vi?t." << std::endl;
        return 1;
    }

    // Vi?t van b?n v�o t?p
    outFile << "mxvccccccccccccccccccccccccccccccccccccccccccnaisjdsad;asdm,z,xz,xz,\nmxvccccccccccccccccccccccccccccccccccccccccccnaisjdsad;asdm,z,xz,xz,\nmxvccccccccccccccccccccccccccccccccccccccccccnaisjdsad;asdm,z,xz,xz," << std::endl;

    // ��ng t?p
    outFile.close();

    std::cout << "Vi?t van b?n th�nh c�ng v�o t?p " << fileName << std::endl;

    return 0;
}
