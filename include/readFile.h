#ifndef READFILE_H
#define READFILE_H

#include <cstdio>

class ReadFile {
public:
  ReadFile(const char *);
  void printFile();
  ~ReadFile();

private:
  const char *file_path = "";
  FILE *file;
  char buffer[100];
};

#endif // READFILE_H
