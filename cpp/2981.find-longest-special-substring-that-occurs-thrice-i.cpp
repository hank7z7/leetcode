/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 *
 * https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/
 *
 * algorithms
 * Medium (43.08%)
 * Likes:    293
 * Dislikes: 21
 * Total Accepted:    41.9K
 * Total Submissions: 82K
 * Testcase Example:  '"aaaa"'
 *
 * You are given a string s that consists of lowercase English letters.
 *
 * A string is called special if it is made up of only a single character. For
 * example, the string "abc" is not special, whereas the strings "ddd", "zz",
 * and "f" are special.
 *
 * Return the length of the longest special substring of s which occurs at
 * least thrice, or -1 if no special substring occurs at least thrice.
 *
 * A substring is a contiguous non-empty sequence of characters within a
 * string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aaaa"
 * Output: 2
 * Explanation: The longest special substring which occurs thrice is "aa":
 * substrings "aaaa", "aaaa", and "aaaa".
 * It can be shown that the maximum length achievable is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abcdef"
 * Output: -1
 * Explanation: There exists no special substring which occurs at least thrice.
 * Hence return -1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abcaba"
 * Output: 1
 * Explanation: The longest special substring which occurs thrice is "a":
 * substrings "abcaba", "abcaba", and "abcaba".
 * It can be shown that the maximum length achievable is 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= s.length <= 50
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
    int maximumLength(const string& s)
    {
        const int n = (int) s.length();

        for (int len = n - 2; len >= 1; len--)
        {
            // substring -> count
            unordered_map<string_view, int> um;

            for (int start = 0; start + len - 1 < n; start++)
            {
                string_view substr = string_view(s).substr(start, len);
                um[substr]++;
                if (um[substr] >= 3)
                {
                    // Check if it contains only one char
                    bool special = true;
                    for (int i = 1; i < len; i++)
                    {
                        if (substr[i] != substr[i - 1])
                        {
                            special = false;
                            break;
                        }
                    }
                    if (special)
                        return len;
                }
            }
        }

        return -1;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "aaaa";
    int res_1 = sol.maximumLength(s_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    string s_2 = "abcdef";
    int res_2 = sol.maximumLength(s_2);
    cout << res_2 << endl;
    assert(res_2 == -1);

    // Test_3
    string s_3 = "abcaba";
    int res_3 = sol.maximumLength(s_3);
    cout << res_3 << endl;
    assert(res_3 == 1);

    // Test_4 (WA)
    string s_4 = "cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde";
    int res_4 = sol.maximumLength(s_4);
    cout << res_4 << endl;
    assert(res_4 == 2);

    return 0;
}
// Accepted
// 811/811 cases passed (112 ms)
// Your runtime beats 18.99 % of cpp submissions
// Your memory usage beats 14.03 % of cpp submissions (49.6 MB)