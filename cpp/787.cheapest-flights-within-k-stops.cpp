/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 *
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 *
 * algorithms
 * Medium (37.47%)
 * Likes:    9135
 * Dislikes: 374
 * Total Accepted:    459.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '4\n[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]\n0\n3\n1'
 *
 * There are n cities connected by some number of flights. You are given an
 * array flights where flights[i] = [fromi, toi, pricei] indicates that there
 * is a flight from city fromi to city toi with cost pricei.
 *
 * You are also given three integers src, dst, and k, return the cheapest price
 * from src to dst with at most k stops. If there is no such route, return
 * -1.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]],
 * src = 0, dst = 3, k = 1
 * Output: 700
 * Explanation:
 * The graph is shown above.
 * The optimal path with at most 1 stop from city 0 to 3 is marked in red and
 * has cost 100 + 600 = 700.
 * Note that the path through cities [0,1,2,3] is cheaper but is invalid
 * because it uses 2 stops.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
 * Output: 200
 * Explanation:
 * The graph is shown above.
 * The optimal path with at most 1 stop from city 0 to 2 is marked in red and
 * has cost 100 + 100 = 200.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
 * Output: 500
 * Explanation:
 * The graph is shown above.
 * The optimal path with no stops from city 0 to 2 is marked in red and has
 * cost 500.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 100
 * 0 <= flights.length <= (n * (n - 1) / 2)
 * flights[i].length == 3
 * 0 <= fromi, toi < n
 * fromi != toi
 * 1 <= pricei <= 10^4
 * There will not be any multiple flights between two cities.
 * 0 <= src, dst, k < n
 * src != dst
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // flight = {src, dst, cost}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        if (src == dst)
            return 0;
        //  Create an adjacency list
        //  src -> [dst, cost]
        vector<vector<pair<int, int>>> al(n);
        // Record number of path to dst
        vector<int> as_dst(n, 0);
        for (auto it : flights)
        {
            al[it[0]].push_back(pair<int, int>(it[1], it[2]));
            as_dst[it[1]]++;
        }
        // Early return
        if (al[src].empty() || as_dst[dst] == 0)
            return -1;
        int dist_min = INT_MAX;  // result
        // BFS search
        queue<pair<int, int>> q;  // Queue of [dst, distance from src]
        q.push(pair<int, int>(src, 0));

        while (!q.empty() && k >= 0)
        {
            size_t curr_size = q.size();
            for (size_t i = 0; i < curr_size; i++)
            {
                // Pop
                auto curr = q.front();
                q.pop();

                // Search all adjacency node from src
                for (auto adj : al[curr.first])
                {
                    int next_dst  = adj.first;
                    int next_dist = curr.second + adj.second;
                    // If the dist of src to this neibor is greater than current min, skip this
                    if (next_dist > dist_min)
                        continue;
                    q.push(pair<int, int>(next_dst, next_dist));
                    // Update dist_min f we find a path to dst
                    if (next_dst == dst)
                        dist_min = min(dist_min, next_dist);
                }
            }
            k--;
        }
        return dist_min == INT_MAX ? -1 : dist_min;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    int      n, src, dst, k;
    // Test_1
    vector<vector<int>> flights_1
        = { { 0, 1, 100 }, { 1, 2, 100 }, { 2, 0, 100 }, { 1, 3, 600 }, { 2, 3, 200 } };
    n = 4, src = 0, dst = 3, k = 1;
    cout << sol.findCheapestPrice(n, flights_1, src, dst, k) << endl;

    // Test_2
    vector<vector<int>> flights_2 = { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } };
    n = 3, src = 0, dst = 2, k = 1;
    cout << sol.findCheapestPrice(n, flights_2, src, dst, k) << endl;

    // Test_3
    vector<vector<int>> flights_3 = { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } };
    n = 3, src = 0, dst = 2, k = 0;
    cout << sol.findCheapestPrice(n, flights_3, src, dst, k) << endl;

    // Test_4
    // vector<vector<int>> flights_4 = { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } };
    // n = 100, src = 0, dst = 2, k = 0;
    // cout << sol.findCheapestPrice(n, flights_4, src, dst, k) << endl;

    return 0;
}
