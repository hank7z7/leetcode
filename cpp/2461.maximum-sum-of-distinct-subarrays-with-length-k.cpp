/*
 * @lc app=leetcode id=2461 lang=cpp
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 *
 * https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
 *
 * algorithms
 * Medium (34.28%)
 * Likes:    1818
 * Dislikes: 38
 * Total Accepted:    152.3K
 * Total Submissions: 363.1K
 * Testcase Example:  '[1,5,4,2,9,9,9]\n3'
 *
 * You are given an integer array nums and an integer k. Find the maximum
 * subarray sum of all the subarrays of nums that meet the following
 * conditions:
 *
 *
 * The length of the subarray is k, and
 * All the elements of the subarray are distinct.
 *
 *
 * Return the maximum subarray sum of all the subarrays that meet the
 * conditions. If no subarray meets the conditions, return 0.
 *
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,4,2,9,9,9], k = 3
 * Output: 15
 * Explanation: The subarrays of nums with length 3 are:
 * - [1,5,4] which meets the requirements and has a sum of 10.
 * - [5,4,2] which meets the requirements and has a sum of 11.
 * - [4,2,9] which meets the requirements and has a sum of 15.
 * - [2,9,9] which does not meet the requirements because the element 9 is
 * repeated.
 * - [9,9,9] which does not meet the requirements because the element 9 is
 * repeated.
 * We return 15 because it is the maximum subarray sum of all the subarrays
 * that meet the conditions
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,4,4], k = 3
 * Output: 0
 * Explanation: The subarrays of nums with length 3 are:
 * - [4,4,4] which does not meet the requirements because the element 4 is
 * repeated.
 * We return 0 because no subarrays meet the conditions.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long maximumSubarraySum(const vector<int> &nums, const int &k)
    {
        const int n = nums.size();
        unordered_map<int, int> um;
        long long res = 0;
        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            um[nums[i]]++;
            sum += nums[i];
        }

        if ((int)um.size() == k)
            res = max(res, sum);

        for (int i = k; i < n; i++)
        {
            um[nums[i - k]]--;
            sum -= nums[i - k];
            if (um[nums[i - k]] == 0)
                um.erase(nums[i - k]);
            um[nums[i]]++;
            sum += nums[i];
            if ((int)um.size() == k)
                res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 5, 4, 2, 9, 9, 9};
    int k_1 = 3;
    long long res_1 = sol.maximumSubarraySum(nums_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 15);

    // Test_2
    vector<int> nums_2 = {4, 4, 4};
    int k_2 = 3;
    long long res_2 = sol.maximumSubarraySum(nums_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 0);
    return 0;
}
// Accepted
// 93/93 cases passed (107 ms)
// Your runtime beats 73.69 % of cpp submissions
// Your memory usage beats 57.32 % of cpp submissions (95.3 MB)