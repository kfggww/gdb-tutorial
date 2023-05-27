build_dir := build

srcs := main.c bstree.c
objs := $(srcs:%.c=$(build_dir)/%.o)
deps := $(srcs:%.c=$(build_dir)/%.d)
exes := $(build_dir)/main

CFLAGS := -g

all: $(exes)

$(build_dir)/main: $(objs)
	$(CC) $^ -o $@

$(build_dir)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $< -c $(CFLAGS) -MM -MT $@ > $(@:%.o=%.d)
	$(CC) $< -c $(CFLAGS) -o $@

clean:
	rm -rf $(objs) $(deps) $(exes)

-include $(deps)