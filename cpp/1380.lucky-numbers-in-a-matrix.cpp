/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 *
 * https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
 *
 * algorithms
 * Easy (71.53%)
 * Likes:    2009
 * Dislikes: 102
 * Total Accepted:    197.2K
 * Total Submissions: 252K
 * Testcase Example:  '[[3,7,8],[9,11,13],[15,16,17]]'
 *
 * Given an m x n matrix of distinct numbers, return all lucky numbers in the
 * matrix in any order.
 *
 * A lucky number is an element of the matrix such that it is the minimum
 * element in its row and maximum in its column.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
 * Output: [15]
 * Explanation: 15 is the only lucky number since it is the minimum in its row
 * and the maximum in its column.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
 * Output: [12]
 * Explanation: 12 is the only lucky number since it is the minimum in its row
 * and the maximum in its column.
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[7,8],[1,2]]
 * Output: [7]
 * Explanation: 7 is the only lucky number since it is the minimum in its row
 * and the maximum in its column.
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= n, m <= 50
 * 1 <= matrix[i][j] <= 10^5.
 * All elements in the matrix are distinct.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = (int)matrix.size();
        int n = (m == 0 ? 0 : (int)matrix[0].size());
        // Store the index of the minimum of each row
        vector<int> row_min_idx(m, -1);
        for (int i = 0; i < m; i++)
        {
            int row_min = INT_MAX;
            int idx = -1;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < row_min)
                {
                    idx = j;
                    row_min = matrix[i][j];
                }
            }
            row_min_idx[i] = idx;
        }

        // Store the index of the maximum of each row
        vector<int> col_max_idx(n, -1);
        for (int i = 0; i < n; i++)
        {
            int col_min = INT_MIN;
            int idx = -1;
            for (int j = 0; j < m; j++)
            {
                if (matrix[j][i] > col_min)
                {
                    idx = j;
                    col_min = matrix[j][i];
                }
            }
            col_max_idx[i] = idx;
        }

        vector<int> res;
        for (int i = 0; i < m; i++)
        {
            if (col_max_idx[row_min_idx[i]] == i)
                res.push_back(matrix[i][row_min_idx[i]]);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> matrix_1 = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    vector<int> res_1 = sol.luckyNumbers(matrix_1);
    for (auto res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<int>{15}));

    // Test_2
    vector<vector<int>> matrix_2 = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    vector<int> res_2 = sol.luckyNumbers(matrix_2);
    for (auto res : res_2)
        cout << res << " ";
    cout << endl;
    assert((res_2 == vector<int>{12}));

    // Test_3
    vector<vector<int>> matrix_3 = {{7, 8}, {1, 2}};
    vector<int> res_3 = sol.luckyNumbers(matrix_3);
    for (auto res : res_3)
        cout << res << " ";
    cout << endl;
    assert((res_3 == vector<int>{7}));

    return 0;
}
// Accepted
// 104/104 cases passed (17 ms)
// Your runtime beats 39.49 % of cpp submissions
// Your memory usage beats 16.09 % of cpp submissions (14.5 MB)