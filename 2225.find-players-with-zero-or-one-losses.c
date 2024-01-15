/*
 * @lc app=leetcode id=2225 lang=c
 *
 * [2225] Find Players With Zero or One Losses
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MATCHES 2
#define MATCHES_SIZE_1 10

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

// Binary search
int bs(int *arr, int start, int end, int key)
{
	if (start >= end)
		return -1;
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key) {
			start = mid + 1;
		} else if (key < arr[mid]) {
			end = mid - 1;
		}
	}

	return -1;
}

int **findWinners(int **matches, int matchesSize, int *matchesColSize,
		  int *returnSize, int **returnColumnSizes)
{
	*returnSize = 2;
	int **result = (int *)malloc(sizeof(int *) * (*returnSize));
	*returnColumnSizes = (int *)calloc((*returnSize), sizeof(int));
	for (int i = 0; i < (*returnSize); i++) {
		result[i] = (int *)malloc(matchesSize * sizeof(int));
	}

	int losers[100001] = { 0 };

	for (int i = 0; i < matchesSize; i++) {
		losers[matches[i][1]]++;
	}
	for (int i = 0; i < matchesSize; i++) {
		if (losers[matches[i][1]] == 1)
			result[1][(*returnColumnSizes)[1]++] = matches[i][1];
		if (losers[matches[i][0]] == 0) {
			result[0][(*returnColumnSizes)[0]++] = matches[i][0];
			losers[matches[i][0]] = -1;
		}
	}
	qsort(result[0], (*returnColumnSizes)[0], sizeof(int), cmp);
	qsort(result[1], (*returnColumnSizes)[1], sizeof(int), cmp);
	return result;
}

// @lc code=end

int main(int argc, char **argv)
{
	// int size_1 = MATCHES_SIZE_1;
	// int matches_1[MATCHES_SIZE_1][MATCHES] = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
	// int matchesColSize_1[MATCHES_SIZE_1] = {0};
	// for(int i = 0; i < size_1; i++)
	//     matchesColSize_1[i] = 2;
	// int returnSize_1 = 0;
	// int*  returnColumnSizes_1;
	// int** result = findWinners(matches_1, size_1, matchesColSize_1, &returnSize_1, &returnColumnSizes_1);
	// for (int i = 0; i < returnSize_1; i++)
	// {
	//     for(int j = 0; j < returnColumnSizes_1[i]; j++)
	//         printf("%d ", result[i][j]);
	//     printf("\n");
	//     free(result[i]);
	// }
	// free(result);
	// free(returnColumnSizes_1);
	return 0;
}

// Accepted
// 127/127 cases passed (618 ms)
// Your runtime beats 54.55 % of c submissions
// Your memory usage beats 54.55 % of c submissions (78.9 MB)
