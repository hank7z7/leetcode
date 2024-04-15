/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Medium (40.23%)
 * Likes:    9722
 * Dislikes: 732
 * Total Accepted:    988.7K
 * Total Submissions: 2.4M
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * You are given an array of non-overlapping intervals intervals where
 * intervals[i] = [starti, endi] represent the start and the end of the i^th
 * interval and intervals is sorted in ascending order by starti. You are also
 * given an interval newInterval = [start, end] that represents the start and
 * end of another interval.
 *
 * Insert newInterval into intervals such that intervals is still sorted in
 * ascending order by starti and intervals still does not have any overlapping
 * intervals (merge overlapping intervals if necessary).
 *
 * Return intervals after the insertion.
 *
 * Note that you don't need to modify intervals in-place. You can make a new
 * array and return it.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^5
 * intervals is sorted by starti in ascending order.
 * newInterval.length == 2
 * 0 <= start <= end <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(),
             intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        vector<vector<int>> ret;
        for (int i = 0; i < (int) intervals.size(); i++)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];
            // Find the index of the right interval
            while ((i + 1) < (int) intervals.size()
                   && (r >= intervals[i + 1][0] || r >= intervals[i + 1][1]))
            {
                i++;
                r = max(r, intervals[i][1]);
            }
            // Push back the new interval
            ret.push_back({ l, r });
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> intervals_1     = { { 1, 3 }, { 6, 9 } };
    vector<int>         new_intervals_1 = { 2, 5 };
    for (auto interval : sol.insert(intervals_1, new_intervals_1))
        cout << "[" << interval[0] << ", " << interval[1] << "]";
    cout << endl;

    // Test_2
    vector<vector<int>> intervals_2     = { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } };
    vector<int>         new_intervals_2 = { 2, 5 };
    for (auto interval : sol.insert(intervals_2, new_intervals_2))
        cout << "[" << interval[0] << ", " << interval[1] << "]";
    cout << endl;

    // Test_3
    vector<vector<int>> intervals_3     = { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } };
    vector<int>         new_intervals_3 = { 4, 8 };
    for (auto interval : sol.insert(intervals_3, new_intervals_3))
        cout << "[" << interval[0] << ", " << interval[1] << "]";
    cout << endl;

    return 0;
}
// Accepted
// 156/156 cases passed (7 ms)
// Your runtime beats 92.69 % of cpp submissions
// Your memory usage beats 50.08 % of c submissions (20.5 MB)