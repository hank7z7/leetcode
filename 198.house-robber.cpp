/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Medium (50.89%)
 * Likes:    20677
 * Dislikes: 410
 * Total Accepted:    2.2M
 * Total Submissions: 4.2M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int         n = (int) nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            int prev      = i > 0 ? dp[i - 1] : 0;
            int prev_prev = i > 1 ? dp[i - 2] : 0;
            dp[i]         = max(prev, prev_prev + nums[i]);
        }
        return dp[n - 1];
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 2, 3, 1 };
    cout << sol.rob(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = { 2, 7, 9, 3, 1 };
    cout << sol.rob(nums_2) << endl;

    return 0;
}
// Accepted
// 70/70 cases passed (4 ms)
// Your runtime beats 32.61 % of cpp submissions
// Your memory usage beats 10.66 % of cpp submissions (9.4 MB)