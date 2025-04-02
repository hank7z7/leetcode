/*
 * @lc app=leetcode id=2874 lang=cpp
 *
 * [2874] Maximum Value of an Ordered Triplet II
 *
 * https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/
 *
 * algorithms
 * Medium (41.01%)
 * Likes:    321
 * Dislikes: 9
 * Total Accepted:    31.5K
 * Total Submissions: 74.7K
 * Testcase Example:  '[12,6,1,2,7]'
 *
 * You are given a 0-indexed integer array nums.
 *
 * Return the maximum value over all triplets of indices (i, j, k) such that i
 * < j < k. If all such triplets have a negative value, return 0.
 *
 * The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j])
 * * nums[k].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [12,6,1,2,7]
 * Output: 77
 * Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) *
 * nums[4] = 77.
 * It can be shown that there are no ordered triplets of indices with a value
 * greater than 77.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,10,3,4,19]
 * Output: 133
 * Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) *
 * nums[4] = 133.
 * It can be shown that there are no ordered triplets of indices with a value
 * greater than 133.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 0
 * Explanation: The only ordered triplet of indices (0, 1, 2) has a negative
 * value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define LL long long
class Solution
{
public:
    LL maximumTripletValue(vector<int>& nums)
    {
        const int n = (int) nums.size();
        vector<LL> max_right(n, LONG_LONG_MIN);
        vector<LL> min_right(n, LONG_LONG_MAX);
        LL max_val = LONG_LONG_MIN, min_val = LONG_LONG_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            max_val = max(max_val, (LL) nums[i]);
            min_val = min(min_val, (LL) nums[i]);
            max_right[i] = max_val;
            min_right[i] = min_val;
        }

        LL max_left = LONG_LONG_MIN, min_left = LONG_LONG_MAX;
        LL res = 0;
        // Iterate the second index
        for (int i = 0; i < n - 1; i++)
        {
            if (i != 0)
            {
                LL curr_max = 0;
                res = max(res, max(curr_max, (max_left - (LL) nums[i]) * max_right[i + 1]));
                res = max(res, max(curr_max, (max_left - (LL) nums[i]) * min_right[i + 1]));
                res = max(res, max(curr_max, (min_left - (LL) nums[i]) * max_right[i + 1]));
                res = max(res, max(curr_max, (min_left - (LL) nums[i]) * min_right[i + 1]));
            }


            // Update max_left and min_left
            max_left = max(max_left, (LL) nums[i]);
            min_left = min(min_left, (LL) nums[i]);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 12, 6, 1, 2, 7 };
    long long res_1 = sol.maximumTripletValue(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 77);

    // Test_2
    vector<int> nums_2 = { 1, 10, 3, 4, 19 };
    long long res_2 = sol.maximumTripletValue(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 133);

    // Test_3
    vector<int> nums_3 = { 1, 2, 3 };
    long long res_3 = sol.maximumTripletValue(nums_3);
    cout << res_3 << endl;
    assert(res_3 == 0);

    // Test_4
    vector<int> nums_4 = { 1000000, 1, 1000000 };
    long long res_4 = sol.maximumTripletValue(nums_4);
    cout << res_4 << endl;
    assert(res_4 == 999999000000);

    return 0;
}
// Accepted
// 599/599 cases passed (19 ms)
// Your runtime beats 8.21 % of cpp submissions
// Your memory usage beats 11.14 % of cpp submissions (105.1 MB)