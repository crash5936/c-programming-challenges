#include <stdio.h>
#include <stdlib.h>

void swap (long* a, long* b)
{
	long tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort (long* nums, long* end)
{
	int n = end - nums;
	printf("array length is %d\n", n);
	if (n <= 1)
		return;

	long* lo = nums;
	long* pivot = nums;

	
	for (int i = 1; i < n; i++) {
		if (*(nums + i) < *pivot) {
			printf("%li < pivot (%li), swapping with %li\n", *(nums + i), *pivot, *(lo + 1));
			swap(nums + i, lo + 1);
			lo++;
		}

	}

	swap(pivot, lo);
	printf("\npivot je ted %li\n", *pivot);
	printf("lo je ted %li na pozici %li\n\n", *lo, lo - nums);

	quicksort(nums, lo - 1);
	quicksort(lo + 1, end); 


}

int main()
{
	int n;

	scanf("%d", &n);

	long* nums = malloc (n * sizeof (long));
	
	for (int i = 0; i < n; i++)
		scanf("%li", nums + i);

	long* end = nums + n;

	quicksort(nums, end);

	for (int i = 0; i < n; i++)
		printf("%li\n", *(nums + i));

	free(nums);
}
