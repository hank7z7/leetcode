/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (33.10%)
 * Likes:    29138
 * Dislikes: 2642
 * Total Accepted:    3.1M
 * Total Submissions: 9.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TEST_SIZE_1 6
// @lc code=start
int cmp(const void* a, const void* b) { return *(int*) a - *(int*) b; }
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize        = 0;
    int   size_now     = 1000;
    int** result       = (int**) malloc(sizeof(int*) * size_now);
    *returnColumnSizes = (int*) malloc(sizeof(int) * size_now);

    // Sort
    qsort(nums, numsSize, sizeof(int), cmp);

    // first, second, and end
    int first, second, end;
    // first will eventaully find a solution
    for (first = 0; first <= (numsSize - 3); first++)
    {
        // Check if the first is duplicate
        if (!(first >= 1 && (nums[first] == nums[first - 1])))
        {
            end = numsSize - 1;
            for (second = first + 1; second < end; second++)
            {
                if (!(second >= (first + 2) && (nums[second] == nums[second - 1])))
                {
                    int sum = nums[first] + nums[second] + nums[end];
                    // Find one solution
                    if (sum == 0)
                    {
                        if (*returnSize == (size_now - 1))
                        {
                            result = (int**) realloc(result, sizeof(int*) * (size_now * 2));
                            *returnColumnSizes
                                = (int*) realloc(*returnColumnSizes, sizeof(int) * (size_now * 2));
                            size_now = size_now * 2;
                        }
                        result[*returnSize]               = (int*) malloc(sizeof(int) * 3);
                        result[*returnSize][0]            = nums[first];
                        result[*returnSize][1]            = nums[second];
                        result[*returnSize][2]            = nums[end];
                        (*returnColumnSizes)[*returnSize] = 3;
                        *returnSize                       = *returnSize + 1;
                    }
                    // Move end to left since the sum is already greater than zero
                    else if (sum > 0)
                    {
                        end--;
                        second--;
                    }
                }
            }
        }
    }

    // realloc the malloc
    result             = (int**) realloc(result, sizeof(int*) * (*returnSize));
    *returnColumnSizes = (int*) realloc(*returnColumnSizes, sizeof(int) * (*returnSize));

    return result;
}
// @lc code=end

int main(int argc, char** argv)
{
    int returnSize = 0;

    // Test 1
    int   size_1               = TEST_SIZE_1;
    int   input_1[TEST_SIZE_1] = { -1, 0, 1, 2, -1, -4 };
    int*  returnColumnSizes_1;
    int** result = threeSum(input_1, size_1, &returnSize, &returnColumnSizes_1);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes_1);

    return 0;
}

// Accepted
// 312/312 cases passed (214 ms)
// Your runtime beats 72.71 % of c submissions
// Your memory usage beats 27.62 % of c submissions (37.1 MB)