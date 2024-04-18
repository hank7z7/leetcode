/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (70.35%)
 * Likes:    6703
 * Dislikes: 371
 * Total Accepted:    597.4K
 * Total Submissions: 826.5K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given row x col grid representing a map where grid[i][j] = 1
 * represents land and grid[i][j] = 0 represents water.
 *
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e.,
 * one or more connected land cells).
 *
 * The island doesn't have "lakes", meaning the water inside isn't connected to
 * the water around the island. One cell is a square with side length 1. The
 * grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * Output: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image above.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1]]
 * Output: 4
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,0]]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * row == grid.length
 * col == grid[i].length
 * 1 <= row, col <= 100
 * grid[i][j] is 0 or 1.
 * There is exactly one island in grid.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int count = 0, repeat = 0;
        int h = (int)grid.size();
        int w = (int)grid[0].size();
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                    if (i != 0 && grid[i - 1][j] == 1)
                        repeat++;
                    if (j != 0 && grid[i][j - 1] == 1)
                        repeat++;
                }
            }
        }
        return 4 * count - repeat * 2;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << sol.islandPerimeter(grid_1) << endl;

    // Test_2
    vector<vector<int>> grid_2 = {{1}};
    cout << sol.islandPerimeter(grid_2) << endl;

    // Test_3
    vector<vector<int>> grid_3 = {{1, 0}};
    cout << sol.islandPerimeter(grid_3) << endl;
    return 0;
}
// Accepted
// 5833/5833 cases passed (80 ms)
// Your runtime beats 39.73 % of cpp submissions
// Your memory usage beats 76.64 % of cpp submissions (100.7 MB)