/*
 * @lc app=leetcode id=1732 lang=c
 *
 * [1732] Find the Highest Altitude
 */
#include <stdio.h>
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

int largestAltitude(int* gain, int gainSize)
{
    int result = 0;
    // Current altitude
    int curr_alt = 0;
    for (int i = 0; i < gainSize; i++)
    {
        curr_alt += gain[i];
        result = max(result, curr_alt);
    }

    return result;
}
// @lc code=end
#define SIZE_1 5
#define SIZE_2 7

int main(int argc, char** argv)
{
    // Test 1
    int size_1          = SIZE_1;
    int input_1[SIZE_1] = { -5, 1, 5, 0, -7 };
    printf("%d\n", largestAltitude(input_1, size_1));

    // Test 2
    int size_2          = SIZE_2;
    int input_2[SIZE_2] = { -4, -3, -2, -1, 4, 3, 2 };
    printf("%d\n", largestAltitude(input_2, size_2));
}
// Accepted
// 80/80 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 98.44 % of c submissions (5.6 MB)