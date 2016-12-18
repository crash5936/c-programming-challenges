#include <stdio.h>

int main()
{
	int first[4][4], second[4][4], third[4][4], count, arrnum, i, j, k, field;


	scanf ("%d", &count);
	if (count < 2) {
		printf ("Enter at least 2 matrices");
		return -1;
	}

	field = 0;
	arrnum = 1;


	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			scanf ("%d", &first[i][j]);
	}

	while (arrnum < count) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++)
				scanf ("%d", &second[i][j]);
		}

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				for (k = 0; k < 4; k++) {
					field += first[i][k] * second[k][j];
				}
				third[i][j] = field;
				field = 0;
			}
		}

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				first[i][j] = third[i][j];
			}
		}

		arrnum++;
	}





	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf ("%d ", first[i][j]);
		}
		printf ("\n");
	}
}
