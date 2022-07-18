/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

// @lc code=start


bool isPowerOfTwo(int n){
    return n > 0 && !(n & (n - 1));
}
// @lc code=end

// Accepted
// 1108/1108 cases passed (6 ms)
// Your runtime beats 22.54 % of c submissions
// Your memory usage beats 97.65 % of c submissions (5.4 MB)