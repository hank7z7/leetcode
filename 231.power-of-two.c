/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

// @lc code=start


bool isPowerOfTwo(int n)
{
    // early return for beating 100%
    if (n <= 0)
        return false;
    return !(n & (n - 1));
}
// @lc code=end

// Accepted
// 1108/1108 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 29.33 % of c submissions (5.6 MB)