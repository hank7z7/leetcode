/*
 * @lc app=leetcode id=594 lang=c
 *
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (52.59%)
 * Likes:    1665
 * Dislikes: 158
 * Total Accepted:    122K
 * Total Submissions: 230.1K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 *
 * Given an integer array nums, return the length of its longest harmonious
 * subsequence among all its possible subsequences.
 *
 * A subsequence of array is a sequence that can be derived from the array by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4]
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 */
// @lc code=start
int cmp(const void *a, const void *b) { return *(int *)a > *(int *)b; }

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int findLHS(int *nums, int numsSize) {
  int result = 0, start = 0, new_start = 0;
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] - nums[start] > 1)
      start = new_start;
    if (nums[i] != nums[i - 1])
      new_start = i;
    if (nums[i] - nums[start] == 1)
      result = MAX(result, i - start + 1);
  }
  return result;
}

// @lc code=end

// Accepted
// 206/206 cases passed (139 ms)
// Your runtime beats 18.75 % of c submissions
// Your memory usage beats 52.08 % of c submissions (8.8 MB)
