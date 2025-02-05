#include <cstdio>
#include <iostream>

class ReadFile {
public:
    ReadFile (const char* file_path) {
        this -> file_path = file_path;
        file = fopen(file_path, "r");
    }

    void printFile() {
        while (fgets(buffer, sizeof(buffer), file)) {
            std::cout << buffer;
        }
    }

    ~ReadFile () {
        fclose(file);
    }
private:
    const char* file_path = "";
    FILE *file;
    char buffer[100];
};

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
