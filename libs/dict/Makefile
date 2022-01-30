CC=gcc
CFLAGS=-g

DEPS=dict.h
BINDIR=bin

%.o: %.c $(DEPS)
	$(CC) -c -o $(BINDIR)/$@ $< $(CFLAGS)

clean:
	rm $(BINDIR)/*.o