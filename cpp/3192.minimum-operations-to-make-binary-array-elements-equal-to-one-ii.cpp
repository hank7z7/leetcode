/*
 * @lc app=leetcode id=3192 lang=cpp
 *
 * [3192] Minimum Operations to Make Binary Array Elements Equal to One II
 *
 * https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/description/
 *
 * algorithms
 * Medium (59.56%)
 * Likes:    5
 * Dislikes: 1
 * Total Accepted:    19.5K
 * Total Submissions: 32.7K
 * Testcase Example:  '[0,1,1,0,1]'
 *
 * You are given a binary array nums.
 *
 * You can do the following operation on the array any number of times
 * (possibly zero):
 *
 *
 * Choose any index i from the array and flip all the elements from index i to
 * the end of the array.
 *
 *
 * Flipping an element means changing its value from 0 to 1, and from 1 to 0.
 *
 * Return the minimum number of operations required to make all elements in
 * nums equal to 1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1,1,0,1]
 *
 * Output: 4
 *
 * Explanation:
 * We can do the following operations:
 *
 *
 * Choose the index i = 1. The resulting array will be nums = [0,0,0,1,0].
 * Choose the index i = 0. The resulting array will be nums = [1,1,1,0,1].
 * Choose the index i = 4. The resulting array will be nums = [1,1,1,0,0].
 * Choose the index i = 3. The resulting array will be nums = [1,1,1,1,1].
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,0,0]
 *
 * Output: 1
 *
 * Explanation:
 * We can do the following operation:
 *
 *
 * Choose the index i = 1. The resulting array will be nums = [1,1,1,1].
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = (int)nums.size();
        int flips = 0;

        // Iterate over the array up to the last element
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] == 0 && flips % 2 == 0) || (nums[i] == 1 && flips % 2 == 1))
                flips++;
        }

        return flips;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {0, 1, 1, 0, 1};
    int res_1 = sol.minOperations(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 4);

    // Test_2
    vector<int> nums_2 = {1, 0, 0, 0};
    int res_2 = sol.minOperations(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    return 0;
}
// Accepted
// 691/691 cases passed (132 ms)
// Your runtime beats 44.44 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (154.9 MB)