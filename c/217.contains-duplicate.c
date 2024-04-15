/*
 * @lc app=leetcode id=217 lang=c
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (60.54%)
 * Likes:    5843
 * Dislikes: 993
 * Total Accepted:    1.9M
 * Total Submissions: 3.1M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
int compare(const void *a, const void *b)
{
	// Be careful the address casting!
	return *(int *)a > *(int *)b;
}

bool containsDuplicate(int *nums, int numsSize)
{
	// Sort nums first, O(nlogn)
	qsort(nums, numsSize, sizeof(int), compare);
	for (int i = 0; i < numsSize; i++) {
		if ((i + 1) != numsSize && nums[i + 1] == nums[i])
			return true;
	}
	return false;
}

// @lc code=end

// Accepted
// 70/70 cases passed (152 ms)
// Your runtime beats 55.46 % of c submissions
// Your memory usage beats 60.18 % of c submissions (12.7 MB)
