# Makefile for SFML C++ Game

# Compiler and compiler flags
CXX := g++
CXXFLAGS := -g -std=c++17 -Wall -Wextra

# SFML flags and libraries
SFML_FLAGS := -lsfml-graphics -lsfml-window -lsfml-system

# Source files and executable name
SRC = main.cc player.cc game_object.cc entity.cc grunt.cc wall.cc enemy.cc play_state.cc
EXECUTABLE = game

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXECUTABLE) $(SFML_FLAGS)

clean:
	rm -f $(EXECUTABLE)