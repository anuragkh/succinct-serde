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

  std::string query_str_in;
  while (std::getline(in, query_str_in, '\n')) {
    std::stringstream ss(query_str_in);
    uint32_t attr_id;
    std::string attr_val;
    ss >> attr_id >> attr_val;
    char delim1 = begin_delim + attr_id;
    char delim2 = delim1 + 1;
    std::string query_str_out = delim1 + attr_val + delim2;
    out << query_str_out << "\n";
  }
  in.close();
  out.close();

  return 0;

}
