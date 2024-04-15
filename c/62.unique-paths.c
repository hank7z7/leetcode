/*
 * @lc app=leetcode id=62 lang=c
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (59.75%)
 * Likes:    14829
 * Dislikes: 405
 * Total Accepted:    1.5M
 * Total Submissions: 2.4M
 * Testcase Example:  '3\n7'
 *
 * There is a robot on an m x n grid. The robot is initially located at the
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the
 * bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
 * either down or right at any point in time.
 * 
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 * 
 * The test cases are generated so that the answer will be less than or equal
 * to 2 * 10^9.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 7
 * Output: 28
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation: From the top-left corner, there are a total of 3 ways to reach
 * the bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 100
 * 
 * 
 */

// @lc code=start
int uniquePaths(int m, int n)
{
	//_R_R_R_R_R_R_ DD
	//_D_R_R_R_R_R_R_ D
	long long result = 1;
	int max = m >= n ? m : n;
	int min = m > n ? n : m;
	int i = 0;

	for (i = 0; i < (min - 1); i++) {
		result *= (max + i);
		result /= (i + 1);
	}

	return (int)result;
}

// @lc code=end

// Accepted
// 63/63 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 15.6 % of c submissions (5.7 MB)
