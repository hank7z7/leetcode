/*
 * @lc app=leetcode id=507 lang=c
 *
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (37.55%)
 * Likes:    627
 * Dislikes: 894
 * Total Accepted:    110.4K
 * Total Submissions: 293.2K
 * Testcase Example:  '28'
 *
 * A perfect number is a positive integer that is equal to the sum of its
 * positive divisors, excluding the number itself. A divisor of an integer x is
 * an integer that can divide x evenly.
 * 
 * Given an integer n, return true if n is a perfect number, otherwise return
 * false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 28
 * Output: true
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 1, 2, 4, 7, and 14 are all divisors of 28.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 7
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 10^8
 * 
 * 
 */

// @lc code=start
#include <math.h>

bool checkPerfectNumber(int num)
{
	if (num == 1)
		return false;
	int sum = 0;
	for (int i = 1; i * i <= num; i++) {
		if (num % i == 0) {
			sum += i;
			if (((i * i) != num) && (i != 1))
				sum += (num / i);
		}
	}
	if (num == sum)
		return true;
	else
		return false;
}

// @lc code=end

// Accepted
// 98/98 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 87.6 % of c submissions (5.3 MB)
