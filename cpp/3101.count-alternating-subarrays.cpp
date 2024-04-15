/*
 * @lc app=leetcode id=3101 lang=cpp
 *
 * [3101] Count Alternating Subarrays
 *
 * https://leetcode.com/problems/count-alternating-subarrays/description/
 *
 * algorithms
 * Medium (50.72%)
 * Likes:    11
 * Dislikes: 1
 * Total Accepted:    14.3K
 * Total Submissions: 28K
 * Testcase Example:  '[0,1,1,1]'
 *
 * You are given a binary array nums.
 *
 * We call a subarray alternating if no two adjacent elements in the subarray
 * have the same value.
 *
 * Return the number of alternating subarrays in nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1,1,1]
 *
 * Output: 5
 *
 * Explanation:
 *
 * The following subarrays are alternating: [0], [1], [1], [1], and [0,1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,0]
 *
 * Output: 10
 *
 * Explanation:
 *
 * Every subarray of the array is alternating. There are 10 possible subarrays
 * that we can choose.
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
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        long long count = 1; // Initialize count with 1 to include single elements
        int n = nums.size();
        if (n == 1)
            return count;

        int j = 0;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                count += (i - j + 1); // Found an alternating subarray ending at index i
            }
            else
            {
                count++;
                j = i;
            }
        }

        return count;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {0, 1, 1, 1};
    cout << sol.countAlternatingSubarrays(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = {1, 0, 1, 0};
    cout << sol.countAlternatingSubarrays(nums_2) << endl;

    return 0;
}
// Accepted
// 789/789 cases passed (90 ms)
// Your runtime beats 71.43 % of cpp submissions
// Your memory usage beats 57.14 % of cpp submissions (116.2 MB)