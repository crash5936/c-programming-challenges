#include <stdio.h>
#include <stdlib.h>

void swap(long* a, long* b) {
	long tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	char swapped = 1;
	int n;
	scanf ("%d", &n);
	long int* nums = malloc (n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf ("%li", &nums[i]);


	for (int i = 0; i < n; i++)
		printf ("%li ", nums[i]);
	printf("\n");

	while (swapped != 0) {
		swapped = 0;
		for (int i = 0; i < n - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				swap(&nums[i], &nums[i+1]);
				swapped = 1;
			}

		}

	}


	for (int i = 0; i < n; i++)
		printf ("%li ", nums[i]);
	printf("\n");

	return 0;
}
