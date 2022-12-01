#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char* argv[]) {
  char *line = NULL;
  size_t len = 0;
  ssize_t BytesSize = 0;
  
  std::cout << "Content-Type: text/html\r\n\r\n";
  
  std::ofstream OutputFile("dat.out", std::ios::binary);
  
  if (!OutputFile) {
     std::cout << "Failed to open output file";
     return -1;
  }

  while ((BytesSize = getline(&line, &len, stdin)) != -1) {
    OutputFile.write(line, BytesSize);
  }
  
  OutputFile.close();
  
  return 0;
}
