#include <stdio.h>

#define MAX 3
char* queue[MAX];
int front = -1;
int rear = -1;
int count = 0;

void enqueue(char* value) {
  if (count == MAX) {
    printf("Queue Overflow\n");
  } else {
    if (front == -1 && rear == -1) {
      front = 0;
    }
    rear = ++rear % MAX;
    queue[rear] = value;
    count++;
  }
}

char* dequeue() {
  if (count == 0) {
    printf("Queue Underflow\n");
    return NULL;
  } else {
    count--;
    char* temp = queue[front];
    front = ++front % MAX;
    return temp;
  }
}

void display() {
  int j = front;
  int i;
  for (i = 0; i < count; i++) {
    printf("%s ", queue[j]);
    j = ++j % MAX;
  }
  printf("\n");
}

int isEmpty() {
  return count == 0;
}

int main() {

  // a) Representing current scenario
  enqueue("John");
  enqueue("Kate");
  enqueue("Shankar");

  // b)
  dequeue();
  enqueue("Zara");
  enqueue("Jack");
  dequeue();
  dequeue();

  return 0;
}

/*

c) One patient is waiting. Because when we try to enqueue "Jack" queue overflows. So finally, only "Zara" will be on the queue.

*/
