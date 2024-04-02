/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (49.25%)
 * Likes:    4754
 * Dislikes: 258
 * Total Accepted:    1.8M
 * Total Submissions: 3.5M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consisting of words and spaces, return the length of the
 * last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello World"
 * Output: 5
 * Explanation: The last word is "World" with length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 * Explanation: The last word is "moon" with length 4.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "luffy is still joyboy"
 * Output: 6
 * Explanation: The last word is "joyboy" with length 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int  l            = (int) s.size();
        bool is_last_word = false;
        int  start        = 0;
        int  end          = -1;
        for (int i = l - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (end != -1)
                {
                    start = i + 1;
                    break;
                }
            }
            else
            {
                if (end == -1)
                    end = i;
            }
        }
        return end - start + 1;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "Hello World";
    cout << sol.lengthOfLastWord(s_1) << endl;

    // Test_2
    string s_2 = "   fly me   to   the moon  ";
    cout << sol.lengthOfLastWord(s_2) << endl;

    // Test_3
    string s_3 = "a";
    cout << sol.lengthOfLastWord(s_3) << endl;

    // Test_4
    string s_4 = "luffy is still joyboy";
    cout << sol.lengthOfLastWord(s_4) << endl;

    return 0;
}
// Accepted
// 58/58 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 87.89 % of cpp submissions (7.5 MB)