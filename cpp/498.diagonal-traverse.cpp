/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (62.73%)
 * Likes:    3942
 * Dislikes: 749
 * Total Accepted:    450.5K
 * Total Submissions: 694.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix mat, return an array of all the elements of the array
 * in a diagonal order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,4,7,5,3,6,8,9]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[1,2],[3,4]]
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<int> result(m * n);
        int row = 0, col = 0;

        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];

            if ((row + col) % 2 == 0) {
                if (col == n - 1) row++;
                else if (row == 0) col++;
                else { row--; col++; }
            } else {
                if (row == m - 1) col++;
                else if (col == 0) row++;
                else { row++; col--; }
            }
        }

        return result;
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution s;
    // Test_1
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    auto res = s.findDiagonalOrder(mat);
    for (auto x: res) {
        cout << x << " ";
    }
    cout << endl;
    assert(res == vector<int>({1,2,4,7,5,3,6,8,9}));

    // Test_2
    mat = {{1,2},{3,4}};
    res = s.findDiagonalOrder(mat);
    for (auto x: res) {
        cout << x << " ";
    }
    cout << endl;
    assert(res == vector<int>({1,2,3,4}));

    return 0;
}
// Accepted
// 32/32 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.85 % of cpp submissions (22.2 MB)