/*
 * @lc app=leetcode id=496 lang=c
 *
 * [496] Next Greater Element I
 *
 * https://leetcode.com/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (69.85%)
 * Likes:    3899
 * Dislikes: 249
 * Total Accepted:    410.5K
 * Total Submissions: 578.7K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 * The next greater element of some element x in an array is the first greater
 * element that is to the right of x in the same array.
 * 
 * You are given two distinct 0-indexed integer arrays nums1 and nums2, where
 * nums1 is a subset of nums2.
 * 
 * For each 0 <= i < nums1.length, find the index j such that nums1[i] ==
 * nums2[j] and determine the next greater element of nums2[j] in nums2. If
 * there is no next greater element, then the answer for this query is -1.
 * 
 * Return an array ans of length nums1.length such that ans[i] is the next
 * greater element as described above.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
 * Output: [-1,3,-1]
 * Explanation: The next greater element for each value of nums1 is as follows:
 * - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so
 * the answer is -1.
 * - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
 * - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so
 * the answer is -1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [2,4], nums2 = [1,2,3,4]
 * Output: [3,-1]
 * Explanation: The next greater element for each value of nums1 is as follows:
 * - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
 * - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so
 * the answer is -1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * All integers in nums1 and nums2 are unique.
 * All the integers of nums1 also appear in nums2.
 * 
 * 
 * 
 * Follow up: Could you find an O(nums1.length + nums2.length) solution?
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size,
			int *returnSize)
{
	int *result = malloc(sizeof(int) * nums1Size);
	(*returnSize) = nums1Size;

	int *index_table = (int *)malloc(sizeof(int) * 10001);
	memset(index_table, 0, sizeof(int) * 10001);

	int *next_greater = (int *)malloc(sizeof(int) * nums2Size);
	memset(next_greater, -1, sizeof(int) * nums2Size);
	for (int i = 0; i < nums2Size; i++) {
		// Fill index_table
		index_table[nums2[i]] = i;
		// Fill next_greater table
		for (int j = i; j < nums2Size; j++) {
			if (nums2[j] > nums2[i]) {
				next_greater[i] = nums2[j];
				break;
			}
		}
	}

	// Fill result
	for (int i = 0; i < nums1Size; i++) {
		result[i] = next_greater[index_table[nums1[i]]];
	}
    
    // Free can be slower
    free(index_table);
    free(next_greater);
	return result;
}

// @lc code=end

// Accepted
// 15/15 cases passed (7 ms)
// Your runtime beats 92.86 % of c submissions
// Your memory usage beats 8.79 % of c submissions (7.1 MB)
