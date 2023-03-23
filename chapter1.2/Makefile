SHELL := $(shell which bash)
CFLAGS := -g

executables := simple-pmap

all: $(executables)

simple-pmap: simple-pmap.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(executables)

.PHONY: all clean