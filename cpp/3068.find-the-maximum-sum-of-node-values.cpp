/*
 * @lc app=leetcode id=3068 lang=cpp
 *
 * [3068] Find the Maximum Sum of Node Values
 *
 * https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/
 *
 * algorithms
 * Hard (27.91%)
 * Likes:    6
 * Dislikes: 3
 * Total Accepted:    1.8K
 * Total Submissions: 6.6K
 * Testcase Example:  '[1,2,1]\n3\n[[0,1],[0,2]]'
 *
 * There exists an undirected tree with n nodes numbered 0 to n - 1. You are
 * given a 0-indexed 2D integer array edges of length n - 1, where edges[i] =
 * [ui, vi] indicates that there is an edge between nodes ui and vi in the
 * tree. You are also given a positive integer k, and a 0-indexed array of
 * non-negative integers nums of length n, where nums[i] represents the value
 * of the node numbered i.
 *
 * Bogdan wants the sum of values of tree nodes to be maximum, for which Bogdan
 * can perform the following operation any number of times (including zero) on
 * the tree:
 *
 *
 * Choose any edge [u, v] connecting the nodes u and v, and update their values
 * as follows:
 *
 *
 * nums[u] = nums[u] XOR k
 * nums[v] = nums[v] XOR k
 *
 *
 *
 *
 * Return the maximum possible sum of the values Bogdan can achieve by
 * performing the operation any number of times.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
 * Output: 6
 * Explanation: Bogdan can achieve the maximum sum of 6 using a single
 * operation:
 * - Choose the edge [0,2]. nums[0] and nums[2] become: 1 XOR 3 = 2, and the
 * array nums becomes: [1,2,1] -> [2,2,2].
 * The total sum of values is 2 + 2 + 2 = 6.
 * It can be shown that 6 is the maximum achievable sum of values.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3], k = 7, edges = [[0,1]]
 * Output: 9
 * Explanation: Bogdan can achieve the maximum sum of 9 using a single
 * operation:
 * - Choose the edge [0,1]. nums[0] becomes: 2 XOR 7 = 5 and nums[1] become: 3
 * XOR 7 = 4, and the array nums becomes: [2,3] -> [5,4].
 * The total sum of values is 5 + 4 = 9.
 * It can be shown that 9 is the maximum achievable sum of values.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]
 * Output: 42
 * Explanation: The maximum achievable sum is 42 which can be achieved by
 * Bogdan performing no operations.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n == nums.length <= 2 * 10^4
 * 1 <= k <= 10^9
 * 0 <= nums[i] <= 10^9
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= edges[i][0], edges[i][1] <= n - 1
 * The input is generated such that edges represent a valid tree.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
// If the count is even, we just return the best sum.

// If the count is odd, we need to sacrifice one node:

// Do not change a node we want to change, or
// Change a node that we do not want to change.
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        long long ret      = 0;
        int       min_diff = INT_MAX;
        int       time     = 0;
        for (auto it : nums)
        {
            int xor_ret = it ^ k;
            if (xor_ret > it)
            {
                ret += (long long) xor_ret;
                time++;
            }
            else
            {
                ret += (long long) it;
            }
            min_diff = min(min_diff, abs(it - xor_ret));
        }

        // Change odd time, sacrafise the min diff one
        if (time & 1)
            ret -= (long long) min_diff;
        // Change even time, the ret is the maximum

        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      k;
    // Test_1
    vector<int> nums_1         = { 1, 2, 1 };
    k                          = 3;
    vector<vector<int>> edge_1 = { { 0, 1 }, { 0, 2 } };
    cout << sol.maximumValueSum(nums_1, k, edge_1) << endl;

    // Test_2
    vector<int> nums_2         = { 2, 3 };
    k                          = 7;
    vector<vector<int>> edge_2 = { { 0, 1 } };
    cout << sol.maximumValueSum(nums_2, k, edge_2) << endl;

    // Test_3
    vector<int> nums_3         = { 7, 7, 7, 7, 7, 7 };
    k                          = 3;
    vector<vector<int>> edge_3 = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 0, 5 } };
    cout << sol.maximumValueSum(nums_3, k, edge_3) << endl;

    // Test_4
    vector<int> nums_4         = { 24, 78, 1, 97, 44 };
    k                          = 6;
    vector<vector<int>> edge_4 = { { 0, 2 }, { 1, 2 }, { 4, 2 }, { 3, 4 } };
    cout << sol.maximumValueSum(nums_4, k, edge_4) << endl;

    // Test_5
    vector<int> nums_5 = { 67, 13, 79, 13, 75, 11, 0, 41, 94 };
    k                  = 7;
    vector<vector<int>> edge_5
        = { { 0, 1 }, { 3, 7 }, { 4, 7 }, { 6, 5 }, { 6, 0 }, { 0, 2 }, { 7, 2 }, { 7, 8 } };
    cout << sol.maximumValueSum(nums_5, k, edge_5) << endl;
    return 0;
}
// Accepted
// 717/717 cases passed (175 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (125.6 MB)