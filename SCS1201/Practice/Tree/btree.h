#ifndef BTREE_H
#define BTREE_H
#include <stdlib.h>

struct btreeNode {
    char data;
    struct btreeNode *left;
    struct btreeNode *right;
}; typedef struct btreeNode btree;

btree *getVertex(char data) {
    btree *newVertex = (btree *) malloc(sizeof(btree));
    newVertex->data = data;
    newVertex->left = NULL;
    newVertex->right = NULL;
    return newVertex;
}

#endif /* BTREE */
