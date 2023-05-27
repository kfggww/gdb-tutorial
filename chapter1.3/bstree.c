#include <stdio.h>
#include <stdlib.h>

#include "bstree.h"

static struct BSTreeNode *min_of(struct BSTreeNode *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

static struct BSTreeNode *max_of(struct BSTreeNode *root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

static struct BSTreeNode *delete_min(struct BSTreeNode *root)
{
    if (root == NULL)
        return NULL;

    struct BSTreeNode *result = NULL;
    if (root->left == NULL)
    {
        result = root->right;
        free(root);
        return result;
    }

    root->left = delete_min(root->left);
    return root;
}

static struct BSTreeNode *delete_max(struct BSTreeNode *root)
{
    if (root == NULL)
        return NULL;

    struct BSTreeNode *result = NULL;
    if (root->right == NULL)
    {
        result = root->left;
        free(root);
        return result;
    }

    root->right = delete_max(root->right);
    return root;
}

struct BSTreeNode *bstree_new(int val)
{
    struct BSTreeNode *root = malloc(sizeof(*root));
    root->left = root->right = NULL;
    root->val = val;
    return root;
}

void bstree_free(struct BSTreeNode *root)
{
    while (root != NULL && root->left != NULL)
    {
        root->left = delete_min(root->left);
    }
    while (root != NULL && root->right != NULL)
    {
        root->right = delete_min(root->right);
    }
    if (root != NULL)
    {
        free(root);
    }
}

struct BSTreeNode *bstree_search(int val, struct BSTreeNode *root)
{
    if (root == NULL)
        return NULL;

    if (val == root->val)
        return root;
    else if (val < root->val)
        return bstree_search(val, root->left);
    else
        return bstree_search(val, root->right);
}

struct BSTreeNode *bstree_insert(int val, struct BSTreeNode *root)
{
    if (root == NULL)
        return bstree_new(val);

    if (val < root->val)
        root->left = bstree_insert(val, root->left);
    else if (val > root->val)
        root->right = bstree_insert(val, root->right);

    return root;
}

struct BSTreeNode *bstree_delete(int val, struct BSTreeNode *root)
{
    if (root == NULL)
        return NULL;

    if (val == root->val)
    {
        if (root->right)
        {
            root->val = min_of(root->right)->val;
            root->right = delete_min(root->right);
        }
        else if (root->left)
        {
            root->val = max_of(root->left)->val;
            root->left = delete_max(root->left);
        }
        else
        {
            free(root);
            root = NULL;
        }
    }
    else if (val < root->val)
    {
        root->left = bstree_delete(val, root->left);
    }
    else
    {
        root->right = bstree_delete(val, root->right);
    }

    return root;
}
