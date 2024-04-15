/*
 * @lc app=leetcode id=2971 lang=c
 *
 * [2971] Find Polygon With the Largest Perimeter
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// @lc code=start
int cmp(const void* a, const void* b) { return *(int*) a - *(int*) b; }

long long largestPerimeter(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    long long prev = 0;
    long long curr;
    long long max_perimeter = -1;
    // Prefix sum
    for (int i = 0; i < numsSize; i++)
    {
        curr = (long long) nums[i];
        // If prefix sum of [0:i-1] edges is greater than the current edge, the polygon is valid
        if (i >= 2 && prev > curr)
            max_perimeter = prev + curr;
        prev += curr;
    }

    return max_perimeter;
}
// @lc code=end
#define SIZE_1 3
#define SIZE_2 7
#define SIZE_3 3
#define SIZE_4 6
int main(int argc, char** argv)
{
    // Test_1
    int nums_1[SIZE_1] = { 5, 5, 5 };
    printf("%lld\n", largestPerimeter(nums_1, SIZE_1));

    // Test_2
    int nums_2[SIZE_2] = { 1, 12, 1, 2, 5, 50, 3 };
    printf("%lld\n", largestPerimeter(nums_2, SIZE_2));

    // Test_3
    int nums_3[SIZE_3] = { 5, 5, 50 };
    printf("%lld\n", largestPerimeter(nums_3, SIZE_3));

    // Test_4
    int nums_4[SIZE_4] = { 1, 1, 1, 10, 12, 21 };
    printf("%lld\n", largestPerimeter(nums_4, SIZE_4));
    return 0;
}
// Accepted
// 980/980 cases passed (206 ms)
// Your runtime beats 67.86 % of c submissions
// Your memory usage beats 71.43 % of c submissions (15 MB)