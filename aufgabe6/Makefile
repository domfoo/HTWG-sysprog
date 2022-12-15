# Makefile

DIRS= \
	lib/ \
	bin/

.PHONY: all clean

all clean:
	for p in $(DIRS); do \
		(cd $$p && $(MAKE) $@); \
	done