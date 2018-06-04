#include <stdio.h>

#define MAX 50
int queue[MAX];
int front = -1;
int rear = -1;
int count = 0;

void enqueue(int value) {
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

int dequeue() {
  if (count == 0) {
    printf("Queue Underflow\n");
    return -1;
  } else {
    count--;
    int temp = queue[front];
    front = ++front % MAX;
    return temp;
  }
}

void display() {
  int j = front;
  int i;
  for (i = 0; i < count; i++) {
    printf("%d ", queue[j]);
    j = ++j % MAX;
  }
  printf("\n");
}

int isEmpty() {
  return count == 0;
}

int size() {
  return count;
}

int main() {
  int n, m;
  printf("Enter n: ");
  scanf("%d", &n);
  printf("Enter m: ");
  scanf("%d", &m);

  int i;
  for (i = 1; i <= n; i++) {
    enqueue(i);
  }

  while (size() != 1) {
    for (i = 1; i < m; i++) {
      enqueue(dequeue());
    }
    printf("%d person is getting eliminated\n", dequeue());
  }

  printf("\n%d person is not getting eliminated\n", dequeue());

  return 0;
}
