/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 *
 * https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/
 *
 * algorithms
 * Medium (61.81%)
 * Likes:    1171
 * Dislikes: 103
 * Total Accepted:    188.7K
 * Total Submissions: 297.7K
 * Testcase Example:  '[1,2,3,3,2,2]'
 *
 * You are given an integer array nums of size n.
 *
 * Consider a non-empty subarray from nums that has the maximum possible
 * bitwise AND.
 *
 *
 * In other words, let k be the maximum value of the bitwise AND of any
 * subarray of nums. Then, only subarrays with a bitwise AND equal to k should
 * be considered.
 *
 *
 * Return the length of the longest such subarray.
 *
 * The bitwise AND of an array is the bitwise AND of all the numbers in it.
 *
 * A subarray is a contiguous sequence of elements within an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,3,2,2]
 * Output: 2
 * Explanation:
 * The maximum possible bitwise AND of a subarray is 3.
 * The longest subarray with that value is [3,3], so we return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4]
 * Output: 1
 * Explanation:
 * The maximum possible bitwise AND of a subarray is 4.
 * The longest subarray with that value is [4], so we return 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int>& nums)
    {
        int n = (int) nums.size();
        int maximum = *max_element(nums.begin(), nums.end());

        int res = 0;    // Size of subarray
        int left = -1;  // Last begin index of consecutive maximum subarray
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maximum && left == -1)
                left = i;
            else if (nums[i] != maximum && left != -1)
            {
                res = max(res, i - left);
                left = -1;
            }
        }
        if (left != -1)
            res = max(res, n - left);

        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums1 = { 1, 2, 3, 3, 2, 2 };
    cout << sol.longestSubarray(nums1) << endl;  // Expected output: 2

    // Test_2
    vector<int> nums2 = { 1, 2, 3, 4 };
    cout << sol.longestSubarray(nums2) << endl;  // Expected output: 1

    return 0;
}
// Accepted
// 52/52 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.15 % of cpp submissions (86 MB)