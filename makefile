CFLAGS = -Wall -Wextra -Wpedantic -Wno-format

bintoc : bintoc.c
	gcc -o $@ $< $(CFLAGS)