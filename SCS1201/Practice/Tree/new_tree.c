#include <stdio.h>
#include <stdlib.h>

// Define stucture
struct structTree {
    int data;
    struct structTree *left;
    struct structTree *right;
}; typedef struct structTree tree;

tree *ROOT = NULL;

tree *getVertex(int data) {
    tree *newVertex = (tree *) malloc(sizeof(tree));
    newVertex->data = data;
    newVertex->left = NULL;
    newVertex->right = NULL;
    return newVertex;
}

tree *insert(tree *root, int data) {
    if (root == NULL) {
        root = getVertex(data);
    } else {
        if (root->data > data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

tree *getLowest(tree *root) {
    if (root == NULL) 
        return root;

    if (root->left == NULL) 
        return root;
    else 
        return getLowest(root->left);
}

tree *delete(tree *root, int data) {
    if (root != NULL) {
        if (root->data == data) {
            if (root->right == NULL) {
                tree *temp = root;
                root = root->left;
                free(temp);
            } else if (root->left == NULL) {
                tree *temp = root;
                root = root->right;
                free(temp);
            } else {
                tree *temp = getLowest(root->right);
                root->data = temp->data;
                root->right = delete(root->right, temp->data);
            }
        } else if (root->data < data) {
            root-> right = delete(root->right, data);
        } else if (root->data > data) {
            root->left = delete(root->left, data);
        }
    }
    return root;
}

void search(tree *root, int data) {
    if (root == NULL)
        return;

    if (root->data == data) {
        printf("Data found");
    } else if (root->data > data) {
        search(root->left, data);
    } else if (root->data < data) {
        search(root->right, data);
    }
}

int getHieght(tree *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left = getHieght(root->left);
        int right = getHieght(root->right);
        if (left > right) {
            return left + 1;
        } else {
            return right + 1;
        }
    }
}

void preorderTraverse(tree *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

void inorderTraverse(tree *root) {
    if (root == NULL) 
        return;

    inorderTraverse(root->left);
    printf("%d ", root->data);
    inorderTraverse(root->right);
}

void postorderTraverse(tree *root) {
    if (root == NULL) 
        return;

    postorderTraverse(root->left);
    postorderTraverse(root->right);
    printf("%d ", root->data);
}

void printLevel(tree *root, int level) {
    if (root == NULL) 
        return;

    if (level == 0) {
        printf("%d ", root->data);
    } else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelorderTraverse(tree *root) {
    int i;
    for (i = 0; i < getHieght(root); i++) {
        printLevel(root, i);
        printf("\n");
    }
}

int getLeafNodeCount(tree *root) {
    if (root == NULL) {
        return 0;
    } else {
        int count = 0;
        if (root->left != NULL || root->right != NULL) {
            count++;
        }
        count += getLeafNodeCount(root->left);
        count += getLeafNodeCount(root->right);
        return count;

    }
} 

int main() {
    ROOT = insert(ROOT, 7);
    insert(ROOT, 5);
    insert(ROOT, 10);
    insert(ROOT, 6);
    insert(ROOT, 3);
    insert(ROOT, 9);
    // insert(ROOT, 11);

    preorderTraverse(ROOT);
    printf("\n");
    inorderTraverse(ROOT);
    printf("\n");
    postorderTraverse(ROOT);
    printf("\n");
    // delete(ROOT, 5);
    levelorderTraverse(ROOT);
    printf("\n%d \n", getLeafNodeCount(ROOT));
    return 0;
}