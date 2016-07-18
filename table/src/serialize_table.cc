#include <cstdio>
#include <fstream>
#include <sstream>

void PrintUsage(char* exec) {
  fprintf(stderr, "%s [filename]\n", exec);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    PrintUsage(argv[1]);
    return -1;
  }

  std::string filename = argv[1];
  std::ifstream in(filename);
  std::ofstream out(filename + ".ser");

  const char begin_delim = -128;

  std::string row_str_in;
  while (std::getline(in, row_str_in, '\n')) {
    std::string row_str_out = "";
    std::stringstream ss(row_str_in);
    std::string cell;
    char delim = begin_delim;
    row_str_out += delim++;
    while (std::getline(ss, cell, '|')) {
      row_str_out += (cell + delim++);
    }
    out << row_str_out << "\n";
  }
  in.close();
  out.close();

  return 0;

}
