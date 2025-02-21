/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (35.99%)
 * Likes:    12247
 * Dislikes: 4555
 * Total Accepted:    1.4M
 * Total Submissions: 3.9M
 * Testcase Example:  '"12"'
 *
 * You have intercepted a secret message encoded as a string of numbers. The
 * message is decoded via the following mapping:
 *
 * "1" -> 'A'
 * "2" -> 'B'
 * ...
 * "25" -> 'Y'
 * "26" -> 'Z'
 *
 * However, while decoding the message, you realize that there are many
 * different ways you can decode the message because some codes are contained
 * in other codes ("2" and "5" vs "25").
 *
 * For example, "11106" can be decoded into:
 *
 *
 * "AAJF" with the grouping (1, 1, 10, 6)
 * "KJF" with the grouping (11, 10, 6)
 * The grouping (1, 11, 06) is invalid because "06" is not a valid code (only
 * "6" is valid).
 *
 *
 * Note: there may be strings that are impossible to decode.
 *
 * Given a string s containing only digits, return the number of ways to decode
 * it. If the entire string cannot be decoded in any valid way, return 0.
 *
 * The test cases are generated so that the answer fits in a 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "12"
 *
 * Output: 2
 *
 * Explanation:
 *
 * "12" could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: s = "226"
 *
 * Output: 3
 *
 * Explanation:
 *
 * "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 *
 *
 * Example 3:
 *
 *
 * Input: s = "06"
 *
 * Output: 0
 *
 * Explanation:
 *
 * "06" cannot be mapped to "F" because of the leading zero ("6" is different
 * from "06"). In this case, the string is not a valid encoding, so return
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numDecodings(string &s)
    {
        const int n = (int)s.length();

        int prev_1 = 1;
        int prev_2 = 1;
        int curr = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            curr = 0;
            // cout << curr << prev_1 << prev_2 << endl;
            if (s[i] != '0')
            {
                // s[i] > 0 so it can map to one char
                // cout << "valid: " << s[i] << endl;
                curr += prev_1;

                // s[i] and s[i + 1] can map to one char
                if (i + 1 < n && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
                {
                    // cout << "valid: " << s[i] << s[i + 1] << endl;
                    curr += prev_2;
                }
            }
            prev_2 = prev_1;
            prev_1 = curr;
        }
        return curr;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "12";
    int res_1 = sol.numDecodings(s_1);
    cout << res_1 << endl;
    assert((res_1 == 2));

    // Test_2
    string s_2 = "226";
    int res_2 = sol.numDecodings(s_2);
    cout << res_2 << endl;
    assert((res_2 == 3));

    // Test_3
    string s_3 = "06";
    int res_3 = sol.numDecodings(s_3);
    cout << res_3 << endl;
    assert((res_3 == 0));

    // Test_4
    // DFS: TLE
    string s_4 = "111111111111111111111111111111111111111111111";
    int res_4 = sol.numDecodings(s_4);
    cout << res_4 << endl;
    assert((res_4 == 1836311903));

    return 0;
}
// Accepted
// 269/269 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.07 % of cpp submissions (8.2 MB)