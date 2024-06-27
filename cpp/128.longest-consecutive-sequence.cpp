/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (47.29%)
 * Likes:    19858
 * Dislikes: 1013
 * Total Accepted:    1.8M
 * Total Submissions: 3.9M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> us;
        for (int num : nums)
        {
            us.insert(num);
        }
        int res = 0;
        for (int num : nums)
        {
            if (us.find(num - 1) == us.end())
            {
                int curr_num = num;
                int consecutive_len = 1;
                while (us.find(curr_num + 1) != us.end())
                {
                    curr_num++;
                    consecutive_len++;
                }
                res = max(res, consecutive_len);
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {100, 4, 200, 1, 3, 2};
    int res_1 = sol.longestConsecutive(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 4);

    // Test_2
    vector<int> nums_2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int res_2 = sol.longestConsecutive(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 9);

    return 0;
}
// Accepted
// 76/76 cases passed (821 ms)
// Your runtime beats 19.25 % of cpp submissions
// Your memory usage beats 43.44 % of cpp submissions (74.2 MB)
