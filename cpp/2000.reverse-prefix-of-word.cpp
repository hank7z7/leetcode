/*
 * @lc app=leetcode id=2000 lang=cpp
 *
 * [2000] Reverse Prefix of Word
 *
 * https://leetcode.com/problems/reverse-prefix-of-word/description/
 *
 * algorithms
 * Easy (80.67%)
 * Likes:    1288
 * Dislikes: 35
 * Total Accepted:    249.9K
 * Total Submissions: 290K
 * Testcase Example:  '"abcdefd"\n"d"'
 *
 * Given a 0-indexed string word and a character ch, reverse the segment of
 * word that starts at index 0 and ends at the index of the first occurrence of
 * ch (inclusive). If the character ch does not exist in word, do
 * nothing.
 *
 *
 * For example, if word = "abcdefd" and ch = "d", then you should reverse the
 * segment that starts at 0 and ends at 3 (inclusive). The resulting string
 * will be "dcbaefd".
 *
 *
 * Return the resulting string.
 *
 *
 * Example 1:
 *
 *
 * Input: word = "abcdefd", ch = "d"
 * Output: "dcbaefd"
 * Explanation: The first occurrence of "d" is at index 3.
 * Reverse the part of word from 0 to 3 (inclusive), the resulting string is
 * "dcbaefd".
 *
 *
 * Example 2:
 *
 *
 * Input: word = "xyxzxe", ch = "z"
 * Output: "zxyxxe"
 * Explanation: The first and only occurrence of "z" is at index 3.
 * Reverse the part of word from 0 to 3 (inclusive), the resulting string is
 * "zxyxxe".
 *
 *
 * Example 3:
 *
 *
 * Input: word = "abcd", ch = "z"
 * Output: "abcd"
 * Explanation: "z" does not exist in word.
 * You should not do any reverse operation, the resulting string is "abcd".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 250
 * word consists of lowercase English letters.
 * ch is a lowercase English letter.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        for (int i = 0; i < (int) word.length(); i++)
        {
            if (word[i] == ch)
            {
                reverse(begin(word), begin(word) + i + 1);
                break;
            }
        }
        return word;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string word_1   = "abcdefd";
    char   ch_1     = 'd';
    string result_1 = sol.reversePrefix(word_1, ch_1);
    cout << result_1 << endl;
    assert(result_1 == "dcbaefd");

    // Test_2
    string word_2   = "xyxzxe";
    char   ch_2     = 'z';
    string result_2 = sol.reversePrefix(word_2, ch_2);
    cout << result_2 << endl;
    assert(result_2 == "zxyxxe");

    // Test_3
    string word_3   = "abcd";
    char   ch_3     = 'z';
    string result_3 = sol.reversePrefix(word_3, ch_3);
    cout << result_3 << endl;
    assert(result_3 == "abcd");

    return 0;
}
// Accepted
// 112/112 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 28.69 % of cpp submissions (7.6 MB)