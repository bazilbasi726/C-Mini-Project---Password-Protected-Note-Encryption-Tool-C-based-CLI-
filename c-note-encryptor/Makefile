CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
INCLUDES = -Iinclude
TARGET = c-note-encryptor
SRC = src/main.c src/encrypt.c src/loglist.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
