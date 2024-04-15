/*
 * @lc app=leetcode id=674 lang=c
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start

int findLengthOfLCIS(int *nums, int numsSize)
{
	int continuous = 1;
	int max = 1;
	if (numsSize > 1)
		for (int i = 1; i < numsSize; i++) {
			if (nums[i] > nums[i - 1])
				continuous++;
			else {
				if (continuous > max)
					max = continuous;
				continuous = 1;
			}
		}

	return continuous > max ? continuous : max;
}

// @lc code=end
