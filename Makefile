# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2

# Target executable
TARGET = ahh_gen

# Source files
SRCS = ahh_gen.c

# Default rule
all: $(TARGET)

# Rule to compile the executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Rule to clean up the build
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean

