/*
 * @lc app=leetcode id=48 lang=c
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (72.28%)
 * Likes:    16561
 * Dislikes: 731
 * Total Accepted:    1.5M
 * Total Submissions: 2.1M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image, rotate the image by
 * 90 degrees (clockwise).
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int matrixSize, int *matrixColSize)
{
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixColSize[i]; j++) {
			printf("%8d", matrix[i][j]);
			if (j != matrixColSize[i] - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// @lc code=start
void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
	for (int i = 0; i < matrixSize / 2; i++) {
		int colSize = matrixColSize[i];
		// Note: We move the row expect the last one
		for (int j = i; j < colSize - i - 1; j++) {
			int tmp = matrix[i][j];
			// (0, 0) -> (3, 0) -> (3, 3) -> (0, 3)
			// (0, 1) -> (2, 0) -> (3, 2) -> (1, 3)
			matrix[i][j] = matrix[matrixSize - 1 - j][0 + i];
			matrix[matrixSize - 1 - j][0 + i] =
			    matrix[matrixSize - 1 - i][matrixSize - 1 - j];
			matrix[matrixSize - 1 - i][matrixSize - 1 - j] =
			    matrix[0 + j][matrixSize - 1 - i];
			matrix[0 + j][matrixSize - 1 - i] = tmp;
		}
	}
}

// @lc code=end

int main(int argc, char **argv)
{
	// Test 1
	const int input_size1 = 3;
	// Allocate input 1
	int **input_matrix1 = (int **)malloc(sizeof(int *) * input_size1);
	for (int i = 0; i < input_size1; i++)
		input_matrix1[i] = (int *)malloc(sizeof(int) * input_size1);

	// Initialize input 1
	for (int i = 0; i < input_size1; i++) {
		for (int j = 0; j < input_size1; j++) {
			input_matrix1[i][j] = i * 10 + j;
		}
	}

	// Allocate colsize 1
	int *colsize1 = (int *)malloc(sizeof(int) * input_size1);

	// Initialize colsize 1
	for (int i = 0; i < input_size1; i++)
		colsize1[i] = input_size1;

	print_matrix((int **)input_matrix1, input_size1, (int *)colsize1);
	rotate(input_matrix1, input_size1, colsize1);
	print_matrix(input_matrix1, input_size1, colsize1);

	// Test 2
	const int input_size2 = 4;
	// Allocate input 2
	int **input_matrix2 = (int **)malloc(sizeof(int *) * input_size2);
	for (int i = 0; i < input_size2; i++)
		input_matrix2[i] = (int *)malloc(sizeof(int) * input_size2);

	// Initialize input 2
	for (int i = 0; i < input_size2; i++) {
		for (int j = 0; j < input_size2; j++) {
			input_matrix2[i][j] = i * 10 + j;
		}
	}

	// Allocate colsize 2
	int *colsize2 = (int *)malloc(sizeof(int) * input_size2);

	// Initialize colsize 1
	for (int i = 0; i < input_size2; i++)
		colsize2[i] = input_size2;

	print_matrix((int **)input_matrix2, input_size2, (int *)colsize2);
	rotate(input_matrix2, input_size2, colsize2);
	print_matrix(input_matrix2, input_size2, colsize2);

	return 0;
}

// Accepted
// 21/21 cases passed (10 ms)
// Your runtime beats 25.47 % of c submissions
// Your memory usage beats 29.81 % of c submissions (7.1 MB)
