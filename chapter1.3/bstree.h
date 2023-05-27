#ifndef BSTREE_H
#define BSTREE_H

struct BSTreeNode
{
    struct BSTreeNode *left;
    struct BSTreeNode *right;
    int val;
};

struct BSTreeNode *bstree_new(int val);
void bstree_free(struct BSTreeNode *root);

struct BSTreeNode *bstree_search(int val, struct BSTreeNode *root);
struct BSTreeNode *bstree_insert(int val, struct BSTreeNode *root);
struct BSTreeNode *bstree_delete(int val, struct BSTreeNode *root);

#endif