/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 *
 * https://leetcode.com/problems/get-equal-substrings-within-budget/description/
 *
 * algorithms
 * Medium (50.81%)
 * Likes:    1340
 * Dislikes: 93
 * Total Accepted:    79.3K
 * Total Submissions: 145.4K
 * Testcase Example:  '"abcd"\n"bcdf"\n3'
 *
 * You are given two strings s and t of the same length and an integer
 * maxCost.
 *
 * You want to change s to t. Changing the i^th character of s to i^th
 * character of t costs |s[i] - t[i]| (i.e., the absolute difference between
 * the ASCII values of the characters).
 *
 * Return the maximum length of a substring of s that can be changed to be the
 * same as the corresponding substring of t with a cost less than or equal to
 * maxCost. If there is no substring from s that can be changed to its
 * corresponding substring from t, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcd", t = "bcdf", maxCost = 3
 * Output: 3
 * Explanation: "abc" of s can change to "bcd".
 * That costs 3, so the maximum length is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abcd", t = "cdef", maxCost = 3
 * Output: 1
 * Explanation: Each character in s costs 2 to change to character in t,  so
 * the maximum length is 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abcd", t = "acde", maxCost = 0
 * Output: 1
 * Explanation: You cannot make any change, so the maximum length is 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * t.length == s.length
 * 0 <= maxCost <= 10^6
 * s and t consist of only lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int         n = (int) s.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++)
            diff[i] = abs(s[i] - t[i]);

        int max_len = 0;
        int sum     = 0;
        int r       = 0;
        for (int l = 0; l < n; l++)
        {
            while (r < n)
            {
                sum += diff[r];
                r++;
                if (sum <= maxCost)
                    max_len = max(max_len, r - l);
                else
                    break;
            }
            sum -= diff[l];
        }
        return max_len;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1       = "abcd";
    string t_1       = "bcdf";
    int    maxCost_1 = 3;
    int    result_1  = sol.equalSubstring(s_1, t_1, maxCost_1);
    cout << result_1 << endl;
    assert(result_1 == 3);

    // Test_2
    string s_2       = "abcd";
    string t_2       = "cdef";
    int    maxCost_2 = 3;
    int    result_2  = sol.equalSubstring(s_2, t_2, maxCost_2);
    cout << result_2 << endl;
    assert(result_2 == 1);

    // Test_3
    string s_3       = "abcd";
    string t_3       = "acde";
    int    maxCost_3 = 0;
    int    result_3  = sol.equalSubstring(s_3, t_3, maxCost_3);
    cout << result_3 << endl;
    assert(result_3 == 1);

    return 0;
}
// Accepted
// 37/37 cases passed (9 ms)
// Your runtime beats 41.73 % of cpp submissions
// Your memory usage beats 7.76 % of cpp submissions (9.6 MB)