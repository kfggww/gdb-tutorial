#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    /* Get environment variable */
    char *gdb_version = getenv("GDB_VERSION");
    printf("hello gdb with version number (%s)\n",
           gdb_version == NULL ? "undefined" : gdb_version);

    /* Print all the arguments */
    int n = argc;
    for (int i = 0; i < n; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
