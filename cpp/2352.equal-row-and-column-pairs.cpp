/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 *
 * https://leetcode.com/problems/equal-row-and-column-pairs/description/
 *
 * algorithms
 * Medium (71.07%)
 * Likes:    2084
 * Dislikes: 135
 * Total Accepted:    184.5K
 * Total Submissions: 260.1K
 * Testcase Example:  '[[3,2,1],[1,7,6],[2,7,7]]'
 *
 * Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri,
 * cj) such that row ri and column cj are equal.
 *
 * A row and column pair is considered equal if they contain the same elements
 * in the same order (i.e., an equal array).
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
 * Output: 1
 * Explanation: There is 1 equal row and column pair:
 * - (Row 2, Column 1): [2,7,7]
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
 * Output: 3
 * Explanation: There are 3 equal row and column pairs:
 * - (Row 0, Column 0): [3,1,2,2]
 * - (Row 2, Column 2): [2,4,2,2]
 * - (Row 3, Column 2): [2,4,2,2]
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * 1 <= grid[i][j] <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        int                   count = 0;
        map<vector<int>, int> mp;
        for (auto row : grid)
            mp[row]++;
        for (size_t i = 0; i < grid.size(); i++)
        {
            vector<int> col;
            for (size_t j = 0; j < grid.size(); j++)
                col.push_back(grid[j][i]);
            if (mp[col] > 0)
                count += mp[col];
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = { { 3, 2, 1 }, { 1, 7, 6 }, { 2, 7, 7 } };
    cout << sol.equalPairs(grid_1) << endl;

    // Test_2
    vector<vector<int>> grid_2 = { { 3, 1, 2, 2 }, { 1, 4, 4, 5 }, { 2, 4, 2, 2 }, { 2, 4, 2, 2 } };
    cout << sol.equalPairs(grid_2) << endl;

    return 0;
}
// Accepted
// 79/79 cases passed (72 ms)
// Your runtime beats 63.2 % of cpp submissions
// Your memory usage beats 39.42 % of cpp submissions (37.5 MB)