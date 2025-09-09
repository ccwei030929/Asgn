# Makefile for Durian Selection Program

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = durian_selection
SOURCE = main.cpp

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

# Clean build artifacts
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run