/*
 * @lc app=leetcode id=350 lang=c
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (54.71%)
 * Likes:    5033
 * Dislikes: 756
 * Total Accepted:    875K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must appear as many times as it
 * shows in both arrays and you may return the result in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * Explanation: [9,4] is also accepted.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
	       int *returnSize)
{
	int table[1001] = { 0 };

	int *result = (int *)malloc(sizeof(int) * 1000);
	*returnSize = 0;

	for (int i = 0; i < nums1Size; i++)
		table[nums1[i]]++;
	for (int i = 0; i < nums2Size; i++)
		if (table[nums2[i]] > 0) {
			result[(*returnSize)++] = nums2[i];
			table[nums2[i]]--;
		}
	return result;
}

// @lc code=end

// Accepted
// 56/56 cases passed (4 ms)
// Your runtime beats 90.97 % of c submissions
// Your memory usage beats 39.92 % of c submissions (6.4 MB)
