#include <stdio.h>

int main() {
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];

	printf("Enter elements of the array\n");
	for (int i = 0;i < n;i++) {
		printf("Element %d: ", i);
		scanf("%d", &arr[i]);
	}

	int total = 0;

	for (int i = 0;i < n;i++) {
		total += arr[i];
	}

	printf("Mean = %.2f\n", (float) total / n);

	int duplicatedElements[n];
	int duplicatedElementsPos = 0;
	for (int i = 0;i < n;i++) {
		int duplicated = 1;
		for (int j = 0;j < n;j++) {
			if(arr[i] == duplicatedElements[j]){
				duplicated = 0;
			}
		}
		if(duplicated != 0)  {
			int repeats = 1;
			for (int j = i + 1;j < n;j++) {
				if(arr[i] == arr[j])
					repeats++;
			}
			if (repeats > 1) {
				printf("%d number is repealty %d times.\n", arr[i], repeats);
			}
			duplicatedElements[duplicatedElementsPos] = arr[i];
			duplicatedElementsPos++;
		}
	}
	return 0;
}
