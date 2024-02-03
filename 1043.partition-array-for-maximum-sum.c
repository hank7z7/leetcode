/*
 * @lc app=leetcode id=1043 lang=c
 *
 * [1043] Partition Array for Maximum Sum
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
#define max(a, b)                                                                                  \
    ({                                                                                             \
        __typeof__(a) _a = (a);                                                                    \
        __typeof__(b) _b = (b);                                                                    \
        _a > _b ? _a : _b;                                                                         \
    })

int maxSumAfterPartitioning(int* arr, int arrSize, int k)
{
    int result = 0;
    /*
    dp[i] = the maximum of dp[i-j] + max(A[i-1], ..., A[i-j]) * j
    j = 1 ~ k
    */
    int* dp = (int*) malloc(sizeof(int) * (arrSize + 1));
    dp[0] = 0;
    for (int i = 1; i <= arrSize; i++)
    {
        int currMax = 0;
        // Divide arr[0:i] into two subarray arr[0:(i-j-1)] and arr[(i-j):i]
        // The max of j = k
        for (int j = 1; j <= k && (i - j) >= 0; j++)
        {
            currMax = max(currMax, arr[i - j]);
            dp[i]   = max(dp[i], dp[i - j] + currMax * j);
        }
    }
    result = dp[arrSize];
    free(dp);
    return result;
}
// @lc code=end
#define SIZE_1 7
#define SIZE_2 11
#define SIZE_3 1
int main(int argc, char** argv)
{
    int k;
    // Test 1
    int size_1 = SIZE_1;
    // 1, 15, 7 | 9 | 2, 5, 10
    int arr_1[SIZE_1] = { 1, 15, 7, 9, 2, 5, 10 };
    k                 = 3;
    printf("%d\n", maxSumAfterPartitioning(arr_1, size_1, k));

    // Test 2
    int size_2        = SIZE_2;
    int arr_2[SIZE_2] = { 1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3 };
    k                 = 4;
    printf("%d\n", maxSumAfterPartitioning(arr_2, size_2, k));

    // Test 3
    int size_3        = SIZE_3;
    int arr_3[SIZE_3] = { 1 };
    k                 = 1;
    printf("%d\n", maxSumAfterPartitioning(arr_3, size_3, k));

    return 0;
}
// Accepted
// 52/52 cases passed (10 ms)
// Your runtime beats 92.31 % of c submissions
// Your memory usage beats 100 % of c submissions (5.7 MB)