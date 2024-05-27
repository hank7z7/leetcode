/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 *
 * https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/
 *
 * algorithms
 * Easy (60.06%)
 * Likes:    1649
 * Dislikes: 282
 * Total Accepted:    89K
 * Total Submissions: 146.1K
 * Testcase Example:  '[3,5]'
 *
 * You are given an array nums of non-negative integers. nums is considered
 * special if there exists a number x such that there are exactly x numbers in
 * nums that are greater than or equal to x.
 *
 * Notice that x does not have to be an element in nums.
 *
 * Return x if the array is special, otherwise, return -1. It can be proven
 * that if nums is special, the value for x is unique.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,5]
 * Output: 2
 * Explanation: There are 2 values (3 and 5) that are greater than or equal to
 * 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0]
 * Output: -1
 * Explanation: No numbers fit the criteria for x.
 * If x = 0, there should be 0 numbers >= x, but there are 2.
 * If x = 1, there should be 1 number >= x, but there are 0.
 * If x = 2, there should be 2 numbers >= x, but there are 0.
 * x cannot be greater since there are only 2 numbers in nums.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,4,3,0,4]
 * Output: 3
 * Explanation: There are 3 values that are greater than or equal to 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
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
    int specialArray(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n      = (int) nums.size();
        int result = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] >= (n - i))
            {
                result = (n - i);
            }
            else if (nums[i] == result)
            {
                result = -1;
                break;
            }
            else
                break;
        }
        return result;
    }
};

// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1   = { 3, 5 };
    int         result_1 = sol.specialArray(nums_1);
    cout << result_1 << endl;
    assert(result_1 == 2);

    // Test_2
    vector<int> nums_2   = { 0, 0 };
    int         result_2 = sol.specialArray(nums_2);
    cout << result_2 << endl;
    assert(result_2 == -1);

    // Test_3
    vector<int> nums_3   = { 3, 6, 7, 7, 0 };
    int         result_3 = sol.specialArray(nums_3);
    cout << result_3 << endl;
    assert(result_3 == -1);

    // Test_4
    vector<int> nums_4   = { 0, 4, 3, 0, 4 };
    int         result_4 = sol.specialArray(nums_4);
    cout << result_4 << endl;
    assert(result_4 == 3);

    return 0;
}

// Accepted
// 98/98 cases passed (5 ms)
// Your runtime beats 33.11 % of cpp submissions
// Your memory usage beats 19.8 % of cpp submissions (10.3 MB)
