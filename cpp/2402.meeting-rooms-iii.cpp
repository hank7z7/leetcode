/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 *
 * https://leetcode.com/problems/meeting-rooms-iii/description/
 *
 * algorithms
 * Hard (39.16%)
 * Likes:    1158
 * Dislikes: 74
 * Total Accepted:    54.4K
 * Total Submissions: 138.6K
 * Testcase Example:  '2\n[[0,10],[1,5],[2,7],[3,4]]'
 *
 * You are given an integer n. There are n rooms numbered from 0 to n - 1.
 *
 * You are given a 2D integer array meetings where meetings[i] = [starti, endi]
 * means that a meeting will be held during the half-closed time interval
 * [starti, endi). All the values of starti are unique.
 *
 * Meetings are allocated to rooms in the following manner:
 *
 *
 * Each meeting will take place in the unused room with the lowest number.
 * If there are no available rooms, the meeting will be delayed until a room
 * becomes free. The delayed meeting should have the same duration as the
 * original meeting.
 * When a room becomes unused, meetings that have an earlier original start
 * time should be given the room.
 *
 *
 * Return the number of the room that held the most meetings. If there are
 * multiple rooms, return the room with the lowest number.
 *
 * A half-closed interval [a, b) is the interval between a and b including a
 * and not including b.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
 * Output: 0
 * Explanation:
 * - At time 0, both rooms are not being used. The first meeting starts in room
 * 0.
 * - At time 1, only room 1 is not being used. The second meeting starts in
 * room 1.
 * - At time 2, both rooms are being used. The third meeting is delayed.
 * - At time 3, both rooms are being used. The fourth meeting is delayed.
 * - At time 5, the meeting in room 1 finishes. The third meeting starts in
 * room 1 for the time period [5,10).
 * - At time 10, the meetings in both rooms finish. The fourth meeting starts
 * in room 0 for the time period [10,11).
 * Both rooms 0 and 1 held 2 meetings, so we return 0.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
 * Output: 1
 * Explanation:
 * - At time 1, all three rooms are not being used. The first meeting starts in
 * room 0.
 * - At time 2, rooms 1 and 2 are not being used. The second meeting starts in
 * room 1.
 * - At time 3, only room 2 is not being used. The third meeting starts in room
 * 2.
 * - At time 4, all three rooms are being used. The fourth meeting is delayed.
 * - At time 5, the meeting in room 2 finishes. The fourth meeting starts in
 * room 2 for the time period [5,10).
 * - At time 6, all three rooms are being used. The fifth meeting is delayed.
 * - At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts
 * in room 1 for the time period [10,12).
 * Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return
 * 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 100
 * 1 <= meetings.length <= 10^5
 * meetings[i].length == 2
 * 0 <= starti < endi <= 5 * 10^5
 * All the values of starti are unique.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    static int meetings_cmp(vector<int>& a, vector<int>& b) { return (a[0] < b[0]); }

    static int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end(), meetings_cmp);

        // Tracking how many meetings are assigned to each room
        vector<int> room(n, 0);
        // Tracking the end of time of each room's last meetgin
        vector<long long> time(n, 0);

        // With each meeting, check if there are any free rooms. If there are, then use the room
        // with the smallest number. Otherwise, assign the meeting to the room whose meeting will
        // end the soonest.
        for (size_t i = 0; i < meetings.size(); i++)
        {
            int       start        = meetings[i][0];
            int       end          = meetings[i][1];
            bool      find_room    = false;
            int       target_room  = -1;
            long long min_end_time = LONG_LONG_MAX;
            for (int j = 0; j < n; j++)
            {
                if (time[j] < min_end_time)
                {
                    min_end_time = time[j];
                    target_room  = j;
                }
                if (time[j] <= start)
                {
                    find_room = true;
                    room[j]++;
                    time[j] = end;
                    break;
                }
            }
            if (!find_room)
            {
                // Assign to the earliest end room
                room[target_room]++;
                time[target_room] += (long long) (end - start);
            }
        }

        // Search for result
        int max_time = INT_MIN;
        int id       = -1;
        for (int i = 0; i < n; i++)
        {
            if (room[i] > max_time)
            {
                max_time = room[i];
                id       = i;
            }
        }
        return id;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    int n;
    // Test_1
    n                              = 2;
    vector<vector<int>> meetings_1 = { { 0, 10 }, { 1, 5 }, { 2, 7 }, { 3, 4 } };
    cout << Solution::mostBooked(n, meetings_1) << endl;
    // Test_2
    n                              = 2;
    vector<vector<int>> meetings_2 = { { 1, 20 }, { 2, 10 }, { 3, 5 }, { 4, 9 }, { 6, 8 } };
    cout << Solution::mostBooked(n, meetings_2) << endl;

    return 0;
}
// Accepted
// 82/82 cases passed (311 ms)
// Your runtime beats 83.54 % of cpp submissions
// Your memory usage beats 60.76 % of cpp submissions (100.4 MB)