/*
 * @lc app=leetcode id=1291 lang=c
 *
 * [1291] Sequential Digits
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
#define TABLE_SIZE 36
int table[TABLE_SIZE]
    = { 12,     23,     34,     45,      56,      67,      78,       89,       123,
        234,    345,    456,    567,     678,     789,     1234,     2345,     3456,
        4567,   5678,   6789,   12345,   23456,   34567,   45678,    56789,    123456,
        234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789 };
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize)
{
    int* result = (int*) malloc(sizeof(int) * TABLE_SIZE);
    *returnSize = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] >= low && table[i] <= high)
        {
            result[*returnSize] = table[i];
            (*returnSize)++;
        }
    }
    return result;
}
// @lc code=end
int main(int argc, char** argv)
{
    int low, high, returnSize;
    // Test 1
    low           = 100;
    high          = 300;
    int* result_1 = sequentialDigits(low, high, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d%c", result_1[i], (i == (returnSize - 1)) ? '\n' : ' ');
    free(result_1);

    // Test 1
    low           = 1000;
    high          = 13000;
    int* result_2 = sequentialDigits(low, high, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d%c", result_2[i], (i == (returnSize - 1)) ? '\n' : ' ');
    free(result_2);

    return 0;
}
// Accepted
// 23/23 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 66.67 % of c submissions (5.8 MB)