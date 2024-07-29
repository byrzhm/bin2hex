#include <iostream>
#include <fstream>
#include <filesystem>

int main(int argc, char *argv[]) {
  
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <binary file>" << std::endl;
    return 1;
  }

  std::string input_file = argv[1];

  // change the extension to .hex using filesystem library
  std::filesystem::path p(input_file);
  p.replace_extension(".hex");
  std::string output_file = p.string();

  std::ifstream in(input_file, std::ios::binary);
  std::ofstream out(output_file, std::ios::out);

  if (!in.is_open()) {
    std::cerr << "Error: Could not open file " << input_file << std::endl;
    return 1;
  }

  if (!out.is_open()) {
    std::cerr << "Error: Could not open file " << output_file << std::endl;
    return 1;
  }

  unsigned int word;
  while (in.read(reinterpret_cast<char*>(&word), sizeof(word))) {
    // specify width and fill with 0s
    out << std::hex << std::setw(8) << std::setfill('0') << word << std::endl;
  }

  in.close();
  out.close();
  
  return 0;
}