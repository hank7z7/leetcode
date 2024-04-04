/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 *
 * https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
 *
 * algorithms
 * Easy (81.43%)
 * Likes:    2046
 * Dislikes: 374
 * Total Accepted:    229K
 * Total Submissions: 277.5K
 * Testcase Example:  '"(1+(2*3)+((8)/4))+1"'
 *
 * A string is a valid parentheses string (denoted VPS) if it meets one of the
 * following:
 *
 *
 * It is an empty string "", or a single character not equal to "(" or ")",
 * It can be written as AB (A concatenated with B), where A and B are VPS's,
 * or
 * It can be written as (A), where A is a VPS.
 *
 *
 * We can similarly define the nesting depth depth(S) of any VPS S as
 * follows:
 *
 *
 * depth("") = 0
 * depth(C) = 0, where C is a string with a single character not equal to "("
 * or ")".
 * depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
 * depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
 *
 *
 * For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1,
 * and 2), and ")(" and "(()" are not VPS's.
 *
 * Given a VPS represented as string s, return the nesting depth of s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(1+(2*3)+((8)/4))+1"
 * Output: 3
 * Explanation: Digit 8 is inside of 3 nested parentheses in the string.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "(1)+((2))+(((3)))"
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and
 * ')'.
 * It is guaranteed that parentheses expression s is a VPS.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxDepth(string s)
    {
        int count = 0;
        int max_count = INT_MIN;
        for (auto c : s)
        {
            if (c == '(')
                count++;
            else if (c == ')')
                count--;

            max_count = max(max_count, count);
        }
        return max_count;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "(1+(2*3)+((8)/4))+1";
    cout << sol.maxDepth(s_1) << endl;

    // Test_2
    string s_2 = "(1)+((2))+(((3)))";
    cout << sol.maxDepth(s_2) << endl;
    return 0;
}

// Accepted
// 167/167 cases passed (4 ms)
// Your runtime beats 10.43 % of cpp submissions
// Your memory usage beats 78.96 % of cpp submissions (7.4 MB)