/*
 * @lc app=leetcode id=977 lang=c
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.80%)
 * Likes:    8982
 * Dislikes: 224
 * Total Accepted:    1.7M
 * Total Submissions: 2.4M
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 *
 *
 *
 * Follow up: Squaring each element and sorting the new array is very trivial,
 * could you find an O(n) solution using a different approach?
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int  l      = 0;
    int  r      = numsSize - 1;
    int  target = 0;
    int* ret    = (int*) malloc(sizeof(int) * numsSize);
    for (int i = ((int) numsSize - 1); i >= 0; i--)
    {
        if (abs(nums[l]) > abs(nums[r]))
        {
            target = l;
            l++;
        }
        else
        {
            target = r;
            r--;
        }
        ret[i] = pow(abs(nums[target]), 2);
    }
    return ret;
}
// @lc code=end
#define SIZE 5
int main(int argc, char** argv)
{
    int size       = SIZE;
    int returnSize = 0;
    // Test_1
    int  nums_1[] = { -4, -1, 0, 3, 10 };
    int* ret_1    = sortedSquares(nums_1, size, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", ret_1[i]);
    printf("\n");
    free(ret_1);

    // Test_2
    int  nums_2[] = { -7, -3, 2, 3, 11 };
    int* ret_2    = sortedSquares(nums_2, size, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", ret_2[i]);
    printf("\n");
    free(ret_2);
    return 0;
}
// Accepted
// 137/137 cases passed (90 ms)
// Your runtime beats 95.93 % of c submissions
// Your memory usage beats 27.47 % of c submissions (20.2 MB)