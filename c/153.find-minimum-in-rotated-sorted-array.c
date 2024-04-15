/*
 * @lc app=leetcode id=153 lang=c
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (49.33%)
 * Likes:    12319
 * Dislikes: 545
 * Total Accepted:    1.5M
 * Total Submissions: 3.1M
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array of length n sorted in ascending order is rotated between 1
 * and n times. For example, the array nums = [0,1,2,4,5,6,7] might
 * become:
 * 
 * 
 * [4,5,6,7,0,1,2] if it was rotated 4 times.
 * [0,1,2,4,5,6,7] if it was rotated 7 times.
 * 
 * 
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results
 * in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * 
 * Given the sorted rotated array nums of unique elements, return the minimum
 * element of this array.
 * 
 * You must write an algorithm that runs in O(log n) time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,4,5,1,2]
 * Output: 1
 * Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2]
 * Output: 0
 * Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4
 * times.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [11,13,15,17]
 * Output: 11
 * Explanation: The original array was [11,13,15,17] and it was rotated 4
 * times. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5000
 * -5000 <= nums[i] <= 5000
 * All the integers of nums are unique.
 * nums is sorted and rotated between 1 and n times.
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define size_1 7
#define size_3 1
// @lc code=start
/*
    All possible rotation
    left   mid      right
    0 1 2 [3] 4 5 6 7      <= in the left
    7 0 1 [2] 3 4 5 6      <= in the left
    6 7 0 [1] 2 3 4 5      <= in the left
    5 6 7 [0] 1 2 3 4      <= in the right
    4 5 6 [7] 0 1 2 3      <= in the right
    3 4 5 [6] 7 0 1 2      <= in the right
    2 3 4 [5] 6 7 0 1      <= in the right
    1 2 3 [4] 5 6 7 0      <= in the right

    left=mid
    [1] 3                  <= in the left
    [3] 1                  <= in the right
*/
int findMin(int *nums, int numsSize)
{
	int left = 0;
	int right = numsSize - 1;
	int mid = 0;
	while (left <= right) {
		if (left == right)
			return nums[left];
		// (left + right) / 2 may overflow 
		mid = left + (right - left) / 2;
		// Minimum is in the left part
		if (nums[mid] < nums[right]) {
			// Check if the mid is minimum
			if (left != mid && nums[mid] < nums[mid - 1])
				return nums[mid];
			else
				right = mid - 1;
		} else if (left == mid) {
			left = mid + 1;
		} else {
			left = mid;
		}

	}
	return nums[left];
}

// @lc code=end

int main(int argc, char **argv)
{
	// Test 1
	int input_1[size_1] = { 4, 5, 6, 7, 0, 1, 2 };
	printf("%d\n", findMin(input_1, size_1));

	// Test 2
	printf("%d\n", findMin(input_1, size_1));

	// Test 3
	int input_3[size_3] = { 1 };
	printf("%d\n", findMin(input_3, size_3));

	return 0;
}

// Accepted
// 150/150 cases passed (4 ms)
// Your runtime beats 54.09 % of c submissions
// Your memory usage beats 80.89 % of c submissions (6.6 MB)