/*
 * @lc app=leetcode id=3381 lang=cpp
 *
 * [3381] Maximum Subarray Sum With Length Divisible by K
 *
 * https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/
 *
 * algorithms
 * Medium (27.43%)
 * Likes:    356
 * Dislikes: 20
 * Total Accepted:    33.9K
 * Total Submissions: 83.4K
 * Testcase Example:  '[1,2]\n1'
 *
 * You are given an array of integers nums and an integer k.
 * 
 * Return the maximum sum of a subarray of nums, such that the size of the
 * subarray is divisible by k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2], k = 1
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by
 * 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,-2,-3,-4,-5], k = 4
 * 
 * Output: -10
 * 
 * Explanation:
 * 
 * The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4
 * which is divisible by 4.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [-5,1,2,-3,4], k = 2
 * 
 * Output: 4
 * 
 * Explanation:
 * 
 * The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which
 * is divisible by 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= nums.length <= 2 * 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const int n = (int)nums.size();
        long long prefixSum = 0, maxSum = LONG_LONG_MIN;
        vector<long long> kSum(k, LONG_LONG_MAX / 2);
        kSum[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxSum = max(maxSum, prefixSum - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], prefixSum);
        }
        return maxSum;
    }
};
// @lc code=end
int main(int argc, char** argv) {
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 2};
    int k_1 = 1;
    long long res_1 = sol.maxSubarraySum(nums_1, k_1);
    cout << "Test_1: " << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    vector<int> nums_2 = {-1, -2, -3, -4, -5};
    int k_2 = 4;
    long long res_2 = sol.maxSubarraySum(nums_2, k_2);
    cout << "Test_2: " << res_2 << endl;
    assert(res_2 == -10);

    // Test_3
    vector<int> nums_3 = {-5, 1, 2, -3, 4};
    int k_3 = 2;
    long long res_3 = sol.maxSubarraySum(nums_3, k_3);
    cout << "Test_3: " << res_3 << endl;
    assert(res_3 == 4);

    return 0;
}
// Accepted
// 661/661 cases passed (12 ms)
// Your runtime beats 63.48 % of cpp submissions
// Your memory usage beats 98.63 % of cpp submissions (162.2 MB)