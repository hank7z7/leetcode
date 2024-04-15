/*
 * @lc app=leetcode id=238 lang=c
 *
 * [238] Product of Array Except Self
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int prefix_product[numsSize];
    int suffix_product[numsSize];
    // int result[numsSize];
    int* result = malloc(numsSize * sizeof(int));
    int  i      = 0;

    for (i = 0; i < numsSize; i++)
    {
        if (i == 0)
        {
            prefix_product[i]                = nums[i];
            suffix_product[numsSize - i - 1] = nums[numsSize - i - 1];
        }
        else
        {
            prefix_product[i] = nums[i] * prefix_product[i - 1];
            suffix_product[numsSize - i - 1]
                = nums[numsSize - i - 1] * suffix_product[numsSize - i];
        }
    }

    for (i = 0; i < numsSize; i++)
    {
        if (i == 0)
            result[i] = suffix_product[i + 1];
        else if (i == (numsSize - 1))
            result[i] = prefix_product[i - 1];
        else
            result[i] = prefix_product[i - 1] * suffix_product[i + 1];
    }

    *returnSize = numsSize;
    return result;
}

// @lc code=end
int main(int argc, char** argv)
{
    int size;
    int returnSize;
    // Test_1
    size          = 4;
    int  nums_1[] = { 1, 2, 3, 4 };
    int* ret_1    = productExceptSelf(nums_1, size, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", ret_1[i]);
    printf("\n");
    free(ret_1);

    // Test_2
    size          = 4;
    int  nums_2[] = { -1, 1, 0, -3, 3 };
    int* ret_2    = productExceptSelf(nums_2, size, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", ret_2[i]);
    printf("\n");
    free(ret_2);

    return 0;
}

// Accepted
// 22/22 cases passed (85 ms)
// Your runtime beats 83.82 % of c submissions
// Your memory usage beats 48.69 % of c submissions (18.8 MB)
