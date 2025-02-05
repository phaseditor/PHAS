#include "readFile.h"
#include <iostream>

ReadFile::ReadFile (const char* file_path) {
    this -> file_path = file_path;
    file = fopen(file_path, "r");
}

void ReadFile::printFile() {
    while (fgets(buffer, sizeof(buffer), file)) {
        std::cout << buffer;
    }
}

ReadFile::~ReadFile () {
    fclose(file);
}
