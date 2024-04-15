/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.46%)
 * Likes:    19430
 * Dislikes: 939
 * Total Accepted:    2.2M
 * Total Submissions: 4.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * A subarray is a contiguous part of an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 */

// @lc code=start

int maxSubArray(int *nums, int numsSize)
{
    int MaxPrefixSum = nums[0];
    int result = nums[0];
    int i;
    for (i = 1; i < numsSize; i++)
    {
        if (MaxPrefixSum > 0)   // Hard to understand!
            MaxPrefixSum += nums[i];
        else
            MaxPrefixSum = nums[i];

        if (MaxPrefixSum > result)
            result = MaxPrefixSum;
    }

    return result;
}
// @lc code=end

// Accepted
// 209/209 cases passed (118 ms)
// Your runtime beats 78.71 % of c submissions
// Your memory usage beats 73.75 % of c submissions (12.2 MB)