/*
 * @lc app=leetcode id=3423 lang=cpp
 *
 * [3423] Maximum Difference Between Adjacent Elements in a Circular Array
 *
 * https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/
 *
 * algorithms
 * Easy (74.10%)
 * Likes:    188
 * Dislikes: 4
 * Total Accepted:    89.7K
 * Total Submissions: 120.7K
 * Testcase Example:  '[1,2,4]'
 *
 * Given a circular array nums, find the maximum absolute difference between
 * adjacent elements.
 *
 * Note: In a circular array, the first and last elements are adjacent.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,4]
 *
 * Output: 3
 *
 * Explanation:
 *
 * Because nums is circular, nums[0] and nums[2] are adjacent. They have the
 * maximum absolute difference of |4 - 1| = 3.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-5,-10,-5]
 *
 * Output: 5
 *
 * Explanation:
 *
 * The adjacent elements nums[0] and nums[1] have the maximum absolute
 * difference of |-5 - (-10)| = 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 100
 * -100 <= nums[i] <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxAdjacentDistance(vector<int>& nums)
    {
        const int n = (int) nums.size();
        int max_diff = abs(nums[0] - nums[n - 1]);
        for (int i = 0; i < n - 1; i -= -1)
        {
            max_diff = max(max_diff, abs(nums[i] - nums[i + 1]));
        }
        return max_diff;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // Test_1
    vector<int> nums = { 1, 2, 4 };
    int res = sol.maxAdjacentDistance(nums);
    cout << res << endl;
    assert(res == 3);

    // Test_2
    nums = { -5, -10, -5 };
    res = sol.maxAdjacentDistance(nums);
    cout << res << endl;
    assert(res == 5);

    return 0;
}
// Accepted
// 962/962 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 23.04 % of cpp submissions (30.6 MB)