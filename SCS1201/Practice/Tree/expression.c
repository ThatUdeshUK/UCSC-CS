#include <stdio.h>
#include <ctype.h>
#include "stackexp.h"
#include "btree.h"

void insert(char exp[], stack *operators, stack *tree) {
    int i;
    for (i = 0;exp[i] != '\0';i++) {
        int c = exp[i]; 
        if (c == '(') {
            // printf("Push ( to operators\n");
            push(operators, getVertex(c));
            // displayStack(operators);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // printf("Push %c to operators\n", c);
            push(operators, getVertex(c));
            // displayStack(operators);
        } else if (isdigit(c)) {
            // printf("Push %c to tree\n", c);
            push(tree, getVertex(c));
            // displayStack(tree);
        } else if (c == ')') {
            // printf(") bracket found\n");
            // printf("Peek %c", peek(operators)->data);
            while (peek(operators) != NULL && peek(operators)->data != '(') {
                // printf("Operator found but not a (\n");
                btree *operator = pop(operators);
                operator->left = pop(tree);
                operator->right = pop(tree);
                push(tree, operator);
                // displayStack(tree);
            }
            // printf("poping operator\n");
            pop(operators);
        }
    }
}

void inorderTraverse(btree *tree) {
    if (tree != NULL) {
        inorderTraverse(tree->left);
        printf("%c ", tree->data);
        inorderTraverse(tree->right);
        // printf("\n");
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
        printf("%c ", root->data);
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

int main()
{
    stack *operators = createStack(10), *tree = createStack(10); 
    char exp[] = "((2+3)/6)";
    insert(exp, operators, tree);
    inorderTraverse(peek(tree));
    printf("\n");
    levelOrderTraverse(peek(tree));
    
    return 0;
}
