/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (62.78%)
 * Likes:    10978
 * Dislikes: 363
 * Total Accepted:    1.3M
 * Total Submissions: 2.1M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 * 
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */

// @lc code=start

int majorityElement(int *nums, int numsSize)
{
	// Boyer-Moore majority vote algorithm
	int majority;
	int count = 0;

	for (int i = 0; i < numsSize; i++) {
		if (count > 0)
			count = majority == nums[i] ? count + 1 : count - 1;
		else {
			majority = nums[i];
			count++;
		}

		// Beats 60%
		// if(count == 0)
		// {
		//     majority = nums[i];
		//     count++;
		// }
		// else if(majority == nums[i])
		//     count++;
		// else
		//     count--;
	}

	return majority;
}

// @lc code=end

// Accepted
// 43/43 cases passed (23 ms)
// Your runtime beats 80.27 % of c submissions
// Your memory usage beats 21.43 % of c submissions (8 MB)
