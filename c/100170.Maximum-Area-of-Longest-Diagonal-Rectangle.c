#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int areaOfMaxDiagonal(int **dimensions, int dimensionsSize,
		      int *dimensionsColSize)
{
	int max_diagnal = 0;
	int max_area = 0;

	for (int i = 0; i < dimensionsSize; i++) {
		int max_diagnal = 0;
		int max_area = 0;
		for (int i = 0; i < dimensionsSize; i++) {
			int diagnal =
			    dimensions[i][0] * dimensions[i][0] +
			    dimensions[i][1] * dimensions[i][1];
			if (diagnal > max_diagnal) {
				max_diagnal = diagnal;
				max_area = dimensions[i][0] * dimensions[i][1];
			} else if (diagnal == max_diagnal) {
				if (dimensions[i][0] * dimensions[i][1] >
				    max_area)
					max_area =
					    dimensions[i][0] * dimensions[i][1];
			}
		}
	}
	return max_area;
}

int main(int argc, char **argv)
{
	// int size_1 = 2;
	// int input_1[2][2] = { {9, 3}, {8, 6}};
	// int colomn_1[] = {2, 2};
	// printf("%d\n", areaOfMaxDiagonal(input_1, size_1, colomn_1));

	// int size_2 = 2;
	// int input_2[2][2] = { {3, 4}, {4, 3} };
	// int colomn_2[] = {2, 2};
	// printf("%d\n", areaOfMaxDiagonal(input_2, size_2, colomn_2));
	return 0;
}
