# Makefile for the p6 Logical Address Calculator

# The name of the executable program to be built.
TARGET = p6

# The C source file containing your program logic.
SRCS = p6.c

# The C compiler to use for compilation.
CC = gcc

# Compiler flags:
# -Wall: Enable all common warning messages.
# -Wextra: Enable extra warnings (good practice!).
# -g: Include debugging information, useful for debugging.
# -std=c11: Specify the C11 standard for compilation.
CFLAGS = -Wall -Wextra -g -std=c11

# Phony targets: .PHONY specifies targets that are not actual files.
# This prevents `make` from getting confused if a file with the same name exists.
.PHONY: all clean

# The 'all' target is the default target when you run 'make' without arguments.
# It depends on the $(TARGET) executable.
all: $(TARGET)

# Rule to build the executable from the source file.
# The command below uses the compiler, applies the specified flags,
# compiles the source file, and outputs the executable with the defined TARGET name.
# IMPORTANT: The line below must be indented with a single TAB character, not spaces.
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# The 'clean' target removes compiled files and object files generated during the build process.
clean:
	rm -f $(TARGET) *.o