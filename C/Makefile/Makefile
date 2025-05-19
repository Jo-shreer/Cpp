# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -g  # -Wall enables all warnings, -g for debugging symbols

# Source files and object files
SRC = main.c util.c  #List of source files. 
OBJ = $(SRC:.c=.o)

# Output file (executable)
TARGET = my_program

# Rule to build the target (the executable)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile .c files into .o files
%.o: %.c # %.o: %.c: This is a pattern rule for compiling .c files into .o files. $< refers to the source file (%.c), and $@ refers to the target file (%.o).
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the generated files (object files and executable)
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (not actual files)
.PHONY: clean
