/*
 * @lc app=leetcode id=1750 lang=c
 *
 * [1750] Minimum Length of String After Deleting Similar Ends
 *
 * https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/
 *
 * algorithms
 * Medium (44.93%)
 * Likes:    707
 * Dislikes: 54
 * Total Accepted:    59.8K
 * Total Submissions: 114.3K
 * Testcase Example:  '"ca"'
 *
 * Given a string s consisting only of characters 'a', 'b', and 'c'. You are
 * asked to apply the following algorithm on the string any number of
 * times:
 *
 *
 * Pick a non-empty prefix from the string s where all the characters in the
 * prefix are equal.
 * Pick a non-empty suffix from the string s where all the characters in this
 * suffix are equal.
 * The prefix and the suffix should not intersect at any index.
 * The characters from the prefix and suffix must be the same.
 * Delete both the prefix and the suffix.
 *
 *
 * Return the minimum length of s after performing the above operation any
 * number of times (possibly zero times).
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ca"
 * Output: 2
 * Explanation: You can't remove any characters, so the string stays as is.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cabaabac"
 * Output: 0
 * Explanation: An optimal sequence of operations is:
 * - Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
 * - Take prefix = "a" and suffix = "a" and remove them, s = "baab".
 * - Take prefix = "b" and suffix = "b" and remove them, s = "aa".
 * - Take prefix = "a" and suffix = "a" and remove them, s = "".
 *
 * Example 3:
 *
 *
 * Input: s = "aabccabba"
 * Output: 3
 * Explanation: An optimal sequence of operations is:
 * - Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
 * - Take prefix = "b" and suffix = "bb" and remove them, s = "cca".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s only consists of characters 'a', 'b', and 'c'.
 *
 *
 */
#include <stdio.h>
#include <string.h>
// @lc code=start
int minimumLength(char* s)
{
    int count = strlen(s);
    int l     = 0;
    int r     = strlen(s) - 1;
    if (r < 0)
        return 0;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            char curr = s[l];
            count -= 2;
            l++;
            r--;
            while (l <= r && s[l] == curr)
            {
                l++;
                count--;
            }
            while (l < r && s[r] == curr)
            {
                r--;
                count--;
            }
        }
        else
            break;
    }
    return count;
}
// @lc code=end
int main(int argc, char** argv)
{
    // Test_1
    char s_1[] = "ca";
    printf("%d\n", minimumLength(s_1));

    // Test_2
    char s_2[] = "cabaabac";
    printf("%d\n", minimumLength(s_2));

    // Test_3
    char s_3[] = "aabccabba";
    printf("%d\n", minimumLength(s_3));

    // Test_4
    char s_4[] = "abbbbbbbbbbbbbbbbbbba";
    printf("%d\n", minimumLength(s_4));

    return 0;
}
// Accepted
// 100/100 cases passed (6 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 100 % of c submissions (7.9 MB)