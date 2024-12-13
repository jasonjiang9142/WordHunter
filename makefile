# Compiler and flags
CC = g++
CFLAGS = -std=c++11

# Source files and target
SRC = main.cpp grid.cpp
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
