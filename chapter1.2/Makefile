SHELL := $(shell which bash)
CFLAGS := -g

executables := pmap

all: $(executables)

pmap: pmap.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(executables)

.PHONY: all clean