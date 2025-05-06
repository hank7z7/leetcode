/*
 * @lc app=leetcode id=1920 lang=cpp
 *
 * [1920] Build Array from Permutation
 *
 * https://leetcode.com/problems/build-array-from-permutation/description/
 *
 * algorithms
 * Easy (90.22%)
 * Likes:    3525
 * Dislikes: 428
 * Total Accepted:    633.1K
 * Total Submissions: 701K
 * Testcase Example:  '[0,2,1,5,3,4]'
 *
 * Given a zero-based permutation nums (0-indexed), build an array ans of the
 * same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and
 * return it.
 *
 * A zero-based permutation nums is an array of distinct integers from 0 to
 * nums.length - 1 (inclusive).
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,2,1,5,3,4]
 * Output: [0,1,2,4,5,3]
 * Explanation: The array ans is built as follows:
 * ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]],
 * nums[nums[4]], nums[nums[5]]]
 * ⁠   = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
 * ⁠   = [0,1,2,4,5,3]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,0,1,2,3,4]
 * Output: [4,5,0,1,2,3]
 * Explanation: The array ans is built as follows:
 * ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]],
 * nums[nums[4]], nums[nums[5]]]
 * ⁠   = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
 * ⁠   = [4,5,0,1,2,3]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] < nums.length
 * The elements in nums are distinct.
 *
 *
 *
 * Follow-up: Can you solve it without using an extra space (i.e., O(1)
 * memory)?
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> buildArray(vector<int>& nums)
    {
        const int n = (int) nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = nums[nums[i]];
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = { 0, 2, 1, 5, 3, 4 };
    vector<int> res = sol.buildArray(nums);
    for (auto num : res)
        cout << num << " ";
    cout << endl;
    assert(res == vector<int>({ 0, 1, 2, 4, 5, 3 }));

    // Test_2
    nums = { 5, 0, 1, 2, 3, 4 };
    res = sol.buildArray(nums);
    for (auto num : res)
        cout << num << " ";
    cout << endl;
    assert(res == vector<int>({ 4, 5, 0, 1, 2, 3 }));

    return 0;
}
// Accepted
// 140/140 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 39.42 % of cpp submissions (20.5 MB)