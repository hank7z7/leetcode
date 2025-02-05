/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 *
 * https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/
 *
 * algorithms
 * Easy (45.79%)
 * Likes:    1312
 * Dislikes: 67
 * Total Accepted:    168.2K
 * Total Submissions: 355.2K
 * Testcase Example:  '"bank"\n"kanb"'
 *
 * You are given two strings s1 and s2 of equal length. A string swap is an
 * operation where you choose two indices in a string (not necessarily
 * different) and swap the characters at these indices.
 *
 * Return true if it is possible to make both strings equal by performing at
 * most one string swap on exactly one of the strings. Otherwise, return
 * false.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "bank", s2 = "kanb"
 * Output: true
 * Explanation: For example, swap the first character with the last character
 * of s2 to make "bank".
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "attack", s2 = "defend"
 * Output: false
 * Explanation: It is impossible to make them equal with one string swap.
 *
 *
 * Example 3:
 *
 *
 * Input: s1 = "kelb", s2 = "kelb"
 * Output: true
 * Explanation: The two strings are already equal, so no string swap operation
 * is required.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 100
 * s1.length == s2.length
 * s1 and s2 consist of only lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        const int n1 = (int) s1.size();
        const int n2 = (int) s2.size();
        if (n1 != n2)
            return false;

        int diff_count = 0;
        int idx = -1;  // Record the first index with different char
        for (int i = 0; i < n1; i++)
        {
            if (s1[i] != s2[i])
            {
                diff_count++;
                if (diff_count > 2)
                    return false;
                else if (diff_count == 1)
                    idx = i;
                else if (diff_count == 2)
                {
                    if (s1[idx] != s2[i] || s1[i] != s2[idx])
                    {
                        return false;
                    }
                }
            }
        }
        if(diff_count == 1)
            return false;
        return true;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string test_1_s1 = "bank";
    string test_1_s2 = "kanb";
    bool res_1 = sol.areAlmostEqual(test_1_s1, test_1_s2);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    string test_2_s1 = "attack";
    string test_2_s2 = "defend";
    bool res_2 = sol.areAlmostEqual(test_2_s1, test_2_s2);
    cout << res_2 << endl;
    assert(res_2 == false);

    // Test_3
    string test_3_s1 = "kelb";
    string test_3_s2 = "kelb";
    bool res_3 = sol.areAlmostEqual(test_3_s1, test_3_s2);
    cout << res_3 << endl;
    assert(res_3 == true);

    // Test_4
    string test_4_s1 = "aa";
    string test_4_s2 = "ac";
    bool res_4 = sol.areAlmostEqual(test_4_s1, test_4_s2);
    cout << res_4 << endl;
    assert(res_4 == false);

    return 0;
}
// Accepted
// 132/132 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 61.87 % of cpp submissions (8.4 MB)