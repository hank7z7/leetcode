/*
 * @lc app=leetcode id=3223 lang=cpp
 *
 * [3223] Minimum Length of String After Operations
 *
 * https://leetcode.com/problems/minimum-length-of-string-after-operations/description/
 *
 * algorithms
 * Medium (47.20%)
 * Likes:    19
 * Dislikes: 1
 * Total Accepted:    17.5K
 * Total Submissions: 37.1K
 * Testcase Example:  '"abaacbcbb"'
 *
 * You are given a string s.
 *
 * You can perform the following process on s any number of times:
 *
 *
 * Choose an index i in the string such that there is at least one character to
 * the left of index i that is equal to s[i], and at least one character to the
 * right that is also equal to s[i].
 * Delete the closest character to the left of index i that is equal to
 * s[i].
 * Delete the closest character to the right of index i that is equal to
 * s[i].
 *
 *
 * Return the minimum length of the final string s that you can achieve.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abaacbcbb"
 *
 * Output: 5
 *
 * Explanation:
 * We do the following operations:
 *
 *
 * Choose index 2, then remove the characters at indices 0 and 3. The resulting
 * string is s = "bacbcbb".
 * Choose index 3, then remove the characters at indices 0 and 5. The resulting
 * string is s = "acbcb".
 *
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aa"
 *
 * Output: 2
 *
 * Explanation:
 * We cannot perform any operations, so we return the length of the original
 * string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2 * 10^5
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
    int minimumLength(string s)
    {
        vector<int> counts(26, 0);
        for (auto c : s)
        {
            counts[c - 'a']++;
        }

        int res = 0;
        for (auto count : counts)
        {
            if (count == 0)
                continue;
            if (count % 2 == 0)
                res += 2;
            else
                res += 1;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "abaacbcbb";
    int res_1 = sol.minimumLength(s_1);
    cout << res_1 << endl;
    assert(res_1 == 5);

    // Test_2
    string s_2 = "aa";
    int res_2 = sol.minimumLength(s_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    return 0;
}
// Accepted
// 702/702 cases passed (89 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 50 % of cpp submissions (30.6 MB)