/*
 * @lc app=leetcode id=2364 lang=cpp
 *
 * [2364] Count Number of Bad Pairs
 *
 * https://leetcode.com/problems/count-number-of-bad-pairs/description/
 *
 * algorithms
 * Medium (41.97%)
 * Likes:    1348
 * Dislikes: 40
 * Total Accepted:    88.1K
 * Total Submissions: 176.2K
 * Testcase Example:  '[4,1,3,3]'
 *
 * You are given a 0-indexed integer array nums. A pair of indices (i, j) is a
 * bad pair if i < j and j - i != nums[j] - nums[i].
 *
 * Return the total number of bad pairs in nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [4,1,3,3]
 * Output: 5
 * Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
 * The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
 * The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
 * The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
 * The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
 * There are a total of 5 bad pairs, so we return 5.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4,5]
 * Output: 0
 * Explanation: There are no bad pairs.
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
    long long countBadPairs(vector<int> &nums)
    {
        const long long n = (long long)nums.size();
        // j - i != nums[j] - nums[i]
        // is the same as
        // nums[i] - i != nums[j] - j
        // So track the count of the same nums[i] - i
        long long total = (n * (n - 1)) >> 1;
        // nums[i] - i -> count
        unordered_map<int, long long> um;
        for (int i = 0; i < n; i++)
        {
            um[nums[i] - i]++;
        }

        for (auto &it : um)
            total -= (it.second * (it.second - 1) >> 1);
        return total;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {4, 1, 3, 3};
    long long res_1 = sol.countBadPairs(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 5);

    // Test_2
    vector<int> nums_2 = {1, 2, 3, 4, 5};
    long long res_2 = sol.countBadPairs(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 0);

    return 0;
}
// Accepted
// 65/65 cases passed (67 ms)
// Your runtime beats 67.78 % of cpp submissions
// Your memory usage beats 19.3 % of cpp submissions (92.5 MB)