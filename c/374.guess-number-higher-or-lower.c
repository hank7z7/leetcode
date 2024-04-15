/*
 * @lc app=leetcode id=374 lang=c
 *
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (48.68%)
 * Likes:    1375
 * Dislikes: 216
 * Total Accepted:    357.2K
 * Total Submissions: 714.3K
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows:
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I will tell you whether the number I picked is
 * higher or lower than your guess.
 * 
 * You call a pre-defined API int guess(int num), which returns three possible
 * results:
 * 
 * 
 * -1: Your guess is higher than the number I picked (i.e. num > pick).
 * 1: Your guess is lower than the number I picked (i.e. num < pick).
 * 0: your guess is equal to the number I picked (i.e. num == pick).
 * 
 * 
 * Return the number that I picked.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 10, pick = 6
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, pick = 1
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 2, pick = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 1 <= pick <= n
 * 
 * 
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n)
{
	long long left = 1, right = n;
	while (left < right) {
		long long mid = (left + right) / 2;
		int type = guess(mid);
		if (type == 0)
			return mid;
		else if (type == -1)
			right = mid - 1;
		else if (type == 1)
			left = mid + 1;
	}
	return left;
}

// @lc code=end

// Accepted
// 25/25 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 37.65 % of c submissions (5.5 MB)