/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

// @lc code=start
void moveZeroes(int *nums, int numsSize)
{
	int i, j = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != 0 && nums[j] == 0 && i != j) {
			nums[j] = nums[i];
			nums[i] = 0;
			j++;
		} else if (nums[i] == 0 && nums[j] != 0) {
			j = i;
		}
	}
}

// @lc code=end
// Accepted
// 74/74 cases passed (77 ms)
// Your runtime beats 67.53 % of c submissions
// Your memory usage beats 19.65 % of c submissions (15.2 MB)