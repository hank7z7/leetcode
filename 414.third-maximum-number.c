/*
 * @lc app=leetcode id=414 lang=c
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (31.72%)
 * Likes:    1875
 * Dislikes: 2437
 * Total Accepted:    355.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,2,1]'
 *
 * Given an integer array nums, return the third distinct maximum number in
 * this array. If the third maximum does not exist, return the maximum
 * number.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,2,1]
 * Output: 1
 * Explanation:
 * The first distinct maximum is 3.
 * The second distinct maximum is 2.
 * The third distinct maximum is 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2]
 * Output: 2
 * Explanation:
 * The first distinct maximum is 2.
 * The second distinct maximum is 1.
 * The third distinct maximum does not exist, so the maximum (2) is returned
 * instead.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,2,3,1]
 * Output: 1
 * Explanation:
 * The first distinct maximum is 3.
 * The second distinct maximum is 2 (both 2's are counted together since they
 * have the same value).
 * The third distinct maximum is 1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Can you find an O(n) solution?
 */

// @lc code=start

int thirdMax(int *nums, int numsSize)
{
	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
	for (int i = 0; i < numsSize; i++) {
		long num = (long)nums[i];
		if (num >= first) {
			if (num > first) {
				third = second;
				second = first;
				first = num;
			}
		} else if (num >= second) {
			if (num > second) {
				third = second;
				second = num;
			}
		} else if (num >= third) {
			third = num;
		}
	}

	return third >= (long)INT_MIN ? (int)third : (int)first;
}

// @lc code=end

// Accepted
// 32/32 cases passed (10 ms)
// Your runtime beats 36.26 % of c submissions
// Your memory usage beats 39.56 % of c submissions (6.3 MB)
