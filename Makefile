# Compiles Project Presidents Inauguration Tool

CC  = gcc
BIN = build/PPIT

CFLAGS  = -std=c11

all:
	$(CC) PPIT.c $(CFLAGS) -o $(BIN)

clean:
	@rm -f *.o $(BIN)
