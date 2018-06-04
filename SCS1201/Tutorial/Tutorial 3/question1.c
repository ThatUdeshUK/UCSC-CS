#include <stdio.h>

#define MAX 20

// Stack 1
int stack[MAX];
int top = -1;
int pop() { return stack[top--]; }
void push(int value) { stack[++top] = value; }
int peek() { return stack[top]; }

int stack1[MAX];
int top1 = -1;
int stack1Pop() { return stack1[top1--]; }
void stack1Push(int value) { stack1[++top1] = value; }
int stackPeek() { return stack1[top1]; }

int stack2[MAX];
int top2 = -1;
int stack2Pop() { return stack2[top2--]; }
void stack2Push(int value) { stack2[++top2] = value; }
int stack2Peek() { return stack2[top2]; }

void copy() {
  for (int i = 0; i <= top1; i++) {
    stack1[i] = stack[i];
  }
}

int main() {
  
  // Basic stack functions
  push(24);
  push(16);
  printf("%d\n", peek());
  printf("%d\n", pop());
  printf("%d\n", pop());

  // Copy stack to stack 1
  copy();

  return 0;
}
