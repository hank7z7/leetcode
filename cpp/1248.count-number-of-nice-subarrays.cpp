/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 *
 * https://leetcode.com/problems/count-number-of-nice-subarrays/description/
 *
 * algorithms
 * Medium (65.44%)
 * Likes:    4034
 * Dislikes: 88
 * Total Accepted:    163.9K
 * Total Submissions: 241.6K
 * Testcase Example:  '[1,1,2,1,1]\n3'
 *
 * Ginumen an array of integers nums and an integer k. A continuous subarray is
 * called nice if there are k odd numbers on it.
 *
 * Return the number of nice sub-arrays.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2,1,1], k = 3
 * Output: 2
 * Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and
 * [1,2,1,1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,4,6], k = 1
 * Output: 0
 * Explanation: There are no odd numbers in the array.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * Output: 16
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = (int)nums.size();

        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        int ans = 0, odd_count = 0;
        for (int num : nums)
        {
            if(num & 1) // is odd
                odd_count++;
            if (odd_count - k >= 0)
            {
                ans += cnt[odd_count - k];
            }
            cnt[odd_count]++;
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char **argnum)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 1, 2, 1, 1};
    int k_1 = 3;
    int res_1 = sol.numberOfSubarrays(nums_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    vector<int> nums_2 = {2, 4, 6};
    int k_2 = 1;
    int res_2 = sol.numberOfSubarrays(nums_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 0);

    // Test_3
    vector<int> nums_3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k_3 = 2;
    int res_3 = sol.numberOfSubarrays(nums_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == 16);

    return 0;
}
// Accepted
// 38/38 cases passed (86 ms)
// Your runtime beats 88.3 % of cpp submissions
// Your memory usage beats 27.58 % of cpp submissions (73.2 MB)