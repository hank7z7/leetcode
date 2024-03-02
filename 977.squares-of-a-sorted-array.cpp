/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.80%)
 * Likes:    8982
 * Dislikes: 224
 * Total Accepted:    1.7M
 * Total Submissions: 2.4M
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 *
 *
 *
 * Follow up: Squaring each element and sorting the new array is very trivial,
 * could you find an O(n) solution using a different approach?
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int         l      = 0;
        int         r      = nums.size() - 1;
        int         target = 0;
        vector<int> ret(nums.size(), 0);
        for (int i = ((int) nums.size() - 1); i >= 0; i--)
        {
            if (abs(nums[l]) > abs(nums[r]))
            {
                target = l;
                l++;
            }
            else
            {
                target = r;
                r--;
            }
            ret[i] = pow(abs(nums[target]), 2);
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { -4, -1, 0, 3, 10 };
    for (auto it : sol.sortedSquares(nums_1))
        cout << it << " ";
    cout << endl;

    // Test_2
    vector<int> nums_2 = { -7, -3, 2, 3, 11 };
    for (auto it : sol.sortedSquares(nums_2))
        cout << it << " ";
    cout << endl;
    return 0;
}
// Accepted
// 137/137 cases passed (24 ms)
// Your runtime beats 58.03 % of cpp submissions
// Your memory usage beats 58.32 % of cpp submissions (28.3 MB)