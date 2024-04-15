/*
 * @lc app=leetcode id=461 lang=c
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (74.46%)
 * Likes:    3203
 * Dislikes: 200
 * Total Accepted:    487.1K
 * Total Submissions: 652.3K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, return the Hamming distance between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 1, y = 4
 * Output: 2
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 3, y = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= x, y <= 2^31 - 1
 * 
 * 
 */

// @lc code=start

int hammingDistance(int x, int y)
{
	int z = x ^ y;
	// int result = 0;
	// while (z > 0) {
	//      result += (z & 1);
	//      z >>= 1;
	// }

	// Use very fast builtin function to count bits
	return __builtin_popcount(z);
}

// @lc code=end

// Accepted
// 149/149 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 67.7 % of c submissions (5.5 MB)
