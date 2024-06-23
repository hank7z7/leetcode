/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 *
 * https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
 *
 * algorithms
 * Medium (49.60%)
 * Likes:    3501
 * Dislikes: 151
 * Total Accepted:    151.1K
 * Total Submissions: 293.4K
 * Testcase Example:  '[8,2,4,7]\n4'
 *
 * Given an array of integers nums and an integer limit, return the size of the
 * longest non-empty subarray such that the absolute difference between any two
 * elements of this subarray is less than or equal to limit.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [8,2,4,7], limit = 4
 * Output: 2
 * Explanation: All subarrays are:
 * [8] with maximum absolute diff |8-8| = 0 <= 4.
 * [8,2] with maximum absolute diff |8-2| = 6 > 4.
 * [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
 * [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
 * [2] with maximum absolute diff |2-2| = 0 <= 4.
 * [2,4] with maximum absolute diff |2-4| = 2 <= 4.
 * [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
 * [4] with maximum absolute diff |4-4| = 0 <= 4.
 * [4,7] with maximum absolute diff |4-7| = 3 <= 4.
 * [7] with maximum absolute diff |7-7| = 0 <= 4.
 * Therefore, the size of the longest subarray is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [10,1,2,4,7,2], limit = 5
 * Output: 4
 * Explanation: The subarray [2,4,7,2] is the longest since the maximum
 * absolute diff is |2-7| = 5 <= 5.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [4,2,2,2,4,4,2,2], limit = 0
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 0 <= limit <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = (int)nums.size();
        priority_queue<pair<int, int>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        int max_len = 0;
        int l = 0, r = 0;
        // Sliding window
        for (r = 0; r < n; r++)
        {
            max_heap.push({nums[r], r});
            min_heap.push({nums[r], r});
            while ((max_heap.top().first - min_heap.top().first) > limit)
            {
                // Get the current left bound
                l = min(max_heap.top().second, min_heap.top().second);
                // Remove the left most element in the sliding window
                l++;
                while (max_heap.top().second < l)
                    max_heap.pop();
                while (min_heap.top().second < l)
                    min_heap.pop();
            }
            int curr_len = r - l + 1;
            max_len = max(max_len, curr_len);
        }
        return max_len;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {8, 2, 4, 7};
    int limit_1 = 4;
    int res_1 = sol.longestSubarray(nums_1, limit_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    vector<int> nums_2 = {10, 1, 2, 4, 7, 2};
    int limit_2 = 5;
    int res_2 = sol.longestSubarray(nums_2, limit_2);
    cout << res_2 << endl;
    assert(res_2 == 4);

    // Test_3
    vector<int> nums_3 = {4, 2, 2, 2, 4, 4, 2, 2};
    int limit_3 = 0;
    int res_3 = sol.longestSubarray(nums_3, limit_3);
    cout << res_3 << endl;
    assert(res_3 == 3);

    return 0;
}
// Accepted
// 61/61 cases passed (111 ms)
// Your runtime beats 50.46 % of cpp submissions
// Your memory usage beats 55.61 % of cpp submissions (61.8 MB)