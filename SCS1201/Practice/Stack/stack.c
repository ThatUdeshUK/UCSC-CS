#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
};

struct node* head = NULL;

malloc(int size)

void push(int value) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = value;
    temp->prev = head;
    head = temp;
}

int pop() {
    if (!(head == NULL)) {
        struct node* temp = head;
        int value = temp->data;
        head = temp->prev;
        free(temp);
        return value;
    } else {
        printf("Empty Stack\n");
        return -1;
    }
}

int peek() {
    int value = head->data;
    return value;
}

int main(){
    push(10);
    push(20);
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    pop();
    pop();
}
