/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 *
 * https://leetcode.com/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (47.24%)
 * Likes:    6180
 * Dislikes: 194
 * Total Accepted:    295.2K
 * Total Submissions: 612.6K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * Given an array of integers nums and an integer k, return the number of
 * contiguous subarrays where the product of all the elements in the subarray
 * is strictly less than k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,5,2,6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are:
 * [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly
 * less than k.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3], k = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int target)
    {
        int l     = (int) nums.size();
        int count = 0;
        for (int i = 0; i < l; i++)
        {
            long long product = 1;
            for (int j = i; j < l; j++)
            {
                product *= (long long) nums[j];
                if (product < (long long) target)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 10, 5, 2, 6 };
    int         k_1    = 100;
    cout << sol.numSubarrayProductLessThanK(nums_1, k_1) << endl;

    // Test_2
    vector<int> nums_2 = { 1, 2, 3 };
    int         k_2    = 0;
    cout << sol.numSubarrayProductLessThanK(nums_2, k_2) << endl;

    return 0;
}
