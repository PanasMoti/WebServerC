# Compiler
CC := clang

# Compiler flags
CFLAGS := -Wall -Wextra -std=c99

# Linker flags
LDFLAGS := -lc

# Directories
LIB_DIR := lib
SRC_DIR := src
INC_DIR := inc
BIN_DIR := bin
OBJ_DIR := obj

# Executable name
EXECUTABLE_NAME := WebServer

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Targets
all: $(BIN_DIR)/$(EXECUTABLE_NAME)

$(BIN_DIR)/$(EXECUTABLE_NAME): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@ -L$(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXECUTABLE_NAME)

	

.PHONY: all clean
