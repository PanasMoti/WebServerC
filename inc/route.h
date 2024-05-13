#ifndef ROUTE_H_
#define ROUTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct route {
    const char *key, *value;
    struct route *left, *right; 
};

/// @brief create a new binary search tree node (route)
struct route* route_create(const char* key, const char* value);

/// @brief create a new node and insert it
struct route* route_insert(struct route* route, const char* key, const char* value);

/// @brief search a node (route) with a key
struct route* route_search(struct route* root, const char* key);

/// @brief print out the route for debug purposes
/// @param root 
void route_dbg(struct route* root);


void treeprint(struct route *root, int level);



#endif // ROUTE_H_