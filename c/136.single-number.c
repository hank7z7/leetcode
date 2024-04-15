/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (71.87%)
 * Likes:    15664
 * Dislikes: 647
 * Total Accepted:    2.5M
 * Total Submissions: 3.5M
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 * 
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 * 
 * 
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * Each element in the array appears twice except for one element which appears
 * only once.
 * 
 * 
 */
#include <stdio.h>
// @lc code=start
int singleNumber(int *nums, int numsSize)
{
	// Exclusive OR each elements
	for (int i = 1; i < numsSize; i++) {
		nums[0] ^= nums[i];
	}

	return nums[0];
}

// @lc code=end

int main(int argc, char **argv)
{
	int numsSize = 0;
	// test 1
	numsSize = 3;
	int nums1[3] = { 2, 2, 1 };
	printf("%d\n", singleNumber(nums1, numsSize));

	// test 2
	numsSize = 5;
	int nums2[5] = { 4, 1, 2, 1, 2 };
	printf("%d\n", singleNumber(nums2, numsSize));

	return 0;
}

// Accepted
// 61/61 cases passed (12 ms)
// Your runtime beats 61.52 % of c submissions
// Your memory usage beats 29.36 % of c submissions (7.9 MB)
