/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 *
 * https://leetcode.com/problems/max-number-of-k-sum-pairs/description/
 *
 * algorithms
 * Medium (55.12%)
 * Likes:    2984
 * Dislikes: 76
 * Total Accepted:    246.3K
 * Total Submissions: 447.5K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * You are given an integer array nums and an integer k.
 *
 * In one operation, you can pick two numbers from the array whose sum equals k
 * and remove them from the array.
 *
 * Return the maximum number of operations you can perform on the array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,4], k = 5
 * Output: 2
 * Explanation: Starting with nums = [1,2,3,4]:
 * - Remove numbers 1 and 4, then nums = [2,3]
 * - Remove numbers 2 and 3, then nums = []
 * There are no more pairs that sum up to 5, hence a total of 2 operations.
 *
 * Example 2:
 *
 *
 * Input: nums = [3,1,3,4,3], k = 6
 * Output: 1
 * Explanation: Starting with nums = [3,1,3,4,3]:
 * - Remove the first two 3's, then nums = [1,4,3]
 * There are no more pairs that sum up to 6, hence a total of 1 operation.
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxOperations(vector<int>& nums, int k)
    {
        int                     count = 0;
        unordered_map<int, int> um;
        for (auto num : nums)
        {
            if (num <= k && um.find(k - num) != um.end() && um[k - num] > 0)
            {
                count++;
                um[k - num]--;
            }
            else
            {
                um[num]++;
            }
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      k;
    // Test_1
    k                  = 5;
    vector<int> nums_1 = { 1, 2, 3, 4 };
    cout << sol.maxOperations(nums_1, k) << endl;

    // Test_2
    k                  = 6;
    vector<int> nums_2 = { 3, 1, 3, 4, 3 };
    cout << sol.maxOperations(nums_2, k) << endl;

    // Test_3
    k                  = 6;
    vector<int> nums_3 = { 3, 1, 3, 4, 3 };
    cout << sol.maxOperations(nums_3, k) << endl;
    return 0;
}
// Accepted
// 51/51 cases passed (91 ms)
// Your runtime beats 73.3 % of cpp submissions
// Your memory usage beats 29.59 % of cpp submissions (69 MB)