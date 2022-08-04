/*
 * @lc app=leetcode id=73 lang=c
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (48.04%)
 * Likes:    8402
 * Dislikes: 528
 * Total Accepted:    778.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row
 * and column to 0's.
 * 
 * You must do it in place.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * A straightforward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start

void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
	// If first column/row need to be set to zero
	bool column = false;
	bool row = false;

	for (int i = 0; i < matrixSize; i++)
		for (int j = 0; j < matrixColSize[0]; j++) {
			if (matrix[i][j] == 0) {
				if (i == 0)
					row = true;
				if (j == 0)
					column = true;
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}

	// Set zeroes without first column and row
	for (int i = 1; i < matrixSize; i++)
		if (matrix[i][0] == 0)
			for (int j = 0; j < matrixColSize[0]; j++)
				matrix[i][j] = 0;

	for (int j = 1; j < matrixColSize[0]; j++)
		if (matrix[0][j] == 0)
			for (int i = 0; i < matrixSize; i++)
				matrix[i][j] = 0;

	if (row)
		for (int j = 0; j < matrixColSize[0]; j++)
			matrix[0][j] = 0;

	if (column)
		for (int i = 0; i < matrixSize; i++)
			matrix[i][0] = 0;
}

// @lc code=end

// Accepted
// 164/164 cases passed (41 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 72.25 % of c submissions (10.9 MB)
