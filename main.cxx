
#include <iostream>
#include "argh.h"

int main(int argc, char *argv[]) {
  argh::parser cmdl(argc, argv);
  
  if (cmdl[{ "-h", "--help" }]) {
    std::cout << "Produce a help message describing the CLI when passing in -h or --help" << std::endl;
    return 0;
  }

  if (cmdl({ "-i", "--input-file" })) {
    std::string inputFile;
    if (cmdl(1) >> inputFile) {
      std::cout << "Reading the CSV file: " << inputFile << std::endl;
      // Add your code to process the CSV file here
    } else {
      std::cerr << "Error: Missing input file. Use --help for usage information." << std::endl;
      return 1;
    }
  }

  return 0;
}
