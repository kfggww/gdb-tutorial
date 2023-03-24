#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[]) {

    list_t *l1 = list_create();

    for (int i = 0; i < 16; i++) {
        list_append(l1, i);
    }

    printf("size: %d\n", l1->size);

    list_foreach(l1, node) { printf("%d\n", node->data); }

    list_free(l1);
    return 0;
}
