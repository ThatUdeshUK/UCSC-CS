#include <stdio.h>

int main() {
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int odd[n];
	int oddPosition = 0;
	int even[n];
	int evenPosition = 0;
	
	printf("Enter elements of the array\n");
	for (int i = 0;i < n;i++) {
		int input;
		printf("Element %d: ", i);
		scanf("%d", &input);
		if (input % 2 == 0) {
			even[evenPosition] = input;
			evenPosition++;
		} else {
			odd[oddPosition] = input;
			oddPosition++;
		}
	}
	
	printf("The Even elements are :\n");
	for (int i = 0;i < evenPosition;i++) {
		printf("%d ", even[i]);
	}
	
	printf("\nThe Odd elements are :\n");
	for (int i = 0;i < oddPosition;i++) {
		printf("%d ", odd[i]);
	}
	
	return 0;
}
