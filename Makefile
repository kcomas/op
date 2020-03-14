.POSIX:
.SUFFIXES:
CC = gcc
CFLAGS = -g -Wall -Wextra

SRC = src
VAR = $(SRC)/var

all: op

op: $(SRC)/main.o $(VAR)/file.o $(VAR)/string.o
	$(CC) -o op $(SRC)/main.o $(VAR)/file.o $(VAR)/string.o

$(SRC)/main.o: $(SRC)/main.c

$(VAR)/file.o: $(VAR)/file.c $(VAR)/file.h

$(VAR)/string.o: $(VAR)/string.c $(VAR)/string.h

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f op
	rm -f src/*.o
	rm -f src/var/*.o
