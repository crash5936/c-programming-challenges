#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	long int n;
	srandom(time(NULL));
	for (int i = 0; i < 100; i++) {
		printf("%ld\n", random() % 1000000000);
	}
	return 0;

}
