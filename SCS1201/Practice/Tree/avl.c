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

btree* rotateRight(btree *root) {
    printf("rotation\n");
    btree *left = root->left;
    btree *subRight = left->right;
    left->right = root;
    root->left = subRight;
    return root;
}

btree *insert(btree *root, int data) {
    if (root == NULL) {
        printf("Inserting %d\n", data);
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
            printf("Has diff\n");
            if (root->data > data) {
                printf("Greater left\n");
                if (root->left->data > data) {
                    printf("Stright line\n");
                    root = rotateRight(root);
                } else {
                    printf("Dog leg\n");
            //         rotateLeft(root->left);
            //         rotateRight(root);
                }
            } else if (root->data < data) {
                printf("Greater right\n");
                if (root->right->data < data) {
            //         rotateLeft(root);
                } else {
            //       rotateRight(root->right);
            //       rotateLeft(root);
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
    insert(ROOT, 3);
    // insert(ROOT, 8);
    // insert(ROOT, 7);
    // insert(ROOT, 10);
    // insert(ROOT, 11);
    levelOrderTraverse(ROOT);
    return 0;
}