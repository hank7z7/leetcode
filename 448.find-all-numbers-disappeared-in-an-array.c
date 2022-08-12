/*
 * @lc app=leetcode id=448 lang=c
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (58.97%)
 * Likes:    7086
 * Dislikes: 400
 * Total Accepted:    617.4K
 * Total Submissions: 1M
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array nums of n integers where nums[i] is in the range [1, n],
 * return an array of all the integers in the range [1, n] that do not appear
 * in nums.
 * 
 * 
 * Example 1:
 * Input: nums = [4,3,2,7,8,2,3,1]
 * Output: [5,6]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [2]
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 * 
 * 
 * 
 * Follow up: Could you do it without extra space and in O(n) runtime? You may
 * assume the returned list does not count as extra space.
 * 
 */
// #include <bits/stdc++.h>
// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
	*returnSize = 0;
	for (int i = 0; i < numsSize; i++) {

		//  [ 4, 3, 2, 7, 8, 2, 3, 1]
		//  [ 1, 1, 1, 1, 0, 0, 1, 1]
		//  [ -, -, -, -, +, +, -, -] 
		int target_index = nums[i] > 0 ? nums[i] - 1 : -nums[i] - 1;
        int target_val = nums[target_index];
		if (target_val > 0) {
			nums[target_index] = -target_val;
		} else {
			(*returnSize)++;
		}
	}
	// (*returnSize)--;
	int *result = (int *)malloc(sizeof(int) * (*returnSize));
	int index = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > 0)
			result[index++] = i + 1;
	}

	return result;
}

// @lc code=end

// int main()
// {
// 	int arr[8] = { 4, 3, 2, 7, 8, 2, 3, 1 };
// 	int size = 0;
// 	int *result = findDisappearedNumbers(arr, 8, &size);
// 	for (int i = 0; i < size; i++)
// 		printf("%d", result[i]);
// 	return 0;
// }

// Accepted
// 33/33 cases passed (201 ms)
// Your runtime beats 33.89 % of c submissions
// Your memory usage beats 90.29 % of c submissions (17.3 MB)