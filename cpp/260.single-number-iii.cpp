/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (68.32%)
 * Likes:    5905
 * Dislikes: 247
 * Total Accepted:    386.1K
 * Total Submissions: 556.9K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 *
 * You must write an algorithm that runs in linear runtime complexity and uses
 * only constant extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0]
 * Output: [-1,0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,1]
 * Output: [1,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> result(0);
        // value -> count
        unordered_map<int, int> um;
        for (auto num : nums)
        {
            um[num]++;
        }

        for (auto pair : um)
        {
            if (pair.second == 1)
                result.push_back(pair.first);
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1   = { 1, 2, 1, 3, 2, 5 };
    vector<int> result_1 = sol.singleNumber(nums_1);
    cout << result_1[0] << " " << result_1[1] << endl;

    // Test_2
    vector<int> nums_2   = { -1, 0 };
    vector<int> result_2 = sol.singleNumber(nums_2);
    cout << result_2[0] << " " << result_2[1] << endl;

    // Test_3
    vector<int> nums_3   = { 0, 1 };
    vector<int> result_3 = sol.singleNumber(nums_3);
    cout << result_3[0] << " " << result_3[1] << endl;

    return 0;
}
// Accepted
// 33/33 cases passed (10 ms)
// Your runtime beats 38.25 % of cpp submissions
// Your memory usage beats 18.19 % of cpp submissions (14.2 MB)