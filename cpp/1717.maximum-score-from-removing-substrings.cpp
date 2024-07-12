/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 *
 * https://leetcode.com/problems/maximum-score-from-removing-substrings/description/
 *
 * algorithms
 * Medium (47.10%)
 * Likes:    973
 * Dislikes: 69
 * Total Accepted:    54.2K
 * Total Submissions: 94.1K
 * Testcase Example:  '"cdbcbbaaabab"\n4\n5'
 *
 * You are given a string s and two integers x and y. You can perform two types
 * of operations any number of times.
 *
 *
 * Remove substring "ab" and gain x points.
 *
 *
 * For example, when removing "ab" from "cabxbae" it becomes
 * "cxbae".
 *
 *
 * Remove substring "ba" and gain y points.
 *
 * For example, when removing "ba" from "cabxbae" it becomes
 * "cabxe".
 *
 *
 *
 *
 * Return the maximum points you can gain after applying the above operations
 * on s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cdbcbbaaabab", x = 4, y = 5
 * Output: 19
 * Explanation:
 * - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5
 * points are added to the score.
 * - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4
 * points are added to the score.
 * - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points
 * are added to the score.
 * - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are
 * added to the score.
 * Total score = 5 + 4 + 5 + 5 = 19.
 *
 * Example 2:
 *
 *
 * Input: s = "aabbaaxybbaabb", x = 5, y = 4
 * Output: 20
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * 1 <= x, y <= 10^4
 * s consists of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumGain(string s, int x, int y) { return 0; }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1   = "cdbcbbaaabab";
    int    x_1   = 4;
    int    y_1   = 5;
    int    res_1 = sol.maximumGain(s_1, x_1, y_1);
    cout << res_1 << endl;
    assert(res_1 == 19);

    // Test_2
    string s_2   = "aabbaaxybbaabb";
    int    x_2   = 5;
    int    y_2   = 4;
    int    res_2 = sol.maximumGain(s_2, x_2, y_2);
    cout << res_2 << endl;
    assert(res_2 == 20);

    return 0;
}
