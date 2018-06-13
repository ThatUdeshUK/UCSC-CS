#include <stdio.h>
#include <math.h>
#include "btree.h"

btree *ROOT = NULL;

btree *insert(btree *root, int data);
int getHeight(btree *root);
void printLevel(btree *root, int level);
void leveOrderTraverse(btree *root);

void rotateLeft(btree *root) {
    if (root->right->left == NULL) {
        root->right->left = root;
        root = root->right;
    } else {
        btree *temp = root->right->left;
        root->right->left = root;
        root = root->right;
        root->left->right = temp;
    }
}

void rotateRight(btree *root) {
    if (root->left->right == NULL) {
        root->left->right = root;
        root = root->left;
    } else {
        btree *temp = root->left->right;
        root->left->right = root;
        root = root->left;
        root->right->left = temp;
    }
}

btree *insert(btree *root, int data) {
    if (root == NULL) {
        root = getVertex(data);
        return root;
    } else {
        if (root->data > data)
            root->left = insert(root->left, data);
        else 
            root->right = insert(root->right, data);
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int diff = abs(left - right);
        if (diff >= 2) {
            if (root->data > data) {
                if (root->left->data > data) {
                    rotateRight(root);
                } else {
                    rotateLeft(root->left);
                    rotateRight(root);
                }
            } else if (root->data < data) {
                if (root->right->data < data) {
                    rotateLeft(root);
                } else {
                  rotateRight(root->right);
                  rotateLeft(root);
                }
            }
        }
        return root;
    }
}

int getHeight(btree *root) {
    if (root == NULL)
        return 0;
    
    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}

void printLevel(btree *root, int level) {
    if (root == NULL)
        return;
    else if (level == 0)
        printf("%d", root->data);
    else if (level > 0) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrderTraverse(btree *root) {
    int height = getHeight(root);
    int i;
    for(i = 0; i < height; i++) {
        printLevel(root, i);
        printf("\n");
    }
}

int main() {
    ROOT = insert(ROOT, 6);
    insert(ROOT, 4);
    insert(ROOT, 5);
    insert(ROOT, 8);
    insert(ROOT, 7);
    insert(ROOT, 10);
    insert(ROOT, 11);
    levelOrderTraverse(ROOT);
    return 0;
}