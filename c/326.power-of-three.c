/*
 * @lc app=leetcode id=326 lang=c
 *
 * [326] Power of Three
 */

// @lc code=start


bool isPowerOfThree(int n)
{
    // 1162261467(3^19) is the max powerofthree in integer
    return (n > 0 && 1162261467 % n == 0);
}
// @lc code=end
// Accepted
// 21038/21038 cases passed (20 ms)
// Your runtime beats 89.35 % of c submissions
// Your memory usage beats 75.6 % of c submissions (6.1 MB)