/*
 * @lc app=leetcode id=3143 lang=cpp
 *
 * [3143] Maximum Points Inside the Square
 *
 * https://leetcode.com/problems/maximum-points-inside-the-square/description/
 *
 * algorithms
 * Medium (31.81%)
 * Likes:    10
 * Dislikes: 7
 * Total Accepted:    8.1K
 * Total Submissions: 25.4K
 * Testcase Example:  '[[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]]\n"abdca"'
 *
 * You are given a 2D array points and a string s where, points[i] represents
 * the coordinates of point i, and s[i] represents the tag of point i.
 *
 * A valid square is a square centered at the origin (0, 0), has edges parallel
 * to the axes, and does not contain two points with the same tag.
 *
 * Return the maximum number of points contained in a valid square.
 *
 * Note:
 *
 *
 * A point is considered to be inside the square if it lies on or within the
 * square's boundaries.
 * The side length of the square can be zero.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]], s = "abdca"
 *
 * Output: 2
 *
 * Explanation:
 *
 * The square of side length 4 covers two points points[0] and points[1].
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: points = [[1,1],[-2,-2],[-2,2]], s = "abb"
 *
 * Output: 1
 *
 * Explanation:
 *
 * The square of side length 2 covers one point, which is points[0].
 *
 *
 * Example 3:
 *
 *
 * Input: points = [[1,1],[-1,-1],[2,-2]], s = "ccd"
 *
 * Output: 0
 *
 * Explanation:
 *
 * It's impossible to make any valid squares centered at the origin such that
 * it covers only one point among points[0] and points[1].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, points.length <= 10^5
 * points[i].length == 2
 * -10^9 <= points[i][0], points[i][1] <= 10^9
 * s.length == points.length
 * points consists of distinct coordinates.
 * s consists only of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        int n = (int)points.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            vector<int> point = points[i];
            int d = max(abs(point[0]), abs(point[1]));
            if (mp.find(d) == mp.end())
            {
                mp[d] = vector<int>(26, 0);
            }
            mp[d][s[i] - 'a']++;
        }

        int result = 0;
        vector<int> acc(26, 0);
        for (auto it : mp)
        {
            bool valid = true;
            for (int i = 0; i < 26; i++)
            {
                acc[i] += it.second[i];
                if (acc[i] > 1)
                {
                    valid = false;
                }
            }

            if (valid)
            {
                int sum = 0;
                for (int i = 0; i < 26; i++)
                    if (acc[i] > 0)
                        sum++;
                result = max(sum, result);
            }
            else
                break;
        }

        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> points_1 = {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}};
    string s_1 = "abdca";
    cout << sol.maxPointsInsideSquare(points_1, s_1) << endl;

    // Test_2
    vector<vector<int>> points_2 = {{1, 1}, {-2, -2}, {-2, 2}};
    string s_2 = "abb";
    cout << sol.maxPointsInsideSquare(points_2, s_2) << endl;

    // Test_3
    vector<vector<int>> points_3 = {{1, 1}, {-1, -1}, {2, -2}};
    string s_3 = "ccd";
    cout << sol.maxPointsInsideSquare(points_3, s_3) << endl;

    return 0;
}
// Accepted
// 575/575 cases passed (378 ms)
// Your runtime beats 10 % of cpp submissions
// Your memory usage beats 10 % of cpp submissions (168.2 MB)