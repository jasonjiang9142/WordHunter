# Compiler and flags
CC = g++
CFLAGS = -std=c++14 

# Source files and target
SRC = main.cpp ./src/grid.cpp ./src/dictionary.cpp ./src/dfs.cpp ./src/bfs.cpp ./src/gameplay.cpp
EXEC = main

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

# Clean up generated files
clean:
	rm -f $(EXEC)

# Phony targets (not actual files)
.PHONY: all clean
