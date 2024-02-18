CC=gcc
CFLAGS=-std=c11
TARGET=dispatch

all: $(TARGET)

$(TARGET): dispatch.c
	$(CC) $(CFLAGS) -o $(TARGET) dispatch.c

clean:
	rm -f $(TARGET)