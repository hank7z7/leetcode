/*
 * @lc app=leetcode id=3432 lang=cpp
 *
 * [3432] Count Partitions with Even Sum Difference
 *
 * https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/
 *
 * algorithms
 * Easy (73.62%)
 * Likes:    264
 * Dislikes: 8
 * Total Accepted:    105.7K
 * Total Submissions: 128.2K
 * Testcase Example:  '[10,10,3,7,6]'
 *
 * You are given an integer array nums of length n.
 *
 * A partition is defined as an index i where 0 <= i < n - 1, splitting the
 * array into two non-empty subarrays such that:
 *
 *
 * Left subarray contains indices [0, i].
 * Right subarray contains indices [i + 1, n - 1].
 *
 *
 * Return the number of partitions where the difference between the sum of the
 * left and right subarrays is even.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,10,3,7,6]
 *
 * Output: 4
 *
 * Explanation:
 *
 * The 4 partitions are:
 *
 *
 * [10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is
 * even.
 * [10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
 * [10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is
 * even.
 * [10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,2]
 *
 * Output: 0
 *
 * Explanation:
 *
 * No partition results in an even sum difference.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [2,4,6,8]
 *
 * Output: 3
 *
 * Explanation:
 *
 * All partitions result in an even sum difference.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n == nums.length <= 100
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
    int countPartitions(vector<int>& nums)
    {
        const int n = (int) nums.size();
        int left_odd_count = 0;
        int right_odd_count = 0;
        for (int i = 0; i < 1; i++)
            if (nums[i] % 2 == 1)
            left_odd_count++;
        for (int i = 1; i < n; i++)
            if (nums[i] % 2 == 1)
                right_odd_count++;
        if ((left_odd_count % 2) == (right_odd_count % 2))
            return n - 1;
        else
            return 0;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = { 10, 10, 3, 7, 6 };
    int res = sol.countPartitions(nums);
    cout << res << endl;
    assert(res == 4);

    // Test_2
    nums = { 1, 2, 2 };
    res = sol.countPartitions(nums);
    cout << res << endl;
    assert(res == 0);

    // Test_3
    nums = { 2, 4, 6, 8 };
    res = sol.countPartitions(nums);
    cout << res << endl;
    assert(res == 3);

    return 0;
}
// Accepted
// 616/616 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 53.79 % of cpp submissions (22.4 MB)