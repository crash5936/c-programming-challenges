#include <stdio.h>

int main()
{
	unsigned long int a, b, r, product, lcm;

	printf ("Enter two natural numbers: \n");
	scanf ("%d %d", &a, &b);

	product = a * b;

	if (a <= 0 || b <= 0) {
		printf ("Input error \n");
		return -1;
	}

	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	lcm = product / a;

	printf ("LCM is %d\n", lcm);

	return 0;
}
