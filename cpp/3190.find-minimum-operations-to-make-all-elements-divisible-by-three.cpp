/*
 * @lc app=leetcode id=3190 lang=cpp
 *
 * [3190] Find Minimum Operations to Make All Elements Divisible by Three
 *
 * https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/
 *
 * algorithms
 * Easy (86.57%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 33.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * You are given an integer array nums. In one operation, you can add or
 * subtract 1 from any element of nums.
 *
 * Return the minimum number of operations to make all elements of nums
 * divisible by 3.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,4]
 *
 * Output: 3
 *
 * Explanation:
 *
 * All array elements can be made divisible by 3 using 3 operations:
 *
 *
 * Subtract 1 from 1.
 * Add 1 to 2.
 * Subtract 1 from 4.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,6,9]
 *
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 50
 * 1 <= nums[i] <= 50
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int count = 0;
        for (auto &num : nums)
        {
            if ((num % 3) != 0)
                count += 1;
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 2, 3, 4};
    int res_1 = sol.minimumOperations(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    vector<int> nums_2 = {3, 6, 9};
    int res_2 = sol.minimumOperations(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 0);

    return 0;
}
// Accepted
// 660/660 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 16.67 % of cpp submissions (22 MB)