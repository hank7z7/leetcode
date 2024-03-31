/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 *
 * https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
 *
 * algorithms
 * Hard (63.14%)
 * Likes:    2499
 * Dislikes: 58
 * Total Accepted:    74K
 * Total Submissions: 116.8K
 * Testcase Example:  '[1,3,5,2,7,5]\n1\n5'
 *
 * You are given an integer array nums and two integers minK and maxK.
 *
 * A fixed-bound subarray of nums is a subarray that satisfies the following
 * conditions:
 *
 *
 * The minimum value in the subarray is equal to minK.
 * The maximum value in the subarray is equal to maxK.
 *
 *
 * Return the number of fixed-bound subarrays.
 *
 * A subarray is a contiguous part of an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
 * Output: 2
 * Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,1,1,1], minK = 1, maxK = 1
 * Output: 10
 * Explanation: Every subarray of nums is a fixed-bound subarray. There are 10
 * possible subarrays.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^5
 * 1 <= nums[i], minK, maxK <= 10^6
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ret = 0;
        int last_split = -1, l = -1, r = -1;

        for (int i = 0; i < (int)nums.size(); ++i)
        {
            if (!(minK <= nums[i] && nums[i] <= maxK))
                last_split = i;

            if (nums[i] == minK)
                l = i;

            if (nums[i] == maxK)
                r = i;

            ret += max(0, min(l, r) - last_split);
        }

        return ret;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 3, 5, 2, 7, 5};
    int minK_1 = 1;
    int maxK_1 = 5;
    cout << sol.countSubarrays(nums_1, minK_1, maxK_1) << endl;

    // Test_2
    vector<int> nums_2 = {1, 1, 1, 1};
    int minK_2 = 1;
    int maxK_2 = 1;
    cout << sol.countSubarrays(nums_2, minK_2, maxK_2) << endl;

    return 0;
}
// Accepted
// 52/52 cases passed (78 ms)
// Your runtime beats 93.35 % of cpp submissions
// Your memory usage beats 53.99 % of cpp submissions (82.6 MB)