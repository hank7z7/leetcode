/*
 * @lc app=leetcode id=3110 lang=cpp
 *
 * [3110] Score of a String
 *
 * https://leetcode.com/problems/score-of-a-string/description/
 *
 * algorithms
 * Easy (94.25%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    21.2K
 * Total Submissions: 22.4K
 * Testcase Example:  '"hello"'
 *
 * You are given a string s. The score of a string is defined as the sum of the
 * absolute difference between the ASCII values of adjacent characters.
 *
 * Return the score of s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "hello"
 *
 * Output: 13
 *
 * Explanation:
 *
 * The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' =
 * 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108
 * - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "zaz"
 *
 * Output: 50
 *
 * Explanation:
 *
 * The ASCII values of the characters in s are: 'z' = 122, 'a' = 97. So, the
 * score of s would be |122 - 97| + |97 - 122| = 25 + 25 = 50.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= s.length <= 100
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
    int scoreOfString(string s)
    {
        int score = 0;
        for (int i = 1; i < (int)s.size(); i++)
        {
            score += abs(s[i] - s[i - 1]);
        }
        return score;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "hello";
    cout << sol.scoreOfString(s_1) << endl;

    // Test_2
    string s_2 = "zaz";
    cout << sol.scoreOfString(s_2) << endl;

    return 0;
}
// Accepted
// 705/705 cases passed (5 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 40 % of cpp submissions (7.9 MB)