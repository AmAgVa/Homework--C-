CXX := g++
CXXWARNINGS := -Wall -Wextra -Werror -Wno-stringop-truncation
CXXOPT := -O3
CXXSTD := -std=c++17

ROOTCXXFLAGS := $(shell root-config --cflags)
ROOTLDFLAGS := $(shell root-config --glibs)

INCLUDES := -I include -I external/include $(ROOTCXXFLAGS)
LDFLAGS := $(ROOTLDFLAGS)

CXXFLAGS := $(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES)

.PHONY: all clean

all: main

main: main.cxx src/Example.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) $^ -c -o $@

clean:
	rm -v src/*.o main