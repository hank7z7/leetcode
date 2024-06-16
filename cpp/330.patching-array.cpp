/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 *
 * https://leetcode.com/problems/patching-array/description/
 *
 * algorithms
 * Hard (41.85%)
 * Likes:    1936
 * Dislikes: 162
 * Total Accepted:    108.7K
 * Total Submissions: 225.7K
 * Testcase Example:  '[1,3]\n6'
 *
 * Given a sorted integer array nums and an integer n, add/patch elements to
 * the array such that any number in the range [1, n] inclusive can be formed
 * by the sum of some elements in the array.
 *
 * Return the minimum number of patches required.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3], n = 6
 * Output: 1
 * Explanation:
 * Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3,
 * 4.
 * Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3],
 * [2,3], [1,2,3].
 * Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
 * So we only need 1 patch.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,5,10], n = 20
 * Output: 2
 * Explanation: The two patches can be [2, 4].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,2], n = 5
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^4
 * nums is sorted in ascending order.
 * 1 <= n <= 2^31 - 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int patches = 0;
        int index = 0;
        long long nextSum = 1;

        while (nextSum <= n)
        {
            if (index < (int)nums.size() && nums[index] <= nextSum)
            {
                nextSum += nums[index++];
            }
            else
            {
                nextSum += nextSum;
                patches++;
            }
        }

        return patches;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 3};
    int n_1 = 6;
    int result_1 = sol.minPatches(nums_1, n_1);
    cout << result_1 << endl;
    assert(result_1 == 1);

    // Test_2
    vector<int> nums_2 = {1,5,10};
    int n_2 = 20;
    int result_2 = sol.minPatches(nums_2, n_2);
    cout << result_2 << endl;
    assert(result_2 == 2);

    // Test_3
    vector<int> nums_3 = {1, 2, 2};
    int n_3 = 5;
    int result_3 = sol.minPatches(nums_3, n_3);
    cout << result_3 << endl;
    assert(result_3 == 0);

    return 0;
}
// Accepted
// 146/146 cases passed (6 ms)
// Your runtime beats 36.72 % of cpp submissions
// Your memory usage beats 12.3 % of cpp submissions (13.8 MB)