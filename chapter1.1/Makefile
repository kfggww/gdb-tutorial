
CFLAGS := -g
GDB_VERSION := $(shell gdb --version | awk '/^GNU gdb/{print $$NF}')

all: hello-gdb

hello-gdb: hello-gdb.c
	$(CC) $(CFLAGS) $< -o $@

start-hello-gdb: hello-gdb
	unset GDB_VERSION; \
	export GDB_VERSION=$(GDB_VERSION); \
	gdb --args ./hello-gdb first-arg second-arg

clean:
	rm -rf hello-gdb

.PHONY: all start-hello-gdb clean