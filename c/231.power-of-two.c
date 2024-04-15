/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */
#include <stdio.h>
#include <stdbool.h>
// @lc code=start


bool isPowerOfTwo(int n)
{
    // early return for beating 100%
    if (n <= 0)
        return false;
    return !(n & (n - 1));
}
// @lc code=end
int main(int argc, char** argv)
{
    int n;
    // Test_1
    n = 1;
    printf("%d\n", isPowerOfTwo(n));

    // Test_1
    n = 16;
    printf("%d\n", isPowerOfTwo(n));

    // Test_1
    n = 13;
    printf("%d\n", isPowerOfTwo(n));
}
// Accepted
// 1108/1108 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 29.33 % of c submissions (5.6 MB)