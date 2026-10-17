# The compiler and warning flags are kept in variables so they can be
# overridden from the command line, for example: make CC=clang.
CC = gcc
CFLAGS = -std=c11 -D_DEFAULT_SOURCE -Wall -Wextra -Wpedantic -g -Iheaders
LDFLAGS =
LDLIBS = -lm

SOURCE_DIR = sources
OBJECT_DIR = obj
TARGET = linked_list

SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/%.o)

.PHONY: all clean

# The first target is the default target run by plain "make".
all: $(TARGET)

# Link the object files into the executable.
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# Compile each source file and create the object directory when needed.
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove generated files without touching the source code.
clean:
	rm -rf $(OBJECT_DIR) $(TARGET)