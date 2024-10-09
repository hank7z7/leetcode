/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 *
 * https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
 *
 * algorithms
 * Medium (74.89%)
 * Likes:    4295
 * Dislikes: 213
 * Total Accepted:    426.7K
 * Total Submissions: 570.5K
 * Testcase Example:  '"())"'
 *
 * A parentheses string is valid if and only if:
 *
 *
 * It is the empty string,
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 *
 *
 * You are given a parentheses string s. In one move, you can insert a
 * parenthesis at any position of the string.
 *
 *
 * For example, if s = "()))", you can insert an opening parenthesis to be
 * "(()))" or a closing parenthesis to be "())))".
 *
 *
 * Return the minimum number of moves required to make s valid.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "())"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: s = "((("
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s[i] is either '(' or ')'.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int openBrackets = 0;

        int minAddsRequired = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                openBrackets++;
            }
            else
            {
                // If open bracket exists, match it with the closing one
                // If not, we need to add a open bracket.
                openBrackets > 0 ? openBrackets-- : minAddsRequired++;
            }
        }

        // Add the remaining open brackets as closing brackets would be
        // required.
        return minAddsRequired + openBrackets;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "())";
    int res_1 = sol.minAddToMakeValid(s_1);
    cout << res_1 << endl;
    assert(res_1 == 1);

    // Test_2
    string s_2 = "(((";
    int res_2 = sol.minAddToMakeValid(s_2);
    cout << res_2 << endl;
    assert(res_2 == 3);

    return 0;
}
