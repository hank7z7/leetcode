/*
 * @lc app=leetcode id=3224 lang=cpp
 *
 * [3224] Minimum Array Changes to Make Differences Equal
 *
 * https://leetcode.com/problems/minimum-array-changes-to-make-differences-equal/description/
 *
 * algorithms
 * Medium (14.44%)
 * Likes:    34
 * Dislikes: 4
 * Total Accepted:    5.2K
 * Total Submissions: 35.9K
 * Testcase Example:  '[1,0,1,2,4,3]\n4'
 *
 * You are given an integer array nums of size n where n is even, and an
 * integer k.
 *
 * You can perform some changes on the array, where in one change you can
 * replace any element in the array with any integer in the range from 0 to k.
 *
 * You need to perform some changes (possibly none) such that the final array
 * satisfies the following condition:
 *
 *
 * There exists an integer X such that abs(a[i] - a[n - i - 1]) = X for all (0
 * <= i < n).
 *
 *
 * Return the minimum number of changes required to satisfy the above
 * condition.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,0,1,2,4,3], k = 4
 *
 * Output: 2
 *
 * Explanation:
 * We can perform the following changes:
 *
 *
 * Replace nums[1] by 2. The resulting array is nums = [1,2,1,2,4,3].
 * Replace nums[3] by 3. The resulting array is nums = [1,2,1,3,4,3].
 *
 *
 * The integer X will be 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,2,3,3,6,5,4], k = 6
 *
 * Output: 2
 *
 * Explanation:
 * We can perform the following operations:
 *
 *
 * Replace nums[3] by 0. The resulting array is nums = [0,1,2,0,3,6,5,4].
 * Replace nums[4] by 4. The resulting array is nums = [0,1,2,0,4,6,5,4].
 *
 *
 * The integer X will be 4.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n == nums.length <= 10^5
 * n is even.
 * 0 <= nums[i] <= k <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minChanges(vector<int> &nums, int k)
    {
        int n = (int)nums.size();
        vector<int> diff(n / 2, 0);
        // diff -> count
        unordered_map<int, int> diff_count;
        // Record the min and max of the pair index = {i, n - 1 -i}
        vector<int> nums_min(n / 2);
        vector<int> nums_max(n / 2);
        for (int i = 0; i < (n / 2); i++)
        {
            diff[i] = abs(nums[i] - nums[n - 1 - i]);
            diff_count[diff[i]]++;
            nums_min[i] = min(nums[i], nums[n - 1 - i]);
            nums_max[i] = max(nums[i], nums[n - 1 - i]);
        }

        int res = INT_MAX;
        for (auto d : diff_count)
        {
            int target_diff = d.first;
            if ((n / 2 - d.second) > res)
                continue;

            int changes = 0;
            for (int i = 0; i < (n / 2); i++)
            {
                if (diff[i] != target_diff)
                {
                    if (((nums_min[i] + target_diff) <= k) ||
                        ((nums_max[i] - target_diff) >= 0))
                    {
                        changes += 1;
                    }
                    else
                    {
                        changes += 2;
                    }
                    // Early return
                    if (changes > res)
                        break;
                }
            }
            res = min(res, changes);
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 0, 1, 2, 4, 3};
    int k_1 = 4;
    int res_1 = sol.minChanges(nums_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    vector<int> nums_2 = {0, 1, 2, 3, 3, 6, 5, 4};
    int k_2 = 6;
    int res_2 = sol.minChanges(nums_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    // Test_3
    vector<int> nums_3 = {1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0};
    int k_3 = 1;
    int res_3 = sol.minChanges(nums_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == 4);

    // Test_4
    vector<int> nums_4 = {1, 10, 5, 1, 4, 6, 4, 2, 4, 9, 7, 9, 0, 11};
    int k_4 = 12;
    int res_4 = sol.minChanges(nums_4, k_4);
    cout << res_4 << endl;
    assert(res_4 == 5);

    // Test_5
    vector<int> nums_5 = {7, 0, 3, 7, 3, 10, 2, 11, 7, 8, 7, 5};
    int k_5 = 14;
    int res_5 = sol.minChanges(nums_5, k_5);
    cout << res_5 << endl;
    assert(res_5 == 5);

    // Test_6
    vector<int> nums_6 = {0, 7, 10, 16, 7, 2, 6, 14, 6, 16, 4, 18, 9, 8};
    int k_6 = 19;
    int res_6 = sol.minChanges(nums_6, k_6);
    cout << res_6 << endl;
    assert(res_6 == 4);

    return 0;
}
// Accepted
// 681/681 cases passed (413 ms)
// Your runtime beats 25 % of cpp submissions
// Your memory usage beats 75 % of cpp submissions (109.9 MB)