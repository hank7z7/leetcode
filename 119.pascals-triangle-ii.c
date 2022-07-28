/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (57.14%)
 * Likes:    2924
 * Dislikes: 274
 * Total Accepted:    563.1K
 * Total Submissions: 960.1K
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndex^th (0-indexed) row of the
 * Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 * 
 * 
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= rowIndex <= 33
 * 
 * 
 * 
 * Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
 * space?
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize)
{
	int *result = (int *)malloc(sizeof(int) * (rowIndex + 1));

	// Return the array size
	*returnSize = rowIndex + 1;

	for (int i = 0; i <= rowIndex; i++) {
		// Write last element first
		result[i] = 1;

		// Only loof the inter array if faster
		for (int j = i - 1; j > 0; j--) {
			result[j] = result[j] + result[j - 1];
		}
	}
	return result;
}

// @lc code=end

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 13.61 % of c submissions (5.9 MB)
