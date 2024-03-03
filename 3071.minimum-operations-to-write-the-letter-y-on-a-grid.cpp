/*
 * @lc app=leetcode id=3071 lang=cpp
 *
 * [3071] Minimum Operations to Write the Letter Y on a Grid
 *
 * https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid/description/
 *
 * algorithms
 * Medium (59.03%)
 * Likes:    0
 * Dislikes: 1
 * Total Accepted:    4.5K
 * Total Submissions: 7.1K
 * Testcase Example:  '[[1,2,2],[1,1,0],[0,1,0]]'
 *
 * You are given a 0-indexed n x n grid where n is odd, and grid[r][c] is 0, 1,
 * or 2.
 *
 * We say that a cell belongs to the Letter Y if it belongs to one of the
 * following:
 *
 *
 * The diagonal starting at the top-left cell and ending at the center cell of
 * the grid.
 * The diagonal starting at the top-right cell and ending at the center cell of
 * the grid.
 * The vertical line starting at the center cell and ending at the bottom
 * border of the grid.
 *
 *
 * The Letter Y is written on the grid if and only if:
 *
 *
 * All values at cells belonging to the Y are equal.
 * All values at cells not belonging to the Y are equal.
 * The values at cells belonging to the Y are different from the values at
 * cells not belonging to the Y.
 *
 *
 * Return the minimum number of operations needed to write the letter Y on the
 * grid given that in one operation you can change the value at any cell to 0,
 * 1, or 2.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,2,2],[1,1,0],[0,1,0]]
 * Output: 3
 * Explanation: We can write Y on the grid by applying the changes highlighted
 * in blue in the image above. After the operations, all cells that belong to
 * Y, denoted in bold, have the same value of 1 while those that do not belong
 * to Y are equal to 0.
 * It can be shown that 3 is the minimum number of operations needed to write Y
 * on the grid.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,1,0,1,0],[2,1,0,1,2],[2,2,2,0,1],[2,2,2,2,2],[2,1,2,2,2]]
 * Output: 12
 * Explanation: We can write Y on the grid by applying the changes highlighted
 * in blue in the image above. After the operations, all cells that belong to
 * Y, denoted in bold, have the same value of 0 while those that do not belong
 * to Y are equal to 2.
 * It can be shown that 12 is the minimum number of operations needed to write
 * Y on the grid.
 *
 *
 * Constraints:
 *
 *
 * 3 <= n <= 49
 * n == grid.length == grid[i].length
 * 0 <= grid[i][j] <= 2
 * n is odd.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid)
    {
        vector<int> count(3, 0);
        vector<int> y_count(3, 0);
        int         ret = 0;
        for (auto row : grid)
            for (auto e : row)
            {
                count[e]++;
            }

        for (size_t i = 0; i < (grid[0].size() / 2); i++)
        {
            y_count[grid[i][i]]++;
            y_count[grid[i][grid[0].size() - 1 - i]]++;
        }
        for (size_t i = (grid[0].size() / 2); i < grid.size(); i++)
            y_count[grid[i][(grid[0].size() / 2)]]++;
        for (int i = 0; i < 3; i++)
            count[i] -= y_count[i];
        int y_0 = y_count[1] + y_count[2];
        int y_1 = y_count[0] + y_count[2];
        int y_2 = y_count[0] + y_count[1];
        int o_0 = count[1] + count[2];
        int o_1 = count[0] + count[2];
        int o_2 = count[0] + count[1];
        ret     = INT_MAX;
        ret     = min(ret, y_0 + o_1);
        ret     = min(ret, y_0 + o_2);
        ret     = min(ret, y_1 + o_0);
        ret     = min(ret, y_1 + o_2);
        ret     = min(ret, y_2 + o_0);
        ret     = min(ret, y_2 + o_1);

        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = { { 1, 2, 2 }, { 1, 1, 0 }, { 0, 1, 0 } };
    cout << sol.minimumOperationsToWriteY(grid_1) << endl;

    // Test_2
    vector<vector<int>> grid_2 = { { 0, 1, 0, 1, 0 },
                           { 2, 1, 0, 1, 2 },
                           { 2, 2, 2, 0, 1 },
                           { 2, 2, 2, 2, 2 },
                           { 2, 1, 2, 2, 2 } };
    cout << sol.minimumOperationsToWriteY(grid_2) << endl;

    return 0;
}
// Accepted
// 909/909 cases passed (39 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 40 % of cpp submissions (44.2 MB)