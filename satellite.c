#include <stdio.h>

int main() {

	int i, peakx, desc;
	float curry, prevy, peaky;
	scanf("%f", &curry);

	do
	{
		prevy = curry;
		i++;
		scanf("%f", &curry);

		if (prevy < curry) {
			peakx = i;
			peaky = curry;
			desc = 0;
		}

		else if (prevy > curry && desc != 1) {
			if (i != 1) {
			printf("vyska: %.2f, delka: %d\n", peaky, peakx);
			}
			desc = 1;
		}
			



	} while (curry >= 0);
	return 0;
}
