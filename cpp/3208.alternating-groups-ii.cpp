/*
 * @lc app=leetcode id=3208 lang=cpp
 *
 * [3208] Alternating Groups II
 *
 * https://leetcode.com/problems/alternating-groups-ii/description/
 *
 * algorithms
 * Medium (27.97%)
 * Likes:    24
 * Dislikes: 1
 * Total Accepted:    11.4K
 * Total Submissions: 37.5K
 * Testcase Example:  '[0,1,0,1,0]\n3'
 *
 * There is a circle of red and blue tiles. You are given an array of integers
 * colors and an integer k. The color of tile i is represented by
 * colors[i]:
 *
 *
 * colors[i] == 0 means that tile i is red.
 * colors[i] == 1 means that tile i is blue.
 *
 *
 * An alternating group is every k contiguous tiles in the circle with
 * alternating colors (each tile in the group except the first and last one has
 * a different color from its left and right tiles).
 *
 * Return the number of alternating groups.
 *
 * Note that since colors represents a circle, the first and the last tiles are
 * considered to be next to each other.
 *
 *
 * Example 1:
 *
 *
 * Input: colors = [0,1,0,1,0], k = 3
 *
 * Output: 3
 *
 * Explanation:
 *
 *
 *
 * Alternating groups:
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: colors = [0,1,0,0,1,0,1], k = 6
 *
 * Output: 2
 *
 * Explanation:
 *
 *
 *
 * Alternating groups:
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: colors = [1,1,0,1], k = 4
 *
 * Output: 0
 *
 * Explanation:
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= colors.length <= 10^5
 * 0 <= colors[i] <= 1
 * 3 <= k <= colors.length
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = (int)colors.size();

        int res = 0;
        int l = 0;
        for (int r = 1; r < (n + k - 1); r++)
        {
            int curr_r = r % n;
            int prev_r = (r - 1) % n;
            if (colors[curr_r] != colors[prev_r])
            {
                if ((r - l + 1) >= k)
                    res++;
            }
            else
            {
                l = r;
            }
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> colors_1 = {0, 1, 0, 1, 0};
    int k_1 = 3;
    int res_1 = sol.numberOfAlternatingGroups(colors_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    vector<int> colors_2 = {0, 1, 0, 0, 1, 0, 1};
    int k_2 = 6;
    int res_2 = sol.numberOfAlternatingGroups(colors_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    // Test_3
    vector<int> colors_3 = {1, 1, 0, 1};
    int k_3 = 4;
    int res_3 = sol.numberOfAlternatingGroups(colors_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == 0);

    return 0;
}
// Accepted
// 625/625 cases passed (91 ms)
// Your runtime beats 14.29 % of cpp submissions
// Your memory usage beats 14.29 % of cpp submissions (100.9 MB)