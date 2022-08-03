/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (40.59%)
 * Likes:    2863
 * Dislikes: 2008
 * Total Accepted:    497.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an integer array nums and an integer k, return true if there are two
 * distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
 * - j) <= k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
 public:
	bool containsNearbyDuplicate(vector < int >&nums, int k) {
		unordered_map < int, int >map;
		for (int i = 0; i < nums.size(); i++) {
			if (map.find(nums[i]) != map.end()) {
				int idx = map[nums[i]];
				if (abs(idx - i) <= k)
					 return true;
			}
			map[nums[i]] = i;
		}
		return false;
	}
};

// @lc code=end

// Accepted
// 51/51 cases passed (223 ms)
// Your runtime beats 78.19 % of cpp submissions
// Your memory usage beats 52.31 % of cpp submissions (77.1 MB)