/*
 * @lc app=leetcode id=3083 lang=cpp
 *
 * [3083] Existence of a Substring in a String and Its Reverse
 *
 * https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/description/
 *
 * algorithms
 * Easy (63.69%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    21.7K
 * Total Submissions: 34.1K
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find any substring of length 2 which is also present in
 * the reverse of s.
 *
 * Return true if such a substring exists, and false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode"
 *
 * Output: true
 *
 * Explanation: Substring "ee" is of length 2 which is also present in
 * reverse(s) == "edocteel".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abcba"
 *
 * Output: true
 *
 * Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are
 * also present in reverse(s) == "abcba".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abcd"
 *
 * Output: false
 *
 * Explanation: There is no substring of length 2 in s, which is also present
 * in the reverse of s.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s consists only of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isSubstringPresent(string s)
    {
        int l = (int) s.size();
        if (l == 1)
            return false;
        unordered_map<string, int> st;
        for (int i = 0; i < l - 1; i++)
        {
            string x = "00";
            x[0]     = s[i];
            x[1]     = s[i + 1];
            st[x]++;
        }
        for (int i = l - 1; i >= 1; i--)
        {
            string x = "00";
            x[0]     = s[i];
            x[1]     = s[i - 1];
            if (st[x] > 0)
                return true;
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char** argv)
{
    Solution sol;

    // Test_1
    string s_1 = "leetcode";
    cout << sol.isSubstringPresent(s_1) << endl;

    // Test_2
    string s_2 = "abcba";
    cout << sol.isSubstringPresent(s_2) << endl;

    // Test_3
    string s_3 = "abcd";
    cout << sol.isSubstringPresent(s_3) << endl;
}
// 713 / 713 test cases passed.
// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 11.8 MB