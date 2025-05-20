# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -g  # -Wall enables all warnings, -g for debugging symbols
# command to run makefile is make

# Source files and object files
SRC = main.c util.c  #List of source files. 
OBJ = $(SRC:.c=.o) #This replaces the .c extension with .o to create object files from the source files.

# Output file (executable)
TARGET = my_program  #The name of the output file.

# Rule to build the target (the executable)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile .c files into .o files
%.o: %.c         # %.o: %.c: This is a pattern rule for compiling .c files into .o files.
                 #$< refers to the source file (%.c), and $@ refers to the target file (%.o).
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the generated files (object files and executable)
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (not actual files)
.PHONY: clean  #This tells make that clean is not a real file and 
               #prevents make from trying to build a file named clean.
