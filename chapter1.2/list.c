#include <stdlib.h>
#include "list.h"

static void insert_between(listnode_t *node, listnode_t *n1, listnode_t *n2) {
    node->next = n2;
    node->prev = n1;
    n1->next = node;
    n2->prev = node;
}

list_t *list_create() {
    list_t *list = malloc(sizeof(*list));
    list->head = malloc(sizeof(listnode_t));
    list->head->next = list->head->prev = list->head;
    list->head->data = 0;
    list->size = 0;
    return list;
}

void list_free(list_t *list) {
    listnode_t *node = list->head->next;
    while (node != list->head) {
        listnode_t *tmp = node;
        node = node->next;
        free(tmp);
    }
    free(list->head);
    free(list);
}

int list_append(list_t *list, int data) {
    listnode_t *node = node_create(data);
    insert_between(node, list->head->prev, list->head);
    list->size++;
    return SUCCESS;
}

int list_prepend(list_t *list, int data) {
    listnode_t *node = node_create(data);
    insert_between(node, list->head, list->head->next);
    list->size++;
    return SUCCESS;
}

int list_search(list_t *list, int data) {
    int ret = ERROR;
    listnode_t *cur = list->head->next;
    while (cur != list->head) {
        if (cur->data == data) {
            ret = SUCCESS;
            break;
        }
        cur = cur->next;
    }
    return ret;
}

int list_delete(list_t *list, int data) {
    int ret = ERROR;
    listnode_t *cur = list->head->next;
    while (cur != list->head) {
        if (cur->data == data) {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            free(cur);
            list->size--;

            ret = SUCCESS;
            break;
        }
        cur = cur->next;
    }
    return ret;
}

listnode_t *node_create(int data) {
    listnode_t *node = malloc(sizeof(*node));
    node->next = node->prev = NULL;
    node->data = data;
    return node;
}