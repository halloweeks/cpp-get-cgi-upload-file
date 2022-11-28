#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char* argv[]) {
  char *line = NULL;
  size_t len = 0;
  ssize_t BytesSize = 0;
  
  unsigned long long i = 0;
  
  std::cout << "Content-Type: text/html\r\n\r\n";
  
  std::ofstream OutputFile("/sdcard/file.out", std::ios::binary);
  
  while ((BytesSize = getline(&line, &len, stdin)) != -1) {
    i = i + BytesSize;
    OutputFile.write(line, BytesSize);
  }
  
  OutputFile.close();
  
  std::cout << "Bytes: " << i << "\n";
  
  return 0;
}