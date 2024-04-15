/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 *
 * https://leetcode.com/problems/number-of-recent-calls/description/
 *
 * algorithms
 * Easy (74.49%)
 * Likes:    456
 * Dislikes: 701
 * Total Accepted:    231.7K
 * Total Submissions: 310.4K
 * Testcase Example:  '["RecentCounter","ping","ping","ping","ping"]\n[[],[1],[100],[3001],[3002]]'
 *
 * You have a RecentCounter class which counts the number of recent requests
 * within a certain time frame.
 *
 * Implement the RecentCounter class:
 *
 *
 * RecentCounter() Initializes the counter with zero recent requests.
 * int ping(int t) Adds a new request at time t, where t represents some time
 * in milliseconds, and returns the number of requests that has happened in the
 * past 3000 milliseconds (including the new request). Specifically, return the
 * number of requests that have happened in the inclusive range [t - 3000,
 * t].
 *
 *
 * It is guaranteed that every call to ping uses a strictly larger value of t
 * than the previous call.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["RecentCounter", "ping", "ping", "ping", "ping"]
 * [[], [1], [100], [3001], [3002]]
 * Output
 * [null, 1, 2, 3, 3]
 *
 * Explanation
 * RecentCounter recentCounter = new RecentCounter();
 * recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
 * recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100],
 * return 2
 * recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001],
 * return 3
 * recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is
 * [2,3002], return 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= t <= 10^9
 * Each test case will call ping with strictly increasing values of t.
 * At most 10^4 calls will be made to ping.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class RecentCounter
{
private:
    queue<int> time;

public:
    RecentCounter() { time = queue<int>(); }

    int ping(int t)
    {
        time.push(t);
        while (time.front() < (t - 3000))
            time.pop();
        return (int) time.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
int main(int argc, char* argv[])
{
    // Test_1
    RecentCounter obj = RecentCounter();
    cout << obj.ping(1) << endl;
    cout << obj.ping(1000) << endl;
    cout << obj.ping(3001) << endl;
    cout << obj.ping(3003) << endl;

    return 0;
}
// Success
// Details
// Runtime: 109 ms, faster than 69.83% of C++ online submissions for Number of Recent Calls.
// Memory Usage: 61.1 MB, less than 22.08% of C++ online submissions for Number of Recent Calls.