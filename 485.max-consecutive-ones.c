/*
 * @lc app=leetcode id=485 lang=c
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (54.97%)
 * Likes:    3132
 * Dislikes: 406
 * Total Accepted:    719.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * Given a binary array nums, return the maximum number of consecutive 1's in
 * the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s. The maximum number of consecutive 1s is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
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

// @lc code=start

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
	int result = 0;
	int length = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == 1) {
			length++;
		} else {
			if (length > result)
				result = length;
			length = 0;
		}
	}

	// Becare of boundary 1 1 0 1 1 1
	if (length > result)
		result = length;
	return result;
}

// @lc code=end

// Accepted
// 42/42 cases passed (51 ms)
// Your runtime beats 72.74 % of c submissions
// Your memory usage beats 87.95 % of c submissions (7.4 MB)
