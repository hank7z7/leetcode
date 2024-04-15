/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (58.61%)
 * Likes:    2164
 * Dislikes: 2671
 * Total Accepted:    286.4K
 * Total Submissions: 488.3K
 * Testcase Example:  '2'
 *
 * An n-bit gray code sequence is a sequence of 2^n integers where:
 *
 *
 * Every integer is in the inclusive range [0, 2^n - 1],
 * The first integer is 0,
 * An integer appears no more than once in the sequence,
 * The binary representation of every pair of adjacent integers differs by
 * exactly one bit, and
 * The binary representation of the first and last integers differs by exactly
 * one bit.
 *
 *
 * Given an integer n, return any valid n-bit gray code sequence.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: [0,1,3,2]
 * Explanation:
 * The binary representation of [0,1,3,2] is [00,01,11,10].
 * - 00 and 01 differ by one bit
 * - 01 and 11 differ by one bit
 * - 11 and 10 differ by one bit
 * - 10 and 00 differ by one bit
 * [0,2,3,1] is also a valid gray code sequence, whose binary representation is
 * [00,10,11,01].
 * - 00 and 10 differ by one bit
 * - 10 and 11 differ by one bit
 * - 11 and 01 differ by one bit
 * - 01 and 00 differ by one bit
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 16
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ret;
        for (int i = 0; i < (1 << n); i++)
            ret.push_back((i >> 1) ^ i);
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    for (auto it : sol.grayCode(2))
        cout << it << " ";
    cout << endl;

    // Test_2
    for (auto it : sol.grayCode(4))
        cout << it << " ";
    cout << endl;

    // Test_3
    for (auto it : sol.grayCode(16))
        cout << it << " ";
    cout << endl;
}
// Accepted
// 16/16 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 28.27 % of cpp submissions (13.1 MB)