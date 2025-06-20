/*
 * @lc app=leetcode id=3443 lang=cpp
 *
 * [3443] Maximum Manhattan Distance After K Changes
 *
 * https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/
 *
 * algorithms
 * Medium (30.81%)
 * Likes:    154
 * Dislikes: 16
 * Total Accepted:    16.1K
 * Total Submissions: 52K
 * Testcase Example:  '"NWSE"\n1'
 *
 * You are given a string s consisting of the characters 'N', 'S', 'E', and
 * 'W', where s[i] indicates movements in an infinite grid:
 *
 *
 * 'N' : Move north by 1 unit.
 * 'S' : Move south by 1 unit.
 * 'E' : Move east by 1 unit.
 * 'W' : Move west by 1 unit.
 *
 *
 * Initially, you are at the origin (0, 0). You can change at most k characters
 * to any of the four directions.
 *
 * Find the maximum Manhattan distance from the origin that can be achieved at
 * any time while performing the movements in order.
 * The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj|
 * + |yi - yj|.
 *
 * Example 1:
 *
 *
 * Input: s = "NWSE", k = 1
 *
 * Output: 3
 *
 * Explanation:
 *
 * Change s[2] from 'S' to 'N'. The string s becomes
 * "NWNE".
 *
 *
 *
 *
 * Movement
 * Position (x, y)
 * Manhattan Distance
 * Maximum
 *
 *
 *
 *
 * s[0] == 'N'
 * (0, 1)
 * 0 + 1 = 1
 * 1
 *
 *
 * s[1] == 'W'
 * (-1, 1)
 * 1 + 1 = 2
 * 2
 *
 *
 * s[2] == 'N'
 * (-1, 2)
 * 1 + 2 = 3
 * 3
 *
 *
 * s[3] == 'E'
 * (0, 2)
 * 0 + 2 = 2
 * 3
 *
 *
 *
 *
 * The maximum Manhattan distance from the origin that can be achieved is 3.
 * Hence, 3 is the output.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "NSWWEW", k = 3
 *
 * Output: 6
 *
 * Explanation:
 *
 * Change s[1] from 'S' to 'N', and s[4] from 'E' to 'W'. The string s becomes
 * "NNWWWW".
 *
 * The maximum Manhattan distance from the origin that can be achieved is 6.
 * Hence, 6 is the output.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * 0 <= k <= s.length
 * s consists of only 'N', 'S', 'E', and 'W'.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test case 1
    string s = "NWSE";
    int k = 1;
    int res = sol.maxDistance(s, k);
    cout << res << endl;  // Expected output: 3

    // Test case 2
    s = "NSWWEW";
    k = 3;
    res = sol.maxDistance(s, k);
    cout << res << endl;  // Expected output: 6

    return 0;
}
// Accepted
// 828/828 cases passed (39 ms)
// Your runtime beats 96.06 % of cpp submissions
// Your memory usage beats 90.61 % of cpp submissions (38.1 MB)