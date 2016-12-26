#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (long* a, long* b)
{
	long tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	char swapped = 1;
	int n;
	scanf ("%d", &n);
	
	clock_t start, end;
	double time;

	long* nums = malloc (n * sizeof (long));
	for (int i = 0; i < n; i++)
		scanf ("%li", &nums[i]);

/*
*	for (int i = 0; i < n; i++)
*		printf ("%li ", nums[i]);
*	printf ("\n");
*/

	start = clock();

	while (swapped != 0) {
		swapped = 0;
		for (int i = 0; i < n - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				swap (&nums[i], &nums[i + 1]);
				swapped = 1;
				if (i % 10000 == 0)
					printf("%ld passes\n", i * 100000);
			}

		}

	}
	
	end = clock();
	time = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("Time taken: %f s\n", time);

	for (int i = 0; i < n; i++)
		printf ("%li ", nums[i]);
	printf ("\n");

	free (nums);

	return 0;
}
