.POSIX:
.SUFFIXES:
CC = gcc
OO = -O0
TYPECHECK = true
CFLAGS = -std=c11 -g $(OO) -Wall -Wextra -D TYPECHECK=$(TYPECHECK)

SRC = src
VAR = $(SRC)/var
PARSER = $(SRC)/parser

all: op

OP = $(SRC)/main.o $(VAR)/var.o $(VAR)/file.o $(VAR)/hash.o $(VAR)/char.o $(VAR)/error.o $(VAR)/string.o $(PARSER)/token.o

op: $(OP)
	$(CC) -o op $(OP)

$(SRC)/main.o: $(SRC)/main.c

$(PARSER)/token.o: $(PARSER)/token.c $(PARSER)/token.h

$(VAR)/hash.o: $(VAR)/hash.c $(VAR)/hash.h

$(VAR)/error.o: $(VAR)/error.c $(VAR)/error.h

$(VAR)/file.o: $(VAR)/file.c $(VAR)/file.h

$(VAR)/char.o: $(VAR)/char.c $(VAR)/char.h

$(VAR)/string.o: $(VAR)/string.c $(VAR)/string.h

$(VAR)/var.o: $(VAR)/var.c $(VAR)/var.h

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f op
	rm -f src/*.o
	rm -f src/var/*.o
	rm -f src/parser/*.o
