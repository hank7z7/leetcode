/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (58.93%)
 * Likes:    12360
 * Dislikes: 578
 * Total Accepted:    768.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; there are no extra
 * white spaces, square brackets are well-formed, etc. Furthermore, you may
 * assume that the original data does not contain any digits and that digits
 * are only for those repeat numbers, k. For example, there will not be input
 * like 3a or 2[4].
 *
 * The test cases are generated so that the length of the output will never
 * exceed 10^5.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        stack<pair<int, string>> st;
        string                   ret;
        string to_int = "";
        for (auto c : s)
        {
            if (isdigit(c))
            {
                to_int += c;
            }
            else if (c == '[')
            {
                int num = stoi(to_int);
                to_int = "";
                st.push(pair<int, string>(num, ""));
            }
            else if (!st.empty() && isalpha(c))
            {
                // cout << "st " << st.top().first << ",push back " << c << endl;
                st.top().second.push_back(c);
            }
            else if (c == ']')
            {
                string to_add = "";
                for (int i = 0; i < st.top().first; i++)
                    to_add += st.top().second;
                // cout << "to_add = " << to_add << endl;
                st.pop();
                if (!st.empty())
                {
                    st.top().second += to_add;
                }
                else
                    ret = ret + to_add;
            }
            else if (st.empty())
            {
                // cout << "push back " << c << endl;
                ret += c;
            }
        }
        if (!st.empty())
        {
            string to_add = "";
            for (int i = 0; i < st.top().first; i++)
                to_add += st.top().second;
            // cout << "to_add = " << to_add << endl;
            st.pop();
            if (!st.empty())
            {
                st.top().second += to_add;
            }
            else
                ret = ret + to_add;
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "3[a]2[bc]";
    cout << sol.decodeString(s_1) << endl;

    // Test_2
    string s_2 = "3[a2[c]]";
    cout << sol.decodeString(s_2) << endl;

    // Test_3
    string s_3 = "2[abc]3[cd]ef";
    cout << sol.decodeString(s_3) << endl;

    // Test_4
    string s_4 = "100[leetcode]";
    cout << sol.decodeString(s_4) << endl;
}
// Accepted
// 34/34 cases passed (3 ms)
// Your runtime beats 39.33 % of cpp submissions
// Your memory usage beats 30.04 % of cpp submissions (7.9 MB)