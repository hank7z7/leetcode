/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.20%)
 * Likes:    16862
 * Dislikes: 272
 * Total Accepted:    1.9M
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        result.push_back({});
        for (auto num : nums)
        {
            int size = (int) result.size();
            for (int i = 0; i < size; i++)
            {
                vector<int> new_vec = result[i];
                new_vec.push_back(num);
                result.push_back(new_vec);
            }
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int>         nums_1   = { 1, 2, 3 };
    vector<vector<int>> result_1 = sol.subsets(nums_1);
    cout << "[";
    for (auto& vec : result_1)
    {
        cout << "[";
        for (auto& num : vec)
        {
            cout << num;
            if (&num != &vec.back())
                cout << ", ";
        }
        cout << "]";
        if (&vec != &result_1.back())
            cout << ",";
    }
    cout << "]";
    cout << endl;

    // Test_2
    vector<int>         nums_2   = { 0 };
    vector<vector<int>> result_2 = sol.subsets(nums_2);
    cout << "[";
    for (auto& vec : result_2)
    {
        cout << "[";
        for (auto& num : vec)
        {
            cout << num;
            if (&num != &vec.back())
                cout << ", ";
        }
        cout << "]";
        if (&vec != &result_2.back())
            cout << ",";
    }
    cout << "]";
    cout << endl;

    return 0;
}
// Accepted
// 10/10 cases passed (4 ms)
// Your runtime beats 39.89 % of cpp submissions
// Your memory usage beats 62.9 % of cpp submissions (8.4 MB)