/*
 * @lc app=leetcode id=152 lang=c
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (34.88%)
 * Likes:    17660
 * Dislikes: 562
 * Total Accepted:    1.1M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find a subarray that has the largest product,
 * and return the product.
 *
 * The test cases are generated so that the answer will fit in a 32-bit
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 *
 */
#include <stdio.h>
#include <limits.h>

#define SIZE_1 4
#define SIZE_2 3

// @lc code=start
#define max(a, b)                                                                                  \
    ({                                                                                             \
        __typeof__(a) _a = (a);                                                                    \
        __typeof__(b) _b = (b);                                                                    \
        _a > _b ? _a : _b;                                                                         \
    })
#define min(a, b)                                                                                  \
    ({                                                                                             \
        __typeof__(a) _a = (a);                                                                    \
        __typeof__(b) _b = (b);                                                                    \
        _a < _b ? _a : _b;                                                                         \
    })

int maxProduct(int* nums, int numsSize)
{
    int max_ending_here = 1;
    // Keep tracking the largest and the smallest product
    // Since  the largest in the negative sense could become the maximum when being multiplied by a
    // negative number
    int min_ending_here = 1;
    int max_so_far      = INT_MIN;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            max_ending_here = max(nums[i], max_ending_here * nums[i]);
            min_ending_here = min(nums[i], min_ending_here * nums[i]);
        }
        else
        {
            int tmp         = max_ending_here;
            max_ending_here = max(nums[i], min_ending_here * nums[i]);
            min_ending_here = min(nums[i], tmp * nums[i]);
        }

        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}
// @lc code=end

int main(int argc, char** argv)
{
    int size_1         = SIZE_1;
    int nums_1[SIZE_1] = { 2, 3, -2, 4 };
    printf("%d\n", maxProduct(nums_1, size_1));

    int size_2         = SIZE_2;
    int nums_2[SIZE_2] = { -2, 0, -1 };
    printf("%d\n", maxProduct(nums_2, size_2));

    int size_3         = SIZE_2;
    int nums_3[SIZE_2] = { -4, -3, -2 };
    printf("%d\n", maxProduct(nums_3, size_3));

    return 0;
}

// Accepted
// 190/190 cases passed (8 ms)
// Your runtime beats 23.19 % of c submissions
// Your memory usage beats 88.41 % of c submissions (7.1 MB)