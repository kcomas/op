.POSIX:
.SUFFIXES:
CC = gcc
OO = -O0
CFLAGS = -std=c11 -g $(OO) -Wall -Wextra

SRC = src
VAR = $(SRC)/var
PARSER = $(SRC)/parser

all: op

op: $(SRC)/main.o $(VAR)/file.o $(VAR)/string.o $(PARSER)/token.o
	$(CC) -o op $(SRC)/main.o $(VAR)/file.o $(VAR)/string.o $(PARSER)/token.o

$(SRC)/main.o: $(SRC)/main.c

$(PARSER)/token.o: $(PARSER)/token.c $(PARSER)/token.h

$(VAR)/file.o: $(VAR)/file.c $(VAR)/file.h

$(VAR)/string.o: $(VAR)/string.c $(VAR)/string.h

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f op
	rm -f src/*.o
	rm -f src/var/*.o
