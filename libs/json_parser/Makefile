CC=gcc
CFLAGS=-g -I ../dict

DEPS=dict.h json_parser.h
BINDIR=bin

%.o: %.c
	$(CC) -c -o $(BINDIR)/$@ $< $(CFLAGS)

clean:
	rm $(BINDIR)/*.o