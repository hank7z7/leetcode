/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 *
 * https://leetcode.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (74.87%)
 * Likes:    1688
 * Dislikes: 184
 * Total Accepted:    60.6K
 * Total Submissions: 79.1K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * You are given an m x n binary matrix grid.
 *
 * A move consists of choosing any row or column and toggling each value in
 * that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
 *
 * Every row of the matrix is interpreted as a binary number, and the score of
 * the matrix is the sum of these numbers.
 *
 * Return the highest possible score after making any number of moves
 * (including zero moves).
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * Output: 39
 * Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 20
 * grid[i][j] is either 0 or 1.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    void flip(int& elem)
    {
        if (elem == 0)
            elem = 1;
        else if (elem == 1)
            elem = 0;
    }
    void flip_row(vector<vector<int>>& grid, int row)
    {
        int n = (int) grid[0].size();
        for (int j = 0; j < n; j++)
            flip(grid[row][j]);
    }
    void flip_col(vector<vector<int>>& grid, int col)
    {
        int m = (int) grid.size();
        for (int i = 0; i < m; i++)
            flip(grid[i][col]);
    }

public:
    int matrixScore(vector<vector<int>>& grid)
    {
        int result = 0;
        int m      = (int) grid.size();
        int n      = (int) grid[0].size();

        for (int i = 0; i < m; i++)
            if (grid[i][0] == 0)
                flip_row(grid, i);

        for (int j = 1; j < n; j++)
        {
            int sum = 0;
            for (int i = 0; i < m; i++)
                sum += grid[i][j];
            if (sum <= (m / 2))
                flip_col(grid, j);
        }

        // Sum
        for (int i = 0; i < m; i++)
        {
            int curr = 0;
            for (int j = 0; j < n; j++)
            {
                curr = curr << 1;
                curr += grid[i][j];
            }
            result += curr;
        }

        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = { { 0, 0, 1, 1 }, { 1, 0, 1, 0 }, { 1, 1, 0, 0 } };
    cout << sol.matrixScore(grid_1) << endl;

    // Test_2
    vector<vector<int>> grid_2 = { { 0 } };
    cout << sol.matrixScore(grid_2) << endl;

    return 0;
}
// Accepted
// 80/80 cases passed (5 ms)
// Your runtime beats 31.84 % of cpp submissions
// Your memory usage beats 37.53 % of cpp submissions (10.3 MB)