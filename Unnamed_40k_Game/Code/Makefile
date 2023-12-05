# Makefile for SFML C++ Game

# Compiler and compiler flags
CXX := g++
CXXFLAGS := -g -std=c++17 -Wall -Wextra

# SFML flags and libraries
SFML_FLAGS := -lsfml-graphics -lsfml-window -lsfml-system

# Source files and executable name
SRC = main.cc player.cc game_object.cc entity.cc play_state.cc wall.cc enemy.cc
EXECUTABLE = game

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXECUTABLE) $(SFML_FLAGS)

clean:
	rm -f $(EXECUTABLE)

# CXXFLAGS := -g -std=c++17 -Wall -Wextra
# LDFLAGS := -g -lsfml-graphics -lsfml-window -lsfml-system

# SOURCES := $(wildcard *.cpp)
# OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))

# # Dependencies:
# DEPS := $(patsubst %.o,%.d,$(OBJECTS))
# DEPFLAGS := -MMD -MP

# all: game

# pdf: uml.pdf

# .PHONY: clean
# clean:
# 	rm -f game $(OBJECTS) $(DEPS)
# 	find . -name "uml.*" | grep -Ev "(pdf|tex)$$" | xargs rm -f

# uml.pdf: uml.tex
# 	latexmk -xelatex -pvc- uml.tex

# game: $(OBJECTS)
# 	g++ $(CXXFLAGS) -o game $(OBJECTS) $(LDFLAGS)

# $(OBJECTS): %.o: %.cpp
# 	g++ $(CXXFLAGS) $(DEPFLAGS) -c -o $@ $<

# # Include dependencies
# -include $(DEPS)
