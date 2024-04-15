/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (37.88%)
 * Likes:    15926
 * Dislikes: 1793
 * Total Accepted:    1.1M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array nums. Return the smallest positive integer
 * that is not present in nums.
 *
 * You must implement an algorithm that runs in O(n) time and uses O(1)
 * auxiliary space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,0]
 * Output: 3
 * Explanation: The numbers in the range [1,2] are all in the array.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Explanation: 1 is in the array but 2 is missing.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 * Explanation: The smallest positive integer 1 is missing.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        unordered_map<int, int> um;
        for (auto num : nums)
            um[num]++;
        bool find = false;
        int  ret  = 0;
        while (!find)
        {
            ret++;
            if (um.find(ret) == um.end())
                find = true;
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 2, 0 };
    cout << sol.firstMissingPositive(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = { 3, 4, -1, 1 };
    cout << sol.firstMissingPositive(nums_2) << endl;

    // Test_3
    vector<int> nums_3 = { 7, 8, 9, 11, 12 };
    cout << sol.firstMissingPositive(nums_3) << endl;
    return 0;
}
// Accepted
// 176/176 cases passed (78 ms)
// Your runtime beats 16.12 % of cpp submissions
// Your memory usage beats 11.54 % of cpp submissions (60.7 MB)