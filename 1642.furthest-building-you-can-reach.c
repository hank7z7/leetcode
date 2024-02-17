/*
 * @lc app=leetcode id=1642 lang=c
 *
 * [1642] Furthest Building You Can Reach
 *
 * https://leetcode.com/problems/furthest-building-you-can-reach/description/
 *
 * algorithms
 * Medium (48.50%)
 * Likes:    5019
 * Dislikes: 107
 * Total Accepted:    149K
 * Total Submissions: 303.9K
 * Testcase Example:  '[4,2,7,6,9,14,12]\n5\n1'
 *
 * You are given an integer array heights representing the heights of
 * buildings, some bricks, and some ladders.
 * 
 * You start your journey from building 0 and move to the next building by
 * possibly using bricks or ladders.
 * 
 * While moving from building i to building i+1 (0-indexed),
 * 
 * 
 * If the current building's height is greater than or equal to the next
 * building's height, you do not need a ladder or bricks.
 * If the current building's height is less than the next building's height,
 * you can either use one ladder or (h[i+1] - h[i]) bricks.
 * 
 * 
 * Return the furthest building index (0-indexed) you can reach if you use the
 * given ladders and bricks optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
 * Output: 4
 * Explanation: Starting at building 0, you can follow these steps:
 * - Go to building 1 without using ladders nor bricks since 4 >= 2.
 * - Go to building 2 using 5 bricks. You must use either bricks or ladders
 * because 2 < 7.
 * - Go to building 3 without using ladders nor bricks since 7 >= 6.
 * - Go to building 4 using your only ladder. You must use either bricks or
 * ladders because 6 < 9.
 * It is impossible to go beyond building 4 because you do not have any more
 * bricks or ladders.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
 * Output: 7
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: heights = [14,3,19,3], bricks = 17, ladders = 0
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= heights.length <= 10^5
 * 1 <= heights[i] <= 10^6
 * 0 <= bricks <= 10^9
 * 0 <= ladders <= heights.length
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders) {
    return 0;
}
// @lc code=end
#define SIZE_1 (7)
#define SIZE_2 (9)
#define SIZE_3 (4)
int main(int argc, char** argv)
{
    int size;
    int bricks = 0;
    int ladders = 0;
    // Test_1
    size = SIZE_1;
    int heights_1[SIZE_1] = {4, 2, 7, 6, 9, 14, 12};
    bricks = 5;
    ladders = 1;
    printf("%d\n", furthestBuilding(heights_1, size, bricks, ladders));

    // Test_2
    size = SIZE_2;
    int heights_2[SIZE_2] = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    bricks = 10;
    ladders = 2;
    printf("%d\n", furthestBuilding(heights_2, size, bricks, ladders));

    // Test_3
    size = SIZE_3;
    int heights_3[SIZE_3] = {14, 3, 19, 3};
    bricks = 17;
    ladders = 0;
    printf("%d\n", furthestBuilding(heights_3, size, bricks, ladders));
    return 0;
}
