#include <stdio.h>
#include <stdlib.h>

typedef struct  node {
    int data;
    struct node* next;
} link;

link *START = NULL;

link* getNode(int data) {
    link *temp = (link *) malloc(sizeof(link));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

link* getLastNode() {
    link *PTR = START;
    while (PTR->next != NULL) {
        PTR = PTR->next;
    }
    return PTR;
}

// Insert
void insertNodeStart(int data) {
    if (START != NULL) {
        link* newNode = getNode(data);
        newNode->next = START;
        START = newNode;
    } else {
        link* newNode = getNode(data);
        if (newNode != NULL) {
            START = newNode;
        } else {
            printf("No momory");
        }
    }
}

void insertNodeEnd(int data) {
    link *PTR = START;
    while (PTR->next != NULL) {
        PTR = PTR->next;
    }
    // link *lastNode = getLastNode();
    link *newNode = getNode(data);
    PTR->next = newNode;
}

void insertNodeBefore(int key, int data) {
    link *PTR = START;
    link *PREPTR = NULL;
    while (PTR->data != key) {
        PREPTR = PTR;
        PTR = PTR->next;
    }
    link * newNode = getNode(data);
    newNode->next = PTR;
    PREPTR->next = newNode;
}

void insertNodeAfter(int key, int data) {
    link *PTR = START;
    while (PTR->data != key) {
        PTR = PTR->next;
    }
    link * newNode = getNode(data);
    newNode->next = PTR->next;
    PTR->next = newNode;
}

// Delete
void deleteStart() {
    link *temp = START;
    START = START->next;
    free(temp);
}

void deleteEnd() {
    link *PTR = START;
    link *PREPTR = NULL;
    while (PTR->next != NULL) {
        PREPTR = PTR;
        PTR = PTR->next;
    }
    PREPTR->next = NULL;
    free(PTR);
}

void deleteNode(int key) {
    link *PTR = START;
    link *PREPTR = NULL;
    while (PTR->data != key) {
        PREPTR = PTR;
        PTR = PTR->next;
    }
    PREPTR->next = PTR->next;
    free(PTR);
}

// Traverse
void traverse() {
    link *PTR = START;
    while (PTR != NULL) {
        printf("%d ", PTR->data);
        PTR = PTR->next;
    }
    printf("\n");
}


int main() {
    insertNodeStart(6);
    traverse();
    insertNodeStart(3);
    traverse();
    insertNodeEnd(10);
    traverse();
    insertNodeEnd(20);
    traverse();
    insertNodeAfter(6, 12);
    traverse();
    insertNodeAfter(10, 90);
    traverse();
    insertNodeBefore(6, 55);
    traverse();
    insertNodeBefore(10, 44);
    traverse();
    deleteStart();
    traverse();
    deleteEnd();
    traverse();
    deleteNode(44);
    traverse();
    insertNodeBefore(10,36);
    traverse();
    return 0;
}