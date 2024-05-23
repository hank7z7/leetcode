/*
 * @lc app=leetcode id=2597 lang=cpp
 *
 * [2597] The Number of Beautiful Subsets
 *
 * https://leetcode.com/problems/the-number-of-beautiful-subsets/description/
 *
 * algorithms
 * Medium (33.49%)
 * Likes:    885
 * Dislikes: 145
 * Total Accepted:    66.3K
 * Total Submissions: 144.6K
 * Testcase Example:  '[2,4,6]\n2'
 *
 * You are given an array nums of positive integers and a positive integer k.
 *
 * A subset of nums is beautiful if it does not contain two integers with an
 * absolute difference equal to k.
 *
 * Return the number of non-empty beautiful subsets of the array nums.
 *
 * A subset of nums is an array that can be obtained by deleting some (possibly
 * none) elements from nums. Two subsets are different if and only if the
 * chosen indices to delete are different.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,4,6], k = 2
 * Output: 4
 * Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2,
 * 6].
 * It can be proved that there are only 4 beautiful subsets in the array
 * [2,4,6].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: 1
 * Explanation: The beautiful subset of the array nums is [1].
 * It can be proved that there is only 1 beautiful subset in the array [1].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 20
 * 1 <= nums[i], k <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int beautifulSubsets(vector<int>& nums, int k)
    {
        int                     result = 1;
        map<int, map<int, int>> freq;
        for (int& num : nums)
        {
            freq[num % k][num]++;
        }
        for (auto& fr : freq)
        {
            int prevNum = -k, prev2, prev1 = 1, curr;
            for (auto& [num, f] : fr.second)
            {
                int skip = prev1;
                int take = ((1 << f) - 1) * (num - prevNum == k ? prev2 : prev1);
                curr     = skip + take;
                prev2    = prev1;
                prev1    = curr;
                prevNum  = num;
            }
            result *= curr;
        }
        return result - 1;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 2, 4, 6 };
    int         k_1    = 2;
    cout << sol.beautifulSubsets(nums_1, k_1) << endl;

    // Test_2
    vector<int> nums_2 = { 1 };
    int         k_2    = 1;
    cout << sol.beautifulSubsets(nums_2, k_2) << endl;

    // Test_3
    vector<int> nums_3 = { 590, 136, 844, 976, 670, 485,  794, 114, 434, 82,
                           245, 673, 738, 416, 252, 1000, 518, 520, 1,   622 };
    int         k_3    = 999;
    cout << sol.beautifulSubsets(nums_3, k_3) << endl;

    return 0;
}
