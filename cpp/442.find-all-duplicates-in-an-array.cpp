/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (73.67%)
 * Likes:    9654
 * Dislikes: 352
 * Total Accepted:    625.4K
 * Total Submissions: 845.5K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an integer array nums of length n where all the integers of nums are
 * in the range [1, n] and each integer appears once or twice, return an array
 * of all the integers that appears twice.
 *
 * You must write an algorithm that runs in O(n) time and uses only constant
 * extra space.
 *
 *
 * Example 1:
 * Input: nums = [4,3,2,7,8,2,3,1]
 * Output: [2,3]
 * Example 2:
 * Input: nums = [1,1,2]
 * Output: [1]
 * Example 3:
 * Input: nums = [1]
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 * Each element in nums appears once or twice.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        unordered_map<int, int> um;
        vector<int>             ret;
        for (auto num : nums)
        {
            if (um.find(num) != um.end())
                ret.push_back(num);
            else
                um[num]++;
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 4, 3, 2, 7, 8, 2, 3, 1 };
    for (auto it : sol.findDuplicates(nums_1))
        cout << it << " ";
    cout << endl;

    // Test_2
    vector<int> nums_2 = { 1, 1, 2 };
    for (auto it : sol.findDuplicates(nums_2))
        cout << it << " ";
    cout << endl;

    // Test_3
    vector<int> nums_3 = { 1 };
    for (auto it : sol.findDuplicates(nums_3))
        cout << it << " ";
    cout << endl;
    return 0;
}
// Accepted
// 28/28 cases passed (74 ms)
// Your runtime beats 23.81 % of cpp submissions
// Your memory usage beats 21.59 % of cpp submissions (48.1 MB)