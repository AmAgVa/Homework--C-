CXX := g++
CXXWARNINGS := -Wall -Wextra -Werror -Wno-stringop-truncation
CXXOPT := -O3
CXXSTD := -std=c++17
INCLUDES := -I include -I external/include 
CXXFLAGS := $(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES)

.PHONY: all clean

all: main

# Your main executable depends on the object files
main: main.cxx src/Example.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) $^ -c -o $@

clean:
	rm -v src/*.o main
