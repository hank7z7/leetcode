/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (56.09%)
 * Likes:    6360
 * Dislikes: 789
 * Total Accepted:    732.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order and
 * return it.
 *
 * You must solve the problem without using any built-in functions in
 * O(nlog(n)) time complexity and with the smallest space complexity
 * possible.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Explanation: After sorting the array, the positions of some numbers are not
 * changed (for example, 2 and 3), while the positions of other numbers are
 * changed (for example, 1 and 5).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * Explanation: Note that the values of nums are not necessairly unique.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {5, 2, 3, 1};
    vector<int> res_1 = sol.sortArray(nums_1);
    for (auto it : res_1)
        cout << it << " ";
    cout << endl;
    assert((res_1 == vector<int>{1, 2, 3, 5}));

    // Test_2
    vector<int> nums_2 = {5, 1, 1, 2, 0, 0};
    vector<int> res_2 = sol.sortArray(nums_2);
    for (auto it : res_2)
        cout << it << " ";
    cout << endl;
    assert((res_2 == vector<int>{0, 0, 1, 1, 2, 5}));

    return 0;
}
// Accepted
// 21/21 cases passed (93 ms)
// Your runtime beats 82.27 % of cpp submissions
// Your memory usage beats 70.15 % of cpp submissions (70.4 MB)