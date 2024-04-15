/*
 * @lc app=leetcode id=54 lang=c
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (47.24%)
 * Likes:    13835
 * Dislikes: 1206
 * Total Accepted:    1.3M
 * Total Submissions: 2.6M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize,
		 int *returnSize)
{
	int retSize = matrixSize * matrixColSize[0];
	int *result = (int *)malloc(sizeof(int) * retSize);
	memset(result, 0, sizeof(int) * retSize);

	int start_x = 0;
	int start_y = 0;
	int max_x = matrixSize - 1;
	int max_y = matrixColSize[0] - 1;
	int index = 0;

	while (start_x <= max_x && start_y <= max_y) {
		// printf("%d %d %d %d\n", start_x, start_y, max_x, max_y);
		if (start_x == max_x) {
			for (int j = start_y; j <= max_y; j++) {
				// printf("%d %d:%d\n", start_x, j, matrix[start_x][j]);
				result[index++] = matrix[start_x][j];
			}
		} else if (start_y == max_y) {
			for (int i = start_x; i <= max_x; i++) {
				// printf("%d %d:%d\n", i, max_y, matrix[i][max_y]);
				result[index++] = matrix[i][max_y];
			}
		} else {
			for (int j = start_y; j < max_y; j++) {
				result[index++] = matrix[start_x][j];
			}
			for (int i = start_x; i < max_x; i++) {
				result[index++] = matrix[i][max_y];
			}
			for (int j = max_y; j > start_y; j--) {
				result[index++] = matrix[max_x][j];
			}
			for (int i = max_x; i > start_x; i--) {
				result[index++] = matrix[i][start_y];
			}
		}

		start_x++;
		start_y++;
		max_x--;
		max_y--;
	}

	*returnSize = retSize;
	return result;
}

// @lc code=end

int main(int argc, char **argv)
{
	int resturnSize = 0;
	int matrixSize = 3;

	// test 1
	// matrixSize = 3;
	// int matrixColSize1[3] = { 3, 3, 3 };
	// int matrix1[3][3] = { {1, 4, 7}, {2, 5, 8}, {3, 6, 9} };
	// int *result1;
	// result1 = spiralOrder(matrix1, matrixSize, matrixColSize1, &resturnSize);
	// for (int i = 0; i < resturnSize; i++) {
	//      printf("%d ", result1[i]);
	// }
	// printf("\n");
	// free(result1);

	// test 2
	// matrixSize = 1;
	// int matrixColSize2[1] = { 3 };
	// int matrix2[1][3] = { {6, 9, 7} };
	// int *result2;
	// result2 = spiralOrder(matrix2, matrixSize, matrixColSize2, &resturnSize);
	// for (int i = 0; i < resturnSize; i++) {
	//      printf("%d ", result2[i]);
	// }
	// printf("\n");
	// free(result2);

	return 0;
}

// Accepted
// 25/25 cases passed (3 ms)
// Your runtime beats 51.91 % of c submissions
// Your memory usage beats 78.01 % of c submissions (6.3 MB)
