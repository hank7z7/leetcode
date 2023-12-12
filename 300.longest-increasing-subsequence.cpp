/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (53.14%)
 * Likes:    19187
 * Dislikes: 363
 * Total Accepted:    1.4M
 * Total Submissions: 2.6M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity?
 * 
 */

// @lc code=start
class Solution {
 public:
	int lengthOfLIS(vector < int >&nums) {
		const int n = nums.size();
		if (n == 0)
			return 0;
		 vector < int >dp;
		for (int i = 0; i < n; ++i) {
			auto it = lower_bound(begin(dp), end(dp), nums[i]);
			if (it == end(dp))
				dp.push_back(nums[i]);
			else
				*it = nums[i];
		} return dp.size();
	}
};

// @lc code=end
