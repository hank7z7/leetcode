/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 *
 * https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/
 *
 * algorithms
 * Medium (58.73%)
 * Likes:    1598
 * Dislikes: 49
 * Total Accepted:    79.8K
 * Total Submissions: 127.8K
 * Testcase Example:  '"aababbab"'
 *
 * You are given a string s consisting only of characters 'a' and 'b'​​​​.
 *
 * You can delete any number of characters in s to make s balanced. s is
 * balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b'
 * and s[j]= 'a'.
 *
 * Return the minimum number of deletions needed to make s balanced.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aababbab"
 * Output: 2
 * Explanation: You can either:
 * Delete the characters at 0-indexed positions 2 and 6 ("aababbab" ->
 * "aaabbb"), or
 * Delete the characters at 0-indexed positions 3 and 6 ("aababbab" ->
 * "aabbbb").
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbaaaaabb"
 * Output: 2
 * Explanation: The only solution is to delete the first two characters.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is 'a' or 'b'​​.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int b_count = 0;
        int res     = 0;
        // Find the "b...a" count
        for (auto c : s)
        {
            if (c == 'b')
            {
                b_count++;
            }
            else if (c == 'a')
            {
                // There is 'b' before 'a'
                if (b_count > 0)
                {
                    b_count--;
                    res++;
                }
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
    string s_1   = "aababbab";
    int    res_1 = sol.minimumDeletions(s_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    string s_2   = "bbaaaaabb";
    int    res_2 = sol.minimumDeletions(s_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    return 0;
}
// Accepted
// 157/157 cases passed (75 ms)
// Your runtime beats 91.23 % of cpp submissions
// Your memory usage beats 66.99 % of cpp submissions (23.7 MB)