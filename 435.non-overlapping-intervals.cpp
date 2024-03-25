/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (52.99%)
 * Likes:    7939
 * Dislikes: 214
 * Total Accepted:    542.3K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are
 * non-overlapping.
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals
 * non-overlapping.
 *
 *
 * Example 3:
 *
 *
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),
             intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int count = 0;
        int end   = INT_MIN;
        for (int i = 0; i < (int) intervals.size(); i++)
        {
            if (intervals[i][0] >= end)
                end = intervals[i][1];
            else
                count++;
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> intervals_1 = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 3 } };
    cout << sol.eraseOverlapIntervals(intervals_1) << endl;

    // Test_2
    vector<vector<int>> intervals_2 = { { 1, 2 }, { 1, 2 }, { 1, 2 } };
    cout << sol.eraseOverlapIntervals(intervals_2) << endl;

    // Test_3
    vector<vector<int>> intervals_3 = { { 1, 2 }, { 2, 3 } };
    cout << sol.eraseOverlapIntervals(intervals_3) << endl;

    // Test_4
    vector<vector<int>> intervals_4 = { { 1, 100 }, { 11, 22 }, { 1, 11 }, { 2, 12 } };
    cout << sol.eraseOverlapIntervals(intervals_4) << endl;
    return 0;
}
// Accepted
// 59/59 cases passed (246 ms)
// Your runtime beats 58.17 % of cpp submissions
// Your memory usage beats 75.63 % of cpp submissions (93.3 MB)