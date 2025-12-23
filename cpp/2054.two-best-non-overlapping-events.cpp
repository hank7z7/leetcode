/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 *
 * https://leetcode.com/problems/two-best-non-overlapping-events/description/
 *
 * algorithms
 * Medium (60.83%)
 * Likes:    1678
 * Dislikes: 67
 * Total Accepted:    133.8K
 * Total Submissions: 214K
 * Testcase Example:  '[[1,3,2],[4,5,2],[2,4,3]]'
 *
 * You are given a 0-indexed 2D integer array of events where events[i] =
 * [startTimei, endTimei, valuei]. The i^th event starts at startTimei and ends
 * at endTimei, and if you attend this event, you will receive a value of
 * valuei. You can choose at most two non-overlapping events to attend such
 * that the sum of their values is maximized.
 * 
 * Return this maximum sum.
 * 
 * Note that the start time and end time is inclusive: that is, you cannot
 * attend two events where one of them starts and the other ends at the same
 * time. More specifically, if you attend an event with end time t, the next
 * event must start at or after t + 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: events = [[1,3,2],[4,5,2],[2,4,3]]
 * Output: 4
 * Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: events = [[1,3,2],[4,5,2],[1,5,5]]
 * Output: 5
 * Explanation: Choose event 2 for a sum of 5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: events = [[1,5,3],[1,5,1],[6,6,5]]
 * Output: 8
 * Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= events.length <= 10^5
 * events[i].length == 3
 * 1 <= startTimei <= endTimei <= 10^9
 * 1 <= valuei <= 10^6
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        const int n = (int)events.size();
        int res = 0;
        // Sort events by start time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Precompute max value from the right
        vector<int> maxFromRight(n);
        maxFromRight[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            maxFromRight[i] = max(maxFromRight[i + 1], events[i][2]);
        }

        // For each event, find the next non-overlapping event (next start time > current end time)
        // by using binary search
        for (int i = 0; i < n; ++i) {
            int currValue = events[i][2];
            int nextIndex = n;
            // Binary search for the next event
            int left = i + 1, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (nextIndex < n) {
                currValue += maxFromRight[nextIndex];
            }
            res = max(res, currValue);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv) {
    Solution sol;
    // Test_1
    vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};
    int res = sol.maxTwoEvents(events);
    cout << res << endl;
    assert(res == 4);

    // Test_2
    events = {{1,3,2},{4,5,2},{1,5,5}};
    res = sol.maxTwoEvents(events);
    cout << res << endl;
    assert(res == 5);

    // Test_3
    events = {{1,5,3},{1,5,1},{6,6,5}};
    res = sol.maxTwoEvents(events);
    cout << res << endl;
    assert(res == 8);

    return 0;
}
// Accepted
// 64/64 cases passed (64 ms)
// Your runtime beats 86.1 % of cpp submissions
// Your memory usage beats 90.73 % of cpp submissions (158.5 MB)