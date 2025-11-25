SOURCES := main.c
BIN = noise
CC = gcc
CFLAGS = -std=c11 -O2
LIBS = -lm

all: $(SOURCES)
		$(CC) $(CFLAGS) $(SOURCES) -o $(BIN) $(LIBS)

run:
	./$(BIN)

clean:
	rm -f $(BIN)
