/*
 * @lc app=leetcode id=3070 lang=cpp
 *
 * [3070] Count Submatrices with Top-Left Element and Sum Less Than k
 *
 * https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/
 *
 * algorithms
 * Medium (53.20%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 19.7K
 * Testcase Example:  '[[7,6,3],[6,6,1]]\n18'
 *
 * You are given a 0-indexed integer matrix grid and an integer k.
 *
 * Return the number of submatrices that contain the top-left element of the
 * grid, and have a sum less than or equal to k.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[7,6,3],[6,6,1]], k = 18
 * Output: 4
 * Explanation: There are only 4 submatrices, shown in the image above, that
 * contain the top-left element of grid, and have a sum less than or equal to
 * 18.
 *
 * Example 2:
 *
 *
 * Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
 * Output: 6
 * Explanation: There are only 6 submatrices, shown in the image above, that
 * contain the top-left element of grid, and have a sum less than or equal to
 * 20.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= n, m <= 1000
 * 0 <= grid[i][j] <= 1000
 * 1 <= k <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countSubmatrices(vector<vector<int>>& grid, int k)
    {
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[i].size(); j++)
            {
                if (j > 0)
                    grid[i][j] += grid[i][j - 1];
            }
        }
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            for (size_t i = 0; i < grid.size(); i++)
            {
                if (i > 0)
                    grid[i][j] += grid[i - 1][j];
            }
        }
        int count = 0;
        for (auto i : grid)
        {
            for (auto j : i)
            {
                if (j <= k)
                    count++;
            }
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      k;
    // Test_1
    k                          = 18;
    vector<vector<int>> grid_1 = {{7, 6, 3}, {6, 6, 1}};
    cout << sol.countSubmatrices(grid_1, k) << endl;

    // Test_2
    k                          = 20;
    vector<vector<int>> grid_2 = { { 7, 2, 9 }, { 1, 5, 0 }, { 2, 6, 6 } };
    cout << sol.countSubmatrices(grid_2, k) << endl;

    return 0;
}
// Accepted
// 859/859 cases passed (184 ms)
// Your runtime beats 30 % of cpp submissions
// Your memory usage beats 20 % of cpp submissions (98.7 MB)