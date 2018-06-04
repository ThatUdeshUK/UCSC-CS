#include <stdio.h>
#include <ctype.h>
#include "stackexp.h"
#include "btree.h"

void insert(char exp[], stack *operators, stack *tree) {
    int i;
    for (i = 0;exp[i] != '\0';i++) {
        int c = exp[i]; 
        if (c == ')')
            push(operators, getVertex(c));
        else if (c == '+' || c == '-' || c == '*' || c == '/')
            push(operators, getVertex(c));
        else if (isdigit(c)) 
            push(tree, getVertex(c));
        else if (c == '(') {
            while (peek(operators) != NULL && peek(operators)->data != ')') {
                btree *operator = pop(operators);
                operator->left = pop(tree);
                operator->right = pop(tree);
                push(tree, operator);
            }
            pop(operators);
        }
    }
}

void inorderTraverse(btree *tree) {
    if (tree != NULL) {
        inorderTraverse(tree->left);
        printf("%c ", tree->data);
        inorderTraverse(tree->right);
        printf("\n");
    }
}

int main()
{
    stack *operators = createStack(10), *tree = createStack(10); 
    char exp[] = ")2+1(";
    insert(exp, operators, tree);
    inorderTraverse(pop(tree));
    
    return 0;
}
