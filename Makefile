# MAIN=src/main.cpp
# OBJ_NAME=bin/game
# INCLUDE_PATH=include
# SRC_FILES=$(wildcard src/*.cpp)

# build:
# 	g++ -gdb $(SRC_FILES) -o $(OBJ_NAME) -I $(INCLUDE_PATH) -std=c++11 -L lib -lSDL2 && ./$(OBJ_NAME)

CXX       := g++
CXX_FLAGS := -std=c++11 -ggdb -L lib -lSDL2

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	 $(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*