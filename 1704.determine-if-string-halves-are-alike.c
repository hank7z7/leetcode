/*
 * @lc app=leetcode id=1704 lang=c
 *
 * [1704] Determine if String Halves Are Alike
 *
 * https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
 *
 * algorithms
 * Easy (77.41%)
 * Likes:    2106
 * Dislikes: 112
 * Total Accepted:    293K
 * Total Submissions: 373.4K
 * Testcase Example:  '"book"'
 *
 * You are given a string s of even length. Split this string into two halves
 * of equal lengths, and let a be the first half and b be the second half.
 *
 * Two strings are alike if they have the same number of vowels ('a', 'e', 'i',
 * 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and
 * lowercase letters.
 *
 * Return true if a and b are alike. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "book"
 * Output: true
 * Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel.
 * Therefore, they are alike.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "textbook"
 * Output: false
 * Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2.
 * Therefore, they are not alike.
 * Notice that the vowel o is counted twice.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= s.length <= 1000
 * s.length is even.
 * s consists of uppercase and lowercase letters.
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// @lc code=start
bool is_vowel(char* c)
{
    if ((*c == 'a') || (*c == 'e') || (*c == 'i') || (*c == 'o') || (*c == 'u') || (*c == 'A')
        || (*c == 'E') || (*c == 'I') || (*c == 'O') || (*c == 'U'))
        return true;
    else
        return false;
}

bool halvesAreAlike(char* s)
{
    int l     = strlen(s);
    int count = 0;
    for (int i = 0; i < (l / 2); i++)
        if (is_vowel(s + i))
            count++;
    for (int i = (l / 2); i < l; i++)
        if (is_vowel(s + i))
            count--;
    return count == 0 ? true : false;
}
// @lc code=end

int main(int argc, char** argv)
{
    char s_1[] = "book\0";
    printf("%d\n", halvesAreAlike(s_1));

    char s_2[] = "textbook\0";
    printf("%d\n", halvesAreAlike(s_2));

    return 0;
}

// Accepted
// 113/113 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 36.84 % of c submissions (6.7 MB)