# File:   Makefile
# Author: Anastasia Marinakou | sdi2400120
# Course: Data Structures and Programing Techniques (Even)

# Brief: use this Makefile to compile question6.c and list.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic

# Source files
SOURCES = main.c state.c

# Header files
HEADERS = state.h

# Object files
OBJS = $(SOURCES:.c=.o)

# Output program name
PROGRAM = game

# Rule to build the executable
$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)

# Rule to compile .c files into .o files, ensuring header dependencies
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(PROGRAM) $(OBJS)