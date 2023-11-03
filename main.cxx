
#include <iostream>
#include "argh.h"
#include "csv.h"

int main(int argc, char *argv[]) {
  argh::parser cmdl(argc, argv);

  if (cmdl[{ "-h", "--help" }]) {
    std::cout << "Help message" << std::endl;
    return 0;
  }

  if (cmdl[{"-i", "--input-file"}]) {
    std::string inputFile;
    if (cmdl(1) >> inputFile) {
      std::cout << "Reading the CSV file: " << inputFile << std::endl;

      // Add code to process the CSV file using your CSV parsing library.
      io::CSVReader<5> in(inputFile);
      in.read_header(io::ignore_extra_column, "day", "year", "month", "ignoreme", "measurement");
      int day, year, month;
      double measurement;

      while (in.read_row(day, year, month, std::ignore, measurement)) {
        // Process your CSV data here, ignoring the "ignoreme" column.
        std::cout << "Day: " << day << ", Year: " << year << ", Month: " << month << ", Measurement: " << measurement << std::endl;
      }
    } else {
      std::cerr << "Error: Missing input file. Use --help for usage information." << std::endl;
      return 1;
    }
  }

  return 0;
}