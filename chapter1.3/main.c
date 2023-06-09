#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bstree.h"

int main(int argc, char const *argv[])
{
    srand(time(0));

    struct BSTreeNode *root = bstree_new(10);
    for (int i = 0; i < 21; i++)
    {
        root = bstree_insert(rand() % 21, root);
    }

    root = bstree_delete(0, root);

    printf("val=0, %p\n", bstree_search(0, root));
    printf("val=8, %p\n", bstree_search(8, root));
    printf("val=21, %p\n", bstree_search(21, root));

    bstree_free(root);

    return 0;
}
