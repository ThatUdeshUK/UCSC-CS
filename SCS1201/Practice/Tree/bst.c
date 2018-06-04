#include <stdio.h>
#include <stdlib.h>
"
struct structTree {
    int key;
    struct structTree* right;
    struct structTree* left;
}; typedef struct structTree tree;

tree *ROOT = NULL;

tree* insertEdge(tree *root, int key) {
    if (root == NULL) {
        tree *newEdge = (tree *) malloc(sizeof(tree));
        newEdge->key = key;
        newEdge->left = NULL;
        newEdge->right = NULL;
        root = newEdge;
    } else {
        if (root->key > key) 
            root->left = insertEdge(root->left, key);
        else
            root->right = insertEdge(root->right, key);
    }
    return root;
}

tree *getDeepest(tree *root) {
    if (root->left != NULL) {
        return getDeepest(root->left);
    } else if (root->right != NULL) {
        return getDeepest(root->right);
    } else {
        return root;
    }
}

tree *deleteEdge(tree *root, int key) {
    if (root != NULL) {
        if (root->key == key) {
            if (root->left == NULL) {
                tree *temp = root;
                root = root->right;
                free(temp);
            } else if (root->right == NULL) {
                tree *temp = root;
                root = root->left;
                free(temp);
            } else {
                tree *lowestInRightBranch = getDeepest(root->right);
                root->key = lowestInRightBranch->key;
                root->right = deleteEdge(root->right, lowestInRightBranch->key);
            }
        } else {
            root->left = deleteEdge(root->left, key);
            root->right = deleteEdge(root->right, key);
        }
    }
    return root;
}

void inorderTraverse(tree *root) {
    if (root != NULL) {
        inorderTraverse(root->left);
        printf("%d ", root->key);
        inorderTraverse(root->right);
        printf("\n");
    }
}

int main() {
    ROOT = insertEdge(ROOT, 5);
    ROOT = insertEdge(ROOT, 3);
    ROOT = insertEdge(ROOT, 4);
    ROOT = insertEdge(ROOT, 7);
    ROOT = insertEdge(ROOT, 6);
    ROOT = insertEdge(ROOT, 8);
    ROOT = insertEdge(ROOT, 2);
    ROOT = insertEdge(ROOT, 14);
    ROOT = insertEdge(ROOT, 16);
    ROOT = insertEdge(ROOT, 1);
    inorderTraverse(ROOT);
    ROOT = deleteEdge(ROOT, 5);
    inorderTraverse(ROOT);
    ROOT = deleteEdge(ROOT, 3);
    inorderTraverse(ROOT);
    return 0;
}