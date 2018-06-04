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
  printf("Enter number of elements: ");
  int n, i;
  scanf("%d", &n);
  int numbers[n];
  int lastLargest = 0;
  for (i = 0; i < n; i++) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &numbers[i]);
    if (numbers[i] > lastLargest) {
      lastLargest = numbers[i];
    }
  }

  for (i = 0; i < n; i++) {
    enqueue(lastLargest);
    int largest = 0;
    int j;
    for (j = 0; j < n; j++) {
      if (numbers[j] > largest && numbers[j] < lastLargest)
        largest = numbers[j];
    }
    lastLargest = largest;
  }

  printf("Largest number: ");
  while (!isEmpty()) {
    printf("%d", dequeue());
  }
  printf("\n");
  return 0;
}
