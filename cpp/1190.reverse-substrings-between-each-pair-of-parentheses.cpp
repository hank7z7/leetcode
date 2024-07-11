/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 *
 * https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
 *
 * algorithms
 * Medium (66.50%)
 * Likes:    2378
 * Dislikes: 93
 * Total Accepted:    144K
 * Total Submissions: 206K
 * Testcase Example:  '"(abcd)"'
 *
 * You are given a string s that consists of lower case English letters and
 * brackets.
 *
 * Reverse the strings in each pair of matching parentheses, starting from the
 * innermost one.
 *
 * Your result should not contain any brackets.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(abcd)"
 * Output: "dcba"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "(u(love)i)"
 * Output: "iloveu"
 * Explanation: The substring "love" is reversed first, then the whole string
 * is reversed.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(ed(et(oc))el)"
 * Output: "leetcode"
 * Explanation: First, we reverse the substring "oc", then "etco", and finally,
 * the whole string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2000
 * s only contains lower case English characters and parentheses.
 * It is guaranteed that all parentheses are balanced.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseParentheses(string s)
    {
        // Wormhole Teleportation technique
        /*
        1. First Pass: Pair up parentheses

        2. Initialize openParenthesesIndices stack and pair vector to establish "wormhole" connections.
        For each character:
        If '(', push its index to openParenthesesIndices to remember its position.
        If ')', pop from openParenthesesIndices and link both indices in pair to create the "wormhole".
        Second Pass: Build the result string

        3. Initialize result string, currIndex, and direction to traverse and build the result.
        While currIndex < input length:
        If '(' or ')', jump through the "wormhole" using pair and reverse direction to simulate reversal.
        Otherwise, append the character to result to build the result.
        Move currIndex by direction to continue traversal.
        Return result as the final string with all reversals simulated.
        */
        int n = s.length();
        stack<int> openParenthesesIndices;
        vector<int> pair(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                openParenthesesIndices.push(i);
            }
            if (s[i] == ')')
            {
                int j = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        for (int currIndex = 0, direction = 1; currIndex < n;
             currIndex += direction)
        {
            if (s[currIndex] == '(' || s[currIndex] == ')')
            {
                currIndex = pair[currIndex];
                direction = -direction;
            }
            else
            {
                result += s[currIndex];
            }
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "(abcd)";
    string res_1 = sol.reverseParentheses(s_1);
    cout << res_1 << endl;
    assert(res_1 == "dcba");

    // Test_2
    string s_2 = "(u(love)i)";
    string res_2 = sol.reverseParentheses(s_2);
    cout << res_2 << endl;
    assert(res_2 == "iloveu");

    // Test_3
    string s_3 = "(ed(et(oc))el)";
    string res_3 = sol.reverseParentheses(s_3);
    cout << res_3 << endl;
    assert(res_3 == "leetcode");

    return 0;
}
