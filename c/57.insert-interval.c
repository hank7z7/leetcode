/*
 * @lc app=leetcode id=57 lang=c
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Medium (39.30%)
 * Likes:    9250
 * Dislikes: 680
 * Total Accepted:    883.6K
 * Total Submissions: 2.2M
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * You are given an array of non-overlapping intervals intervals where
 * intervals[i] = [starti, endi] represent the start and the end of the i^th
 * interval and intervals is sorted in ascending order by starti. You are also
 * given an interval newInterval = [start, end] that represents the start and
 * end of another interval.
 *
 * Insert newInterval into intervals such that intervals is still sorted in
 * ascending order by starti and intervals still does not have any overlapping
 * intervals (merge overlapping intervals if necessary).
 *
 * Return intervals after the insertion.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^5
 * intervals is sorted by starti in ascending order.
 * newInterval.length == 2
 * 0 <= start <= end <= 10^5
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

int** insert(int** intervals,
             int   intervalsSize,
             int*  intervalsColSize,
             int*  newInterval,
             int   newIntervalSize,
             int*  returnSize,
             int** returnColumnSizes)
{
    int** to_merge = (int**) malloc(sizeof(int*) * (intervalsSize + 1));
    for (int i = 0; i < (intervalsSize + 1); i++)
    {
        if (i == intervalsSize)
            to_merge[i] = newInterval;
        else
            to_merge[i] = intervals[i];
    }

    int** result
        = merge(to_merge, intervalsSize + 1, intervalsColSize, returnSize, returnColumnSizes);
    free(to_merge);
    return result;
}
// @lc code=end
#define SIZE_1 (2)
#define SIZE_2 (5)

int main(int argc, char** argv)
{
    // Test_1
    int   test_1[SIZE_1][INTERVAL_SIZE]      = { { 1, 3 }, { 6, 9 } };
    int*  test_1_to_pointer_of_array[SIZE_1] = { test_1[0], test_1[1] };
    int** interval_1                         = test_1_to_pointer_of_array;
    int   colsize_1[SIZE_1]                  = { 2, 2 };
    int   returnSize_1;
    int*  returnColSize_1;
    int   insert_1[INTERVAL_SIZE] = { 2, 5 };
    int** result_1                = insert(
        interval_1, SIZE_1, colsize_1, insert_1, INTERVAL_SIZE, &returnSize_1, &returnColSize_1);
    for (int i = 0; i < returnSize_1; i++)
    {
        printf("[%d, %d]%c", result_1[i][0], result_1[i][1], i == (returnSize_1 - 1) ? '\n' : ',');
        free(result_1[i]);
    }
    free(returnColSize_1);
    free(result_1);

    // Test_2
    int  test_2[SIZE_2][INTERVAL_SIZE] = { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } };
    int* test_2_to_pointer_of_array[SIZE_2]
        = { test_2[0], test_2[1], test_2[2], test_2[3], test_2[4] };
    int** interval_2        = test_2_to_pointer_of_array;
    int   colsize_2[SIZE_2] = { 2, 2, 2, 2, 2 };
    int   returnSize_2;
    int*  returnColSize_2;
    int   insert_2[INTERVAL_SIZE] = { 4, 8 };
    int** result_2                = insert(
        interval_2, SIZE_2, colsize_2, insert_2, INTERVAL_SIZE, &returnSize_2, &returnColSize_2);
    for (int i = 0; i < returnSize_2; i++)
    {
        printf("[%d, %d]%c", result_2[i][0], result_2[i][1], i == (returnSize_2 - 1) ? '\n' : ',');
        free(result_2[i]);
    }
    free(returnColSize_2);
    free(result_2);
    return 0;
}
// Accepted
// 156/156 cases passed (16 ms)
// Your runtime beats 40.15 % of c submissions
// Your memory usage beats 19.7 % of c submissions (9 MB)