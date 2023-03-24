#include <stdio.h>
#include "list.h"

void print_list(list_t *list) {
    list_foreach(list, node) {
        printf("%d%s", node->data, node->next != list->head ? ", " : "\n");
    }
    printf("size: %d\n", list->size);
}

int main(int argc, char const *argv[]) {

    /*1. create*/
    list_t *list = list_create();

    /*2. append*/
    for (int i = 0; i < 8; i++) {
        list_append(list, i);
    }
    printf("list_append:\n");
    print_list(list);

    /*3. prepend*/
    list_prepend(list, 1024);
    printf("\nlist_prepend:\n");
    print_list(list);

    /*4. search*/
    int data = 4;
    int found = list_search(list, data);
    printf("\nlist_search %d: %s\n", data,
           found == SUCCESS ? "FOUND" : "NOT FOUND");
    print_list(list);

    /*5. delete*/
    data = 5;
    list_delete(list, data);
    printf("\nlist_delete %d\n", data);
    print_list(list);

    /*6. free*/
    list_free(list);

    return 0;
}
