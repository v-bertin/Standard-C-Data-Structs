SUBDIRS=dict json_parser red_black_tree

all: object

mrproper:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

object:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $$dir.o; \
	done