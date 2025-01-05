/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 *
 * https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
 *
 * algorithms
 * Medium (66.06%)
 * Likes:    2329
 * Dislikes: 93
 * Total Accepted:    208.1K
 * Total Submissions: 297K
 * Testcase Example:  '"aabca"'
 *
 * Given a string s, return the number of unique palindromes of length three
 * that are a subsequence of s.
 *
 * Note that even if there are multiple ways to obtain the same subsequence, it
 * is still only counted once.
 *
 * A palindrome is a string that reads the same forwards and backwards.
 *
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 *
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aabca"
 * Output: 3
 * Explanation: The 3 palindromic subsequences of length 3 are:
 * - "aba" (subsequence of "aabca")
 * - "aaa" (subsequence of "aabca")
 * - "aca" (subsequence of "aabca")
 *
 *
 * Example 2:
 *
 *
 * Input: s = "adc"
 * Output: 0
 * Explanation: There are no palindromic subsequences of length 3 in "adc".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "bbcbaba"
 * Output: 4
 * Explanation: The 4 palindromic subsequences of length 3 are:
 * - "bbb" (subsequence of "bbcbaba")
 * - "bcb" (subsequence of "bbcbaba")
 * - "bab" (subsequence of "bbcbaba")
 * - "aba" (subsequence of "bbcbaba")
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<int> leftmost(26, -1);
        vector<int> rightmost(26, -1);

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "aabca";
    int res_1 = sol.countPalindromicSubsequence(s_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    string s_2 = "adc";
    int res_2 = sol.countPalindromicSubsequence(s_2);
    cout << res_2 << endl;
    assert(res_2 == 0);

    // Test_3
    string s_3 = "bbcbaba";
    int res_3 = sol.countPalindromicSubsequence(s_3);
    cout << res_3 << endl;
    assert(res_3 == 4);

    return 0;
}
