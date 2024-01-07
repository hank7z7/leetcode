/*
 * @lc app=leetcode id=55 lang=c
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (38.68%)
 * Likes:    18233
 * Dislikes: 1059
 * Total Accepted:    1.6M
 * Total Submissions: 4.2M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * You are given an integer array nums. You are initially positioned at the
 * array's first index, and each element in the array represents your maximum
 * jump length at that position.
 * 
 * Return true if you can reach the last index, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */
#include <stdio.h>
#include <stdbool.h>

// @lc code=start
bool canJump(int *nums, int numsSize)
{
	int max_length = 0;
	for (int i = 0; i < numsSize; i++) {
		if (i <= max_length && (nums[i] + i) > max_length)
			max_length = nums[i] + i;
		if (max_length >= (numsSize - 1))
			return true;
	}

	return false;
}

// @lc code=end

int main(int argc, char **argv)
{
	int size_1 = 5;
	int input_1[] = { 2, 3, 1, 1, 4 };
	printf("%d\n", canJump(input_1, size_1));

	int size_2 = 5;
	int input_2[] = { 3, 2, 1, 0, 4 };
	printf("%d\n", canJump(input_2, size_2));

	return 0;
}

// AC at first trial
// Accepted
// 172/172 cases passed (49 ms)
// Your runtime beats 50 % of c submissions
// Your memory usage beats 90.37 % of c submissions (8.8 MB)
