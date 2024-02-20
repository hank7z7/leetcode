/*
 * @lc app=leetcode id=2405 lang=c
 *
 * [2405] Optimal Partition of String
 *
 * https://leetcode.com/problems/optimal-partition-of-string/description/
 *
 * algorithms
 * Medium (78.40%)
 * Likes:    2522
 * Dislikes: 98
 * Total Accepted:    168.6K
 * Total Submissions: 215.2K
 * Testcase Example:  '"abacaba"'
 *
 * Given a string s, partition the string into one or more substrings such that
 * the characters in each substring are unique. That is, no letter appears in a
 * single substring more than once.
 *
 * Return the minimum number of substrings in such a partition.
 *
 * Note that each character should belong to exactly one substring in a
 * partition.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abacaba"
 * Output: 4
 * Explanation:
 * Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
 * It can be shown that 4 is the minimum number of substrings needed.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "ssssss"
 * Output: 6
 * Explanation:
 * The only valid partition is ("s","s","s","s","s","s").
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only English lowercase letters.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
int partitionString(char* s)
{
    size_t l = strlen(s);
    // Start with 1 because the last substring will not be counted in for loop
    int ret                   = 1;
    // bitmask
    unsigned int count =  0;
    // unordered_map<char, int> um;
    for (size_t i = 0; i < l; i++)
    {
        unsigned int val = s[i] - 'a';
        // Greedy method: if s[i] is in current substring, partition it
        if (count & (1 << val))
        {
            count = 0;
            ret++;
        }
        count |= (1 << val);
    }
    return ret;
}
// @lc code=end
int main(int argc, char** argv)
{
    // Test_1
    printf("%d\n", partitionString("abacaba"));

    // Test_2
    printf("%d\n", partitionString("ssssss"));

    // Test_3
    printf("%d\n", partitionString("abacaba"));
    return 0;
}
// Optimize by bitmask
// Accepted
// 59/59 cases passed (8 ms)
// Your runtime beats 91.92 % of c submissions
// Your memory usage beats 94.95 % of c submissions (6.7 MB)

// Accepted
// 59/59 cases passed (13 ms)
// Your runtime beats 67.68 % of c submissions
// Your memory usage beats 69.7 % of c submissions (7 MB)