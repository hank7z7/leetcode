/*
 * @lc app=leetcode id=3195 lang=cpp
 *
 * [3195] Find the Minimum Area to Cover All Ones I
 *
 * https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/
 *
 * algorithms
 * Medium (73.83%)
 * Likes:    31
 * Dislikes: 2
 * Total Accepted:    25.9K
 * Total Submissions: 35K
 * Testcase Example:  '[[0,1,0],[1,0,1]]'
 *
 * You are given a 2D binary array grid. Find a rectangle with horizontal and
 * vertical sides with the smallest area, such that all the 1's in grid lie
 * inside this rectangle.
 * 
 * Return the minimum possible area of the rectangle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,1,0],[1,0,1]]
 * 
 * Output: 6
 * 
 * Explanation:
 * 
 * 
 * 
 * The smallest rectangle has a height of 2 and a width of 3, so it has an area
 * of 2 * 3 = 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,0],[1,0]]
 * 
 * Output: 1
 * 
 * Explanation:
 * 
 * 
 * 
 * The smallest rectangle has both height and width 1, so its area is 1 * 1 =
 * 1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length, grid[i].length <= 1000
 * grid[i][j] is either 0 or 1.
 * The input is generated such that there is at least one 1 in grid.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_x = INT32_MAX;
        int max_x = INT32_MIN;
        int min_y = INT32_MAX;
        int max_y = INT32_MIN;
        int m = (int)grid.size();
        int n = 0;
        if(m != 0)
            n = (int)grid[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    min_x = min(min_x, j);
                    max_x = max(max_x, j);
                    min_y = min(min_y, i);
                    max_y = max(max_y, i);
                }
            }
        }
        return ((max_x - min_x + 1) * (max_y - min_y + 1));
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> grid_1 = {{0, 1, 0}, {1, 0, 1}};
    int res_1 = sol.minimumArea(grid_1);
    cout << res_1 << endl;
    assert(res_1 == 6);

    // Test_2
    vector<vector<int>> grid_2 = {{0, 0}, {1, 0}};
    int res_2 = sol.minimumArea(grid_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    return 0;
}
// Accepted
// 712/712 cases passed (260 ms)
// Your runtime beats 14.29 % of cpp submissions
// Your memory usage beats 28.57 % of cpp submissions (132.2 MB)