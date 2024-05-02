/*
 * @lc app=leetcode id=2441 lang=cpp
 *
 * [2441] Largest Positive Integer That Exists With Its Negative
 *
 * https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/
 *
 * algorithms
 * Easy (68.15%)
 * Likes:    583
 * Dislikes: 16
 * Total Accepted:    75.9K
 * Total Submissions: 107.5K
 * Testcase Example:  '[-1,2,-3,3]'
 *
 * Given an integer array nums that does not contain any zeros, find the
 * largest positive integer k such that -k also exists in the array.
 *
 * Return the positive integer k. If there is no such integer, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,-3,3]
 * Output: 3
 * Explanation: 3 is the only valid k we can find in the array.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,10,6,7,-7,1]
 * Output: 7
 * Explanation: Both 1 and 7 have their corresponding negative values in the
 * array. 7 has a larger value.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [-10,8,6,7,-2,-3]
 * Output: -1
 * Explanation: There is no a single valid k, we return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * nums[i] != 0
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMaxK(vector<int>& nums)
    {
        // set to record value
        unordered_set<int> us;
        int                result = INT_MIN;
        for (auto num : nums)
        {
            if (us.find(num * -1) != us.end())
                result = max(result, abs(num));
            else
                us.insert(num);
        }
        return result == INT_MIN ? -1 : result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { -1, 2, -3, 3 };
    cout << sol.findMaxK(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = { -1, 10, 6, 7, -7, 1 };
    cout << sol.findMaxK(nums_2) << endl;

    // Test_3
    vector<int> nums_3 = { -10, 8, 6, 7, -2, -3 };
    cout << sol.findMaxK(nums_3) << endl;

    return 0;
}
// Accepted
// 337/337 cases passed (22 ms)
// Your runtime beats 41.5 % of cpp submissions
// Your memory usage beats 26.52 % of cpp submissions (26.1 MB)