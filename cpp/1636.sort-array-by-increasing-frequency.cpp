/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 *
 * https://leetcode.com/problems/sort-array-by-increasing-frequency/description/
 *
 * algorithms
 * Easy (71.75%)
 * Likes:    3081
 * Dislikes: 127
 * Total Accepted:    177.4K
 * Total Submissions: 233.9K
 * Testcase Example:  '[1,1,2,2,2,3]'
 *
 * Given an array of integers nums, sort the array in increasing order based on
 * the frequency of the values. If multiple values have the same frequency,
 * sort them in decreasing order.
 *
 * Return the sorted array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2,2,2,3]
 * Output: [3,1,1,2,2,2]
 * Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has
 * a frequency of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3,1,3,2]
 * Output: [1,3,3,2,2]
 * Explanation: '2' and '3' both have a frequency of 2, so they are sorted in
 * decreasing order.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [-1,1,-6,4,5,-6,1,4,1]
 * Output: [5,-1,4,4,-6,-6,1,1,1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * -100 <= nums[i] <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        // num -> count
        unordered_map<int, int> um;
        for (auto num : nums)
            um[num]++;
        sort(nums.begin(),
             nums.end(),
             [&um](const int& a, const int& b)
             {
                 if (um[a] < um[b])
                     return true;
                 else if (um[a] == um[b])
                     return a > b;
                 else
                     return false;
             });
        return nums;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 1, 2, 2, 2, 3 };
    vector<int> res_1  = sol.frequencySort(nums_1);
    for (auto elem : res_1)
        cout << elem << " ";
    cout << endl;
    assert((res_1 == vector<int>{ 3, 1, 1, 2, 2, 2 }));

    // Test_2
    vector<int> nums_2 = { 2, 3, 1, 3, 2 };
    vector<int> res_2  = sol.frequencySort(nums_2);
    for (auto elem : res_2)
        cout << elem << " ";
    cout << endl;
    // assert((res_2 == vector<int>{1,3,3,2,2}));

    // Test_3
    vector<int> nums_3 = { -1, 1, -6, 4, 5, -6, 1, 4, 1 };
    vector<int> res_3  = sol.frequencySort(nums_3);
    for (auto elem : res_3)
        cout << elem << " ";
    cout << endl;
    assert((res_3 == vector<int>{ 5, -1, 4, 4, -6, -6, 1, 1, 1 }));

    return 0;
}
// Accepted
// 180/180 cases passed (6 ms)
// Your runtime beats 58.8 % of cpp submissions
// Your memory usage beats 14.29 % of cpp submissions (15.1 MB)