/*
 * @lc app=leetcode id=2373 lang=cpp
 *
 * [2373] Largest Local Values in a Matrix
 *
 * https://leetcode.com/problems/largest-local-values-in-a-matrix/description/
 *
 * algorithms
 * Easy (83.13%)
 * Likes:    843
 * Dislikes: 104
 * Total Accepted:    72.3K
 * Total Submissions: 84.5K
 * Testcase Example:  '[[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]'
 *
 * You are given an n x n integer matrix grid.
 *
 * Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such
 * that:
 *
 *
 * maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid
 * centered around row i + 1 and column j + 1.
 *
 *
 * In other words, we want to find the largest value in every contiguous 3 x 3
 * matrix in grid.
 *
 * Return the generated matrix.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
 * Output: [[9,9],[8,6]]
 * Explanation: The diagram above shows the original matrix and the generated
 * matrix.
 * Notice that each value in the generated matrix corresponds to the largest
 * value of a contiguous 3 x 3 matrix in grid.
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
 * Output: [[2,2,2],[2,2,2],[2,2,2]]
 * Explanation: Notice that the 2 is contained within every contiguous 3 x 3
 * matrix in grid.
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length == grid[i].length
 * 3 <= n <= 100
 * 1 <= grid[i][j] <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m - 2, vector<int>(n - 2, 0));

        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = 1; j <= n - 2; j++)
            {
                int maxi = 0;
                maxi = max({maxi, grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1]});
                maxi = max({maxi, grid[i][j - 1], grid[i][j], grid[i][j + 1]});
                maxi = max({maxi, grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]});

                result[i - 1][j - 1] = maxi;
            }
        }

        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = {{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
    vector<vector<int>> result_1 = sol.largestLocal(grid_1);
    for (auto row : result_1)
    {
        for (auto elem : row)
            cout << elem << " ";
        cout << endl;
    }

    // Test_2
    vector<vector<int>> grid_2 = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 2, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
    vector<vector<int>> result_2 = sol.largestLocal(grid_2);
    for (auto row : result_2)
    {
        for (auto elem : row)
            cout << elem << " ";
        cout << endl;
    }

    return 0;
}
// Accepted
// 50/50 cases passed (7 ms)
// Your runtime beats 89.68 % of cpp submissions
// Your memory usage beats 33.59 % of cpp submissions (13.6 MB)