#ifndef LIST_H
#define LIST_H

#define SUCCESS 0
#define ERROR 1

typedef struct listnode {
    struct listnode *prev;
    struct listnode *next;
    int data;
} listnode_t;

typedef struct list {
    listnode_t *head;
    int size;
} list_t;

/*list APIs*/
list_t *list_create();
void list_free(list_t *list);
int list_append(list_t *list, int data);
int list_prepend(list_t *list, int data);
int list_search(list_t *list, int data);
int list_delete(list_t *list, int data);

/*listnode API*/
listnode_t *node_create(int data);

#define list_foreach(list, node)                                               \
    for (listnode_t *node = list->head->next; node != list->head;              \
         node = node->next)

#endif