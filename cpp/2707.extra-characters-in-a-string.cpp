/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 *
 * https://leetcode.com/problems/extra-characters-in-a-string/description/
 *
 * algorithms
 * Medium (52.56%)
 * Likes:    2319
 * Dislikes: 115
 * Total Accepted:    127.6K
 * Total Submissions: 230.8K
 * Testcase Example:  '"leetscode"\n["leet","code","leetcode"]'
 *
 * You are given a 0-indexed string s and a dictionary of words dictionary. You
 * have to break s into one or more non-overlapping substrings such that each
 * substring is present in dictionary. There may be some extra characters in s
 * which are not present in any of the substrings.
 *
 * Return the minimum number of extra characters left over if you break up s
 * optimally.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
 * Output: 1
 * Explanation: We can break s in two substrings: "leet" from index 0 to 3 and
 * "code" from index 5 to 8. There is only 1 unused character (at index 4), so
 * we return 1.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: s = "sayhelloworld", dictionary = ["hello","world"]
 * Output: 3
 * Explanation: We can break s in two substrings: "hello" from index 3 to 7 and
 * "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used
 * in any substring and thus are considered as extra characters. Hence, we
 * return 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 50
 * 1 <= dictionary.length <= 50
 * 1 <= dictionary[i].length <= 50
 * dictionary[i] and s consists of only lowercase English letters
 * dictionary contains distinct words
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        // Build hash map for O(1) search
        unordered_set<string> us(dictionary.begin(), dictionary.end());

        int n = (int)s.length();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr_min = dp[i + 1] + 1;
            for (int len = 1; (i + len) <= n; len++)
            {
                if (us.find(s.substr(i, len)) != us.end())
                {
                    // cout << "find " << s.substr(i, len) << endl;
                    curr_min = min(curr_min, dp[i + len]);
                }
            }
            dp[i] = curr_min;
        }

        return dp[0];
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "leetscode";
    vector<string> dict_1 = {"leet", "code", "leetcode"};
    int res_1 = sol.minExtraChar(s_1, dict_1);
    cout << res_1 << endl;
    assert(res_1 == 1);

    // Test_2
    string s_2 = "sayhelloworld";
    vector<string> dict_2 = {"hello", "world"};
    int res_2 = sol.minExtraChar(s_2, dict_2);
    cout << res_2 << endl;
    assert(res_2 == 3);

    return 0;
}
// Accepted
// 2028/2028 cases passed (138 ms)
// Your runtime beats 49.46 % of cpp submissions
// Your memory usage beats 46.01 % of cpp submissions (86.8 MB)