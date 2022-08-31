/*
 * @lc app=leetcode id=645 lang=c
 *
 * [645] Set Mismatch
 */
#include <bits/stdc++.h>
// @lc code=start

int cmp(const void *a, const void *b)
{
	return *(int *)a > *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
	(*returnSize) = 2;
	int *result = (int *)malloc(sizeof(int) * 2);
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
			result[1] = i + 1;
	}

	return result;
}

// @lc code=end

int main()
{
	int input_size = 6;
	int arr[input_size] = { 3, 2, 3, 4, 6, 5 };
	int *ans;
	int returnSize;
	ans = findErrorNums(arr, input_size, &returnSize);
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}

// Accepted
// 49/49 cases passed (55 ms)
// Your runtime beats 18.75 % of c submissions
// Your memory usage beats 76.56 % of c submissions (7.1 MB)
