CFLAGS = -Wall -Wextra -Wpedantic

bintoc.exe : bintoc.c
	gcc -o $@ $< $(CFLAGS)