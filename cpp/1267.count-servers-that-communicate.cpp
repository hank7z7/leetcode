/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 *
 * https://leetcode.com/problems/count-servers-that-communicate/description/
 *
 * algorithms
 * Medium (60.62%)
 * Likes:    1486
 * Dislikes: 90
 * Total Accepted:    96.1K
 * Total Submissions: 143.9K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * You are given a map of a server center, represented as a m * n integer
 * matrix grid, where 1 means that on that cell there is a server and 0 means
 * that it is no server. Two servers are said to communicate if they are on the
 * same row or on the same column.
 *
 * Return the number of servers that communicate with any other server.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: grid = [[1,0],[0,1]]
 * Output: 0
 * Explanation: No servers can communicate with others.
 *
 * Example 2:
 *
 *
 *
 *
 * Input: grid = [[1,0],[1,1]]
 * Output: 3
 * Explanation: All three servers can communicate with at least one other
 * server.
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
 * Output: 4
 * Explanation: The two servers in the first row can communicate with each
 * other. The two servers in the third column can communicate with each other.
 * The server at right bottom corner can't communicate with any other
 * server.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m <= 250
 * 1 <= n <= 250
 * grid[i][j] == 0 or 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countServers(const vector<vector<int>>& grid)
    {
        const int m = grid.size();
        const int n = m == 0 ? 0 : grid[0].size();
        // Count the number of cell in a row or column
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                row_count[i] += grid[i][j];
                col_count[j] += grid[i][j];
            }

        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1))
                    res++;

        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = { { 1, 0 }, { 0, 1 } };
    int res_1 = sol.countServers(grid_1);
    cout << res_1 << endl;
    assert(res_1 == 0);

    // Test_2
    vector<vector<int>> grid_2 = { { 1, 0 }, { 1, 1 } };
    int res_2 = sol.countServers(grid_2);
    cout << res_2 << endl;
    assert(res_2 == 3);

    // Test_3
    vector<vector<int>> grid_3 = { { 1, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };
    int res_3 = sol.countServers(grid_3);
    cout << res_3 << endl;
    assert(res_3 == 4);

    return 0;
}
// Accepted
// 55/55 cases passed (11 ms)
// Your runtime beats 25.98 % of cpp submissions
// Your memory usage beats 59.58 % of cpp submissions (26.6 MB)