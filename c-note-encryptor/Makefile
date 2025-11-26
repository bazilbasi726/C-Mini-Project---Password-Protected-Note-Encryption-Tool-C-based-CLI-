CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Iinclude
TARGET := c-note-encryptor
SOURCES := $(wildcard src/*.c)
OBJECTS := $(SOURCES:.c=.o)

.PHONY: all clean test
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

test: $(TARGET)
	@set -e; \
		tmp_enc=$$(mktemp); tmp_dec=$$(mktemp); tmp_enc2=$$(mktemp); tmp_dec2=$$(mktemp); \
		printf "pass\n" | ./$(TARGET) -e tests/small.txt $$tmp_enc; \
		printf "pass\n" | ./$(TARGET) -d $$tmp_enc $$tmp_dec; \
		diff -u tests/small.txt $$tmp_dec; \
		printf "päss\n" | ./$(TARGET) -e tests/utf8.txt $$tmp_enc2; \
		printf "päss\n" | ./$(TARGET) -d $$tmp_enc2 $$tmp_dec2; \
		diff -u tests/utf8.txt $$tmp_dec2; \
		printf "pass\n" | ./$(TARGET) -e tests/empty.txt $$tmp_enc; \
		printf "pass\n" | ./$(TARGET) -d $$tmp_enc $$tmp_dec; \
		[ ! -s $$tmp_dec ]; \
		rm -f $$tmp_enc $$tmp_dec $$tmp_enc2 $$tmp_dec2

clean:
	rm -f $(TARGET) $(OBJECTS)
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
