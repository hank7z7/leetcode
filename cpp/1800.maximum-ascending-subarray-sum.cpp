/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 *
 * https://leetcode.com/problems/maximum-ascending-subarray-sum/description/
 *
 * algorithms
 * Easy (61.99%)
 * Likes:    934
 * Dislikes: 30
 * Total Accepted:    113.3K
 * Total Submissions: 174.6K
 * Testcase Example:  '[10,20,30,5,10,50]'
 *
 * Given an array of positive integers nums, return the maximum possible sum of
 * an ascending subarray in nums.
 *
 * A subarray is defined as a contiguous sequence of numbers in an array.
 *
 * A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i
 * where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is
 * ascending.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,20,30,5,10,50]
 * Output: 65
 * Explanation: [5,10,50] is the ascending subarray with the maximum sum of
 * 65.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [10,20,30,40,50]
 * Output: 150
 * Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum
 * of 150.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [12,17,15,13,10,11,12]
 * Output: 33
 * Explanation: [10,11,12] is the ascending subarray with the maximum sum of
 * 33.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxAscendingSum(const vector<int>& nums)
    {
        const int n = (int) nums.size();
        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || nums[i] > nums[i - 1])
                sum += nums[i];
            else
                sum = nums[i];

            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 10, 20, 30, 5, 10, 50 };
    int res_1 = sol.maxAscendingSum(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 65);

    // Test_2
    vector<int> nums_2 = { 10, 20, 30, 40, 50 };
    int res_2 = sol.maxAscendingSum(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 150);

    // Test_3
    vector<int> nums_3 = { 12, 17, 15, 13, 10, 11, 12 };
    int res_3 = sol.maxAscendingSum(nums_3);
    cout << res_3 << endl;
    assert(res_3 == 33);

    return 0;
}
// Accepted
// 104/104 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.52 % of cpp submissions (11 MB)