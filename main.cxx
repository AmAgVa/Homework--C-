#include <iostream>
#include "argh.h"
#include "csv.h"
#include "date.h"

using namespace date;
using namespace std::chrono;

int main(int argc, char *argv[]) {
  argh::parser cmdl(argc, argv);

  if (cmdl[{ "-h", "--help" }]) {
    std::cout << "Execute by ./main -i data.csv" << std::endl;
    return 0;
  }

  if (cmdl[{"-i", "--input-file"}]) {
    std::string inputFile;
    if (cmdl(1) >> inputFile) {
      std::cout << "Reading the CSV file: " << inputFile << std::endl;

      io::CSVReader<5> in(inputFile);
      in.read_header(io::ignore_extra_column, "day", "year", "month", "ignoreme", "measurement");
      int d, y, m;
      double measurement;
      std::string ignoreme;

      while (in.read_row(d, y, m, ignoreme, measurement)) {
        auto date = year{y}/m/d;
        auto WeekDay = weekday{date};
        std::cout << "Date: " << date << ", Weekday: " << WeekDay << ", Measurement: " << measurement << std::endl;
      }
    } else {
      std::cerr << "Error: Missing input file. Use --help for usage information." << std::endl;
      return 1;
    }
  }

  return 0;
}
