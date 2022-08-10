/*
 * @lc app=leetcode id=367 lang=c
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (42.90%)
 * Likes:    2669
 * Dislikes: 246
 * Total Accepted:    400.5K
 * Total Submissions: 927.2K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Follow up: Do not use any built-in library function such as sqrt.
 * 
 * 
 * Example 1:
 * Input: num = 16
 * Output: true
 * Example 2:
 * Input: num = 14
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
int32_t floorSqrt(int32_t x)
{
	double y = x;
	// https://en.wikipedia.org/wiki/Fast_inverse_square_root
	int64_t i = 0x5fe6eb50c7b537a9;
	i = i - (*(int64_t *) & y) / 2;
	y = *(double *)&(i);
	y = y * (3 - x * y * y) * 0.5;
	y = y * (3 - x * y * y) * 0.5;
	i = x * y + 1;
	return i - (i * i > x);
}

bool isPerfectSquare(int num)
{
//   if (num == 1)
//     return true;
	int mod_10 = num % 10;
	int mod_100 = num % 100;
//   if (mod_10 != 1 && mod_10 != 4 && mod_10 != 6 && mod_10 != 9 && mod_100 != 0
//       && mod_100 != 25)
//     return false;
//   int x = num / 2;
//   int y = 2;
//   while (x > (y + 1))
//     {
//       x = (x + y) / 2;
//       y = num / x;
//     }
//   if ((x * x) == num)
//     return true;
//   if ((y * y) == num)
//     return true;
//   return false;
	// Accepted
	// 70/70 cases passed (5 ms)
	// Your runtime beats 27.88 % of c submissions
	// Your memory usage beats 57.58 % of c submissions (5.4 MB)
	//   int mod_10 = num % 10;
	if (mod_10 != 1 && mod_10 != 4 && mod_10 != 6 && mod_10 != 9
	    && mod_100 != 0 && mod_100 != 25)
		return false;

	int root = floorSqrt(num);
	return root * root == num;
}

// @lc code=end

// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 12.42 % of c submissions (5.7 MB)
