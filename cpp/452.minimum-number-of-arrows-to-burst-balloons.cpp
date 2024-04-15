/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (56.87%)
 * Likes:    6887
 * Dislikes: 211
 * Total Accepted:    404.9K
 * Total Submissions: 712.3K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are some spherical balloons taped onto a flat wall that represents the
 * XY-plane. The balloons are represented as a 2D integer array points where
 * points[i] = [xstart, xend] denotes a balloon whose horizontal diameter
 * stretches between xstart and xend. You do not know the exact y-coordinates
 * of the balloons.
 *
 * Arrows can be shot up directly vertically (in the positive y-direction) from
 * different points along the x-axis. A balloon with xstart and xend is burst
 * by an arrow shot at x if xstart <= x <= xend. There is no limit to the
 * number of arrows that can be shot. A shot arrow keeps traveling up
 * infinitely, bursting any balloons in its path.
 *
 * Given the array points, return the minimum number of arrows that must be
 * shot to burst all balloons.
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[10,16],[2,8],[1,6],[7,12]]
 * Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 * - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
 * - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[1,2],[3,4],[5,6],[7,8]]
 * Output: 4
 * Explanation: One arrow needs to be shot for each balloon for a total of 4
 * arrows.
 *
 *
 * Example 3:
 *
 *
 * Input: points = [[1,2],[2,3],[3,4],[4,5]]
 * Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 * - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
 * - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= points.length <= 10^5
 * points[i].length == 2
 * -2^31 <= xstart < xend <= 2^31 - 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int       arrows           = 0;
        long long last_arrow_index = LONG_LONG_MIN;
        sort(points.begin(),
             points.end(),
             [](const vector<int>& a, const vector<int>& b)
             {
                 if (a[0] < b[0])
                     return true;
                 else if (a[0] == b[0] && a[1] < b[1])
                     return true;
                 else
                     return false;
             });
        for (auto point : points)
        {
            // No intersection
            if (last_arrow_index < point[0])
            {
                arrows++;
                last_arrow_index = point[1];
            }
            // Have intersection
            else
            {
                if (last_arrow_index > point[1])
                    last_arrow_index = point[1];
            }
        }
        return arrows;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> points_1 = { { 10, 16 }, { 2, 8 }, { 1, 6 }, { 7, 12 } };
    cout << sol.findMinArrowShots(points_1) << endl;

    // Test_2
    vector<vector<int>> points_2 = { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };
    cout << sol.findMinArrowShots(points_2) << endl;

    // Test_3
    vector<vector<int>> points_3 = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 } };
    cout << sol.findMinArrowShots(points_3) << endl;

    // Test_4
    vector<vector<int>> points_4 = { { -2147483648, 2147483647 } };
    cout << sol.findMinArrowShots(points_4) << endl;
    return 0;
}
// 50 / 50 test cases passed.
// Status: Accepted
// Runtime: 280 ms
// Memory Usage: 105.7 MB