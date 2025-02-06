#include <cstdio>
#include <iostream>
#include "readFile.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file-path>" << std::endl;
        return 1;
    }

    const char* file_path = argv[1];

    std::cout << file_path << std::endl;
    ReadFile *new_file;
    new_file = new ReadFile(file_path);
    new_file->printFile();
    delete new_file;
}
