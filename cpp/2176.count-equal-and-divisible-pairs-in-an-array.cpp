/*
 * @lc app=leetcode id=2176 lang=cpp
 *
 * [2176] Count Equal and Divisible Pairs in an Array
 *
 * https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/
 *
 * algorithms
 * Easy (79.62%)
 * Likes:    812
 * Dislikes: 48
 * Total Accepted:    141.1K
 * Total Submissions: 171.3K
 * Testcase Example:  '[3,1,2,2,2,1,3]\n2'
 *
 * Given a 0-indexed integer array nums of length n and an integer k, return
 * the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] ==
 * nums[j] and (i * j) is divisible by k.
 *
 * Example 1:
 *
 *
 * Input: nums = [3,1,2,2,2,1,3], k = 2
 * Output: 4
 * Explanation:
 * There are 4 pairs that meet all the requirements:
 * - nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
 * - nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
 * - nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
 * - nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4], k = 1
 * Output: 0
 * Explanation: Since no value in nums is repeated, there are no pairs (i,j)
 * that meet all the requirements.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i], k <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countPairs(vector<int>& nums, int k)
    {
        const int n = (int) nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = { 3, 1, 2, 2, 2, 1, 3 };
    int k = 2;
    int res = sol.countPairs(nums, k);
    cout << res << endl;
    assert(res == 4);

    // Test_2
    nums = { 1, 2, 3, 4 };
    k = 1;
    res = sol.countPairs(nums, k);
    cout << res << endl;
    assert(res == 0);

    return 0;
}
// Accepted
// 238/238 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 31.03 % of cpp submissions (15.5 MB)