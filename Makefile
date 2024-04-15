# Variables
CC=gcc
CFLAGS=-Wall -Werror -ansi
SRC_DIR=./src/
OBJ_DIR=./build/
SRC_FILE=$(SRC_DIR)Library_Management.c
OBJ_FILE=$(OBJ_DIR)$(notdir $(SRC_FILE:.c=.o))

# Default target
all: $(OBJ_DIR) $(OBJ_FILE)

# Ensure the object directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilation rule
$(OBJ_FILE): $(SRC_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_DIR)

# Phony targets
.PHONY: all clean
