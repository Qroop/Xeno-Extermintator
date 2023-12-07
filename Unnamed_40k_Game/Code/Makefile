# Makefile for SFML C++ Game

# Compiler and compiler flags
CXX := g++
CXXFLAGS := -g -std=c++17 -Wall -Wextra

# SFML flags and libraries
SFML_FLAGS := -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

# Source files and executable name
SRC := $(wildcard $(SRC_DIR)/*.cc)
HEADERS := $(wildcard $(INCLUDE_DIR)/*.h)
OBJECTS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRC))
EXECUTABLE := game.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(SFML_FLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(EXECUTABLE)
