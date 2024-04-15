/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 *
 * https://leetcode.com/problems/max-consecutive-ones-iii/description/
 *
 * algorithms
 * Medium (62.67%)
 * Likes:    8274
 * Dislikes: 116
 * Total Accepted:    499.2K
 * Total Submissions: 794.6K
 * Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
 *
 * Given a binary array nums and an integer k, return the maximum number of
 * consecutive 1's in the array if you can flip at most k 0's.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestOnes(const vector<int>& nums, const int k)
    {
        // Store the index of zeors
        queue<int> q;
        int        left   = -1;
        int        result = INT_MIN;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                q.push(i);
                if ((int) q.size() > k)
                {
                    left = q.front();
                    q.pop();
                }
            }
            int length = i - left;
            result     = max(result, length);
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int         k_1    = 2;
    cout << sol.longestOnes(nums_1, k_1) << endl;

    // Test_2
    vector<int> nums_2 = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    int         k_2    = 3;
    cout << sol.longestOnes(nums_2, k_2) << endl;

    return 0;
}
// Accepted
// 55/55 cases passed (47 ms)
// Your runtime beats 27.37 % of cpp submissions
// Your memory usage beats 5.07 % of cpp submissions (59.3 MB)