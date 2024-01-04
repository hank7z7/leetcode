/*
 * @lc app=leetcode id=33 lang=c
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (39.87%)
 * Likes:    24831
 * Dislikes: 1462
 * Total Accepted:    2.4M
 * Total Submissions: 6M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 * 
 * Prior to being passed to your function, nums is possibly rotated at an
 * unknown pivot index k (1 <= k < nums.length) such that the resulting array
 * is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
 * and become [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is an ascending array that is possibly rotated.
 * -10^4 <= target <= 10^4
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define size_1 7
#define size_3 1

// @lc code=start
int search(int *nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1;
	int mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;

		if (target < nums[mid]) {
			// Left part is ascending, equal case is must!
			// And target is in right part
			if (nums[left] <= nums[mid] && target < nums[left]) {
				// Target is in left part
				// if (nums[left] <= target)
				//      right = mid - 1;
				// // Target is in right part
				// else
				left = mid + 1;
			}
			// Left part is not ascending OR target is in left part
			else {
				right = mid - 1;
			}
		} else {
			// Right part is ascending, equal case is must!
			// And target is in left part
			if (nums[mid] <= nums[right] && nums[right] < target) {
				// Target is in right part
				// if (target <= nums[right])
				//      left = mid + 1;
				// Tartet is in left part
				// else
				right = mid - 1;
			}
			// Right part is not ascending OR target is in right part
			else {
				left = mid + 1;
			}
		}
	}
	return -1;
}

// @lc code=end
int main(int argc, char **argv)
{
	// Test 1
	int input_1[size_1] = { 4, 5, 6, 7, 0, 1, 2 };
	int target_1 = 0;
	printf("%d\n", search(input_1, size_1, target_1));

	// Test 2
	int target_2 = 3;
	printf("%d\n", search(input_1, size_1, target_2));

	// Test 3
	int input_3[size_3] = { 1 };
	int target_3 = 0;
	printf("%d\n", search(input_3, size_3, target_3));

	return 0;
}
// Accepted
// 195/195 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 67.64 % of c submissions (6.6 MB)