/*
 * @lc app=leetcode id=643 lang=c
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start

double findMaxAverage(int *nums, int numsSize, int k)
{
	int sum_of_k = 0;
	for (int i = 0; i < k; i++) {
		sum_of_k += nums[i];
	}
	int max = sum_of_k;
	int offset = numsSize - k;
	for (int i = 0; i < offset; i++) {
		sum_of_k -= nums[i];
		sum_of_k += nums[i + k];
		if (sum_of_k > max)
			max = sum_of_k;
	}

	return (double)max / k;
}

// @lc code=end

// Accepted
// 127/127 cases passed (218 ms)
// Your runtime beats 72.94 % of c submissions
// Your memory usage beats 64.71 % of c submissions (14.1 MB)
