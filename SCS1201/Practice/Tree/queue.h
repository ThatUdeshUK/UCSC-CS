#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct charQueue {
    int front;
    int rear;
    int count;
    int capacity;
    char *queue;
}; typedef struct charQueue queue;

void enqueue(queue *, char);
char dequeue(queue *);
char peek(queue *);
bool isEmpty(queue *);
bool isFull(queue *);
void displayQueue(queue *);

queue *createQueue(int capacity) {
    queue *newQueue = (queue *) malloc(sizeof(queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->count = 0;
    newQueue->capacity = capacity;
    newQueue->queue = (char *) calloc(capacity, sizeof(char));
}

void enqueue(queue *s, char data) {
    if (s->count >= s->capacity) {
        printf("Queue Overflow\n");
    } else {
        if (s->front == -1) 
            s->front = 0;
        s->rear = ++s->rear % s->capacity;
        s->queue[s->rear] = data;
        s->count++;
    }
}

char dequeue(queue *s) {
    if (s->count <= 0) {
        printf("Queue Underflow\n");
    } else {
        char val = s->queue[s->front];
        s->front = ++s->front % s->capacity;
        s->count--;
        return val;        
    }
}

char peek(queue *s) {
    if (!isEmpty) {
        return s->queue[s->front];    
    } else {
        printf("Empty Queue\n");
    }
}

bool isEmpty(queue *s) {
    return s->count == 0;
}

bool isFull(queue *s) {
    return s->count == s->capacity;
}

void displayQueue(queue *s) {
    int i;
    int front = s->front;
    for (i = 0; i < s->count; i++) {
        printf("%c ", s->queue[front]);
        front = ++front % s->capacity;
    }
}

#endif /* QUEUE_H */
