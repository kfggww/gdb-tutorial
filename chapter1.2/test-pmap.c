#include <stdio.h>
#include <stdlib.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define die_if(cond, fmt, ...)                                                 \
    do {                                                                       \
        if (cond) {                                                            \
            printf(fmt, ##__VA_ARGS__);                                        \
            perror("error");                                                   \
            exit(EXIT_FAILURE);                                                \
        }                                                                      \
    } while (0)

void print_maps(pid_t pid);

int main(int argc, char const *argv[]) {

    for (int i = 1; i < argc; i++) {
        pid_t pid = atoi(argv[i]);
        print_maps(pid);
    }

    return 0;
}

void print_maps(pid_t pid) {
    char mapsfile[256];
    char cmdfile[256];
    sprintf(mapsfile, "/proc/%d/maps", pid);
    sprintf(cmdfile, "/proc/%d/cmdline", pid);

    FILE *fp = fopen(mapsfile, "r");
    die_if(fp == NULL, "fopen fail\n");

    /*print cmdline*/
    FILE *fp1 = fopen(cmdfile, "r");
    die_if(fp1 == NULL, "fopen fail\n");
    char cmdline[256];
    fgets(cmdline, 255, fp1);
    printf("%d:\t%s\n", pid, cmdline);
    fclose(fp1);

    /*print maps*/
    char buf[1024];

    long begin, end;
    char perm[5];
    long offset;
    char dev[16];
    int inode;
    char pathname[256];

    while (!feof(fp)) {
        if (fgets(buf, 1023, fp) != buf)
            break;

        sscanf(buf, "%lx-%lx %s %lx %s %d %s", &begin, &end, perm, &offset, dev,
               &inode, pathname);

        long size = (end - begin) / 1024;
        printf("%016lx %8ldK %s %s\n", begin, size, perm, pathname);
    }

    fclose(fp);
};