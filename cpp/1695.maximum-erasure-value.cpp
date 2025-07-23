/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 *
 * https://leetcode.com/problems/maximum-erasure-value/description/
 *
 * algorithms
 * Medium (59.07%)
 * Likes:    3060
 * Dislikes: 58
 * Total Accepted:    194.1K
 * Total Submissions: 314.2K
 * Testcase Example:  '[4,2,4,5,6]'
 *
 * You are given an array of positive integers nums and want to erase a
 * subarray containing unique elements. The score you get by erasing the
 * subarray is equal to the sum of its elements.
 * 
 * Return the maximum score you can get by erasing exactly one subarray.
 * 
 * An array b is called to be a subarray of a if it forms a contiguous
 * subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some
 * (l,r).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,4,5,6]
 * Output: 17
 * Explanation: The optimal subarray here is [2,4,5,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,2,1,2,5,2,1,2,5]
 * Output: 8
 * Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int n = (int)nums.size();
        
        vector<long long> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        unordered_map<int, int> last_seen;
        int left = 0;
        int max_sum = 0;
        for (int right = 0; right < n; ++right) {
            if (last_seen.find(nums[right]) != last_seen.end()) {
                left = max(left, last_seen[nums[right]] + 1);
            }
            last_seen[nums[right]] = right;
            long long current_sum = prefix_sum[right] - (left > 0 ? prefix_sum[left - 1] : 0);
            max_sum = max(max_sum, (int)current_sum);
        }
        return max_sum;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = {4, 2, 4, 5, 6};
    int res = sol.maximumUniqueSubarray(nums);
    cout << res << endl;  // Expected output: 17
    assert(res == 17);

    // Test_2
    nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    res = sol.maximumUniqueSubarray(nums);
    cout << res << endl;  // Expected output: 8
    assert(res == 8);

    return 0;
}
