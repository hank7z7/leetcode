/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 *
 * https://leetcode.com/problems/make-sum-divisible-by-p/description/
 *
 * algorithms
 * Medium (29.19%)
 * Likes:    1797
 * Dislikes: 90
 * Total Accepted:    53.4K
 * Total Submissions: 159.9K
 * Testcase Example:  '[3,1,4,2]\n6'
 *
 * Given an array of positive integers nums, remove the smallest subarray
 * (possibly empty) such that the sum of the remaining elements is divisible by
 * p. It is not allowed to remove the whole array.
 *
 * Return the length of the smallest subarray that you need to remove, or -1 if
 * it's impossible.
 *
 * A subarray is defined as a contiguous block of elements in the array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,1,4,2], p = 6
 * Output: 1
 * Explanation: The sum of the elements in nums is 10, which is not divisible
 * by 6. We can remove the subarray [4], and the sum of the remaining elements
 * is 6, which is divisible by 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [6,3,5,2], p = 9
 * Output: 2
 * Explanation: We cannot remove a single element to get a sum divisible by 9.
 * The best way is to remove the subarray [5,2], leaving us with [6,3] with sum
 * 9.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3], p = 3
 * Output: 0
 * Explanation: Here the sum is 6. which is already divisible by 3. Thus we do
 * not need to remove anything.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= p <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        const int n = (int)nums.size();
        // Build prefix sum modulo
        nums[0] = nums[0] % p;
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
            nums[i] = nums[i] % p;
        }
        // The target subarray to remove
        int target = nums[n - 1];
        if (target == 0)
            return 0;

        // modulo -> last index of the modulo
        unordered_map<int, int> um;
        um[0] = -1;

        int res = INT_MAX;
        // Iterate prefix sum as the last element of subarray
        for (int i = 0; i < n; i++)
        {
            // Find last prefix sum
            int last_mod = (nums[i] + p - target) % p;
            if (um.find(last_mod) != um.end())
                res = min(res, i - um[last_mod]);
            um[nums[i]] = i;
        }

        if (res == INT_MAX || res == n)
            return -1;
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {3, 1, 4, 2};
    // prefix = {3, 4, 8, 10}
    // mod = {3, 4, 2, 4};
    int p_1 = 6;
    int res_1 = sol.minSubarray(nums_1, p_1);
    cout << res_1 << endl;
    assert(res_1 == 1);

    // Test_2
    vector<int> nums_2 = {6, 3, 5, 2};
    // prefix = {6, 9, 14, 16}
    // mod = {6, 0, 5, 7};
    int p_2 = 9;
    int res_2 = sol.minSubarray(nums_2, p_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    // Test_3
    vector<int> nums_3 = {1, 2, 3};
    // prefix = {6, 9, 14, 16}
    // mod = {6, 0, 5, 7};
    int p_3 = 3;
    int res_3 = sol.minSubarray(nums_3, p_3);
    cout << res_3 << endl;
    assert(res_3 == 0);

    // Test_4
    vector<int> nums_4 = {1, 2, 3};
    // prefix = {1, 3, 6}
    // mod = {1, 0, 0};
    int p_4 = 3;
    int res_4 = sol.minSubarray(nums_4, p_4);
    cout << res_4 << endl;
    assert(res_4 == 0);

    // Test_4_1
    vector<int> nums_4_1 = {1, 2, 3};
    // prefix = {1, 3, 6}
    // mod = {1, 0, 0};
    int p_4_1 = 7;
    int res_4_1 = sol.minSubarray(nums_4_1, p_4_1);
    cout << res_4_1 << endl;
    assert(res_4_1 == -1);

    // Test_5
    vector<int> nums_5 = {26, 19, 11, 14, 18, 4, 7, 1, 30, 23, 19, 8, 10, 6, 26, 3};
    int p_5 = 26;
    int res_5 = sol.minSubarray(nums_5, p_5);
    cout << res_5 << endl;
    assert(res_5 == 3);

    // Test_6
    int p_6 = 949467102;
    int res_6 = sol.minSubarray(nums_6, p_6);
    cout << res_6 << endl;
    assert(res_6 == 4008);

    return 0;
}
// Accepted
// 142/142 cases passed (141 ms)
// Your runtime beats 37.28 % of cpp submissions
// Your memory usage beats 85.6 % of cpp submissions (70.4 MB)