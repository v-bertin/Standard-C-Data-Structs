CC			= gcc
CC_OPTS  = -Wall -Wextra -Werror -O0 -g

INCLUDEDIR	= ..
BINDIR		= bin

%.o: %.c 
	$(CC) -I $(INCLUDEDIR) -c -o $(BINDIR)/$@ $< $(CC_OPTS)

clean:
	rm $(BINDIR)/*.o