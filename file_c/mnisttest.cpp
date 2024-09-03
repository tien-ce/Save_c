#include <fstream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()

int main() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator

    std::ofstream file("mnist.csv");

    // Write the header
    file << "label,";
    for (int i = 1; i <= 28; ++i) {
    for (int j = 1; j <= 28; ++j) {
        file << i << "x" << j;
        if (i != 28 || j != 28) {
            file << ",";
        }
    }
}
    file << "\n";

    // Write 1000 rows of random data
    for (int n = 0; n < 200; ++n) {
        int label = std::rand() % 10; // Random number between 0 and 9
        file << label;

        for (int i = 1; i <= 28; ++i) {
            for (int j = 1; j <= 28; ++j) {
                int pixel = std::rand() % 256; // Random number between 0 and 255
                file << "," << pixel;
            }
        }
        file << "\n";
    }

    file.close();

    return 0;
}


