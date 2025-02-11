CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = encryption_tool

all: $(TARGET)

$(TARGET): encryption_tool.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
	rm -f $(TARGET)

.PHONY: all clean
