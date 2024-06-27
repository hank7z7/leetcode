/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (34.97%)
 * Likes:    39564
 * Dislikes: 1874
 * Total Accepted:    5.9M
 * Total Submissions: 17M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define ASCII_SIZE 128
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = (int)s.size();
        vector<int> count(ASCII_SIZE, 0);
        int res = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            char c = s[r];
            count[c]++;
            while (count[c] > 1)
            {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "abcabcbb";
    int res_1 = sol.lengthOfLongestSubstring(s_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    string s_2 = "bbbbb";
    int res_2 = sol.lengthOfLongestSubstring(s_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    // Test_3
    string s_3 = "pwwkew";
    int res_3 = sol.lengthOfLongestSubstring(s_3);
    cout << res_3 << endl;
    assert(res_3 == 3);

    // Test_4
    string s_4 = " ";
    int res_4 = sol.lengthOfLongestSubstring(s_4);
    cout << res_4 << endl;
    assert(res_4 == 1);

    return 0;
}
// Accepted
// 987/987 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 92.1 % of cpp submissions (9.5 MB)