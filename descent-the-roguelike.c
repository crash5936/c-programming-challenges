#include <stdio.h>

struct vector {
	int x;
	int y;
	int z;
};

struct vector neg (struct vector input)
{
	struct vector output = { -input.x, -input.y, -input.z};
	return output;
}

struct vector add (struct vector vec_a, struct vector vec_b)
{
	struct vector output = {vec_a.x + vec_b.x, vec_a.y + vec_b.y, vec_a.z + vec_b.z};
	return output;
}

int main()
{
	unsigned char input;

	struct vector right = {1, 0, 0};
	struct vector top = {0, 1, 0};
	struct vector front = {0, 0, 1};
	struct vector pos = {0, 0, 0};
	struct vector tmp;

	while ( (scanf ("%1c", &input)) != EOF) {
		switch (input) {
		case 'u':
		case 'U': /* vector Z = vector Y, vector Y = vector -Z */
			tmp = neg (front);
			front = top;
			top = tmp;

			break;
		case 'd':
		case 'D': /* vector Z = vector Y * -1, vector Y = vector Z */
			tmp = neg (top);
			top = front;
			front = tmp;

			break;
		case 'l':
		case 'L': /* vector X = vector Z; vector Z = vector X * -1 */
			tmp = neg (right);
			right = front;
			front = tmp;

			break;
		case 'r':
		case 'R': /* vector X = vector Z * -1, vector Z = vector X */
			tmp = neg (front);
			front = right;
			right = tmp;

			break;
		case '<': /* vector Y = vector X * -1, vector X = vector Y */
			tmp = neg (right);
			right = top;
			top = tmp;

			break;
		case '>': /* vector X = vector Y * -1, vector Y = vector X */
			tmp = neg (top);
			top = right;
			right = tmp;
			break;
		case 'f':
		case 'F': /* plane goes along its Z axis */
			pos = add (front, pos);
			printf ("%d %d %d\n", pos.x, pos.y, pos.z);
			break;
		default:
			continue;


		}


	}

	return 0;
}

