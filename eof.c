#include <stdio.h>

int main() {
	int e = EOF;
	printf("%d\n", e);

	long nc;

	while (getchar() != EOF)
		++nc;

	printf("%ld\n", nc);


	return 0;
}
