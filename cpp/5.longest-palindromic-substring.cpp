/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (34.02%)
 * Likes:    29180
 * Dislikes: 1778
 * Total Accepted:    3.1M
 * Total Submissions: 9.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string expand(int i, int j, string s)
    {
        int left  = i;
        int right = j;

        while (left >= 0 && right < (int) s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s)
    {
        int    n   = (int) s.size();
        string res = "";

        for (int i = 0; i < n; i++)
        {
            string odd = expand(i, i, s);
            if ((int) odd.size() > (int) res.size())
            {
                res = odd;
            }

            string even = expand(i, i + 1, s);
            if ((int) even.size() > (int) res.size())
            {
                res = even;
            }
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1   = "babad";
    string res_1 = sol.longestPalindrome(s_1);
    cout << res_1 << endl;
    assert(res_1 == "bab");

    // Test_2
    string s_2   = "cbbd";
    string res_2 = sol.longestPalindrome(s_2);
    cout << res_2 << endl;
    assert(res_2 == "bb");

    return 0;
}
// Accepted
// 142/142 cases passed (55 ms)
// Your runtime beats 54.19 % of cpp submissions
// Your memory usage beats 19.71 % of cpp submissions (174 MB)