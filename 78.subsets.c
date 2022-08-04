/*
 * @lc app=leetcode id=78 lang=c
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (71.05%)
 * Likes:    11276
 * Dislikes: 167
 * Total Accepted:    1.2M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **
subsets (int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
  *returnSize = 1 << numsSize;
  int **result = (int **) malloc (sizeof (int *) * (*returnSize));
  *returnColumnSizes = (int *) calloc (*returnSize, sizeof (int));

  for (int i = 0; i < *returnSize; i++)
    {
      (*returnColumnSizes)[i] = 0;
      int index = 1;
      result[i] = (int *) malloc (sizeof (int) * numsSize);
      // Every bits in j means whether nums[i] is in set
      for (int j = 0; j < numsSize; j++)
	{
	  if (((index << j) & i) != 0)
	    {
	      (*returnColumnSizes)[i]++;
	      result[i][(*returnColumnSizes)[i] - 1] = nums[j];
	    }

	}
    }

  return result;
}

// @lc code=end

// Accepted
// 10/10 cases passed (4 ms)
// Your runtime beats 93.07 % of c submissions
// Your memory usage beats 66.34 % of c submissions (6.4 MB)
