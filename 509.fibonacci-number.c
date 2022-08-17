/*
 * @lc app=leetcode id=509 lang=c
 *
 * [509] Fibonacci Number
 *
 * https://leetcode.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (68.13%)
 * Likes:    4810
 * Dislikes: 284
 * Total Accepted:    987.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '2'
 *
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
 * Fibonacci sequence, such that each number is the sum of the two preceding
 * ones, starting from 0 and 1. That is,
 * 
 * 
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 * 
 * 
 * Given n, calculate F(n).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: 2
 * Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 30
 * 
 * 
 */

// @lc code=start

int fib(int n)
{
	int prev[2] = { 0, 1 };
	if (n < 2)
		return prev[n];
	else {
		for (int i = 2; i <= n; i++)
			prev[i % 2] = prev[0] + prev[1];
	}
	return prev[n % 2];
}

// @lc code=end
