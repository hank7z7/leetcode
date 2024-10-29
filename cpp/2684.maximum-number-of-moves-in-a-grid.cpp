/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 *
 * https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/
 *
 * algorithms
 * Medium (46.02%)
 * Likes:    508
 * Dislikes: 10
 * Total Accepted:    36.9K
 * Total Submissions: 72.7K
 * Testcase Example:  '[[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]'
 *
 * You are given a 0-indexed m x n matrix grid consisting of positive
 * integers.
 *
 * You can start at any cell in the first column of the matrix, and traverse
 * the grid in the following way:
 *
 *
 * From a cell (row, col), you can move to any of the cells: (row - 1, col +
 * 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell
 * you move to, should be strictly bigger than the value of the current cell.
 *
 *
 * Return the maximum number of moves that you can perform.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
 * Output: 3
 * Explanation: We can start at the cell (0, 0) and make the following moves:
 * - (0, 0) -> (0, 1).
 * - (0, 1) -> (1, 2).
 * - (1, 2) -> (2, 3).
 * It can be shown that it is the maximum number of moves that can be made.
 *
 * Example 2:
 *
 *
 *
 * Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
 * Output: 0
 * Explanation: Starting from any cell in the first column we cannot perform
 * any moves.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 2 <= m, n <= 1000
 * 4 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^6
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxMoves(const vector<vector<int>>& grid)
    {
        int m = (int) grid.size();
        int n = m == 0 ? 0 : (int) grid[0].size();
        stack<pair<int, int>> st;

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            st.push({ i, 0 });
            // cout << "push " << i << " " << 0 << endl;
            while (!st.empty())
            {
                pair<int, int> curr = st.top();
                st.pop();
                res = max(res, curr.second);
                if ((curr.first - 1) >= 0 && (curr.second + 1) < n
                    && grid[curr.first - 1][curr.second + 1]
                           > grid[curr.first][curr.second])
                    st.push({ curr.first - 1, curr.second + 1 });
                if ((curr.second + 1) < n
                    && grid[curr.first][curr.second + 1]
                           > grid[curr.first][curr.second])
                    st.push({ curr.first, curr.second + 1 });
                if ((curr.first + 1) < m && (curr.second + 1) < n
                    && grid[curr.first + 1][curr.second + 1]
                           > grid[curr.first][curr.second])
                    st.push({ curr.first + 1, curr.second + 1 });
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = {
        { 2, 4, 3, 5 }, { 5, 4, 9, 3 }, { 3, 4, 2, 11 }, { 10, 9, 13, 15 }
    };
    int res_1 = sol.maxMoves(grid_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    vector<vector<int>> grid_2 = { { 3, 2, 4 }, { 2, 1, 9 }, { 1, 1, 7 } };
    int res_2 = sol.maxMoves(grid_2);
    cout << res_2 << endl;
    assert(res_2 == 0);

    // Test_3
    vector<vector<int>> grid_3 = { { 137, 112, 78, 67 }, { 76, 65, 122, 135 } };
    int res_3 = sol.maxMoves(grid_3);
    cout << res_3 << endl;
    assert(res_3 == 3);

    return 0;
}
