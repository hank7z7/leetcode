/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (47.33%)
 * Likes:    11366
 * Dislikes: 379
 * Total Accepted:    741.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given an integer array nums and an integer target.
 *
 * You want to build an expression out of nums by adding one of the symbols '+'
 * and '-' before each integer in nums and then concatenate all the
 * integers.
 *
 *
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
 * and concatenate them to build the expression "+2-1".
 *
 *
 * Return the number of different expressions that you can build, which
 * evaluates to target.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,1,1], target = 3
 * Output: 5
 * Explanation: There are 5 ways to assign symbols to make the sum of nums be
 * target 3.
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], target = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findTargetSumWays(const vector<int>& nums, const int target)
    {
        // target -> number of ways to target
        unordered_map<int, int> curr;
        // Initialize target to 1
        curr[target]++;

        // DP
        for (auto& num : nums)
        {
            unordered_map<int, int> next;
            for (auto& [old_target, ways] : curr)
            {
                next[old_target + num] += curr[old_target];
                next[old_target - num] += curr[old_target];
            }
            curr = next;
        }
        return curr[0];
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 1, 1, 1, 1 };
    int target_1 = 3;
    int res_1 = sol.findTargetSumWays(nums_1, target_1);
    cout << res_1 << endl;
    assert(res_1 == 5);

    // Test_2
    vector<int> nums_2 = { 1 };
    int target_2 = 1;
    int res_2 = sol.findTargetSumWays(nums_2, target_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    return 0;
}
// Accepted
// 140/140 cases passed (142 ms)
// Your runtime beats 46.02 % of cpp submissions
// Your memory usage beats 17.87 % of cpp submissions (53.8 MB)