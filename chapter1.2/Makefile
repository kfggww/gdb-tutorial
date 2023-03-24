SHELL := $(shell which bash)
CFLAGS := -g

executables := test-list test-pmap

all: $(executables)

test-list: test-list.c list.c
	$(CC) $(CFLAGS) $^ -o $@

test-pmap: test-pmap.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(executables)

.PHONY: all clean