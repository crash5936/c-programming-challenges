#include <stdio.h>

int main() {
	unsigned long int a;
	unsigned long int b;
	unsigned long int r;
	unsigned long int product;
	unsigned long int nsn;

	printf("Zadejte dvě přirozená čísla: \n");
	scanf("%d %d", &a, &b);

	product = a * b;

	if (a <= 0 || b <= 0)
	{
		printf("Input error \n");
		return -1;
	}

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	nsn = product / a;

	printf("NSN je %d\n", nsn);
	return 0;
}
