/*
 * @lc app=leetcode id=3330 lang=cpp
 *
 * [3330] Find the Original Typed String I
 *
 * https://leetcode.com/problems/find-the-original-typed-string-i/description/
 *
 * algorithms
 * Easy (57.39%)
 * Likes:    302
 * Dislikes: 44
 * Total Accepted:    101.1K
 * Total Submissions: 148.1K
 * Testcase Example:  '"abbcccc"'
 *
 * Alice is attempting to type a specific string on her computer. However, she
 * tends to be clumsy and may press a key for too long, resulting in a
 * character being typed multiple times.
 *
 * Although Alice tried to focus on her typing, she is aware that she may still
 * have done this at most once.
 *
 * You are given a string word, which represents the final output displayed on
 * Alice's screen.
 *
 * Return the total number of possible original strings that Alice might have
 * intended to type.
 *
 *
 * Example 1:
 *
 *
 * Input: word = "abbcccc"
 *
 * Output: 5
 *
 * Explanation:
 *
 * The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and
 * "abcccc".
 *
 *
 * Example 2:
 *
 *
 * Input: word = "abcd"
 *
 * Output: 1
 *
 * Explanation:
 *
 * The only possible string is "abcd".
 *
 *
 * Example 3:
 *
 *
 * Input: word = "aaaa"
 *
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 100
 * word consists only of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int possibleStringCount(string word)
    {
        const int n = (int) word.length();
        int res = 1;

        for (int i = 1; i < n; i++)
        {
            if (word[i] == word[i - 1])
            {
                // If the current character is the same as the previous one,
                // it can be counted as a possible original string.
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string word = "abbcccc";
    int res = sol.possibleStringCount(word);
    cout << res << endl;  // Expected output: 5
    assert(res == 5);

    // Test_2
    word = "abcd";
    res = sol.possibleStringCount(word);
    cout << res << endl;  // Expected output: 1
    assert(res == 1);

    // Test_3
    word = "aaaa";
    res = sol.possibleStringCount(word);
    cout << res << endl;  // Expected output: 4
    assert(res == 4);

    return 0;
}
// Accepted
// 780/780 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.47 % of cpp submissions (8.7 MB)