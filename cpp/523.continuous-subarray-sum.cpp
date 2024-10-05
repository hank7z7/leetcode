/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 *
 * https://leetcode.com/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (30.30%)
 * Likes:    6340
 * Dislikes: 665
 * Total Accepted:    603.8K
 * Total Submissions: 2M
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * Given an integer array nums and an integer k, return true if nums has a good
 * subarray or false otherwise.
 *
 * A good subarray is a subarray where:
 *
 *
 * its length is at least two, and
 * the sum of the elements of the subarray is a multiple of k.
 *
 *
 * Note that:
 *
 *
 * A subarray is a contiguous part of the array.
 * An integer x is a multiple of k if there exists an integer n such that x = n
 * * k. 0 is always a multiple of k.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [23,2,4,6,7], k = 6
 * Output: true
 * Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up
 * to 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [23,2,6,4,7], k = 6
 * Output: true
 * Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose
 * elements sum up to 42.
 * 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [23,2,6,4,7], k = 13
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= sum(nums[i]) <= 2^31 - 1
 * 1 <= k <= 2^31 - 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkSubarraySum(const vector<int> &nums, const int k)
    {
        const int n = (int)nums.size();
        // modulo -> first index
        unordered_map<int, int> um;
        um[0] = -1;

        int curr_sum = 0;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            curr_sum += num;
            curr_sum = curr_sum % k;
            if (um.find(curr_sum) != um.end())
            {
                if ((i - um[curr_sum]) > 1)
                    return true;
            }
            else
                um[curr_sum] = i;
        }
        return false;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {23, 2, 4, 6, 7};
    int k_1 = 6;
    bool res_1 = sol.checkSubarraySum(nums_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    vector<int> nums_2 = {23, 2, 6, 4, 7};
    int k_2 = 6;
    bool res_2 = sol.checkSubarraySum(nums_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == true);

    // Test_3
    vector<int> nums_3 = {23, 2, 6, 4, 7};
    int k_3 = 13;
    bool res_3 = sol.checkSubarraySum(nums_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == false);

    // Test_4
    vector<int> nums_4 = {0};
    int k_4 = 1;
    bool res_4 = sol.checkSubarraySum(nums_4, k_4);
    cout << res_4 << endl;
    assert(res_4 == false);

    // Test_5
    vector<int> nums_5 = {1, 0};
    int k_5 = 2;
    bool res_5 = sol.checkSubarraySum(nums_5, k_5);
    cout << res_5 << endl;
    assert(res_5 == false);

    // Test_6
    vector<int> nums_6 = {5, 0, 0, 0};
    int k_6 = 3;
    bool res_6 = sol.checkSubarraySum(nums_6, k_6);
    cout << res_6 << endl;
    assert(res_6 == true);

    // Test_7
    vector<int> nums_7 = {23, 2, 4, 6, 6};
    int k_7 = 7;
    bool res_7 = sol.checkSubarraySum(nums_7, k_7);
    cout << res_7 << endl;
    assert(res_7 == true);

    return 0;
}
// Accepted
// 101/101 cases passed (202 ms)
// Your runtime beats 48.78 % of cpp submissions
// Your memory usage beats 66.47 % of cpp submissions (146.3 MB)