/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (43.78%)
 * Likes:    8332
 * Dislikes: 1932
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 *
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, int> um_s;
        unordered_map<char, int> um_t;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (um_s.find(s[i]) == um_s.end())
                um_s[s[i]] = (int) um_s.size();

            s[i] = um_s[s[i]] + 'a';
        }
        // cout << s << endl;
        for (size_t i = 0; i < t.size(); i++)
        {
            if (um_t.find(t[i]) == um_t.end())
                um_t[t[i]] = (int) um_t.size();

            t[i] = um_t[t[i]] + 'a';
        }
        // cout << t << endl;
        return s == t;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "egg";
    string t_1 = "add";
    cout << sol.isIsomorphic(s_1, t_1) << endl;

    // Test_2
    string s_2 = "foo";
    string t_2 = "bar";
    cout << sol.isIsomorphic(s_2, t_2) << endl;

    // Test_3
    string s_3 = "paper";
    string t_3 = "title";
    cout << sol.isIsomorphic(s_3, t_3) << endl;
    return 0;
}
// Accepted
// 45/45 cases passed (6 ms)
// Your runtime beats 65.28 % of cpp submissions
// Your memory usage beats 17.52 % of cpp submissions (9.5 MB)