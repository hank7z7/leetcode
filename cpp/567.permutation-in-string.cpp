/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.67%)
 * Likes:    11646
 * Dislikes: 437
 * Total Accepted:    984.4K
 * Total Submissions: 2.2M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkInclusion(string &s1, string &s2)
    {
        const int n1 = (int)s1.length();
        const int n2 = (int)s2.length();
        if (n1 > n2)
            return false;

        vector<int> s1_table(26, 0);
        vector<int> s2_table(26, 0);

        for (auto &c : s1)
            s1_table[c - 'a']++;

        for (int i = 0; i < n2; i++)
        {
            char &c = s2[i];
            s2_table[c - 'a']++;
            if (i >= n1)
                s2_table[s2[i - n1] - 'a']--;
            if (i >= (n1 - 1) && s1_table == s2_table)
                return true;
        }
        return false;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string test_1_s1 = "ab";
    string test_1_s2 = "eidbaooo";
    bool res_1 = sol.checkInclusion(test_1_s1, test_1_s2);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    string test_2_s1 = "ab";
    string test_2_s2 = "eidboaoo";
    bool res_2 = sol.checkInclusion(test_2_s1, test_2_s2);
    cout << res_2 << endl;
    assert(res_2 == false);

    return 0;
}
// Accepted
// 108/108 cases passed (9 ms)
// Your runtime beats 48.5 % of cpp submissions
// Your memory usage beats 92.55 % of cpp submissions (8.6 MB)