/*
 * @lc app=leetcode id=2108 lang=c
 *
 * [2108] Find First Palindromic String in the Array
 *
 * https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
 *
 * algorithms
 * Easy (79.19%)
 * Likes:    1462
 * Dislikes: 50
 * Total Accepted:    245.5K
 * Total Submissions: 292.2K
 * Testcase Example:  '["abc","car","ada","racecar","cool"]'
 *
 * Given an array of strings words, return the first palindromic string in the
 * array. If there is no such string, return an empty string "".
 *
 * A string is palindromic if it reads the same forward and backward.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abc","car","ada","racecar","cool"]
 * Output: "ada"
 * Explanation: The first string that is palindromic is "ada".
 * Note that "racecar" is also palindromic, but it is not the first.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["notapalindrome","racecar"]
 * Output: "racecar"
 * Explanation: The first and only string that is palindromic is "racecar".
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["def","ghi"]
 * Output: ""
 * Explanation: There are no palindromic strings, so the empty string is
 * returned.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] consists only of lowercase English letters.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// @lc code=start
bool is_palindrome(char* str)
{
    size_t l = strlen(str);
    for (size_t i = 0; i < (l / 2); i++)
        if (str[i] != str[l - 1 - i])
            return false;
    return true;
}
char* firstPalindrome(char** words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++)
        if (is_palindrome(words[i]))
            return words[i];
    return "";
}
// @lc code=end
#define SIZE_1 (5)
#define SIZE_2 (2)
#define SIZE_3 (2)
int main(int argc, char** argv)
{
    int wordsSize;
    // Test_1
    wordsSize             = SIZE_1;
    char* words_1[SIZE_1] = { "abc", "car", "ada", "racecar", "cool" };
    printf("%s\n", firstPalindrome((char**) words_1, wordsSize));

    // Test_2
    wordsSize             = SIZE_2;
    char* words_2[SIZE_2] = { "notapalindrome", "racecar" };
    printf("%s\n", firstPalindrome((char**) words_2, wordsSize));

    // Test_3
    wordsSize             = SIZE_3;
    char* words_3[SIZE_3] = { "def", "ghi" };
    printf("%s\n", firstPalindrome((char**) words_3, wordsSize));
    return 0;
}
// Accepted
// 266/266 cases passed (22 ms)
// Your runtime beats 64.77 % of c submissions
// Your memory usage beats 70.45 % of c submissions (9.5 MB)