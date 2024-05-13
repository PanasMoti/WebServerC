#include "route.h"

struct route *route_create(const char *key, const char *value)
{
    struct route *temp = (struct route *)malloc(sizeof(struct route));
    temp->key = key;
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct route *route_insert(struct route *root, const char *key, const char *value)
{
    if (root == NULL)
        return route_create(key, value);

    if (strcmp(key, root->key) == 0)
    {
        printf("============ WARNING ============\n");
        printf("A Route For \"%s\" Already Exists\n", key);
    }
    else if (strcmp(key, root->key) > 0)
    {
        root->right = route_insert(root->right, key, value);
    }
    else
    {
        root->left = route_insert(root->left, key, value);
    }
    return root;
}

struct route *route_search(struct route *root, const char *key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (strcmp(key, root->key) == 0)
    {
        return root;
    }
    else if (strcmp(key, root->key) > 0)
    {
        return search(root->right, key);
    }
    else if (strcmp(key, root->key) < 0)
    {
        return search(root->left, key);
    }
}

void route_dbg(struct route *root)
{
    if (root != NULL)
    {
        route_dbg(root->left);
        fprintf(stdout, "('%s', '%s') \n", root->key, root->value);
        route_dbg(root->right);
    }
}

// Function to print the binary tree sideways
void treeprint(struct route *root, int level)
{
    if (root == NULL)
        return;
    treeprint(root->right, level + 1);

    // Indentation for visual clarity
    for (int i = 0; i < level; i++)
        printf("\t\t");

    printf("(`%s`, `%s`)\n", root->key, root->value);

    treeprint(root->left, level + 1);
}
