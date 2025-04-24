/*
 * @lc app=leetcode id=2799 lang=cpp
 *
 * [2799] Count Complete Subarrays in an Array
 *
 * https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/
 *
 * algorithms
 * Medium (65.46%)
 * Likes:    803
 * Dislikes: 17
 * Total Accepted:    91.1K
 * Total Submissions: 126.6K
 * Testcase Example:  '[1,3,1,2,2]'
 *
 * You are given an array nums consisting of positive integers.
 *
 * We call a subarray of an array complete if the following condition is
 * satisfied:
 *
 *
 * The number of distinct elements in the subarray is equal to the number of
 * distinct elements in the whole array.
 *
 *
 * Return the number of complete subarrays.
 *
 * A subarray is a contiguous non-empty part of an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,1,2,2]
 * Output: 4
 * Explanation: The complete subarrays are the following: [1,3,1,2],
 * [1,3,1,2,2], [3,1,2] and [3,1,2,2].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,5,5,5]
 * Output: 10
 * Explanation: The array consists only of the integer 5, so any subarray is
 * complete. The number of subarrays that we can choose is 10.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 2000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        int res = 0;
        unordered_map<int, int> cnt;
        int n = (int) nums.size();
        int right = 0;
        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinct_count = (int) distinct.size();

        for (int left = 0; left < n; left++)
        {
            if (left > 0)
            {
                int remove = nums[left - 1];
                cnt[remove]--;
                if (cnt[remove] == 0)
                {
                    cnt.erase(remove);
                }
            }
            while (right < n && (int) cnt.size() < distinct_count)
            {
                int add = nums[right];
                cnt[add]++;
                right++;
            }
            if ((int) cnt.size() == distinct_count)
            {
                res += (n - right + 1);
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = { 1, 3, 1, 2, 2 };
    int res = sol.countCompleteSubarrays(nums);
    cout << "Test_1: " << res << endl;
    assert(res == 4);

    // Test_2
    nums = { 5, 5, 5, 5 };
    res = sol.countCompleteSubarrays(nums);
    cout << "Test_2: " << res << endl;
    assert(res == 10);

    return 0;
}
