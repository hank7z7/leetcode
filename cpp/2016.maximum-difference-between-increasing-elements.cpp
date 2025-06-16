/*
 * @lc app=leetcode id=2016 lang=cpp
 *
 * [2016] Maximum Difference Between Increasing Elements
 *
 * https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/
 *
 * algorithms
 * Easy (58.67%)
 * Likes:    1235
 * Dislikes: 42
 * Total Accepted:    162K
 * Total Submissions: 258.3K
 * Testcase Example:  '[7,1,5,4]'
 *
 * Given a 0-indexed integer array nums of size n, find the maximum difference
 * between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j
 * < n and nums[i] < nums[j].
 *
 * Return the maximum difference. If no such i and j exists, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [7,1,5,4]
 * Output: 4
 * Explanation:
 * The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 -
 * 1 = 4.
 * Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 =
 * 6, but i > j, so it is not valid.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [9,4,3,2]
 * Output: -1
 * Explanation:
 * There is no i and j such that i < j and nums[i] < nums[j].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,5,2,10]
 * Output: 9
 * Explanation:
 * The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 -
 * 1 = 9.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 2 <= n <= 1000
 * 1 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumDifference(vector<int>& nums)
    {
        int res = -1;
        stack<int> st;
        for (auto& num : nums)
        {
            if (!st.empty() && num > st.top())
            {
                // Calculate the difference and update res if it's greater
                res = max(res, num - st.top());
            }
            else
            {
                st.push(num);  // Push the current number onto the stack
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = { 7, 1, 5, 4 };
    int res = sol.maximumDifference(nums);
    cout << res << endl;
    assert(res == 4);

    // Test_2
    nums = { 9, 4, 3, 2 };
    res = sol.maximumDifference(nums);
    cout << res << endl;
    assert(res == -1);

    // Test_3
    nums = { 1, 5, 2, 10 };
    res = sol.maximumDifference(nums);
    cout << res << endl;
    assert(res == 9);

    return 0;
}
// Accepted
// 54/54 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 10.39 % of cpp submissions (12 MB)