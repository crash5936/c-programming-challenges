#include <stdio.h>

int main() {
	int parc, c, nwsp;

	while(((c = getchar()) != EOF))
	{
		if (c == 40) {
			parc++;
			nwsp = 0;
		}

		else if (c == 41) {
			if (parc == 0) {
				printf("Nope\n");
				return -1;
			}

			parc--;
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
			nwsp = 1;
		else if (c == 32 || c == '\n' || c == '\t' || c == 13) {
			continue;
		}
		else {
			printf("Nope\n");
			return -1;
		}
	}




	if (parc != 0 || nwsp == 0) {
		printf("Nope\n");
		return -1;
		}	
		
	else {
		printf("OK\n");
		return 0;
	}

}
