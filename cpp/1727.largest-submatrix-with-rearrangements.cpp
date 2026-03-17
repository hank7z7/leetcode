/*
 * @lc app=leetcode id=1727 lang=cpp
 *
 * [1727] Largest Submatrix With Rearrangements
 *
 * https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/
 *
 * algorithms
 * Medium (75.22%)
 * Likes:    2074
 * Dislikes: 116
 * Total Accepted:    99.2K
 * Total Submissions: 128.4K
 * Testcase Example:  '[[0,0,1],[1,1,1],[1,0,1]]'
 *
 * You are given a binary matrix matrix of size m x n, and you are allowed to
 * rearrange the columns of the matrix in any order.
 * 
 * Return the area of the largest submatrix within matrix where every element
 * of the submatrix is 1 after reordering the columns optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
 * Output: 4
 * Explanation: You can rearrange the columns as shown above.
 * The largest submatrix of 1s, in bold, has an area of 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,0,1,0,1]]
 * Output: 3
 * Explanation: You can rearrange the columns as shown above.
 * The largest submatrix of 1s, in bold, has an area of 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[1,1,0],[1,0,1]]
 * Output: 2
 * Explanation: Notice that you must rearrange entire columns, and there is no
 * way to make a submatrix of 1s larger than an area of 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m * n <= 10^5
 * matrix[i][j] is either 0 or 1.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int m = (int) matrix.size();
        const int n = m == 0 ? 0 : (int) matrix[0].size();
        // For each column, find the number of consecutive ones ending at each position.
        vector<vector<int>> count(m, vector<int>(n));
        for (int j = 0; j < n; j++) {
            count[0][j] = matrix[0][j];
            for (int i = 1; i < m; i++) {
                count[i][j] = matrix[i][j] == 0 ? 0 : count[i - 1][j] + 1;
            }
        }

        // For each row, sort the cumulative ones in non-increasing order and "fit" the largest submatrix.
        int res = 0;
        for (int i = 0; i < m; i++) {
            vector<int> sorted_count = count[i];
            sort(sorted_count.begin(), sorted_count.end(), greater<int>());
            for (int j = 0; j < n; j++) {
                res = max(res, sorted_count[j] * (j + 1));
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv) {
    Solution sol;
    // Test_1
    vector<vector<int>> matrix_1 = {{0,0,1},{1,1,1},{1,0,1}};
    int res = sol.largestSubmatrix(matrix_1);
    cout << res << endl;
    assert(res == 4);

    // Test_2
    vector<vector<int>> matrix_2 = {{1,0,1,0,1}};
    res = sol.largestSubmatrix(matrix_2);
    cout << res << endl;
    assert(res == 3);

    // Test_3
    vector<vector<int>> matrix_3 = {{1,1,0},{1,0,1}};
    res = sol.largestSubmatrix(matrix_3);
    cout << res << endl;
    assert(res == 2);

    return 0;
}
// Accepted
// 59/59 cases passed (63 ms)
// Your runtime beats 21.28 % of cpp submissions
// Your memory usage beats 13.83 % of cpp submissions (102.4 MB)