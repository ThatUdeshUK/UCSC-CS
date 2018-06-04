#include <stdio.h>
#include <string.h>

#define MAX 100
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

int size() {
  return count;
}

int main() {
  printf("Enter K: ");
  int k, wordCount = 0;
  scanf("%d", &k);
  printf("Enter string with %d words or more: ", k);
  char str[50];
  scanf(" %[^\n]s", &str);
  char* token = strtok(str, " ");
  while (token != NULL) {
    enqueue(token);
    wordCount++;
    token = strtok(NULL, " ");
  }
  if (wordCount < k) {
    printf("Not enough words. Should enter a string with %d words or more\n", k);
  } else {
    int i;
    for (i = 0; i < wordCount - k; i++) {
      dequeue();
    }
    printf("%dth string from end is \"%s\"\n", k, dequeue());
  }
  return 0;
}
