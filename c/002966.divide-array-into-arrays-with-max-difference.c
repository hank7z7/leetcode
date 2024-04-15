/*
 * @lc app=leetcode id=2966 lang=c
 *
 * [2966] Divide Array Into Arrays With Max Difference
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define GROUP_SIZE 3

int cmp(const void* a, const void* b) { return *(int*) a - *(int*) b; }

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes)
{
    int size           = (numsSize % GROUP_SIZE) ? 0 : (numsSize / GROUP_SIZE);
    *returnColumnSizes = (int*) malloc(sizeof(int) * size);
    int** result       = (int**) malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++)
    {
        result[i]               = (int*) malloc(sizeof(int) * GROUP_SIZE);
        (*returnColumnSizes)[i] = GROUP_SIZE;
    }
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), cmp);
    bool is_valid = true;
    for (int i = 0; i < numsSize; i += GROUP_SIZE)
    {
        if ((nums[i + 2] - nums[i]) > k)
        {
            is_valid = false;
            break;
        }
        else
        {
            (*returnSize)++;
            for (int j = 0; j < GROUP_SIZE; j++)
                result[i / 3][0 + j] = nums[i + j];
        }
    }

    if (!is_valid)
    {
        *returnSize = 0;
        for (int i = 0; i < size; i++)
            free(result[i]);
    }

    return result;
}
// @lc code=end
#define SIZE_1 9
#define SIZE_2 6
int main(int argc, char** argv)
{
    int size;
    int k;
    int returnSize = 0;

    // Test 1
    size = SIZE_1;
    k    = 2;
    int*  returnColumnSizes_1;
    int   input_1[SIZE_1] = { 1, 3, 4, 8, 7, 9, 3, 5, 1 };
    int** result_1        = divideArray(input_1, size, k, &returnSize, &returnColumnSizes_1);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes_1[i]; j++)
            printf("%d%c", result_1[i][j], (j == (returnColumnSizes_1[i] - 1)) ? ',' : ' ');
    }
    printf("\n");
    for (int i = 0; i < returnSize; i++)
    {
        free(result_1[i]);
    }
    free(result_1);
    free(returnColumnSizes_1);

    // Test 2
    size = SIZE_2;
    k    = 2;
    int*  returnColumnSizes_2;
    int   input_2[SIZE_2] = { 1, 3, 3, 2, 7, 3 };
    int** result_2        = divideArray(input_2, size, k, &returnSize, &returnColumnSizes_2);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes_2[i]; j++)
            printf("%d%c", result_2[i][j], (j == (returnColumnSizes_2[i] - 1)) ? ',' : ' ');
    }
    printf("\n");
    for (int i = 0; i < returnSize; i++)
    {
        free(result_2[i]);
    }
    free(result_2);
    free(returnColumnSizes_2);
    return 0;
}
// Accepted
// 103/103 cases passed (669 ms)
// Your runtime beats 94.12 % of c submissions
// Your memory usage beats 85.29 % of c submissions (89.0 MB)