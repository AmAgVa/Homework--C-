# MNXB11-project-template
# About
This folder contains the following instructions on how to build a CLI library for the submission for homework tutorial 8 to 11. 

# Usage
How to compile and execute the code contents of this repository.

# Folder structure
All the header in used must be located inside external/include, here we have 'argh.h', 'csv.h', 'date.h' and 'fmt/core.h'.  

Our 'main.cxx', 'makefile', '.gitignore', 'clang-format', 'rootlogon.C' and 'data.csv' should be in the same directory which have the folders 'build' and 'external'.  

### Compile code by running the makefile
```
make
```
### For clean up
```
make clean
```
### Display help message
```
./main -h
```
### Read a CSV file
```
./main -i data.csv
```
## Adding external software libraries

The library in used can be download by cloning into their GitHub repositories.  

For argh
```
git clone git@github.com:adishavit/argh.git
```

For fast-cpp-csv-parser
```
git clone git@github.com:ben-strasser/fast-cpp-csv-parser.git
```

For date
```
git clone git@github.com:HowardHinnant/date.git
```

For fmt
```
git clone git@github.com:fmtlib/fmt.git
```

The header files in used should be moved to external/include to follow the structure as stated above.  