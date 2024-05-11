/*
 * @lc app=leetcode id=3142 lang=cpp
 *
 * [3142] Check if Grid Satisfies Conditions
 *
 * https://leetcode.com/problems/check-if-grid-satisfies-conditions/description/
 *
 * algorithms
 * Easy (37.16%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 49.5K
 * Testcase Example:  '[[1,0,2],[1,0,2]]'
 *
 * You are given a 2D matrix grid of size m x n. You need to check if each cell
 * grid[i][j] is:
 *
 *
 * Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it
 * exists).
 * Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if
 * it exists).
 *
 *
 * Return true if all the cells satisfy these conditions, otherwise, return
 * false.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,0,2],[1,0,2]]
 *
 * Output: true
 *
 * Explanation:
 *
 *
 *
 * All the cells in the grid satisfy the conditions.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,1,1],[0,0,0]]
 *
 * Output: false
 *
 * Explanation:
 *
 *
 *
 * All cells in the first row are equal.
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1],[2],[3]]
 *
 * Output: false
 *
 * Explanation:
 *
 *
 *
 * Cells in the first column have different values.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n, m <= 10
 * 0 <= grid[i][j] <= 9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool satisfiesConditions(vector<vector<int>> &grid)
    {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        for (int j = 0; j < m; j++)
        {
            if (j > 0 && grid[0][j] == grid[0][j - 1])
                return false;
            for (int i = 0; i < n; i++)
            {
                if (i > 0 && grid[i][j] != grid[i - 1][j])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = {{1, 0, 2}, {1, 0, 2}};
    cout << sol.satisfiesConditions(grid_1) << endl;

    // Test_2
    vector<vector<int>> grid_2 = {{1, 1, 1}, {0, 0, 0}};
    cout << sol.satisfiesConditions(grid_2) << endl;
    return 0;
}
// Accepted
// 880/880 cases passed (23 ms)
// Your runtime beats 16.67 % of cpp submissions
// Your memory usage beats 50 % of cpp submissions (28.7 MB)