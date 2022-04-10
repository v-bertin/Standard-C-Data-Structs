CC=gcc
CFLAGS=-g

SUBDIRS=dict json_parser
LIBSDIR=../libs
BINDIR=bin

all: test_dict test_json_parser

dict/$(BINDIR)/%.o: dict/%.c
	$(CC) -I $(LIBSDIR)/dict -c -o $@ $< $(CFLAGS)

json_parser/$(BINDIR)/%.o: json_parser/%.c
	$(CC) -I $(LIBSDIR)/dict -I $(LIBSDIR)/json_parser -c -o $@ $< $(CFLAGS)

test_dict: dict/$(BINDIR)/test.o $(LIBSDIR)/dict/$(BINDIR)/dict.o
	$(CC) -o $@ $^ $(CFLAGS)

test_json_parser: json_parser/$(BINDIR)/test.o $(LIBSDIR)/dict/$(BINDIR)/dict.o $(LIBSDIR)/json_parser/$(BINDIR)/json_parser.o
	$(CC) -I $(LIBSDIR)/json_parser -o $@ $^ $(CFLAGS)

tests:
	for dir in $(SUBDIRS); do \
		$(MAKE) test_$$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		rm $$dir/$(BINDIR)/*.o; \
	done

mrproper: clean
	for dir in $(SUBDIRS); do \
		rm test_$$dir; \
	done


