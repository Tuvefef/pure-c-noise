SOURCES := main.cpp gnoise.cpp gfunctions.cpp permute.cpp
BIN = noise
CC = g++
CFLAGS = -std=c11 -O2
LIBS = -lm

all: $(SOURCES)
		$(CC) $(SOURCES) -o $(BIN)

run:
	./$(BIN)

clean:
	rm -f $(BIN)
