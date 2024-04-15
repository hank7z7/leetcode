/*
 * @lc app=leetcode id=598 lang=c
 *
 * [598] Range Addition II
 *
 * https://leetcode.com/problems/range-addition-ii/description/
 *
 * algorithms
 * Easy (54.64%)
 * Likes:    707
 * Dislikes: 832
 * Total Accepted:    81.5K
 * Total Submissions: 148.4K
 * Testcase Example:  '3\n3\n[[2,2],[3,3]]'
 *
 * You are given an m x n matrix M initialized with all 0's and an array of
 * operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented
 * by one for all 0 <= x < ai and 0 <= y < bi.
 *
 * Count and return the number of maximum integers in the matrix after
 * performing all the operations.
 *
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 3, ops = [[2,2],[3,3]]
 * Output: 4
 * Explanation: The maximum integer in M is 2, and there are four of it in M.
 * So return 4.
 *
 *
 * Example 2:
 *
 *
 * Input: m = 3, n = 3, ops =
 * [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
 * Output: 4
 *
 *
 * Example 3:
 *
 *
 * Input: m = 3, n = 3, ops = []
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 4 * 10^4
 * 0 <= ops.length <= 10^4
 * ops[i].length == 2
 * 1 <= ai <= m
 * 1 <= bi <= n
 *
 *
 */

// @lc code=start

int maxCount(int m, int n, int **ops, int opsSize, int *opsColSize)
{
	int m_min = m;
	int n_min = n;
	for (int i = 0; i < opsSize; i++) {
		if (ops[i][0] < m_min)
			m_min = ops[i][0];
		if (ops[i][1] < n_min)
			n_min = ops[i][1];
	}

	return m_min * n_min;
}

// @lc code=end

// Accepted
// 69/69 cases passed (12 ms)
// Your runtime beats 72.34 % of c submissions
// Your memory usage beats 8.51 % of c submissions (7.5 MB)
