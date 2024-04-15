/*
 * @lc app=leetcode id=739 lang=c
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (65.92%)
 * Likes:    12177
 * Dislikes: 283
 * Total Accepted:    791.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 *
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    *returnSize    = temperaturesSize;
    int* result    = (int*) malloc(sizeof(int) * temperaturesSize);
    int  stack_top = 0;
    int* stack     = (int*) malloc(sizeof(int) * temperaturesSize);

    for (int i = 0; i < temperaturesSize; i++)
    {
        if (stack_top == 0)
        {
            stack[stack_top] = i;
            stack_top++;
        }
        else
        {
            while (stack_top >= 1 && temperatures[i] > temperatures[stack[stack_top - 1]])
            {
                // Pop the stack
                result[stack[stack_top - 1]] = i - stack[stack_top - 1];
                stack_top--;
            }
            // Push back the stack
            stack[stack_top] = i;
            stack_top++;
        }
    }
    for (int i = 0; i < stack_top; i++)
        result[stack[i]] = 0;
    free(stack);
    return result;
}
// @lc code=end
#define SIZE_1 8
#define SIZE_2 4
#define SIZE_3 3
int main(int argc, char** argv)
{
    int returnSize = 0;
    // Test 1
    int  size_1          = SIZE_1;
    int  input_1[SIZE_1] = { 73, 74, 75, 71, 69, 72, 76, 73 };
    int* result_1        = dailyTemperatures(input_1, size_1, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d%c", result_1[i], (i == (returnSize - 1)) ? '\n' : ' ');
    free(result_1);

    // Test 2
    int  size_2          = SIZE_2;
    int  input_2[SIZE_2] = { 30, 40, 50, 60 };
    int* result_2        = dailyTemperatures(input_2, size_2, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d%c", result_2[i], (i == (returnSize - 1)) ? '\n' : ' ');
    free(result_2);

    // Test 3
    int  size_3          = SIZE_3;
    int  input_3[SIZE_3] = { 30, 60, 90 };
    int* result_3        = dailyTemperatures(input_3, size_3, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d%c", result_3[i], (i == (returnSize - 1)) ? '\n' : ' ');
    free(result_3);
    return 0;
}
// Accepted
// 48/48 cases passed (462 ms)
// Your runtime beats 95.86 % of c submissions
// Your memory usage beats 49.7 % of c submissions (65.5 MB)