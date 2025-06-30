/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (56.58%)
 * Likes:    2517
 * Dislikes: 319
 * Total Accepted:    267.1K
 * Total Submissions: 437.2K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 *
 * Given an integer array nums, return the length of its longest harmonious
 * subsequence among all its possible subsequences.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,2,2,5,2,3,7]
 *
 * Output: 5
 *
 * Explanation:
 *
 * The longest harmonious subsequence is [3,2,2,2,3].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4]
 *
 * Output: 2
 *
 * Explanation:
 *
 * The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of
 * which have a length of 2.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,1,1]
 *
 * Output: 0
 *
 * Explanation:
 *
 * No harmonic subsequence exists.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findLHS(vector<int>& nums)
    {
        int res = 0;
        const int n = (int) nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        for (auto& [num, count] : freq)
        {
            if (freq.count(num + 1))
            {
                res = max(res, count + freq[num + 1]);
            }
        }
        return res;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // Test_1
    vector<int> nums = { 1, 3, 2, 2, 5, 2, 3, 7 };
    int result = sol.findLHS(nums);
    cout << result << endl;  // Expected output: 5
    assert(result == 5);

    // Test_2
    nums = { 1, 2, 3, 4 };
    result = sol.findLHS(nums);
    cout << result << endl;  // Expected output: 2
    assert(result == 2);

    // Test_3
    nums = { 1, 1, 1, 1 };
    result = sol.findLHS(nums);
    cout << result << endl;  // Expected output: 0
    assert(result == 0);

    return 0;
}
// Accepted