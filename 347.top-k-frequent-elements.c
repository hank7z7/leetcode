/*
 * @lc app=leetcode id=347 lang=c
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.33%)
 * Likes:    16339
 * Dislikes: 596
 * Total Accepted:    1.8M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 * 
 * 
 * 
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define BUCKET_SIZE (20000)
#define NUMS_MIN_VAL (-10000)

struct bucket_t {
	int value;
	int count;
} BUCKET_T;

int bucket_val_cmp(const void *a, const void *b)
{
	return ((struct bucket_t *)b)->count - ((struct bucket_t *)a)->count;
}

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize)
{
	*returnSize = k;
	int *result = (int *)malloc(sizeof(int) * k);
	// memset(result, 0, sizeof(int) * k);

	struct bucket_t buckets[BUCKET_SIZE] = { 0 };
	// memset(buckets, 0, sizeof(struct bucket_t) * BUCKET_SIZE);
	for (int i = 0; i < numsSize; i++) {
		buckets[nums[i] - NUMS_MIN_VAL].value = nums[i];
		buckets[nums[i] - NUMS_MIN_VAL].count++;
	}

	qsort(buckets, BUCKET_SIZE, sizeof(struct bucket_t), bucket_val_cmp);

	for (int i = 0; i < k; i++) {
		result[i] = buckets[i].value;
	}
	return result;
}

// @lc code=end
int main(int argc, char **argv)
{
	int k = 0;
	int numsSize = 0;
	int returnSize = 0;

	// test 1
	int *result1;
	k = 2;
	numsSize = 6;
	int nums1[6] = { 1, 1, 1, 2, 2, 3 };
	result1 = topKFrequent(nums1, numsSize, k, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", result1[i]);
	}
	printf("\n");
	free(result1);

	// test 1
	int *result2;
	k = 1;
	numsSize = 1;
	int nums2[1] = { 1 };
	result2 = topKFrequent(nums1, numsSize, k, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", result2[i]);
	}
	printf("\n");
	free(result2);

	return 0;
}

// Accepted
// 21/21 cases passed (52 ms)
// Your runtime beats 23.08 % of c submissions
// Your memory usage beats 23.08 % of c submissions (11 MB)