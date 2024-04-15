/*
 * @lc app=leetcode id=645 lang=c
 *
 * [645] Set Mismatch
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_1 6
// @lc code=start
#define RETRUN_SIZE 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
	(*returnSize) = RETRUN_SIZE;
	int *result = (int *)malloc(sizeof(int) * RETRUN_SIZE);

	// Counting method
	int table[numsSize];
	memset(table, 0, sizeof(int) * numsSize);

	for (int i = 0; i < numsSize; i++) {
		if (table[nums[i] - 1] == 0)
			table[nums[i] - 1]++;
		else
			result[0] = nums[i];
	}
	for (int i = 0; i < numsSize; i++) {
		if (table[i] == 0)
		{
			result[1] = i + 1;
			break;
		}
	}

	return result;
}

// @lc code=end

int main()
{
	int input_size = SIZE_1;
	int arr[SIZE_1] = { 3, 2, 3, 4, 6, 5 };
	int *ans;
	int returnSize;
	ans = findErrorNums(arr, input_size, &returnSize);
	printf("%d %d\n", ans[0], ans[1]);
	free(ans);

	return 0;
}

// Accepted
// 49/49 cases passed (19 ms)
// Your runtime beats 85.71 % of c submissions
// Your memory usage beats 100 % of c submissions (6.7 MB)
