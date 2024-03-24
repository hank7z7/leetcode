/*
 * @lc app=leetcode id=3090 lang=cpp
 *
 * [3090] Maximum Length Substring With Two Occurrences
 *
 * https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/
 *
 * algorithms
 * Easy (59.33%)
 * Likes:    25
 * Dislikes: 1
 * Total Accepted:    19.2K
 * Total Submissions: 32.4K
 * Testcase Example:  '"bcbbbcba"'
 *
 * Given a string s, return the maximum length of a substring such that it
 * contains at most two occurrences of each character.
 *
 * Example 1:
 *
 *
 * Input: s = "bcbbbcba"
 *
 * Output: 4
 *
 * Explanation:
 * The following substring has a length of 4 and contains at most two
 * occurrences of each character: "bcbbbcba".
 *
 * Example 2:
 *
 *
 * Input: s = "aaaa"
 *
 * Output: 2
 *
 * Explanation:
 * The following substring has a length of 2 and contains at most two
 * occurrences of each character: "aaaa".
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
    int maximumLengthSubstring(string s)
    {
        int l = (int)s.size();
        int max_l = 0;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l; j++)
            {
                vector<int> count(26, 0);
                bool valid = true;
                for (int k = i; k <= j; k++)
                {
                    count[s[k] - 'a']++;
                    if (count[s[k] - 'a'] > 2)
                        valid = false;
                }
                if (valid)
                    max_l = max(max_l, j - i + 1);
            }
        }
        return max_l;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "bcbbbcba";
    cout << sol.maximumLengthSubstring(s_1) << endl;

    // Test_2
    string s_2 = "aaaa";
    cout << sol.maximumLengthSubstring(s_2) << endl;

    return 0;
}
// Accepted
// 709/709 cases passed (210 ms)
// Your runtime beats 16.67 % of cpp submissions
// Your memory usage beats 16.67 % of cpp submissions (182.4 MB)