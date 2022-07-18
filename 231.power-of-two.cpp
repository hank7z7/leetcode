/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return (((n) & (n - 1)) == 0);
    }
};
// @lc code=end
// Accepted
// 1108/1108 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 88.2 % of cpp submissions (5.7 MB)