/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 *
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
 *
 * algorithms
 * Medium (67.30%)
 * Likes:    6375
 * Dislikes: 128
 * Total Accepted:    625.8K
 * Total Submissions: 923.7K
 * Testcase Example:  '"lee(t(c)o)de)"'
 *
 * Given a string s of '(' , ')' and lowercase English characters.
 *
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in
 * any positions ) so that the resulting parentheses string is valid and return
 * any valid string.
 *
 * Formally, a parentheses string is valid if and only if:
 *
 *
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "lee(t(c)o)de)"
 * Output: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a)b(c)d"
 * Output: "ab(c)d"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "))(("
 * Output: ""
 * Explanation: An empty string is also valid.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is either'(' , ')', or lowercase English letter.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        // Count for left parentheses
        int lp_c = 0;
        // Record the index to be removed
        vector<int> remove;
        for (int i = 0; i < (int)s.size(); i++)
        {
            char c = s[i];
            if (c == '(')
            {
                lp_c++;
            }
            else if (c == ')')
            {
                if (lp_c == 0)
                {
                    remove.push_back(i);
                }
                else
                    lp_c--;
            }
        }

        for (int i = (int)s.size() - 1; i >= 0; i--)
        {
            if (lp_c > 0 && s[i] == '(')
            {
                remove.push_back(i);
                lp_c--;
            }
        }

        for (auto idx : remove)
            s[idx] = '*';
        string result;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] != '*')
                result.push_back(s[i]);
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "lee(t(c)o)de)";
    cout << sol.minRemoveToMakeValid(s_1) << endl;

    // Test_2
    string s_2 = "a)b(c)d";
    cout << sol.minRemoveToMakeValid(s_2) << endl;

    // Test_3
    string s_3 = "))((";
    cout << sol.minRemoveToMakeValid(s_3) << endl;
    return 0;
}
// Accepted
// 62/62 cases passed (24 ms)
// Your runtime beats 37.61 % of cpp submissions
// Your memory usage beats 64.51 % of cpp submissions (12.4 MB)