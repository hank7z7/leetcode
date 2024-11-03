/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 *
 * https://leetcode.com/problems/rotate-string/description/
 *
 * algorithms
 * Easy (59.50%)
 * Likes:    4091
 * Dislikes: 267
 * Total Accepted:    472.7K
 * Total Submissions: 761K
 * Testcase Example:  '"abcde"\n"cdeab"'
 *
 * Given two strings s and goal, return true if and only if s can become goal
 * after some number of shifts on s.
 *
 * A shift on s consists of moving the leftmost character of s to the rightmost
 * position.
 *
 *
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 *
 *
 *
 * Example 1:
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 * Example 2:
 * Input: s = "abcde", goal = "abced"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, goal.length <= 100
 * s and goal consist of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
#define MOD (10000009)

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        return s.length() == goal.length() && (s + s).find(goal) != -1;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "abcde";
    string goal_1 = "cdeab";
    bool res_1 = sol.rotateString(s_1, goal_1);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    string s_2 = "abcde";
    string goal_2 = "abced";
    bool res_2 = sol.rotateString(s_2, goal_2);
    cout << res_2 << endl;
    assert(res_2 == false);

    return 0;
}
// Accepted
// 54/54 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.69 % of cpp submissions (7.6 MB)