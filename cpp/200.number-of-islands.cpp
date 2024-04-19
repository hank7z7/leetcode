/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * {200} Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (58.63%)
 * Likes:    22189
 * Dislikes: 496
 * Total Accepted:    2.6M
 * Total Submissions: 4.4M
 * Testcase Example:
 * '{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}}'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = {
 * ⁠ {'1','1','1','1','0'},
 * ⁠ {'1','1','0','1','0'},
 * ⁠ {'1','1','0','0','0'},
 * ⁠ {'0','0','0','0','0'}
 * }
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = {
 * ⁠ {'1','1','0','0','0'},
 * ⁠ {'1','1','0','0','0'},
 * ⁠ {'0','0','1','0','0'},
 * ⁠ {'0','0','0','1','1'}
 * }
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid{i}.length
 * 1 <= m, n <= 300
 * grid{i}{j} is '0' or '1'.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
private:
    const int                    dir_size = 4;
    const vector<pair<int, int>> dir      = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    bool                         valid(pair<int, int> p, int h, int w)
    {
        if (p.first < 0 || p.first >= h || p.second < 0 || p.second >= w)
            return false;
        else
            return true;
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int                  islands = 0;
        int                  h       = grid.size();
        int                  w       = grid[0].size();
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    islands++;
                    // (index i, index j)
                    queue<pair<int, int>> q;
                    // Initialize queue
                    q.push({ i, j });
                    visited[i][j] = true;
                    while (!q.empty())
                    {
                        pair<int, int> curr = q.front();
                        q.pop();
                        for (int k = 0; k < dir_size; k++)
                        {
                            pair<int, int> next
                                = { curr.first + dir[k].first, curr.second + dir[k].second };
                            if (valid(next, h, w) && !visited[next.first][next.second]
                                && grid[next.first][next.second] == '1')
                            {
                                visited[next.first][next.second] = true;
                                q.push(next);
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<char>> grid_1 = { { '1', '1', '1', '1', '0' },
                                    { '1', '1', '0', '1', '0' },
                                    { '1', '1', '0', '0', '0' },
                                    { '0', '0', '0', '0', '0' } };
    cout << sol.numIslands(grid_1) << endl;

    // Test_2
    vector<vector<char>> grid_2 = { { '1', '1', '0', '0', '0' },
                                    { '1', '1', '0', '0', '0' },
                                    { '0', '0', '1', '0', '0' },
                                    { '0', '0', '0', '1', '1' } };
    cout << sol.numIslands(grid_2) << endl;

    return 0;
}
// Success
// Runtime: 41 ms, faster than 16.35% of C++ online submissions for Number of Islands.
// Memory Usage: 21.8 MB, less than 30.53% of C++ online submissions for Number of Islands.