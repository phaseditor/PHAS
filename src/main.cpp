#include <cstdio>
#include <iostream>
#include "phaseEditor.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file-path>" << std::endl;
        return 1;
    }

    const char* file_path = argv[1];
    std::string file_content = readFile(file_path);

    Editor phase(file_content);

    EditFile(phase);

    //if(save file condition)
    //SaveFile(phase);

    return 0;
}
