/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (80.15%)
 * Likes:    10768
 * Dislikes: 419
 * Total Accepted:    654.3K
 * Total Submissions: 808.6K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * You are given a string s. We want to partition the string into as many parts
 * as possible so that each letter appears in at most one part. For example,
 * the string "ababcc" can be partitioned into ["abab", "cc"], but partitions
 * such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
 *
 * Note that the partition is done so that after concatenating all the parts in
 * order, the resultant string should be s.
 *
 * Return a list of integers representing the size of these parts.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits s into less parts.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "eccbbbbdec"
 * Output: [10]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        const int n = (int)s.length();

        vector<int> last_idx(26, -1);
        for (int i = 0; i < n; i++)
            last_idx[s[i] - 'a'] = i;

        vector<int> res;
        int start = 0;
        int end = 0;
        for (int i = 0; i <= n; i++)
        {

            if (i == n || i > end)
            {
                res.push_back(end - start + 1);
                start = i;
                if (i == n)
                    break;
            }
            end = max(end, last_idx[s[i] - 'a']);
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string s_1 = "ababcbacadefegdehijhklij";
    vector<int> res_1 = sol.partitionLabels(s_1);
    for (auto &i : res_1)
        cout << i << " ";
    cout << endl;
    assert((res_1 == vector<int>{9, 7, 8}));

    // Test_2
    string s_2 = "eccbbbbdec";
    vector<int> res_2 = sol.partitionLabels(s_2);
    for (auto &i : res_2)
        cout << i << " ";
    cout << endl;
    assert((res_2 == vector<int>{10}));

    // Test_3
    string s_3 = "ababcbacadefegdehijhklij";
    vector<int> res_3 = sol.partitionLabels(s_3);
    for (auto &i : res_3)
        cout << i << " ";
    cout << endl;
    assert((res_3 == vector<int>{9, 7, 8}));

    return 0;
}
// Accepted
// 118/118 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 49.45 % of cpp submissions (8.9 MB)