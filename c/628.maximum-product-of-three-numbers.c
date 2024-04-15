/*
 * @lc app=leetcode id=628 lang=c
 *
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (46.75%)
 * Likes:    3048
 * Dislikes: 553
 * Total Accepted:    227.3K
 * Total Submissions: 488.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums, find three numbers whose product is maximum and
 * return the maximum product.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: 6
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: 24
 * Example 3:
 * Input: nums = [-1,-2,-3]
 * Output: -6
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 * 
 * 
 */
#include <bits/stdc++.h>
// @lc code=start
int cmp(const void *a, const void *b)
{
	return (*(int *)a) > (*(int *)b);
}

int maximumProduct(int *nums, int numsSize)
{
	int max = nums[0] * nums[1] * nums[2];
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	int max3 = INT_MIN;
	int min1 = INT_MAX;
	int min2 = INT_MAX;

	for (int i = 0; i < numsSize; i++) {
		int tmp = nums[i];
		if (tmp > max1) {
			max3 = max2;
			max2 = max1;
			max1 = tmp;
		} else if (tmp > max2) {
			max3 = max2;
			max2 = tmp;
		} else if (tmp > max3)
			max3 = tmp;

		if (tmp < min1) {
			min2 = min1;
			min1 = tmp;
		} else if (tmp < min2) {
			min2 = tmp;
		}
	}
	int product = max1 * max2 * max3;
	if (product > max)
		max = product;
	product = min1 * min2 * max1;
	if (product > max)
		max = product;

	return max;
}

// @lc code=end

int main()
{
	int n = 6;
	int arr[n] = { -100, -98, -1, 2, 3, 4 };
	printf("%d\n", maximumProduct(arr, n));
	return 0;
}

// Accepted
// 92/92 cases passed (52 ms)
// Your runtime beats 88.3 % of c submissions
// Your memory usage beats 54.26 % of c submissions (7.3 MB)
