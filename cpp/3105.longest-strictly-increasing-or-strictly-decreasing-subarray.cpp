/*
 * @lc app=leetcode id=3105 lang=cpp
 *
 * [3105] Longest Strictly Increasing or Strictly Decreasing Subarray
 *
 * https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/
 *
 * algorithms
 * Easy (57.03%)
 * Likes:    313
 * Dislikes: 13
 * Total Accepted:    90.1K
 * Total Submissions: 144.1K
 * Testcase Example:  '[1,4,3,3,2]'
 *
 * You are given an array of integers nums. Return the length of the longest
 * subarray of nums which is either strictly increasing or strictly
 * decreasing.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,4,3,3,2]
 *
 * Output: 2
 *
 * Explanation:
 *
 * The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and
 * [1,4].
 *
 * The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4],
 * [3,2], and [4,3].
 *
 * Hence, we return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,3,3,3]
 *
 * Output: 1
 *
 * Explanation:
 *
 * The strictly increasing subarrays of nums are [3], [3], [3], and [3].
 *
 * The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
 *
 * Hence, we return 1.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,2,1]
 *
 * Output: 3
 *
 * Explanation:
 *
 * The strictly increasing subarrays of nums are [3], [2], and [1].
 *
 * The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1],
 * and [3,2,1].
 *
 * Hence, we return 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 50
 * 1 <= nums[i] <= 50
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        int inc = 1, dec = 1;  // Count number of lenght
        const int n = (int) nums.size();

        int res = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                inc++;
                dec = 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                dec++;
                inc = 1;
            }
            else if (nums[i] == nums[i - 1])
            {
                inc = 1;
                dec = 1;
            }
            res = max(res, max(inc, dec));
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 4, 3, 3, 2 };
    int res_1 = sol.longestMonotonicSubarray(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_3
    vector<int> nums_3 = { 3, 3, 3, 3 };
    int res_3 = sol.longestMonotonicSubarray(nums_3);
    cout << res_3 << endl;
    assert(res_3 == 1);

    // Test_4
    vector<int> nums_4 = { 3, 2, 1 };
    int res_4 = sol.longestMonotonicSubarray(nums_4);
    cout << res_4 << endl;
    assert(res_4 == 3);

    return 0;
}
// Accepted
// 868/868 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 64.71 % of cpp submissions (27.8 MB)