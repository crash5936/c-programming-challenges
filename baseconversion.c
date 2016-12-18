#include <stdio.h>

int convnum(int conv);

int main() {
	unsigned long n, o; 
	int i, j;
	unsigned int num[62];

	printf("base 10 input: ");
	scanf("%d", &n);
	


	for (i = 2; i <= 62; i++) {
		printf("base %d: ", i);
		j = 0;
		o = n;

		while (o != 0)
		{
			num[j] = o % i;
			o /= i;
			j++;
		}
		
		j--;

		while (j >= 0) {
			printf("%c", convnum(num[j]));
			j--;
		}

		printf("\n");

	}

}

int convnum(int conv) {
	if (conv <= 9) {
		return conv + '0';
	}
	else if (conv > 9 && conv < 37) {
		return conv + 'a' - 10;

	}
	else if (conv >= 37 && conv < 62) {
		return conv + 'A' - 36;
	}
}
