#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define state of the queue
int MAX;
int front = -1;
int rear = -1;
int count = 0;

// Function prototypes
void enqueue(char *waitingroom[], char *name);
char* dequeue(char *waitingroom[]);
int isFull();
int isEmpty();
void finishHaircut(char *waitingroom[]);
void clientArrival(char *waitingroom[], char *name);

// Variable to hold current client
char *currentClient = NULL;

int main() {
    printf("Enter no of chairs: ");
    scanf("%d", &MAX);
    MAX--;
    printf("\n**Commands**\nC : Customer arrival\nF : Finish haircut\nQ : Quit\n\nBarber is sleeping\n");
    char *waitingroom[MAX];
    char command;
    int run = 1;
    while (run == 1) {
        printf("\nEnter command:");
        scanf(" %c", &command);
        switch (command) {
            case 'C':
                printf("Enter person name: ");
                char *in;
                scanf("%s", in);
                char *name = (char *) malloc(strlen(in) + 1);
                strcpy(name, in);
                clientArrival(waitingroom, name);
                break;
            case 'F':
                finishHaircut(waitingroom);
                break;
            case 'Q':
                run = 0;
                break;
            default:
                printf("Invalid Command\n\n**Commands**\nC : Customer arrival\nF : FInish haircut\nQ : Quit\n");
                break;
        }
    } 
    return 0;
}

// Function to add elements to queue
void enqueue(char *waitingroom[], char *name) {
    if (count >= MAX) {
        printf("Queue overflow");
    } else {
        if (front == -1)
            front = 0;
        rear = ++rear % MAX;
        waitingroom[rear] = name;
        count++;
    }
}

// Funtion to remove and get elements from queue
char* dequeue(char *waitingroom[]) {
    if (count <= 0) {
        printf("Queue underflow");
    } else {
        char *val = waitingroom[front]; 
        front = ++front % MAX;
        count--;
        return val;
    }
}

// Check whether queue is full or not
int isFull() {
    return count == MAX;
}

// Check whether queue is empty or not
int isEmpty() {
    return count == 0;
}

// Finish the current haircut
void finishHaircut(char *waitingroom[]) {
    // Check whether there is a current client
    if (currentClient != NULL) {
        // Finish haircut and free allocated memory for the finished client
        printf("%s got a hair cut, ", currentClient);
        free(currentClient);

        // Check whether the waiting room is empty 
        if (isEmpty()) {
            currentClient = NULL;
            printf("no clients in waiting room. Barber sleeps.\n");
        } else {
            // Get the next customer and give him a haircut
            currentClient = dequeue(waitingroom);
            printf("barber checks the waiting room, %s goes to barber room and gets a haircut.\n", currentClient);
        }
    } else {
        printf("No clients, barber is sleeping.\n");
    }
}

// Client arrival
void clientArrival(char *waitingroom[], char *name) {
    // Check whether there is a current client
    if (currentClient != NULL) {
        // Check whether the waiting list is full
        if (isFull()) {
            printf("Barber is busy and waiting list full, %s leaves.\n", name);
        } else {
            // Enqueue client to waiting list
            enqueue(waitingroom, name);
            printf("Barber is busy, %s went to waiting room.\n", name);
        }
    } else {
        // Set client as current client to give a haircut
        currentClient = name;
        printf("Barber is sleeping, %s wake up barber and gets a haircut.\n", name);
    }
}