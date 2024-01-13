/*
 * @lc app=leetcode id=1347 lang=c
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 *
 * https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/
 *
 * algorithms
 * Medium (78.27%)
 * Likes:    2120
 * Dislikes: 92
 * Total Accepted:    163.8K
 * Total Submissions: 206.5K
 * Testcase Example:  '"bab"\n"aba"'
 *
 * You are given two strings of the same length s and t. In one step you can
 * choose any character of t and replace it with another character.
 *
 * Return the minimum number of steps to make t an anagram of s.
 *
 * An Anagram of a string is a string that contains the same characters with a
 * different (or the same) ordering.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "bab", t = "aba"
 * Output: 1
 * Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram
 * of s.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "leetcode", t = "practice"
 * Output: 5
 * Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper
 * characters to make t anagram of s.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "anagram", t = "mangaar"
 * Output: 0
 * Explanation: "anagram" and "mangaar" are anagrams.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * s.length == t.length
 * s and t consist of lowercase English letters only.
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// @lc code=start
#define LETTER_SIZE 26
int minSteps(char* s, char* t)
{
    int l_s                  = strlen(s);
    int result               = 0;
    int count_s[LETTER_SIZE] = { 0 };
    int count_t[LETTER_SIZE] = { 0 };
    for (int i = 0; i < l_s; i++)
    {
        count_s[s[i] - 'a']++;
        count_t[t[i] - 'a']++;
    }
    for (int i = 0; i < LETTER_SIZE; i++)
    {
        result += abs(count_s[i] - count_t[i]);
    }

    return result / 2;
}
// @lc code=end
int main(int argc, char** argv)
{
    char s_1[] = "bab\0";
    char t_1[] = "aba\0";
    printf("%d\n", minSteps(s_1, t_1));

    char s_2[] = "leetcode\0";
    char t_2[] = "practice\0";
    printf("%d\n", minSteps(s_2, t_2));

    char s_3[] = "anagram\0";
    char t_3[] = "mangaar\0";
    printf("%d\n", minSteps(s_3, t_3));

    return 0;
}

// Accepted
// 63/63 cases passed (12 ms)
// Your runtime beats 84.21 % of c submissions
// Your memory usage beats 26.32 % of c submissions (9.4 MB)
