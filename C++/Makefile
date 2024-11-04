# Makefile for C++ Project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -I graph_based_algorithms/include

# Source files
SOURCES = main.cpp \
           graph_based_algorithms/src/breadth_first_search.cpp

# Output executable
TARGET = main

# Build target
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Clean up
clean:
	rm -f $(TARGET)
