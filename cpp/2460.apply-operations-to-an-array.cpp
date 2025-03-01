/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 *
 * https://leetcode.com/problems/apply-operations-to-an-array/description/
 *
 * algorithms
 * Easy (68.51%)
 * Likes:    927
 * Dislikes: 52
 * Total Accepted:    182.6K
 * Total Submissions: 245.5K
 * Testcase Example:  '[1,2,2,1,1,0]'
 *
 * You are given a 0-indexed array nums of size n consisting of non-negative
 * integers.
 *
 * You need to apply n - 1 operations to this array where, in the i^th
 * operation (0-indexed), you will apply the following on the i^th element of
 * nums:
 *
 *
 * If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to
 * 0. Otherwise, you skip this operation.
 *
 *
 * After performing all the operations, shift all the 0's to the end of the
 * array.
 *
 *
 * For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end,
 * is [1,2,1,0,0,0].
 *
 *
 * Return the resulting array.
 *
 * Note that the operations are applied sequentially, not all at once.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,2,1,1,0]
 * Output: [1,4,2,0,0,0]
 * Explanation: We do the following operations:
 * - i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
 * - i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and change
 * nums[2] to 0. The array becomes [1,4,0,1,1,0].
 * - i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
 * - i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and change
 * nums[4] to 0. The array becomes [1,4,0,2,0,0].
 * - i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and change
 * nums[5] to 0. The array becomes [1,4,0,2,0,0].
 * After that, we shift the 0's to the end, which gives the array
 * [1,4,2,0,0,0].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1]
 * Output: [1,0]
 * Explanation: No operation can be applied, we just shift the 0 to the
 * end.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 2000
 * 0 <= nums[i] <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        const int n = (int)nums.size();
        int writeIndex = 0; // Pointer to place non-zero elements

        for (int index = 0; index < n; index++)
        {
            // Step 1: Merge adjacent equal elements if they are non-zero
            if (index < n - 1 && nums[index] == nums[index + 1] &&
                nums[index] != 0)
            {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }

            // Step 2: Shift non-zero elements to the front
            if (nums[index] != 0)
            {
                if (index != writeIndex)
                {
                    swap(nums[index], nums[writeIndex]);
                }
                writeIndex++;
            }
        }

        return nums;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 2, 2, 1, 1, 0};
    vector<int> res_1 = sol.applyOperations(nums_1);
    for (auto &it : res_1)
        cout << it << " ";
    cout << endl;
    assert((res_1 == vector<int>{1, 4, 2, 0, 0, 0}));

    // Test_2
    vector<int> nums_2 = {0, 1};
    vector<int> res_2 = sol.applyOperations(nums_2);
    for (auto &it : res_2)
        cout << it << " ";
    cout << endl;
    assert((res_2 == vector<int>{1, 0}));

    return 0;
}
