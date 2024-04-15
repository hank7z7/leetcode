/*
 * @lc app=leetcode id=3084 lang=cpp
 *
 * [3084] Count Substrings Starting and Ending with Given Character
 *
 * https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/description/
 *
 * algorithms
 * Medium (42.93%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    18K
 * Total Submissions: 42K
 * Testcase Example:  '"abada"\n"a"'
 *
 * You are given a string s and a character c. Return the total number of
 * substrings of s that start and end with c.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abada", c = "a"
 *
 * Output: 6
 *
 * Explanation: Substrings starting and ending with "a" are: "abada", "abada",
 * "abada", "abada", "abada", "abada".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "zzz", c = "z"
 *
 * Output: 6
 *
 * Explanation: There are a total of 6 substrings in s and all start and end
 * with "z".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s and c consist only of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long countSubstrings(string s, char c)
    {
        long long count = 0;
        for (auto it : s)
            if (it == c)
                count++;

        return count * (count + 1) / 2;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "abada";
    char   c_1 = 'a';
    cout << sol.countSubstrings(s_1, c_1) << endl;

    // Test_2
    string s_2 = "zzz";
    char   c_2 = 'z';
    cout << sol.countSubstrings(s_2, c_2) << endl;

    return 0;
}
// 669 / 669 test cases passed.
// Status: Accepted
// Runtime: 12 ms
// Memory Usage: 11.1 MB
