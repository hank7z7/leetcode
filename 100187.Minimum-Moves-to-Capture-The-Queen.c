#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
//                            Rock          Bishop        Queen            
int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
{
	// Rock
	if (a == e) {
		if (a != c)
			return 1;
		else if (abs(b - f) == abs(b - d) + abs(d - f))
			return 2;
		else
			return 1;
	} else if (b == f) {
		if (b != d)
			return 1;
		else if (abs(a - e) == abs(a - c) + abs(c - e))
			return 2;
		else
			return 1;
	}
	// Bishop
	if (abs(c - e) == abs(d - f)) {
		int move_x = (c - e) > 0 ? -1 : 1;
		int move_y = (d - f) > 0 ? -1 : 1;
		// Rock is not on diagnal of Queen
		if (abs(a - e) != (b - f))
			return 1;
		else {
			while (c != e && d != f) {
				c += move_x;
				d += move_y;
				// Bishop encounter Rock
				if (c == a && d == b) {
					return 2;
				}
			}
			return 1;
		}

	}

	return 2;
}

int main(int argc, char **argv)
{
	int input_1[] = { 1, 1, 8, 8, 2, 3 };
	printf("%d\n",
	       minMovesToCaptureTheQueen(input_1[0], input_1[1], input_1[2],
					 input_1[3], input_1[4], input_1[5]));

	int input_2[] = { 5, 3, 3, 4, 5, 2 };
	printf("%d\n",
	       minMovesToCaptureTheQueen(input_2[0], input_2[1], input_2[2],
					 input_2[3], input_2[4], input_2[5]));

	int input_3[] = { 4, 3, 3, 4, 5, 2 };
	printf("%d\n",
	       minMovesToCaptureTheQueen(input_3[0], input_3[1], input_3[2],
					 input_3[3], input_3[4], input_3[5]));

	return 0;
}
