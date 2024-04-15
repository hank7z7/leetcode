/*
 * @lc app=leetcode id=342 lang=c
 *
 * [342] Power of Four
 */

// @lc code=start


bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;
    return ((n - 1) % 3 == 0) && !(n & (n - 1));
}
// @lc code=end

// Accepted
// 1061/1061 cases passed (2 ms)
// Your runtime beats 63.28 % of c submissions
// Your memory usage beats 11.55 % of c submissions (5.7 MB)