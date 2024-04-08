/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 *
 * https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
 *
 * algorithms
 * Medium (67.08%)
 * Likes:    3827
 * Dislikes: 68
 * Total Accepted:    249.5K
 * Total Submissions: 371.4K
 * Testcase Example:  '[1,1,0,1]'
 *
 * Given a binary array nums, you should delete one element from it.
 *
 * Return the size of the longest non-empty subarray containing only 1's in the
 * resulting array. Return 0 if there is no such subarray.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,0,1]
 * Output: 3
 * Explanation: After deleting the number in position 2, [1,1,1] contains 3
 * numbers with value of 1's.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1,1,0,1,1,0,1]
 * Output: 5
 * Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
 * longest subarray with value of 1's is [1,1,1,1,1].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,1]
 * Output: 2
 * Explanation: You must delete one element.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestSubarray(const vector<int>& nums)
    {
        int result    = 0;
        int left      = -1;
        int last_zero = -1;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                left      = last_zero;
                last_zero = i;
            }
            int length = (i - left);
            result     = max(result, length);
        }
        return result - 1;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 1, 0, 1 };
    cout << sol.longestSubarray(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = { 0, 1, 1, 1, 0, 1, 1, 0, 1 };
    cout << sol.longestSubarray(nums_2) << endl;

    // Test_3
    vector<int> nums_3 = { 1, 1, 1 };
    cout << sol.longestSubarray(nums_3) << endl;

    return 0;
}
// Accepted
// 82/82 cases passed (30 ms)
// Your runtime beats 96.18 % of cpp submissions
// Your memory usage beats 77.43 % of cpp submissions (58.6 MB)