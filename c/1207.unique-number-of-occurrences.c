/*
 * @lc app=leetcode id=1207 lang=c
 *
 * [1207] Unique Number of Occurrences
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE_1 6
#define SIZE_2 2
#define SIZE_3 10
// @lc code=start
#define ARR_MIN_VAL (-1000)
#define COUNT_SIZE (2001)

int cmp(const void* a, const void* b) { return *(int*) a - *(int*) b; }

bool uniqueOccurrences(int* arr, int arrSize)
{
    int count[COUNT_SIZE] = { 0 };
    for (int i = 0; i < arrSize; i++)
        count[arr[i] - ARR_MIN_VAL]++;
    qsort(count, COUNT_SIZE, sizeof(int), cmp);
    for (int i = 1; i < COUNT_SIZE; i++)
    {
        if (count[i] != 0 && (count[i] == count[i - 1]))
            return false;
    }
    return true;
}
// @lc code=end
int main(int argc, char** argv)
{
    int size_1        = SIZE_1;
    int arr_1[SIZE_1] = { 1, 2, 2, 1, 1, 3 };
    printf("%d\n", uniqueOccurrences(arr_1, size_1));
    int size_2        = SIZE_2;
    int arr_2[SIZE_2] = { 1, 2 };
    printf("%d\n", uniqueOccurrences(arr_2, size_2));
    int size_3        = SIZE_3;
    int arr_3[SIZE_3] = { -3, 0, 1, -3, 1, 1, 1, -3, 10, 0 };
    printf("%d\n", uniqueOccurrences(arr_3, size_3));
    return 0;
}
// Accepted
// 67/67 cases passed (12 ms)
// Your runtime beats 13.13 % of c submissions
// Your memory usage beats 11.11 % of c submissions (7.7 MB)