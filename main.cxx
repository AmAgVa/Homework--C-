#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {
  std::vector<std::string> args(argv, argv + argc);

  if (std::find(args.begin(), args.end(), "-h") != args.end() || std::find(args.begin(), args.end(), "--help") != args.end()) {
    std::cout << "Help message when passing in -h or --help" << std::endl;
    return 0;
  }

  if (args.size() >= 2 && (args[1] == "-i" || args[1] == "--input-file")) {
    if (args.size() >= 3) {
      std::string inputFile = args[2];
      std::cout << "Reading the CSV file: " << inputFile << std::endl;
      // Add your code to process the CSV file here
    } else {
      std::cerr << "Error: Missing input file. Use --help for usage information." << std::endl;
      return 1;
    }
  }

  return 0;
}
