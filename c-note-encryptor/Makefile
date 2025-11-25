CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Iinclude
TARGET := c-note-encryptor
SOURCES := $(wildcard src/*.c)
OBJECTS := $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

SRC = src/main.c src/encrypt.c src/loglist.c
OBJ = $(SRC:.c=.o)
INCLUDES = -Iinclude

all: c-note-encryptor

c-note-encryptor: $(OBJ)
$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
rm -f $(OBJ) c-note-encryptor

.PHONY: all clean
