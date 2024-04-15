/*
 * @lc app=leetcode id=349 lang=c
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (68.78%)
 * Likes:    3367
 * Dislikes: 1970
 * Total Accepted:    714.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
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
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size,
		  int *returnSize)
{
	int table[1001] = { 0 };

	int *result = (int *)malloc(sizeof(int) * 1000);
	*returnSize = 0;

	for (int i = 0; i < nums1Size; i++)
		table[nums1[i]] = 1;
	for (int i = 0; i < nums2Size; i++)
		if (table[nums2[i]] == 1) {
			result[(*returnSize)++] = nums2[i];
			table[nums2[i]] = 2;
		}
	return result;
}

// @lc code=end

// Accepted
// 55/55 cases passed (6 ms)
// Your runtime beats 76.26 % of c submissions
// Your memory usage beats 42.41 % of c submissions (6.6 MB)