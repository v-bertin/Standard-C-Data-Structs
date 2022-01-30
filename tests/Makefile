CC=gcc
CFLAGS=-g

SUBDIRS=dict
LIBSDIR=../libs
BINDIR=bin

dict/$(BINDIR)/%.o: dict/%.c
	$(CC) -I $(LIBSDIR)/dict -c -o $@ $< $(CFLAGS)

test_dict: dict/$(BINDIR)/test.o $(LIBSDIR)/dict/$(BINDIR)/dict.o
	$(CC) -o $@ $^ $(CFLAGS)

tests:
	for dir in $(SUBDIRS); do \
		$(MAKE) test_$$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		rm $$dir/$(BINDIR)/*; \
	done

mrproper:
	$(MAKE) clean
	rm test_dict


