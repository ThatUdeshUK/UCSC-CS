#include <stdio.h>

int n;
int front = -1;
int rear = -1;
int count = 0;

int x = -1;

void enqueue(int wait[], int id) {
    if (count >= n) {

    } else {
        if (front == -1)
            front = 0;
        rear = ++rear % n;
        wait[rear] = id;
        count++;
    }
}

int dequeue(int wait[]) {
    if (count <= 0) {

    } else {
        int val = wait[front]; 
        front = ++front % n;
        count--;
        return val;
    }
}

int isFull() {
    return count == n;
}

int isEmpty() {
    return count == 0;
}

void come(int wait[], int id) {
    if (x != -1) {
        if (isFull()) {
            printf("Barber busy. Waiting list full. %d leaves.\n", id);
        } else {
            enqueue(wait, id);
            printf("Barber busy. %d went to waiting room.\n", id);
        }
    } else {
        x = id;
        printf("Barber sleeping, %d gets a haircut.\n", id);
    }
}

void finish(int wait[]) {
    if (x != -1) {
        printf("%d hair cut finish. ", x);
        if (isEmpty()) {
            x = -1;
            printf("0 in waiting room. Barber sleeps.\n");
        } else {
            x = dequeue(wait);
            printf("%d gets a haircut.\n", x);
        }
    } else {
        printf("Barber is sleeping.\n");
    }
}

int main() {
    printf("Enter n: ");
    scanf("%d", &n);
    n--;
    printf("\n**Commands**\nC : Customer arrival\nF : Finish haircut\nQ : Quit\n");
    int wait[n];
    char option;
    int x = 1;
    while (x == 1) {
        printf("\nEnter option:");
        scanf(" %c", &option);
        switch (option) {
            case 'C':
                printf("Enter id: ");
                int id;
                scanf("%d", &id);
                clientArrival(wait, id);
                break;
            case 'F':
                finishHaircut(wait);
                break;
            case 'Q':
                x = 0;
                break;
        }
    } 
    return 0;
}