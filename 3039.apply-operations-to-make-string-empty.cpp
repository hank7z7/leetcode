/*
 * @lc app=leetcode id=3039 lang=cpp
 *
 * [3039] Apply Operations to Make String Empty
 *
 * https://leetcode.com/problems/apply-operations-to-make-string-empty/description/
 *
 * algorithms
 * Medium (48.18%)
 * Likes:    1
 * Dislikes: 1
 * Total Accepted:    12K
 * Total Submissions: 24.8K
 * Testcase Example:  '"aabcbbca"'
 *
 * You are given a string s.
 *
 * Consider performing the following operation until s becomes empty:
 *
 *
 * For every alphabet character from 'a' to 'z', remove the first occurrence of
 * that character in s (if it exists).
 *
 *
 * Return the value of the string s right before applying the last
 * operation.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aabcbbca"
 * Output: "ba"
 * Explanation: We do the following operations:
 * - Remove the underlined characters s = "aabcbbca". The resulting string is s
 * = "abbca".
 * - Remove the underlined characters s = "abbca". The resulting string is s =
 * "ba".
 * - Remove the underlined characters s = "ba". The resulting string is s = "".
 * The string just before the last operation is "ba".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abcd"
 * Output: "abcd"
 * Explanation: We do the following operation:
 * - Remove the underlined characters s = "abcd". The resulting string is s =
 * "".
 * The string just before the last operation is "abcd".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^5
 * s consists only of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
#define LETTER_SIZE (26)
class Solution
{
public:
    static string lastNonEmptyString(string s)
    {
        string      ret;
        vector<int> count;
        for (int i = 0; i < LETTER_SIZE; i++)
            count.push_back(0);
        int max        = 0;
        int occur_time = 1;
        for (int i = 0; i < (int) s.size(); i++)
        {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] > max)
            {
                max        = count[s[i] - 'a'];
                occur_time = 1;
            }
            else if (count[s[i] - 'a'] == max)
                occur_time++;
        }

        for (int i = ((int) s.size() - 1); i >= 0 && occur_time > 0; i--)
            if (count[s[i] - 'a'] == max)
            {
                ret.push_back(s[i]);
                count[s[i] - 'a'] = 0;
                occur_time--;
            }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    // Test_1
    string s_1 = "aabcbbca";
    cout << Solution::lastNonEmptyString(s_1) << endl;
    return 0;

    // Test_2
    string s_2 = "abcd";
    cout << Solution::lastNonEmptyString(s_2) << endl;
    return 0;
}
// Accepted
// 697/697 cases passed (109 ms)
// Your runtime beats 25 % of cpp submissions
// Your memory usage beats 25 % of cpp submissions (30.9 MB)