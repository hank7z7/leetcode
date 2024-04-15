/*
 * @lc app=leetcode id=56 lang=c
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (46.44%)
 * Likes:    21180
 * Dislikes: 721
 * Total Accepted:    2.1M
 * Total Submissions: 4.5M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlap, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define max(a, b)                                                                                  \
    ({                                                                                             \
        __typeof__(a) _a = (a);                                                                    \
        __typeof__(b) _b = (b);                                                                    \
        _a > _b ? _a : _b;                                                                         \
    })
#define INTERVAL_SIZE (2)
int cmp(const void** a, const void** b)
{
    if ((*(int**) a)[0] > (*(int**) b)[0])
        return 1;
    else if ((*(int**) a)[0] == (*(int**) b)[0])
    {
        return (*(int**) a)[1] < (*(int**) b)[1];
    }
    else
        return -1;
}

int** merge(int** intervals,
            int   intervalsSize,
            int*  intervalsColSize,
            int*  returnSize,
            int** returnColumnSizes)
{
    // Malloc result
    int** result = (int**) malloc(sizeof(int*) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++)
        result[i] = (int*) malloc(sizeof(int) * INTERVAL_SIZE);
    // Initialize result size
    *returnSize = 0;
    // Malloc and initialize return ColumnSizes
    *returnColumnSizes = (int*) malloc(sizeof(int) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++)
        (*returnColumnSizes)[i] = INTERVAL_SIZE;

    // Sort by the left interval
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);

    for (int i = 0; i < intervalsSize; i++)
    {
        // Fill left interval
        result[*returnSize][0] = intervals[i][0];
        int max_r              = intervals[i][1];
        // Find the index of the right interval
        while ((i + 1) < intervalsSize
               && (max_r >= intervals[i + 1][0] || max_r >= intervals[i + 1][1]))
        {
            i++;
            max_r = max(max_r, intervals[i][1]);
        }
        // Fill right interval
        result[*returnSize][1] = max_r;
        // Update result size
        (*returnSize)++;
    }
    // Free the remainning result
    for (int i = (*returnSize); i < intervalsSize; i++)
        free(result[i]);
    return result;
}
// @lc code=end
#define SIZE_1 (4)
#define SIZE_2 (2)
#define SIZE_3 (2)
#define SIZE_4 (5)
int main(int argc, char** argv)
{
    // Test_1
    int   test_1[SIZE_1][INTERVAL_SIZE]      = { { 1, 4 }, { 2, 6 }, { 15, 18 }, { 8, 10 } };
    int*  test_1_to_pointer_of_array[SIZE_1] = { test_1[0], test_1[1], test_1[2], test_1[3] };
    int** interval_1                         = test_1_to_pointer_of_array;
    int   colsize_1[SIZE_1]                  = { 2, 2, 2, 2 };
    int   returnSize_1;
    int*  returnColSize_1;
    int** result_1 = merge(interval_1, SIZE_1, colsize_1, &returnSize_1, &returnColSize_1);
    for (int i = 0; i < returnSize_1; i++)
    {
        printf("[%d, %d]%c", result_1[i][0], result_1[i][1], i == (returnSize_1 - 1) ? '\n' : ',');
        free(result_1[i]);
    }
    free(returnColSize_1);
    free(result_1);

    // Test_2
    int   test_2[SIZE_2][INTERVAL_SIZE]      = { { 1, 4 }, { 4, 5 } };
    int*  test_2_to_pointer_of_array[SIZE_2] = { test_2[0], test_2[1] };
    int** interval_2                         = test_2_to_pointer_of_array;
    int   colsize_2[SIZE_2]                  = { 2, 2 };
    int   returnSize_2;
    int*  returnColSize_2;
    int** result_2 = merge(interval_2, SIZE_2, colsize_2, &returnSize_2, &returnColSize_2);
    for (int i = 0; i < returnSize_2; i++)
    {
        printf("[%d, %d]%c", result_2[i][0], result_2[i][1], i == (returnSize_2 - 1) ? '\n' : ',');
        free(result_2[i]);
    }
    free(returnColSize_2);
    free(result_2);

    // Test_3
    int   test_3[SIZE_3][INTERVAL_SIZE]      = { { 1, 4 }, { 2, 3 } };
    int*  test_3_to_pointer_of_array[SIZE_3] = { test_3[0], test_3[1] };
    int** interval_3                         = test_3_to_pointer_of_array;
    int   colsize_3[SIZE_3]                  = { 2, 2 };
    int   returnSize_3;
    int*  returnColSize_3;
    int** result_3 = merge(interval_3, SIZE_3, colsize_3, &returnSize_3, &returnColSize_3);
    for (int i = 0; i < returnSize_3; i++)
    {
        printf("[%d, %d]%c", result_3[i][0], result_3[i][1], i == (returnSize_3 - 1) ? '\n' : ',');
        free(result_3[i]);
    }
    free(returnColSize_3);
    free(result_3);

    // Test_4
    int  test_4[SIZE_4][INTERVAL_SIZE] = { { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 9 }, { 1, 10 } };
    int* test_4_to_pointer_of_array[SIZE_4]
        = { test_4[0], test_4[1], test_4[2], test_4[3], test_4[4] };
    int** interval_4        = test_4_to_pointer_of_array;
    int   colsize_4[SIZE_4] = { 2, 2, 2, 2, 2 };
    int   returnSize_4;
    int*  returnColSize_4;
    int** result_4 = merge(interval_4, SIZE_4, colsize_4, &returnSize_4, &returnColSize_4);
    for (int i = 0; i < returnSize_4; i++)
    {
        printf("[%d, %d]%c", result_4[i][0], result_4[i][1], i == (returnSize_4 - 1) ? '\n' : ',');
        free(result_4[i]);
    }
    free(returnColSize_4);
    free(result_4);
    return 0;
}
// Accepted
// 170/170 cases passed (55 ms)
// Your runtime beats 34.16 % of c submissions
// Your memory usage beats 48.51 % of c submissions (13 MB)