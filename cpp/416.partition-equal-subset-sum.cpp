/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (47.22%)
 * Likes:    12942
 * Dislikes: 270
 * Total Accepted:    1.1M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given an integer array nums, return true if you can partition the array into
 * two subsets such that the sum of the elements in both subsets is equal or
 * false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;

        // DP
        unordered_set<int> set;
        set.insert(0);
        for (int num : nums)
        {
            vector<int> new_set;
            for (auto& it : set)
            {
                if ((it + num) == target)
                    return true;
                new_set.push_back(it + num);
            }
            for (auto& it : new_set)
                set.insert(it);
        }

        // Don't need to check if target is in set
        // if(set.find(target) != set.end())
        //     return true;
        return false;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 5, 11, 5 };
    bool res_1 = sol.canPartition(nums_1);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    vector<int> nums_2 = { 1, 2, 3, 5 };
    bool res_2 = sol.canPartition(nums_2);
    cout << res_2 << endl;
    assert(res_2 == false);

    // Test_3
    vector<int> nums_3 = { 1, 2, 3, 4, 5 };
    bool res_3 = sol.canPartition(nums_3);
    cout << res_3 << endl;
    assert(res_3 == false);

    // Test_4
    vector<int> nums_4 = { 1, 2, 3, 4, 5, 6 };
    bool res_4 = sol.canPartition(nums_4);
    cout << res_4 << endl;
    assert(res_4 == false);

    // Test_5
    vector<int> nums_5
        = { 4,  4,  4,  4,  4,  4,  4,  4,  8,  8,  8,  8,  8,  8,  8,  8,  12, 12, 12, 12, 12, 12,
            12, 12, 16, 16, 16, 16, 16, 16, 16, 16, 20, 20, 20, 20, 20, 20, 20, 20, 24, 24, 24, 24,
            24, 24, 24, 24, 28, 28, 28, 28, 28, 28, 28, 28, 32, 32, 32, 32, 32, 32, 32, 32, 36, 36,
            36, 36, 36, 36, 36, 36, 40, 40, 40, 40, 40, 40, 40, 40, 44, 44, 44, 44, 44, 44, 44, 44,
            48, 48, 48, 48, 48, 48, 48, 48, 52, 52, 52, 52, 52, 52, 52, 52, 56, 56, 56, 56, 56, 56,
            56, 56, 60, 60, 60, 60, 60, 60, 60, 60, 64, 64, 64, 64, 64, 64, 64, 64, 68, 68, 68, 68,
            68, 68, 68, 68, 72, 72, 72, 72, 72, 72, 72, 72, 76, 76, 76, 76, 76, 76, 76, 76, 80, 80,
            80, 80, 80, 80, 80, 80, 84, 84, 84, 84, 84, 84, 84, 84, 88, 88, 88, 88, 88, 88, 88, 88,
            92, 92, 92, 92, 92, 92, 92, 92, 96, 96, 96, 96, 96, 96, 96, 96, 97, 99 };
    bool res_5 = sol.canPartition(nums_5);
    cout << res_5 << endl;
    assert(res_5 == false);

    return 0;
}
// Accepted
// 144/144 cases passed (75 ms)
// Your runtime beats 80.86 % of cpp submissions
// Your memory usage beats 50.4 % of cpp submissions (63.9 MB)