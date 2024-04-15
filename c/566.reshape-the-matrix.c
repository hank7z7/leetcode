/*
 * @lc app=leetcode id=566 lang=c
 *
 * [566] Reshape the Matrix
 *
 * https://leetcode.com/problems/reshape-the-matrix/description/
 *
 * algorithms
 * Easy (62.31%)
 * Likes:    2607
 * Dislikes: 293
 * Total Accepted:    275.3K
 * Total Submissions: 439.7K
 * Testcase Example:  '[[1,2],[3,4]]\n1\n4'
 *
 * In MATLAB, there is a handy function called reshape which can reshape an m x
 * n matrix into a new one with a different size r x c keeping its original
 * data.
 * 
 * You are given an m x n matrix mat and two integers r and c representing the
 * number of rows and the number of columns of the wanted reshaped matrix.
 * 
 * The reshaped matrix should be filled with all the elements of the original
 * matrix in the same row-traversing order as they were.
 * 
 * If the reshape operation with given parameters is possible and legal, output
 * the new reshaped matrix; Otherwise, output the original matrix.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,2],[3,4]], r = 1, c = 4
 * Output: [[1,2,3,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[1,2],[3,4]], r = 2, c = 4
 * Output: [[1,2],[3,4]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * -1000 <= mat[i][j] <= 1000
 * 1 <= r, c <= 300
 * 
 * 
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int c,
		    int *returnSize, int **returnColumnSizes)
{
	int m = matSize;
	int n = matColSize[0];
	int **result;
	if ((m * n) != (r * c)) {
		(*returnSize) = m;
		(*returnColumnSizes) = (int *)malloc(sizeof(int) * m);
		for (int i = 0; i < m; i++)
			(*returnColumnSizes)[i] = n;
		result = mat;
	} else {
		(*returnSize) = r;
		(*returnColumnSizes) = (int *)malloc(sizeof(int) * r);
		result = (int **)malloc(sizeof(int *) * r);
		for (int i = 0; i < r; i++) {
			result[i] = (int *)malloc(sizeof(int) * c);
			(*returnColumnSizes)[i] = c;
		}
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				result[i][j] =
				    mat[(i * c + j) / n][(i * c + j) % n];
	}
	return result;
}

// @lc code=end

// Accepted
// 57/57 cases passed (58 ms)
// Your runtime beats 37.58 % of c submissions
// Your memory usage beats 78.79 % of c submissions (10.1 MB)
