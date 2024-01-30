/*
 * @lc app=leetcode id=724 lang=c
 *
 * [724] Find Pivot Index
 */
#include <stdio.h>
// @lc code=start
int pivotIndex(int* nums, int numsSize)
{
    int prev = 0;
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] += prev;
        prev = nums[i];
    }

    for (int i = 0; i < numsSize; i++)
    {
        int l_sum = (i == 0) ? 0 : nums[i - 1];
        int r_sum = nums[numsSize - 1] - nums[i];
        if (l_sum == r_sum)
        {
            return i;
        }
    }

    return -1;
}
// @lc code=end
#define SIZE_1 6
#define SIZE_2 3
#define SIZE_3 6
int main(int argc, char** argv)
{
    // Test 1
    int size_1          = SIZE_1;
    int input_1[SIZE_1] = { 1, 7, 3, 6, 5, 6 };
    printf("%d\n", pivotIndex(input_1, size_1));

    // Test 2
    int size_2          = SIZE_2;
    int input_2[SIZE_2] = { 1, 2, 3 };
    printf("%d\n", pivotIndex(input_2, size_2));

    // Test 3
    int size_3          = SIZE_3;
    int input_3[SIZE_3] = { -1, -1, 0, 0, -1, -1 };
    printf("%d\n", pivotIndex(input_3, size_3));
}
// Accepted
// 746/746 cases passed (14 ms)
// Your runtime beats 77.37 % of c submissions
// Your memory usage beats 95.26 % of c submissions (6.2 MB)