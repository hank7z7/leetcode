/*
 * @lc app=leetcode id=2405 lang=cpp
 *
 * [2405] Optimal Partition of String
 *
 * https://leetcode.com/problems/optimal-partition-of-string/description/
 *
 * algorithms
 * Medium (78.40%)
 * Likes:    2522
 * Dislikes: 98
 * Total Accepted:    168.6K
 * Total Submissions: 215.2K
 * Testcase Example:  '"abacaba"'
 *
 * Given a string s, partition the string into one or more substrings such that
 * the characters in each substring are unique. That is, no letter appears in a
 * single substring more than once.
 *
 * Return the minimum number of substrings in such a partition.
 *
 * Note that each character should belong to exactly one substring in a
 * partition.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abacaba"
 * Output: 4
 * Explanation:
 * Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
 * It can be shown that 4 is the minimum number of substrings needed.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "ssssss"
 * Output: 6
 * Explanation:
 * The only valid partition is ("s","s","s","s","s","s").
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only English lowercase letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int partitionString(string s)
    {
        size_t l = s.size();
        // Start with 1 because the last substring will not be counted in for loop
        int         ret = 1;
        unsigned int bitmask = 0;
        // unordered_map<char, int> um;
        for (size_t i = 0; i < l; i++)
        {
            unsigned int val = s[i] - 'a';
            // Greedy method: if s[i] is in current substring, partition it
            if (bitmask & (1 << val))
            {
                bitmask = 0;
                ret++;
            }
            bitmask |= (1 << val);
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    cout << sol.partitionString("abacaba") << endl;

    // Test_2
    cout << sol.partitionString("ssssss") << endl;

    // Test_3
    cout << sol.partitionString("abacaba") << endl;
    return 0;
}
// Optimize by bitmask
// Accepted
// 59/59 cases passed (20 ms)
// Your runtime beats 88.2 % of cpp submissions
// Your memory usage beats 76.92 % of cpp submissions (11.4 MB)

// Count table method
// Accepted
// 59/59 cases passed (23 ms)
// Your runtime beats 81.97 % of cpp submissions
// Your memory usage beats 65.05 % of cpp submissions (11.5 MB)

// Hashmap method
// Accepted
// 59/59 cases passed (164 ms)
// Your runtime beats 42.13 % of cpp submissions
// Your memory usage beats 28.54 % of cpp submissions (47 MB)