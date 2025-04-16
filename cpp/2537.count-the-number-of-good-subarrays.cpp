/*
 * @lc app=leetcode id=2537 lang=cpp
 *
 * [2537] Count the Number of Good Subarrays
 *
 * https://leetcode.com/problems/count-the-number-of-good-subarrays/description/
 *
 * algorithms
 * Medium (52.97%)
 * Likes:    1331
 * Dislikes: 49
 * Total Accepted:    94.5K
 * Total Submissions: 144.2K
 * Testcase Example:  '[1,1,1,1,1]\n10'
 *
 * Given an integer array nums and an integer k, return the number of good
 * subarrays of nums.
 *
 * A subarray arr is good if there are at least k pairs of indices (i, j) such
 * that i < j and arr[i] == arr[j].
 *
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,1,1], k = 10
 * Output: 1
 * Explanation: The only good subarray is the array nums itself.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,1,4,3,2,2,4], k = 2
 * Output: 4
 * Explanation: There are 4 different good subarrays:
 * - [3,1,4,3,2,2] that has 2 pairs.
 * - [3,1,4,3,2,2,4] that has 3 pairs.
 * - [1,4,3,2,2,4] that has 2 pairs.
 * - [4,3,2,2,4] that has 2 pairs.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long countGood(vector<int>& nums, int k)
    {
        const int n = (int) nums.size();
        int same = 0, right = -1;
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int left = 0; left < n; ++left)
        {
            while (same < k && right + 1 < n)
            {
                right++;
                same += cnt[nums[right]];
                cnt[nums[right]]++;
            }
            if (same >= k)
            {
                ans += n - right;
            }
            cnt[nums[left]]--;
            same -= cnt[nums[left]];
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char* argv[])
{
    Solution solution;
    // Test_1
    vector<int> nums = { 1, 1, 1, 1, 1 };
    int k = 10;
    int res = solution.countGood(nums, k);
    cout << res << endl;
    assert(res == 1);

    // Test_2
    nums = { 3, 1, 4, 3, 2, 2, 4 };
    k = 2;
    res = solution.countGood(nums, k);
    cout << res << endl;
    assert(res == 4);

    return 0;
}
// Accepted
// 41/41 cases passed (80 ms)
// Your runtime beats 61.85 % of cpp submissions
// Your memory usage beats 77.96 % of cpp submissions (79.1 MB)