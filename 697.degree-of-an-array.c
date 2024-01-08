/*
 * @lc app=leetcode id=697 lang=c
 *
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (56.29%)
 * Likes:    2948
 * Dislikes: 1687
 * Total Accepted:    201.7K
 * Total Submissions: 358.1K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 *
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,2,3,1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,2,3,1,4,2]
 * Output: 6
 * Explanation:
 * The degree is 3 because the element 2 is repeated 3 times.
 * So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 *
 *
 *
 * Constraints:
 *
 *
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// @lc code=start
#define SIZE 50000

int findShortestSubArray(int* nums, int numsSize)
{
    int count[SIZE]       = { 0 };
    int start_index[SIZE] = { 0 };
    int end_index[SIZE]   = { 0 };
    // int* count = (int*)malloc(sizeof(int) * SIZE);
    // memset(count, 0, sizeof(int) * SIZE);
    // int* start_index = (int*)malloc(sizeof(int) * SIZE);
    // memset(start_index, 0, sizeof(int) * SIZE);
    // int* end_index = (int*)malloc(sizeof(int) * SIZE);
    // memset(end_index, 0, sizeof(int) * SIZE);
    int max_count = 0;
    int max       = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > max)
            max = nums[i];
        if (count[nums[i]] == 0)
        {
            start_index[nums[i]] = i;
        }
        count[nums[i]]++;
        end_index[nums[i]] = i;
        if (count[nums[i]] > max_count)
        {
            max_count = count[nums[i]];
        }
    }

    int min_length = INT_MAX;
    for (int i = 0; i <= max; i++)
    {
        if (count[i] == max_count)
            if (end_index[i] - start_index[i] + 1 < min_length)
                min_length = end_index[i] - start_index[i] + 1;
    }

    // free(count);
    // free(start_index);
    // free(end_index);
    return min_length;
}
// @lc code=end
int main(int argc, char** argv)
{
    int size_1    = 5;
    int input_1[] = { 1, 2, 2, 3, 1 };
    printf("%d\n", findShortestSubArray(input_1, size_1));

    int size_2    = 7;
    int input_2[] = { 1, 2, 2, 3, 1, 4, 2 };
    printf("%d\n", findShortestSubArray(input_2, size_2));

    return 0;
}

// Accepted
// 89/89 cases passed (24 ms)
// Your runtime beats 59.38 % of c submissions
// Your memory usage beats 81.25 % of c submissions (8.5 MB)