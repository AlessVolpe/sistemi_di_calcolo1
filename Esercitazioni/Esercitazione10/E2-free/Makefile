CC=gcc
CFLAGS=-Wno-deprecated-declarations -O1

all: e2

e2: e2_main.c e2.c e2.h
	$(CC) $(CFLAGS) e2_main.c e2.c -o e2

.phony: clean
	
clean:
	rm -rf e2
