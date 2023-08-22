/*
 * @lc app=leetcode id=238 lang=c
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	int prefix_product[numsSize];
	int suffix_product[numsSize];
	// int result[numsSize];
	int *result = malloc(numsSize * sizeof(int));
	int i = 0;

	for (i = 0; i < numsSize; i++) {
		if (i == 0) {
			prefix_product[i] = nums[i];
			suffix_product[numsSize - i - 1] =
			    nums[numsSize - i - 1];
		} else {
			prefix_product[i] = nums[i] * prefix_product[i - 1];
			suffix_product[numsSize - i - 1] =
			    nums[numsSize - i - 1] * suffix_product[numsSize -
								    i];

		}
	}

	for (i = 0; i < numsSize; i++) {
		if (i == 0)
			result[i] = suffix_product[i + 1];
		else if (i == (numsSize - 1))
			result[i] = prefix_product[i - 1];
		else
			result[i] =
			    prefix_product[i - 1] * suffix_product[i + 1];
	}

	*returnSize = numsSize;
	return result;
}

// @lc code=end
// Accepted
// 22/22 cases passed (85 ms)
// Your runtime beats 83.82 % of c submissions
// Your memory usage beats 48.69 % of c submissions (18.8 MB)
