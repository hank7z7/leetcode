/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (63.87%)
 * Likes:    7174
 * Dislikes: 234
 * Total Accepted:    932.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '5'
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 * 
 * 
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numRows <= 30
 * 
 * 
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
	int **result = (int **)malloc(sizeof(int *) * numRows);
	// Return an array, array[i] is the row size
	*returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
	*returnSize = numRows;

	for (int i = 0; i < numRows; i++) {
		// (pointer)[index] is needed!
		(*returnColumnSizes)[i] = i + 1;
		result[i] = (int *)malloc(sizeof(int) * (i + 1));

		// Write first and last element first
		result[i][0] = 1;
		result[i][i] = 1;

		// Only loof the inter array if faster
		for (int j = 1; j < i; j++) {
			// if(j == 0 || j == i)
			//     result[i][j] = 1;
			// else
			result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
		}
	}
	return result;
}

// @lc code=end

// Accepted
// 14/14 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 79.05 % of c submissions (5.9 MB)
