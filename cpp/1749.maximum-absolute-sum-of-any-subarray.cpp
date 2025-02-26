/*
 * @lc app=leetcode id=1749 lang=cpp
 *
 * [1749] Maximum Absolute Sum of Any Subarray
 *
 * https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/
 *
 * algorithms
 * Medium (60.70%)
 * Likes:    1740
 * Dislikes: 33
 * Total Accepted:    130.1K
 * Total Submissions: 185K
 * Testcase Example:  '[1,-3,2,3,-4]'
 *
 * You are given an integer array nums. The absolute sum of a subarray [numsl,
 * numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 +
 * numsr).
 *
 * Return the maximum absolute sum of any (possibly empty) subarray of nums.
 *
 * Note that abs(x) is defined as follows:
 *
 *
 * If x is a negative integer, then abs(x) = -x.
 * If x is a non-negative integer, then abs(x) = x.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,-3,2,3,-4]
 * Output: 5
 * Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,-5,1,-4,3,-2]
 * Output: 8
 * Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8)
 * = 8.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        const int n = (int)nums.size();
        int curr_sum = 0;
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            curr_sum += nums[i];
            max_sum = max(max_sum, curr_sum);
            min_sum = min(min_sum, curr_sum);
        }
        int res = 0;
        res = max(res, abs(max_sum));
        res = max(res, abs(min_sum));
        res = max(res, abs(max_sum - min_sum));

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, -3, 2, 3, -4};
    int res_1 = sol.maxAbsoluteSum(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 5);

    // Test_2
    vector<int> nums_2 = {2, -5, 1, -4, 3, -2};
    int res_2 = sol.maxAbsoluteSum(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 8);

    return 0;
}
// Accepted
// 66/66 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 78.26 % of cpp submissions (45 MB)