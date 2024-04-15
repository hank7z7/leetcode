/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 *
 * https://leetcode.com/problems/removing-stars-from-a-string/description/
 *
 * algorithms
 * Medium (74.40%)
 * Likes:    2765
 * Dislikes: 193
 * Total Accepted:    254.9K
 * Total Submissions: 342.1K
 * Testcase Example:  '"leet**cod*e"'
 *
 * You are given a string s, which contains stars *.
 *
 * In one operation, you can:
 *
 *
 * Choose a star in s.
 * Remove the closest non-star character to its left, as well as remove the
 * star itself.
 *
 *
 * Return the string after all stars have been removed.
 *
 * Note:
 *
 *
 * The input will be generated such that the operation is always possible.
 * It can be shown that the resulting string will always be unique.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leet**cod*e"
 * Output: "lecoe"
 * Explanation: Performing the removals from left to right:
 * - The closest character to the 1^st star is 't' in "leet**cod*e". s becomes
 * "lee*cod*e".
 * - The closest character to the 2^nd star is 'e' in "lee*cod*e". s becomes
 * "lecod*e".
 * - The closest character to the 3^rd star is 'd' in "lecod*e". s becomes
 * "lecoe".
 * There are no more stars, so we return "lecoe".
 *
 * Example 2:
 *
 *
 * Input: s = "erase*****"
 * Output: ""
 * Explanation: The entire string is removed, so we return an empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters and stars *.
 * The operation above can be performed on s.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeStars(string s)
    {
        size_t j = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                j--;
            }
            else
            {
                if (i != j)
                {
                    s[j] = s[i];
                }
                j++;
            }
        }
        for (size_t i = j; i < s.size(); i++)
            s.erase(i);
        return s;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "leet**cod*e";
    cout << sol.removeStars(s_1) << endl;

    // Test_2
    string s_2 = "erase*****";
    cout << sol.removeStars(s_2) << endl;

    // Test_3
    string s_3 = "leetcode";
    cout << sol.removeStars(s_3) << endl;

    return 0;
}
// Accepted
// 65/65 cases passed (77 ms)
// Your runtime beats 88.53 % of cpp submissions
// Your memory usage beats 95.33 % of cpp submissions (24.7 MB)