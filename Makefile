
SRCDIR = src
TESTDIR = tests

all: rps unittest

rps: $(SRCDIR)/main.c
	gcc -Wall -std=c99 src/main.c -o rps

unittest: $(TESTDIR)/test_rps.c
	gcc -Wall -std=c99 tests/test_rps.c -o unittest
		
clean:
	rm -f rps unittest
