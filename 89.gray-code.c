/*
 * @lc app=leetcode id=89 lang=c
 *
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (58.61%)
 * Likes:    2164
 * Dislikes: 2671
 * Total Accepted:    286.4K
 * Total Submissions: 488.3K
 * Testcase Example:  '2'
 *
 * An n-bit gray code sequence is a sequence of 2^n integers where:
 *
 *
 * Every integer is in the inclusive range [0, 2^n - 1],
 * The first integer is 0,
 * An integer appears no more than once in the sequence,
 * The binary representation of every pair of adjacent integers differs by
 * exactly one bit, and
 * The binary representation of the first and last integers differs by exactly
 * one bit.
 *
 *
 * Given an integer n, return any valid n-bit gray code sequence.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: [0,1,3,2]
 * Explanation:
 * The binary representation of [0,1,3,2] is [00,01,11,10].
 * - 00 and 01 differ by one bit
 * - 01 and 11 differ by one bit
 * - 11 and 10 differ by one bit
 * - 10 and 00 differ by one bit
 * [0,2,3,1] is also a valid gray code sequence, whose binary representation is
 * [00,10,11,01].
 * - 00 and 10 differ by one bit
 * - 10 and 11 differ by one bit
 * - 11 and 01 differ by one bit
 * - 01 and 00 differ by one bit
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 16
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize)
{
    *returnSize = (1 << n);
    int* ret    = (int*) malloc(sizeof(int) * (1 << n));
    for (int i = 0; i < (1 << n); i++)
        ret[i] = (i >> 1) ^ i;
    return ret;
}
// @lc code=end
int main(int argc, char** argv)
{
    int returnSize = 0;
    // Test_1
    int* ret_1 = grayCode(2, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d%c", ret_1[i], i == (returnSize - 1) ? '\n' : ' ');
    free(ret_1);

    // Test_2
    int* ret_2 = grayCode(3, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d%c", ret_2[i], i == (returnSize - 1) ? '\n' : ' ');
    free(ret_2);

    // Test_3
    int* ret_3 = grayCode(4, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d%c", ret_3[i], i == (returnSize - 1) ? '\n' : ' ');
    free(ret_3);

    return 0;
}
// Accepted
// 16/16 cases passed (97 ms)
// Your runtime beats 40.23 % of c submissions
// Your memory usage beats 73.56 % of c submissions (19.6 MB)