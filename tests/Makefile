CC			= gcc
CC_OPTS  = -Wall -Wextra -Werror -O0 -g

LIBSDIR	= ../libs
BINDIR   = bin

SUBDIRS	= dict json_parser

all: test_dict test_json_parser

dict/$(BINDIR)/%.o: dict/%.c
	$(CC) -I $(LIBSDIR) -I $(LIBSDIR)/dict -c -o $@ $< $(CC_OPTS)

json_parser/$(BINDIR)/%.o: json_parser/%.c
	$(CC) -I $(LIBSDIR) -I $(LIBSDIR)/dict -I $(LIBSDIR)/json_parser -c -o $@ $< $(CC_OPTS)

test_dict: dict/$(BINDIR)/test.o $(LIBSDIR)/dict/$(BINDIR)/dict.o
	$(CC) -o $@ $^ $(CC_OPTS)

test_json_parser: json_parser/$(BINDIR)/test.o $(LIBSDIR)/dict/$(BINDIR)/dict.o $(LIBSDIR)/json_parser/$(BINDIR)/json_parser.o
	$(CC) -o $@ $^ $(CC_OPTS)

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


