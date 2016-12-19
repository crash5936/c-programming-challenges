#include <stdio.h>

int main() {
	unsigned char input;
	int pos[3] = {0, 0, 0};
	
	struct vector{
		int x;
		int y;
		int z;
	};	

	struct system {
		struct vector vector_x;
		struct vector vector_y;
		struct vector vector_z;
	};

	struct system plane = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	struct system buffer = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	while((scanf("%1c", &input)) != EOF) {
		switch (input) {
			case 'u': case 'U': /* vector Z = vector Y * -1 */
				buffer.vector_z = plane.vector_y;
				buffer.vector_y.x = plane.vector_z.x * -1;
				buffer.vector_y.y = plane.vector_z.y * -1;
				buffer.vector_y.z = plane.vector_z.z * -1;

				plane.vector_y = buffer.vector_y;
				plane.vector_z = buffer.vector_z;
					
				break;
			case 'd': case 'D': /* vector Z = vector Y * -1, vector Y = vector Z */
				buffer.vector_z.x = plane.vector_y.x * -1;
				buffer.vector_z.y = plane.vector_y.y * -1;
				buffer.vector_z.z = plane.vector_y.z * -1;
				buffer.vector_y = plane.vector_z;

				plane.vector_y = buffer.vector_y;
				plane.vector_z = buffer.vector_z;

				break;
			case 'l': case 'L': /* vector X = vector Z; vector Z = vector X * -1 */
				buffer.vector_z.x = plane.vector_x.x * -1;
				buffer.vector_z.y = plane.vector_x.y * -1;
				buffer.vector_z.z = plane.vector_x.z * -1;
				buffer.vector_x = plane.vector_z;

				plane.vector_x = buffer.vector_x;
				plane.vector_z = buffer.vector_z;

				break;
			case 'r': case 'R': /* vector X = vector Z * -1, vector Z = vector X */
				buffer.vector_x.x = plane.vector_z.x * -1;
				buffer.vector_x.y = plane.vector_z.y * -1;
				buffer.vector_x.z = plane.vector_z.z * -1;
				buffer.vector_z = plane.vector_x;

				plane.vector_x = buffer.vector_x;
				plane.vector_z = buffer.vector_z;

				break;
			case '<': /* vector Y = vector X * -1, vector X = vector Y */
				buffer.vector_y.x = plane.vector_x.x * -1;
				buffer.vector_y.y = plane.vector_x.y * -1;
				buffer.vector_y.z = plane.vector_x.z * -1;
				buffer.vector_x = plane.vector_y;

				plane.vector_x = buffer.vector_x;
				plane.vector_y = buffer.vector_y;

				break;
			case '>': /* vector X = vector Y * -1, vector Y = vector X */
				buffer.vector_x.x = plane.vector_y.x * -1;
				buffer.vector_x.y = plane.vector_y.y * -1;
				buffer.vector_x.z = plane.vector_y.z * -1;
				buffer.vector_y = plane.vector_x;

				plane.vector_x = buffer.vector_x;
				plane.vector_y = buffer.vector_y;

				break;
			case 'f': case 'F':
				pos[0] += plane.vector_z.x;
				pos[1] += plane.vector_z.y;
				pos[2] += plane.vector_z.z;
				printf("%d %d %d\n", pos[0], pos[1], pos[2]);
				break;
			default:
				continue;


		}


	}

	return 0;
}
