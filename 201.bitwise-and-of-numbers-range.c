/*
 * @lc app=leetcode id=201 lang=c
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (43.06%)
 * Likes:    3434
 * Dislikes: 253
 * Total Accepted:    298.7K
 * Total Submissions: 678.2K
 * Testcase Example:  '5\n7'
 *
 * Given two integers left and right that represent the range [left, right],
 * return the bitwise AND of all numbers in this range, inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: left = 5, right = 7
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: left = 0, right = 0
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: left = 1, right = 2147483647
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= left <= right <= 2^31 - 1
 *
 *
 */
#include <stdio.h>
#include <stdbool.h>
// @lc code=start
int rangeBitwiseAnd(int left, int right)
{
    int ret               = 0;
    int xor               = left ^ right;
    unsigned int leftmost = 1;
    int          mask     = 0;
    while (xor)
    {
        mask |= leftmost;
        leftmost <<= 1;
        xor >>= 1;
    }
    ret = left & (~mask);
    return ret;
}
// @lc code=end
int main(int argc, char** argv)
{
    int l, r;
    // Test_1
    l = 5;  // 0b1001
    r = 7;  // 0b1011
    printf("%d\n", rangeBitwiseAnd(l, r));

    // Test_2
    l = 0;
    r = 0;
    printf("%d\n", rangeBitwiseAnd(l, r));

    // Test_3
    l = 1;
    r = 2147483647;
    printf("%d\n", rangeBitwiseAnd(l, r));

    return 0;
}
// Accepted
// 8269/8269 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 80.3 % of c submissions (5.6 MB)