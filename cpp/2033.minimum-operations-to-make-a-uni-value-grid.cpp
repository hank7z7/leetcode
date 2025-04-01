/*
 * @lc app=leetcode id=2033 lang=cpp
 *
 * [2033] Minimum Operations to Make a Uni-Value Grid
 *
 * https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/
 *
 * algorithms
 * Medium (53.91%)
 * Likes:    843
 * Dislikes: 59
 * Total Accepted:    76.2K
 * Total Submissions: 120.7K
 * Testcase Example:  '[[2,4],[6,8]]\n2'
 *
 * You are given a 2D integer grid of size m x n and an integer x. In one
 * operation, you can add x to or subtract x from any element in the grid.
 *
 * A uni-value grid is a grid where all the elements of it are equal.
 *
 * Return the minimum number of operations to make the grid uni-value. If it is
 * not possible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,4],[6,8]], x = 2
 * Output: 4
 * Explanation: We can make every element equal to 4 by doing the following:
 * - Add x to 2 once.
 * - Subtract x from 6 once.
 * - Subtract x from 8 twice.
 * A total of 4 operations were used.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,5],[2,3]], x = 1
 * Output: 5
 * Explanation: We can make every element equal to 3.
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,2],[3,4]], x = 2
 * Output: -1
 * Explanation: It is impossible to make every element equal.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10^5
 * 1 <= m * n <= 10^5
 * 1 <= x, grid[i][j] <= 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<vector<int>>& grid, int x)
    {
        const int m = (int) grid.size();
        const int n = m == 0 ? 0 : (int) grid[0].size();
        const int total = m * n;
        if (m == 0 || n == 0)
            return 0;

        // Sort grid
        vector<int> nums;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                nums.push_back(grid[i][j]);
        sort(nums.begin(), nums.end());

        // Find the num that has median of count
        const int median = total / 2;
        int median_num_1 = nums[median];
        int median_num_2 = (median + 1) >= n ? nums[median] : nums[median + 1];

        // Check if it is possible for making the grid uni-value
        bool possible_1 = true;
        int res_1 = 0;
        bool possible_2 = true;
        int res_2 = 0;
        for (auto& num : nums)
        {
            // Early return
            if (!possible_1 && !possible_2)
                return -1;

            int diff_1 = abs(num - median_num_1);
            if (diff_1 % x != 0)
            {
                possible_1 = false;
            }
            res_1 += diff_1 / x;

            int diff_2 = abs(num - median_num_2);
            if (diff_2 % x != 0)
            {
                possible_2 = false;
            }
            res_2 += diff_2 / x;
        }

        if (!possible_1 && !possible_2)
            return -1;
        return min(res_1, res_2);
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = { { 2, 4 }, { 6, 8 } };
    int x_1 = 2;
    int res_1 = sol.minOperations(grid_1, x_1);
    cout << res_1 << endl;
    assert(res_1 == 4);

    // Test_2
    vector<vector<int>> grid_2 = { { 1, 5 }, { 2, 3 } };
    int x_2 = 1;
    int res_2 = sol.minOperations(grid_2, x_2);
    cout << res_2 << endl;
    assert(res_2 == 5);

    // Test_3
    vector<vector<int>> grid_3 = { { 1, 2 }, { 3, 4 } };
    int x_3 = 2;
    int res_3 = sol.minOperations(grid_3, x_3);
    cout << res_3 << endl;
    assert(res_3 == -1);

    // Test_4
    vector<vector<int>> grid_4 = { { 146 } };
    int x_4 = 86;
    int res_4 = sol.minOperations(grid_4, x_4);
    cout << res_4 << endl;
    assert(res_4 == 0);

    return 0;
}
// Accepted
// 62/62 cases passed (45 ms)
// Your runtime beats 48.94 % of cpp submissions
// Your memory usage beats 48.02 % of cpp submissions (90.1 MB)