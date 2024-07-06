/*
 * @lc app=leetcode id=3206 lang=cpp
 *
 * [3206] Alternating Groups I
 *
 * https://leetcode.com/problems/alternating-groups-i/description/
 *
 * algorithms
 * Easy (62.17%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    26.8K
 * Total Submissions: 43K
 * Testcase Example:  '[1,1,1]'
 *
 * There is a circle of red and blue tiles. You are given an array of integers
 * colors. The color of tile i is represented by colors[i]:
 *
 *
 * colors[i] == 0 means that tile i is red.
 * colors[i] == 1 means that tile i is blue.
 *
 *
 * Every 3 contiguous tiles in the circle with alternating colors (the middle
 * tile has a different color from its left and right tiles) is called an
 * alternating group.
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
 * Input: colors = [1,1,1]
 *
 * Output: 0
 *
 * Explanation:
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: colors = [0,1,0,0,1]
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
 *
 * Constraints:
 *
 *
 * 3 <= colors.length <= 100
 * 0 <= colors[i] <= 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors)
    {
        int count = 0;
        int n = (int)colors.size();
        for (int i = 1; i < n - 1; i++)
        {
            if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1])
                count++;
        }

        if (colors[0] != colors[1] && colors[0] != colors[n - 1])
            count++;
        if (colors[n - 1] != colors[n - 2] && colors[n - 1] != colors[0])
            count++;

        return count;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> colors_1 = {1, 1, 1};
    int res_1 = sol.numberOfAlternatingGroups(colors_1);
    cout << res_1 << endl;
    assert(res_1 == 0);

    // Test_2
    vector<int> colors_2 = {0, 1, 0, 0, 1};
    int res_2 = sol.numberOfAlternatingGroups(colors_2);
    cout << res_2 << endl;
    assert(res_2 == 3);

    return 0;
}
// Accepted
// 795/795 cases passed (4 ms)
// Your runtime beats 60 % of cpp submissions
// Your memory usage beats 20 % of cpp submissions (25.9 MB)