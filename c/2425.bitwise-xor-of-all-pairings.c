/*
 * @lc app=leetcode id=2425 lang=c
 *
 * [2425] Bitwise XOR of All Pairings
 */
#include <stdio.h>
// @lc code=start
int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int result = 0;
    if ((!(nums1Size & 1)) && (!(nums2Size & 1)))
        return 0;
    if ((nums1Size & 1))
    {
        for (int i = 0; i < nums2Size; i++)
            result ^= nums2[i];
    }
    if ((nums2Size & 1))
    {
        for (int i = 0; i < nums1Size; i++)
            result ^= nums1[i];
    }

    return result;
}
// @lc code=end

int main()
{
    int size_1_1    = 3;
    int input_1_1[] = { 2, 1, 3 };
    int size_1_2    = 4;
    int input_1_2[] = { 10, 2, 5, 0 };
    printf("%d\n", xorAllNums(input_1_1, size_1_1, input_1_2, size_1_2));

    int size_2_1    = 2;
    int input_2_1[] = { 1, 2 };
    int size_2_2    = 2;
    int input_2_2[] = { 3, 4 };
    printf("%d\n", xorAllNums(input_2_1, size_2_1, input_2_2, size_2_2));
    return 0;
}
// Accepted
// 42/42 cases passed (90 ms)
// Your runtime beats 58.33 % of c submissions
// Your memory usage beats 33.33 % of c submissions (14.7 MB)