/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
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

int maxArea(int* height, int heightSize)
{
    int i, j, w, h;
    int result = 0;
    // O(n^2) TLE
    // int w;
    // for(i = 0; i < heightSize; i++)
    // {
    // 	for(j = i + 1, w = 1; j < heightSize; j++, w++)
    // 	{
    // 		int h = height[i] <= height[j] ? height[i] : height[j];
    // 		int area = h * w;
    // 		if(area > result)
    // 		{
    // 			result = area;
    // 		}
    // 	}
    // }
    i = 0;
    j = heightSize - 1;
    w = heightSize - 1;
    while (i <= j)
    {
        // Move the lower wall
        if (height[i] < height[j])
        {
            h = height[i];
            i++;
        }
        else
        {
            h = height[j];
            j--;
        }
        result = max(result, h * w);
        w--;
    }

    return result;
}
// @lc code=end
#define SIZE_1 9
#define SIZE_2 2

int main(int argc, char** argv)
{
    // Test 1
    int size_1           = SIZE_1;
    int height_1[SIZE_1] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    printf("%d\n", maxArea(height_1, size_1));

    // Test 2
    int size_2           = SIZE_2;
    int height_2[SIZE_2] = { 1, 1 };
    printf("%d\n", maxArea(height_2, size_2));
    return 0;
}
// Accepted
// 62/62 cases passed (56 ms)
// Your runtime beats 97.65 % of c submissions
// Your memory usage beats 96.58 % of c submissions (11.4 MB)
