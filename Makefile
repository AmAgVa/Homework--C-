CXX := g++
CXXWARNINGS := -Wall -Wextra -Werror
CXXOPT := -O3
CXXSTD := -std=c++17
INCLUDES := -I include -I external/include
CXXFLAGS := $(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES)

# List of source files in the src/ directory (add your source files here)
SOURCES := $(wildcard src/*.cxx)

SOURCES += main.cxx

# Generate a list of object files based on the source files
OBJECTS := $(SOURCES:src/%.cxx=src/%.o)

.PHONY: all clean

all: main

# Your main executable depends on the object files
main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build object files from source files
src/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) $^ -c -o $@

clean:
	rm -v src/*.o main