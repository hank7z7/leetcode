/*
 * @lc app=leetcode id=2962 lang=cpp
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 *
 * https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
 *
 * algorithms
 * Medium (45.08%)
 * Likes:    477
 * Dislikes: 20
 * Total Accepted:    38.6K
 * Total Submissions: 72.3K
 * Testcase Example:  '[1,3,2,3,3]\n2'
 *
 * You are given an integer array nums and a positive integer k.
 *
 * Return the number of subarrays where the maximum element of nums appears at
 * least k times in that subarray.
 *
 * A subarray is a contiguous sequence of elements within an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,2,3,3], k = 2
 * Output: 6
 * Explanation: The subarrays that contain the element 3 at least 2 times are:
 * [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,4,2,1], k = 3
 * Output: 0
 * Explanation: No subarray contains the element 4 at least 3 times.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 1 <= k <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        int max_num = INT_MIN;
        for (auto num : nums)
            max_num = max(max_num, num);

        // Record index of max_num
        vector<int> idx;
        long long count = 0;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            if (nums[i] == max_num)
                idx.push_back(i);

            if ((int) idx.size() >= k)
                count += ((long long) idx[idx.size() - k] + 1);
        }

        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 3, 2, 3, 3 };
    int k_1 = 2;
    cout << sol.countSubarrays(nums_1, k_1) << endl;

    // Test_2
    vector<int> nums_2 = { 1, 4, 2, 1 };
    int k_2 = 3;
    cout << sol.countSubarrays(nums_2, k_2) << endl;

    // Test_3
    vector<int> nums_3 = { 61, 23, 38, 23, 56, 40, 82, 56, 82, 82, 82, 70, 8,
                           69, 8,  7,  19, 14, 58, 42, 82, 10, 82, 78, 15, 82 };
    int         k_3    = 2;
    cout << sol.countSubarrays(nums_3, k_3) << endl;

    return 0;
}
// Vector method
// Accepted
// 633/633 cases passed (130 ms)
// Your runtime beats 64.15 % of cpp submissions
// Your memory usage beats 38.76 % of cpp submissions (123.7 MB)


// Accepted
// 633/633 cases passed (136 ms)
// Your runtime beats 51.55 % of cpp submissions
// Your memory usage beats 84.3 % of cpp submissions (119.9 MB)