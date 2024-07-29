#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char *argv[]) {
  
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <binary file>" << std::endl;
    return 1;
  }

  std::string input_file = argv[1];

  std::ifstream in(input_file, std::ios::binary);

  if (!in.is_open()) {
    std::cerr << "Error: Could not open file " << input_file << std::endl;
    return 1;
  }


  unsigned int word;
  while (in.read(reinterpret_cast<char*>(&word), sizeof(word))) {
    // specify width and fill with 0s
    std::cout << std::hex << std::setw(8) << std::setfill('0') << word << '\n';
  }

  in.close();
  
  return 0;
}