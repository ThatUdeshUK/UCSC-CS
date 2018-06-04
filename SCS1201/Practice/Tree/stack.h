#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct charStack {
    int top;
    int capacity;
    char *stack;
}; typedef struct charStack stack;

void push(stack *, char);
char pop(stack *);
char peek(stack *);
bool isEmpty(stack *);
bool isFull(stack *);
void displayStack(stack *);

stack *createStack(int capacity) {
    stack *newStack = (stack *) malloc(sizeof(stack));
    newStack->top = -1;
    newStack->capacity = capacity;
    newStack->stack = (char *) calloc(capacity, sizeof(char));
}

void push(stack *s, char data) {
    if (s->top >= s->capacity - 1) {
        printf("Stack Overflow\n");
    } else {
        s->stack[++s->top] = data;
    }
}

char pop(stack *s) {
    if (s->top < 0) {
        printf("Queue Underflow\n");
    } else {
        return s->stack[s->top--];    
    }
}

char peek(stack *s) {
    if (!isEmpty) {
        return s->stack[s->top];    
    } else {
        printf("Empty Stack\n");
    }
}

bool isEmpty(stack *s) {
    return s->top == -1;
}

bool isFull(stack *s) {
    return s->top == s->capacity - 1;
}

void displayStack(stack *s) {
    int i;
    for (i = 0; i <= s->top; i++) {
        printf("%c ", s->stack[i]);
    }
}

#endif /* QUEUE_H */
