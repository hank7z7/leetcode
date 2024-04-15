#include <bits/stdc++.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findIntersectionValues(int *nums1, int nums1Size, int *nums2,
			    int nums2Size, int *returnSize)
{
	*returnSize = 2;
	int *result = (int *)malloc(sizeof(int) * (*returnSize));
	result[0] = 0;
	result[1] = 0;

	int i, j;
	for (i = 0; i < nums1Size; i++) {
		for (j = 0; j < nums2Size; j++) {
			if (nums1[i] == nums2[j]) {
				result[0]++;
				break;
			}
		}
	}
	for (i = 0; i < nums2Size; i++) {
		for (j = 0; j < nums1Size; j++) {
			if (nums2[i] == nums1[j]) {
				result[1]++;
				break;
			}
		}
	}
	return result;
}

int main(int argc, char **argv)
{
	int nums1Size = 5;
	int nums2Size = 6;
	int nums1[5] = { 4, 3, 2, 3, 1 };
	int nums2[6] = { 2, 2, 5, 2, 3, 6 };
	int *returnSize;

	int *result =
	    findIntersectionValues(nums1, nums1Size, nums2, nums2Size,
				   returnSize);
	printf("%d %d\n", result[0], result[1]);
	free(result);

	return 0;
}
