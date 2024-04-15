/*
 * @lc app=leetcode id=2864 lang=c
 *
 * [2864] Maximum Odd Binary Number
 *
 * https://leetcode.com/problems/maximum-odd-binary-number/description/
 *
 * algorithms
 * Easy (73.29%)
 * Likes:    332
 * Dislikes: 6
 * Total Accepted:    74.3K
 * Total Submissions: 92.7K
 * Testcase Example:  '"010"'
 *
 * You are given a binary string s that contains at least one '1'.
 *
 * You have to rearrange the bits in such a way that the resulting binary
 * number is the maximum odd binary number that can be created from this
 * combination.
 *
 * Return a string representing the maximum odd binary number that can be
 * created from the given combination.
 *
 * Note that the resulting string can have leading zeros.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "010"
 * Output: "001"
 * Explanation: Because there is just one '1', it must be in the last position.
 * So the answer is "001".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "0101"
 * Output: "1001"
 * Explanation: One of the '1's must be in the last position. The maximum
 * number that can be made with the remaining digits is "100". So the answer is
 * "1001".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s consists only of '0' and '1'.
 * s contains at least one '1'.
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// @lc code=start
char* maximumOddBinaryNumber(char* s)
{
    int one_count = 0;
    int l         = (int) strlen(s);
    for (int i = 0; i < l; i++)
        if (s[i] == '1')
            one_count++;
    memset(s, '0', sizeof(char) * l);
    s[l - 1] = '1';
    for (int i = 0; i < (one_count - 1); i++)
        s[i] = '1';
    return s;
}
// @lc code=end
#define STRING_SIZE (101)
int main(int argc, char** argv)
{
    // Test_1
    char s_1[] = "010\0";
    printf("%s\n", maximumOddBinaryNumber(s_1));

    // Test_2
    char s_2[] = "0101\0";
    printf("%s\n", maximumOddBinaryNumber(s_2));

    return 0;
}
// Accepted
// 985/985 cases passed (5 ms)
// Your runtime beats 20.83 % of c submissions
// Your memory usage beats 97.92 % of c submissions (5.5 MB)