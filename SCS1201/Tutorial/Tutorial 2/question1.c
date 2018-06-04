#include <stdio.h>

int main() {
	int arr[10];
	printf("Enter number of elements (Less than 10): ");
	int n;
	scanf("%d", &n);

	printf("Enter elements of the array\n");
	for (int i = 0;i < n;i++) {
		printf("Element %d: ", i);
		scanf("%d", &arr[i]);
	}

	int sumPositive = 0;
	int sumNegative = 0;
	int total = 0;

	for (int i = 0;i < n;i++) {
		if (arr[i] > 0) {
			sumPositive += arr[i];
		} else {
			sumNegative += arr[i];
		}
	}

	total = sumPositive + sumNegative;

	printf("Sum of all positive numbers = %d\n", sumPositive);
	printf("Sum of all negative numbers = %d\n", sumNegative);
	printf("Average of all input numbers = %.2f\n", total * 1.0f/n);

	return 0;
}
