# Compiles Inaugural Run

CC  = gcc -Wall -ansi
BIN = build/PPIT

CFLAGS  = `sdl-config --cflags` -std=c99
UNAME = $(shell uname -s)

all:
	$(CC) PPIT.c $(CFLAGS) -o $(BIN)

clean:
	@rm -f *.o $(BIN)
