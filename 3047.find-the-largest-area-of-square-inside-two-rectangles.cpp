/*
 * @lc app=leetcode id=3047 lang=cpp
 *
 * [3047] Find the Largest Area of Square Inside Two Rectangles
 *
 * https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/
 *
 * algorithms
 * Medium (43.92%)
 * Likes:    84
 * Dislikes: 36
 * Total Accepted:    16.6K
 * Total Submissions: 37.8K
 * Testcase Example:  '[[1,1],[2,2],[3,1]]\n[[3,3],[4,4],[6,6]]'
 *
 * There exist n rectangles in a 2D plane. You are given two 0-indexed 2D
 * integer arrays bottomLeft and topRight, both of size n x 2, where
 * bottomLeft[i] and topRight[i] represent the bottom-left and top-right
 * coordinates of the i^th rectangle respectively.
 *
 * You can select a region formed from the intersection of two of the given
 * rectangles. You need to find the largest area of a square that can fit
 * inside this region if you select the region optimally.
 *
 * Return the largest possible area of a square, or 0 if there do not exist any
 * intersecting regions between the rectangles.
 *
 *
 * Example 1:
 *
 *
 * Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
 * Output: 1
 * Explanation: A square with side length 1 can fit inside either the
 * intersecting region of rectangle 0 and rectangle 1, or the intersecting
 * region of rectangle 1 and rectangle 2. Hence the largest area is side * side
 * which is 1 * 1 == 1.
 * It can be shown that a square with a greater side length can not fit inside
 * any intersecting region.
 *
 *
 * Example 2:
 *
 *
 * Input: bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]
 * Output: 1
 * Explanation: A square with side length 1 can fit inside either the
 * intersecting region of rectangle 0 and rectangle 1, the intersecting region
 * of rectangle 1 and rectangle 2, or the intersection region of all 3
 * rectangles. Hence the largest area is side * side which is 1 * 1 == 1.
 * It can be shown that a square with a greater side length can not fit inside
 * any intersecting region.
 * Note that the region can be formed by the intersection of more than 2
 * rectangles.
 *
 *
 * Example 3:
 *
 *
 * Input: bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]
 * Output: 0
 * Explanation: No pair of rectangles intersect, hence, we return 0.
 *
 *
 *
 * Constraints:
 *
 *
 * n == bottomLeft.length == topRight.length
 * 2 <= n <= 10^3
 * bottomLeft[i].length == topRight[i].length == 2
 * 1 <= bottomLeft[i][0], bottomLeft[i][1] <= 10^7
 * 1 <= topRight[i][0], topRight[i][1] <= 10^7
 * bottomLeft[i][0] < topRight[i][0]
 * bottomLeft[i][1] < topRight[i][1]
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr)
    {
        long long ret  = 0;
        int       size = (int) bl.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                long long w = max(0, min(tr[i][0], tr[j][0]) - max(bl[i][0], bl[j][0]));
                long long h = max(0, min(tr[i][1], tr[j][1]) - max(bl[i][1], bl[j][1]));
                ret         = max(ret, min(w, h) * min(w, h));
            }
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> buttomLeft_1 = { { 1, 1 }, { 2, 2 }, { 1, 2 } };
    vector<vector<int>> topRight_1   = { { 3, 3 }, { 4, 4 }, { 3, 4 } };
    cout << sol.largestSquareArea(buttomLeft_1, topRight_1) << endl;

    // Test_2
    vector<vector<int>> buttomLeft_2 = { { 1, 1 }, { 3, 3 }, { 3, 1 } };
    vector<vector<int>> topRight_2   = { { 2, 2 }, { 4, 4 }, { 4, 2 } };
    cout << sol.largestSquareArea(buttomLeft_2, topRight_2) << endl;

    return 0;
}
// Accepted
// 660/660 cases passed (219 ms)
// Your runtime beats 23.51 % of cpp submissions
// Your memory usage beats 49.36 % of cpp submissions (58.8 MB)