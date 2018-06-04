#include <stdio.h>

int stack[10];
int pointer = 0;

void push(int number) {
	stack[pointer] = number;
	pointer++;
}

int pop() {
	int value = stack[pointer];
	pointer--;
	return value;
}

int peek() {
	return stack[pointer];
}

int main() {
	
	return 0;
}

