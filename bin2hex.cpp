#include <argparse/argparse.hpp>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  argparse::ArgumentParser program("bin2hex");

  program.add_argument("-w")
      .help("Specify the number of bits in a word")
      .scan<'i', int>()
      .default_value(32);

  program.add_argument("input-binary")
      .help("The input binary file to convert to hex");

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }

  int width = program.get<int>("-w") >> 3;
  std::string input_binary = program.get<std::string>("input-binary");

  std::ifstream in(input_binary, std::ios::binary);

  if (!in.is_open()) {
    std::cerr << "Error: Could not open file " << input_binary << std::endl;
    return 1;
  }

  std::vector<uint8_t> word;
  uint8_t byte;

  while (in.read(reinterpret_cast<char *>(&byte), 1)) {
    word.emplace_back(byte);
    if (word.size() == width) {
      for (auto it = word.rbegin(); it != word.rend(); ++it) {
        // specify width and fill with 0s
        std::cout << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<uint32_t>(*it);
      }
      std::cout << '\n';
      word.clear();
    }
  }

  in.close();

  return 0;
}