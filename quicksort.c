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
	long n = end - nums;
	
	if (n <= 1)
		return;

	long* lo = nums;
	long* pivot = nums;

	
	for (int i = 1; i < n; i++) {
		if (*(nums + i) < *pivot) {
			swap(nums + i, lo + 1);
			lo++;
		}

	}

	swap(pivot, lo);

	quicksort(nums, lo);
	quicksort(lo + 1, end); 


}

int main()
{
	long n;

	scanf("%li", &n);

	long* nums = malloc (n * sizeof (long));
	
	for (int i = 0; i < n; i++)
		scanf("%li", nums + i);

	long* end = nums + n;

	quicksort(nums, end);

	for (int i = 0; i < n; i++)
		printf("%li\n", *(nums + i));

	free(nums);
}
