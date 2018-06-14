#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "btree.h"

struct btreeStack {
    int top;
    int capacity;
    btree* *stack;
}; typedef struct btreeStack stack;

void push(stack *, btree *);
btree *pop(stack *);
btree *peek(stack *);
bool isEmpty(stack *);
bool isFull(stack *);
void displayStack(stack *);

stack *createStack(int capacity) {
    stack *newStack = (stack *) malloc(sizeof(stack));
    newStack->top = -1;
    newStack->capacity = capacity;
    newStack->stack = (btree **) calloc(capacity, sizeof(btree*));
}

void push(stack *s, btree *tree) {
    if (s->top >= s->capacity - 1) {
        printf("Stack Overflow\n");
    } else {
        int top = ++s->top;
        s->stack[top] = tree;
    }
}

btree *pop(stack *s) {
    if (s->top < 0) {
        printf("Queue Underflow\n");
    } else {
        return s->stack[s->top--];    
    }
}

btree *peek(stack *s) {
    // if (!isEmpty) {
        return s->stack[s->top];    
    // } else {
        // return NULL;
    // }
}

bool isEmpty(stack *s) {
    return s->top == -1;
}

bool isFull(stack *s) {
    return s->top == s->capacity - 1;
}

bool size(stack *s) {
    return s->top;
}

void displayStack(stack *s) {
    int i;
    for (i = 0; i <= s->top; i++) {
        printf("%c ", s->stack[i]->data);
    }
    printf("\n");
}

#endif /* QUEUE_H */
