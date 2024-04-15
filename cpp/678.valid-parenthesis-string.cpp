/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (34.82%)
 * Likes:    5826
 * Dislikes: 173
 * Total Accepted:    335.8K
 * Total Submissions: 900.6K
 * Testcase Example:  '"()"'
 *
 * Given a string s containing only three types of characters: '(', ')' and
 * '*', return true if s is valid.
 *
 * The following rules define a valid string:
 *
 *
 * Any left parenthesis '(' must have a corresponding right parenthesis
 * ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis
 * '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis
 * ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string "".
 *
 *
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 * Example 2:
 * Input: s = "(*)"
 * Output: true
 * Example 3:
 * Input: s = "(*))"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s[i] is '(', ')' or '*'.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkValidString(string s)
    {
        bool result = true;
        // Count open parenthesis if all '*' is '('
        int op_max = 0;
        // Count open parenthesis if '*' is ')'
        // But '*' is '' if the string before '*' has valid parenthesis
        int op_min = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                op_max++;
                op_min++;
            }
            else if (c == ')')
            {
                op_max--;
                op_min--;
            }
            else if (c == '*')
            {
                op_max++;
                op_min--;
            }
            if (op_max < 0)
            {
                result = false;
                break;
            }
            op_min = op_min < 0 ? 0 : op_min;
        }
        if (op_min != 0)
            result = false;
        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "()";
    cout << sol.checkValidString(s_1) << endl;

    // Test_2
    string s_2 = "(*)";
    cout << sol.checkValidString(s_2) << endl;

    // Test_3
    string s_3 = "(*))";
    cout << sol.checkValidString(s_3) << endl;

    return 0;
}
// Accepted
// 83/83 cases passed (1 ms)
// Your runtime beats 47.5 % of cpp submissions
// Your memory usage beats 75.32 % of cpp submissions (7.3 MB)