/*
 * @lc app=leetcode id=3046 lang=cpp
 *
 * [3046] Split the Array
 *
 * https://leetcode.com/problems/split-the-array/description/
 *
 * algorithms
 * Easy (56.06%)
 * Likes:    56
 * Dislikes: 4
 * Total Accepted:    32.8K
 * Total Submissions: 58.5K
 * Testcase Example:  '[1,1,2,2,3,4]'
 *
 * You are given an integer array nums of even length. You have to split the
 * array into two parts nums1 and nums2 such that:
 * 
 * 
 * nums1.length == nums2.length == nums.length / 2.
 * nums1 should contain distinct elements.
 * nums2 should also contain distinct elements.
 * 
 * 
 * Return true if it is possible to split the array, and false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2,2,3,4]
 * Output: true
 * Explanation: One of the possible ways to split nums is nums1 = [1,2,3] and
 * nums2 = [1,2,4].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,1,1,1]
 * Output: false
 * Explanation: The only possible way to split nums is nums1 = [1,1] and nums2
 * = [1,1]. Both nums1 and nums2 do not contain distinct elements. Therefore,
 * we return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * nums.length % 2 == 0 
 * 1 <= nums[i] <= 100
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define COUNT_SIZE 101
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        // 1 <= nums[i] <= 100, use count table
        vector<int> count(COUNT_SIZE, 0);
        bool ret = true;
        for(auto num : nums)
        {
            if(count[num] == 2)
            {
                ret = false;
                break;
            }
            else
                count[num]++;
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1,1,2,2,3,4};
    cout << sol.isPossibleToSplit(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = {1,1,1,1};
    cout << sol.isPossibleToSplit(nums_2) << endl;

    return 0;
}
// Accepted
// 715/715 cases passed (7 ms)
// Your runtime beats 58.5 % of cpp submissions
// Your memory usage beats 86.5 % of cpp submissions (24 MB)