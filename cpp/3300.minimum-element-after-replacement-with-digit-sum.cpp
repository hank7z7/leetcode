/*
 * @lc app=leetcode id=3300 lang=cpp
 *
 * [3300] Minimum Element After Replacement With Digit Sum
 *
 * https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/
 *
 * algorithms
 * Easy (83.09%)
 * Likes:    37
 * Dislikes: 1
 * Total Accepted:    36K
 * Total Submissions: 43.3K
 * Testcase Example:  '[10,12,13,14]'
 *
 * You are given an integer array nums.
 *
 * You replace each element in nums with the sum of its digits.
 *
 * Return the minimum element in nums after all replacements.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,12,13,14]
 *
 * Output: 1
 *
 * Explanation:
 *
 * nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4]
 *
 * Output: 1
 *
 * Explanation:
 *
 * nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [999,19,199]
 *
 * Output: 10
 *
 * Explanation:
 *
 * nums becomes [27, 10, 19] after all replacements, with minimum element
 * 10.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minElement(vector<int> &nums)
    {
        int res = INT_MAX;
        for (auto &num : nums)
        {
            int sum = 0;
            while (num)
            {
                sum += (num % 10);
                num /= 10;
            }
            res = min(res, sum);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {10, 12, 13, 14};
    int res_1 = sol.minElement(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 1);

    // Test_2
    vector<int> nums_2 = {1, 2, 3, 4};
    int res_2 = sol.minElement(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    // Test_3
    vector<int> nums_3 = {999, 19, 199};
    int res_3 = sol.minElement(nums_3);
    cout << res_3 << endl;
    assert(res_3 == 10);
    return 0;
}
// Accepted
// 835/835 cases passed (3 ms)
// Your runtime beats 90.8 % of cpp submissions
// Your memory usage beats 93.08 % of cpp submissions (27 MB)