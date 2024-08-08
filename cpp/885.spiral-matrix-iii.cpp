/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 *
 * https://leetcode.com/problems/spiral-matrix-iii/description/
 *
 * algorithms
 * Medium (74.56%)
 * Likes:    1124
 * Dislikes: 923
 * Total Accepted:    70.2K
 * Total Submissions: 89.4K
 * Testcase Example:  '1\n4\n0\n0'
 *
 * You start at the cell (rStart, cStart) of an rows x cols grid facing east.
 * The northwest corner is at the first row and column in the grid, and the
 * southeast corner is at the last row and column.
 *
 * You will walk in a clockwise spiral shape to visit every position in this
 * grid. Whenever you move outside the grid's boundary, we continue our walk
 * outside the grid (but may return to the grid boundary later.). Eventually,
 * we reach all rows * cols spaces of the grid.
 *
 * Return an array of coordinates representing the positions of the grid in the
 * order you visited them.
 *
 *
 * Example 1:
 *
 *
 * Input: rows = 1, cols = 4, rStart = 0, cStart = 0
 * Output: [[0,0],[0,1],[0,2],[0,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: rows = 5, cols = 6, rStart = 1, cStart = 4
 * Output:
 * [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= rows, cols <= 100
 * 0 <= rStart < rows
 * 0 <= cStart < cols
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    void valid_i_j(int& rows, int& cols, int& i, int& j, vector<vector<int>>& res, int& total)
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            res.push_back(vector<int>{ i, j });
            total--;
        }
    }

public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> res;
        int                 total = rows * cols;
        int                 r_1 = 1, d = 1, l = 2, u = 2, r_2 = 1;
        int                 curr_i = rStart, curr_j = cStart;
        while (total)
        {
            // Go right
            for (int j = 0; j < r_1; j++, curr_j++)
                valid_i_j(rows, cols, curr_i, curr_j, res, total);

            // Go down
            for (int i = 0; i < d; i++, curr_i++)
                valid_i_j(rows, cols, curr_i, curr_j, res, total);

            // Go left
            for (int j = 0; j < l; j++, curr_j--)
                valid_i_j(rows, cols, curr_i, curr_j, res, total);

            // Go up
            for (int i = 0; i < u; i++, curr_i--)
                valid_i_j(rows, cols, curr_i, curr_j, res, total);

            // Go right
            for (int j = 0; j < r_2; j++, curr_j++)
                valid_i_j(rows, cols, curr_i, curr_j, res, total);

            // Update size
            r_1 += 1;
            d += 2;
            l += 2;
            u += 2;
            r_2 += 1;

            if (total <= 0)
                break;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int                 rows_1 = 1, cols_1 = 4;
    int                 rStart_1 = 0, cStart_1 = 0;
    vector<vector<int>> res_1 = sol.spiralMatrixIII(rows_1, cols_1, rStart_1, cStart_1);
    cout << "[";
    for (int i = 0; i < (int) res_1.size(); i++)
    {
        vector<int> cordinate = res_1[i];
        cout << "[" << cordinate[0] << "," << cordinate[1] << "]";
        if (i != (int) res_1.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    assert((res_1 == vector<vector<int>>{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } }));

    // Test_2
    int                 rows_2 = 5, cols_2 = 6;
    int                 rStart_2 = 1, cStart_2 = 4;
    vector<vector<int>> res_2 = sol.spiralMatrixIII(rows_2, cols_2, rStart_2, cStart_2);
    cout << "[";
    for (int i = 0; i < (int) res_2.size(); i++)
    {
        vector<int> cordinate = res_2[i];
        cout << "[" << cordinate[0] << "," << cordinate[1] << "]";
        if (i != (int) res_2.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    assert((res_2 == vector<vector<int>>{ { 1, 4 }, { 1, 5 }, { 2, 5 }, { 2, 4 }, { 2, 3 },
                                          { 1, 3 }, { 0, 3 }, { 0, 4 }, { 0, 5 }, { 3, 5 },
                                          { 3, 4 }, { 3, 3 }, { 3, 2 }, { 2, 2 }, { 1, 2 },
                                          { 0, 2 }, { 4, 5 }, { 4, 4 }, { 4, 3 }, { 4, 2 },
                                          { 4, 1 }, { 3, 1 }, { 2, 1 }, { 1, 1 }, { 0, 1 },
                                          { 4, 0 }, { 3, 0 }, { 2, 0 }, { 1, 0 }, { 0, 0 } }));

    return 0;
}
// Accepted
// 73/73 cases passed (3 ms)
// Your runtime beats 98.99 % of cpp submissions
// Your memory usage beats 48.36 % of cpp submissions (13.6 MB)