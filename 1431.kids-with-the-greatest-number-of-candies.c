/*
 * @lc app=leetcode id=1431 lang=c
 *
 * [1431] Kids With the Greatest Number of Candies
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
    *returnSize  = candiesSize;
    bool* result = (bool*) malloc(sizeof(bool) * candiesSize);
    int   max    = 0;
    for (int i = 0; i < candiesSize; i++)
        if (candies[i] > max)
            max = candies[i];
    for (int i = 0; i < candiesSize; i++)
        if ((candies[i] + extraCandies) >= max)
            result[i] = true;
        else
            result[i] = false;
    return result;
}
// @lc code=end
#define SIZE_1 5
#define SIZE_2 5
#define SIZE_3 3

int main(int argc, char** argv)
{
    int returnSize   = 0;
    int extraCandies = 0;
    // Test 1
    int size_1          = SIZE_1;
    int input_1[SIZE_1] = { 2, 3, 5, 1, 3 };
    extraCandies        = 3;
    bool* result_1      = kidsWithCandies(input_1, size_1, extraCandies, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result_1[i]);
    printf("\n");
    free(result_1);

    // Test 2
    int size_2          = SIZE_2;
    int input_2[SIZE_2] = { 4, 2, 1, 1, 2 };
    extraCandies        = 1;
    bool* result_2      = kidsWithCandies(input_2, size_2, extraCandies, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result_2[i]);
    printf("\n");
    free(result_2);

    // Test 3
    int size_3          = SIZE_3;
    int input_3[SIZE_3] = { 12, 1, 12 };
    extraCandies        = 10;
    bool* result_3      = kidsWithCandies(input_3, size_3, extraCandies, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result_3[i]);
    printf("\n");
    free(result_3);
    return 0;
}
// Accepted
// 103/103 cases passed (5 ms)
// Your runtime beats 57.62 % of c submissions
// Your memory usage beats 94.84 % of c submissions (5.9 MB)