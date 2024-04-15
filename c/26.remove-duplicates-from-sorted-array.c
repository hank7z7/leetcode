/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include <stdio.h>
// @lc code=start
int removeDuplicates(int* nums, int numsSize)
{
    int first  = 0;
    int second = 0;
    for (int second = 0; second < numsSize; second++)
    {
        if (nums[second] != nums[first])
        {
            first++;
            nums[first] = nums[second];
        }
    }
    return first + 1;
}
// @lc code=end
#define SIZE_1 3
#define SIZE_2 10
int main(int argc, char** argv)
{
    int returnSize;
    // Test 1
    int size_1         = SIZE_1;
    int test_1[SIZE_1] = { 1, 1, 2 };
    returnSize         = removeDuplicates(test_1, size_1);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", test_1[i]);
    printf("\n");

    // Test 2
    int size_2         = SIZE_2;
    int test_2[SIZE_2] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    returnSize         = removeDuplicates(test_2, size_2);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", test_2[i]);
    printf("\n");

    return 0;
}
// Accepted
// 362/362 cases passed (7 ms)
// Your runtime beats 94.88 % of c submissions
// Your memory usage beats 93.95 % of c submissions (7.2 MB)