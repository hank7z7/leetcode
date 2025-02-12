/*
 * @lc app=leetcode id=2342 lang=cpp
 *
 * [2342] Max Sum of a Pair With Equal Sum of Digits
 *
 * https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
 *
 * algorithms
 * Medium (55.18%)
 * Likes:    835
 * Dislikes: 29
 * Total Accepted:    78.9K
 * Total Submissions: 131.2K
 * Testcase Example:  '[18,43,36,13,7]'
 *
 * You are given a 0-indexed array nums consisting of positive integers. You
 * can choose two indices i and j, such that i != j, and the sum of digits of
 * the number nums[i] is equal to that of nums[j].
 *
 * Return the maximum value of nums[i] + nums[j] that you can obtain over all
 * possible indices i and j that satisfy the conditions.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [18,43,36,13,7]
 * Output: 54
 * Explanation: The pairs (i, j) that satisfy the conditions are:
 * - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18
 * + 36 = 54.
 * - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43
 * + 7 = 50.
 * So the maximum sum that we can obtain is 54.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [10,12,19,14]
 * Output: -1
 * Explanation: There are no two numbers that satisfy the conditions, so we
 * return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumSum(vector<int>& nums)
    {
        const int n = (int) nums.size();
        unordered_map<int, vector<int>> um;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int x = nums[i]; x > 0; x /= 10)
            {
                sum += x % 10;
            }
            um[sum].push_back(nums[i]);
        }

        int res = -1;
        for (auto& [sum, vec] : um)
        {
            if (vec.size() < 2)
            {
                continue;
            }
            sort(vec.begin(), vec.end());
            res = max(res, vec[vec.size() - 1] + vec[vec.size() - 2]);
        }
        return res;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 18, 43, 36, 13, 7 };
    int res_1 = sol.maximumSum(nums_1);  // 54
    cout << res_1 << endl;
    assert(res_1 == 54);

    // Test_2
    vector<int> nums_2 = { 10, 12, 19, 14 };
    int res_2 = sol.maximumSum(nums_2);  // -1
    cout << res_2 << endl;
    assert(res_2 == -1);

    return 0;
}
// Accepted
// 83/83 cases passed (35 ms)
// Your runtime beats 42.73 % of cpp submissions
// Your memory usage beats 35.53 % of cpp submissions (71.7 MB)