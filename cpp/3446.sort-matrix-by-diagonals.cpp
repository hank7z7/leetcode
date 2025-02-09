/*
 * @lc app=leetcode id=3446 lang=cpp
 *
 * [3446] Sort Matrix by Diagonals
 *
 * https://leetcode.com/problems/sort-matrix-by-diagonals/description/
 *
 * algorithms
 * Medium (69.94%)
 * Likes:    32
 * Dislikes: 6
 * Total Accepted:    20.6K
 * Total Submissions: 29.4K
 * Testcase Example:  '[[1,7,3],[9,8,2],[4,5,6]]'
 *
 * You are given an n x n square matrix of integers grid. Return the matrix
 * such that:
 *
 *
 * The diagonals in the bottom-left triangle (including the middle diagonal)
 * are sorted in non-increasing order.
 * The diagonals in the top-right triangle are sorted in non-decreasing
 * order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
 *
 * Output: [[8,2,3],[9,6,7],[4,5,1]]
 *
 * Explanation:
 *
 *
 *
 * The diagonals with a black arrow (bottom-left triangle) should be sorted in
 * non-increasing order:
 *
 *
 * [1, 8, 6] becomes [8, 6, 1].
 * [9, 5] and [4] remain unchanged.
 *
 *
 * The diagonals with a blue arrow (top-right triangle) should be sorted in
 * non-decreasing order:
 *
 *
 * [7, 2] becomes [2, 7].
 * [3] remains unchanged.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,1],[1,2]]
 *
 * Output: [[2,1],[1,0]]
 *
 * Explanation:
 *
 *
 *
 * The diagonals with a black arrow must be non-increasing, so [0, 2] is
 * changed to [2, 0]. The other diagonals are already in the correct order.
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1]]
 *
 * Output: [[1]]
 *
 * Explanation:
 *
 * Diagonals with exactly one element are already in order, so no changes are
 * needed.
 *
 *
 *
 * Constraints:
 *
 *
 * grid.length == grid[i].length == n
 * 1 <= n <= 10
 * -10^5 <= grid[i][j] <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        const int m = (int)grid.size();
        const int n = m == 0 ? 0 : (int)grid[0].size();
        if (m != n)
            return grid;
        vector<int> tmp(n);
        for (int i = 0; i < n; i++)
        {
            int len = n - i;
            // buttom-left triangle
            // Start from (i, 0), store to tmp
            for (int j = 0; j < len; j++)
                tmp[j] = grid[i + j][0 + j];
            // Sort tmp
            sort(tmp.begin(), tmp.begin() + len, greater<int>());
            // Store back to grid
            for (int j = 0; j < len; j++)
                grid[i + j][0 + j] = tmp[j];

            // top-right triangle
            if (i == 0)
                continue;
            // Start from (0, i), store to tmp
            for (int j = 0; j < len; j++)
                tmp[j] = grid[0 + j][i + j];
            // Sort tmp
            sort(tmp.begin(), tmp.begin() + len);
            // Store back to grid
            for (int j = 0; j < len; j++)
                grid[0 + j][i + j] = tmp[j];
        }
        return grid;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    vector<vector<int>> res_1 = sol.sortMatrix(grid_1);
    for (auto &row : res_1)
    {
        for (auto &elem : row)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;
    assert((res_1 == vector<vector<int>>{{8, 2, 3}, {9, 6, 7}, {4, 5, 1}}));

    // Test_2
    vector<vector<int>> grid_2 = {{0, 1}, {1, 2}};
    vector<vector<int>> res_2 = sol.sortMatrix(grid_2);
    for (auto &row : res_2)
    {
        for (auto &elem : row)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;
    assert((res_2 == vector<vector<int>>{{2, 1}, {1, 0}}));

    // Test_3
    vector<vector<int>> grid_3 = {{1}};
    vector<vector<int>> res_3 = sol.sortMatrix(grid_3);
    for (auto &row : res_3)
    {
        for (auto &elem : row)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;
    assert((res_3 == vector<vector<int>>{{1}}));

    return 0;
}
// Accepted
// 1306/1306 cases passed (7 ms)
// Your runtime beats 90 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (41.9 MB)