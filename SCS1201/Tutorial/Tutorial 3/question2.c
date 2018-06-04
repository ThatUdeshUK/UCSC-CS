#include <stdio.h>

#define MAX 20
int stack[MAX];
int top = -1;

int pop() {
  if (top >= 0) {
    return stack[top--];
  } else {
    printf("Stack Underflow");
  }
}

void push(int value) {
  if (top < MAX) {
    stack[++top] = value;
  } else {
    printf("Stack Overflow");
  }
}

int peek() {
  if (top >= 0) {
    return stack[top];
  } else {
    printf("Empty Stack");
  }
}

int main() {
  printf("Enter number of elements (Less Than 20): ");
  int n;
  scanf("%d", &n);
  int arr[n];

  int i;
  for (i = 0;i < n;i++) {
    printf("Enter element %d : ", i);
    scanf("%d", &arr[i]);
  }

  printf("Elements: ");
  for (i = 0;i < n;i++) {
    printf("%d ", arr[i]);
  }

  for (i = 0;i < n;i++) {
    push(arr[i]);
  }

  for (i = 0;i < n;i++) {
    arr[i] = pop();
  }

  printf("\nRevised Elements: ");
  for (i = 0;i < n;i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}
