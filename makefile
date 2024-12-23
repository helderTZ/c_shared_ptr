CC=gcc
CFLAGS=-Wall -Wextra

test:	test.c shared_ptr.h
	$(CC) -o test test.c $(CFLAGS)

.PHONY: clean

clean: test
	if [ -f test ]; then rm test; fi
