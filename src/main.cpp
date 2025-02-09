#include <cstdio>
#include <iostream>
#include "readFile.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file-path>" << std::endl;
        return 1;
    }

    const char* file_path = argv[1];

    std::string file_content = readFile(file_path);
    Rope rope(file_content, 32);
    rope.display();
}
