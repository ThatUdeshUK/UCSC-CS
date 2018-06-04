#include <stdio.h>
#include <string.h>

#define MAX 20
char stack[MAX];
int top = -1;

char pop() {
  if (top >= 0) {
    return stack[top--];
  } else {
    printf("Stack Underflow");
  }
}

void push(char value) {
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
  char expr[20];
  expr[0] = '\0';

  printf("Enter the equation: ");
  char phrase[20];
  scanf("%s", &phrase);

  strncat(phrase, ")", 1);
  push('(');

  int i;
  for (i = 0;i < strlen(phrase);i++) {
    if (phrase[i] == '(') {
      push('(');
    } else if ((phrase[i] >= 48 && phrase[i] <= 57) || (phrase[i] >= 65 && phrase[i] <= 90) || (phrase[i] >= 97 && phrase[i] <= 122)) {
      int len = strlen(expr);
      expr[len] = phrase[i];
      expr[len + 1] = '\0';
    } else if (phrase[i] == ')') {
       while (peek() != '(') {
        int len = strlen(expr);
        expr[len] = pop();
        expr[len + 1] = '\0';
      }
      pop();
    } else if (phrase[i] == '+' || phrase[i] == '-') {
      while (peek() != '(') {
       int len = strlen(expr);
       expr[len] = pop();
       expr[len + 1] = '\0';
      }
      push(phrase[i]);
    } else if (phrase[i] == '*' || phrase[i] == '/' ) {
      push(phrase[i]);
    }

  }
  int j;
  for (j = 0;j < strlen(expr);j++) {
    printf("%c", expr[j]);
  }
  printf("\n");
  return 0;
}

/*
  a) stack
  b) 32*4AB+*+
  c) AB+CD+*
  d) AB+C*DE-FG+*-
*/
