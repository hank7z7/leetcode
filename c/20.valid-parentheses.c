/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.87%)
 * Likes:    12334
 * Dislikes: 540
 * Total Accepted:    2.1M
 * Total Submissions: 5.2M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */

// @lc code=start

bool isValid(char* s)
{
    int  length = strlen(s);
    char stack[length];
    int  index = -1;

    int i;
    for (i = 0; i < length; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            index++;
            stack[index] = s[i];
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (index == -1)
                return false;
            if ((s[i] == ')' && stack[index] == '(') || (s[i] == ']' && stack[index] == '[')
                || (s[i] == '}' && stack[index] == '{'))
                index--;
            else
                return false;
        }
        else
        {
            return false;
        }
    }

    if (index == -1)
        return true;
    else
        return false;
}
// @lc code=end

// Accepted
// 91/91 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 39.5 % of c submissions (5.7 MB)