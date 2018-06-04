#include <stdio.h>

int main() {
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	
	int newArr[n];
	
	printf("Enter elements of the array\n");
	for (int i = 0;i < n;i++) {
		printf("Element %d: ", i);
		scanf("%d", &arr[i]);
	}
	
	for (int i = 0;i < n;i++) {
		newArr[i] = arr[n-1-i];
	}	
	
	for (int i = 0;i < n;i++) {
		printf("%d ", newArr[i]);
	}
	
	return 0;
}
