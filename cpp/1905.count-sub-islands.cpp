/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 *
 * https://leetcode.com/problems/count-sub-islands/description/
 *
 * algorithms
 * Medium (67.53%)
 * Likes:    2119
 * Dislikes: 65
 * Total Accepted:    104.5K
 * Total Submissions: 153.2K
 * Testcase Example:  '[[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]\n' +
  '[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]'
 *
 * You are given two m x n binary matrices grid1 and grid2 containing only 0's
 * (representing water) and 1's (representing land). An island is a group of
 * 1's connected 4-directionally (horizontal or vertical). Any cells outside of
 * the grid are considered water cells.
 *
 * An island in grid2 is considered a sub-island if there is an island in grid1
 * that contains all the cells that make up this island in grid2.
 *
 * Return the number of islands in grid2 that are considered sub-islands.
 *
 *
 * Example 1:
 *
 *
 * Input: grid1 =
 * [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 =
 * [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
 * Output: 3
 * Explanation: In the picture above, the grid on the left is grid1 and the
 * grid on the right is grid2.
 * The 1s colored red in grid2 are those considered to be part of a sub-island.
 * There are three sub-islands.
 *
 *
 * Example 2:
 *
 *
 * Input: grid1 =
 * [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 =
 * [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
 * Output: 2
 * Explanation: In the picture above, the grid on the left is grid1 and the
 * grid on the right is grid2.
 * The 1s colored red in grid2 are those considered to be part of a sub-island.
 * There are two sub-islands.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid1.length == grid2.length
 * n == grid1[i].length == grid2[i].length
 * 1 <= m, n <= 500
 * grid1[i][j] and grid2[i][j] are either 0 or 1.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int m = (int) grid1.size();
        int n = m == 0 ? 0 : (int) grid1[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // DFS if curr is a non-visited land
                if (grid2[i][j] == 1 && !visited[i][j])
                {
                    bool is_subisland = true;

                    // Stack stores indexes of lands
                    stack<pair<int, int>> st;
                    // Initailize with first land
                    st.push({ i, j });
                    while (!st.empty())
                    {
                        pair<int, int> curr = st.top();
                        st.pop();

                        visited[curr.first][curr.second] = true;

                        if (grid1[curr.first][curr.second] == 0)
                            is_subisland = false;

                        // Up
                        if (curr.first - 1 >= 0 && !visited[curr.first - 1][curr.second]
                            && grid2[curr.first - 1][curr.second] == 1)
                            st.push({ curr.first - 1, curr.second });
                        // Right
                        if (curr.second + 1 < n && !visited[curr.first][curr.second + 1]
                            && grid2[curr.first][curr.second + 1] == 1)
                            st.push({ curr.first, curr.second + 1 });
                        // Down
                        if (curr.first + 1 < m && !visited[curr.first + 1][curr.second]
                            && grid2[curr.first + 1][curr.second] == 1)
                            st.push({ curr.first + 1, curr.second });
                        // Left
                        if (curr.second - 1 >= 0 && !visited[curr.first][curr.second - 1]
                            && grid2[curr.first][curr.second - 1] == 1)
                            st.push({ curr.first, curr.second - 1 });
                    }

                    if (is_subisland)
                        res++;
                }
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
    vector<vector<int>> test_1_grid1 = { { 1, 1, 1, 0, 0 },
                                         { 0, 1, 1, 1, 1 },
                                         { 0, 0, 0, 0, 0 },
                                         { 1, 0, 0, 0, 0 },
                                         { 1, 1, 0, 1, 1 } };
    vector<vector<int>> test_1_grid2 = { { 1, 1, 1, 0, 0 },
                                         { 0, 0, 1, 1, 1 },
                                         { 0, 1, 0, 0, 0 },
                                         { 1, 0, 1, 1, 0 },
                                         { 0, 1, 0, 1, 0 } };
    int                 res_1        = sol.countSubIslands(test_1_grid1, test_1_grid2);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    vector<vector<int>> test_2_grid1 = { { 1, 0, 1, 0, 1 },
                                         { 1, 1, 1, 1, 1 },
                                         { 0, 0, 0, 0, 0 },
                                         { 1, 1, 1, 1, 1 },
                                         { 1, 0, 1, 0, 1 } };
    vector<vector<int>> test_2_grid2 = { { 0, 0, 0, 0, 0 },
                                         { 1, 1, 1, 1, 1 },
                                         { 0, 1, 0, 1, 0 },
                                         { 0, 1, 0, 1, 0 },
                                         { 1, 0, 0, 0, 1 } };
    int                 res_2        = sol.countSubIslands(test_2_grid1, test_2_grid2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    // Test_3
    vector<vector<int>> test_3_grid1
        = { { 1, 1, 1, 1, 0, 0 }, { 1, 1, 0, 1, 0, 0 }, { 1, 0, 0, 1, 1, 1 }, { 1, 1, 1, 0, 0, 1 },
            { 1, 1, 1, 1, 1, 0 }, { 1, 0, 1, 0, 1, 0 }, { 0, 1, 1, 1, 0, 1 }, { 1, 0, 0, 0, 1, 1 },
            { 1, 0, 0, 0, 1, 0 }, { 1, 1, 1, 1, 1, 0 } };
    vector<vector<int>> test_3_grid2
        = { { 1, 1, 1, 1, 0, 1 }, { 0, 0, 1, 0, 1, 0 }, { 1, 1, 1, 1, 1, 1 }, { 0, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 0, 1, 0 }, { 0, 1, 1, 1, 1, 1 }, { 1, 1, 0, 1, 1, 1 }, { 1, 0, 0, 1, 0, 1 },
            { 1, 1, 1, 1, 1, 1 }, { 1, 0, 0, 1, 0, 0 } };
    int res_3 = sol.countSubIslands(test_3_grid1, test_3_grid2);
    cout << res_3 << endl;
    assert(res_3 == 0);

    return 0;
}
// Accepted
// 57/57 cases passed (335 ms)
// Your runtime beats 27.73 % of cpp submissions
// Your memory usage beats 10.72 % of cpp submissions (224.3 MB)