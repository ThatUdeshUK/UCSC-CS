#include <stdio.h>
#include <stdlib.h>

struct structTree {
    int data;
    struct structTree *sibling;
    struct structTree *child;
}; typedef struct structTree tree;

tree *ROOT = NULL;

tree *getVertex(int data) {
    tree *newVertex = (tree *) malloc(sizeof(tree));
    newVertex->data = data;
    newVertex->sibling = NULL;
    newVertex->child = NULL;
    return newVertex;
}

void createRoot(int data) {
    ROOT = getVertex(data);
}

void addChild(tree *sub, int data) {
    if (sub != NULL) {
        if (sub->child == NULL) {
            sub->child = getVertex(data);
        } else {
            tree *PTR = sub->child;
            while(PTR->sibling != NULL) 
                PTR = PTR->sibling;
            PTR->sibling = getVertex(data);
        }
    }
}

void addChildTo(tree *root, int key, int data) {
    if (root == NULL)
        return;
    if (root->data == key) {
        addChild(root, data);
    } else {
        addChildTo(root->sibling, key, data);
        addChildTo(root->child, key, data);
    }
}

void deleteChild(tree *root) {
    if (root == NULL)
        return;
    deleteChild(root->sibling);
    deleteChild(root->child);
    free(root);
}

tree *deleteByKey(tree *root, int key) {
    if (root == NULL)
        return NULL;
    if (root->data == key) {
        deleteChild(root->child);
        tree *temp = root;
        root = root->sibling;
        free(temp);
        return root;
    } else {
        root->sibling = deleteByKey(root->sibling, key);
        root->child = deleteByKey(root->child, key);
        return root;
    }
}

void traverse(tree *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    traverse(root->sibling);
    printf("\n");
    traverse(root->child);
}

int main() {
    createRoot(0);
    addChildTo(ROOT, 0, 1);
    addChildTo(ROOT, 0, 2);
    addChildTo(ROOT, 0, 3);
    addChildTo(ROOT, 1, 4);
    addChildTo(ROOT, 1, 5);
    addChildTo(ROOT, 2, 6);
    addChildTo(ROOT, 2, 7);
    deleteByKey(ROOT, 2);
    traverse(ROOT);
    return 0;
}