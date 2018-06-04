#include <stdio.h>
#include <string.h>

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
  printf("Enter the number: ");
  int n;
  scanf("%d", &n);

  while (n > 0) {
    push(n % 2);
    n /= 2;
  }

  int i;
  while (top >= 0) {
    printf("%d", pop());
  }
  printf("\n");
  return 0;
}
