/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 *
 * https://leetcode.com/problems/path-with-maximum-probability/description/
 *
 * algorithms
 * Medium (55.53%)
 * Likes:    3266
 * Dislikes: 79
 * Total Accepted:    171.8K
 * Total Submissions: 299.7K
 * Testcase Example:  '3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.2]\n0\n2'
 *
 * You are given an undirected weighted graph of n nodes (0-indexed),
 * represented by an edge list where edges[i] = [a, b] is an undirected edge
 * connecting the nodes a and b with a probability of success of traversing
 * that edge succProb[i].
 *
 * Given two nodes start_node and end, find the path with the maximum probability of
 * success to go from start_node to end and return its success probability.
 *
 * If there is no path from start_node to end, return 0. Your answer will be
 * accepted if it differs from the correct answer by at most 1e-5.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start_node =
 * 0, end = 2
 * Output: 0.25000
 * Explanation: There are two paths from start_node to end, one having a probability
 * of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start_node =
 * 0, end = 2
 * Output: 0.30000
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: n = 3, edges = [[0,1]], succProb = [0.5], start_node = 0, end = 2
 * Output: 0.00000
 * Explanation: There is no path between 0 and 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 10^4
 * 0 <= start_node, end < n
 * start_node != end
 * 0 <= a, b < n
 * a != b
 * 0 <= succProb.length == edges.length <= 2*10^4
 * 0 <= succProb[i] <= 1
 * There is at most one edge between every two nodes.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start_node
class Solution
{
public:
    double maxProbability(
        int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node)
    {
        // Adjacency list
        unordered_map<int, vector<pair<int, double>>> um;
        for (int i = 0; i < (int) edges.size(); i++)
        {
            um[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            um[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }

        vector<int> visited(n, 0);

        priority_queue<pair<double, int>> q;
        q.push({ (double) 1.0, start_node });

        vector<double> mx(n, (double) 0.0);
        mx[start_node] = 1.0;

        while (!q.empty())
        {
            auto top = q.top();
            q.pop();
            double proba = top.first;
            int    node  = top.second;
            if (!visited[node])
            {
                visited[node]++;
                for (auto& to : um[node])
                {
                    if (mx[to.first] < to.second * proba)
                    {
                        mx[to.first] = to.second * proba;
                        q.push({ mx[to.first], to.first });
                    }
                }
            }
        }
        return mx[end_node];
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int                 n_1          = 3;
    vector<vector<int>> edges_1      = { { 0, 1 }, { 1, 2 }, { 0, 2 } };
    vector<double>      sussProb_1   = { 0.5, 0.5, 0.2 };
    int                 start_node_1 = 0, end_1 = 2;
    double              res_1 = sol.maxProbability(n_1, edges_1, sussProb_1, start_node_1, end_1);
    cout << res_1 << endl;
    assert(res_1 == 0.25000);

    // Test_2
    int                 n_2          = 3;
    vector<vector<int>> edges_2      = { { 0, 1 }, { 1, 2 }, { 0, 2 } };
    vector<double>      sussProb_2   = { 0.5, 0.5, 0.3 };
    int                 start_node_2 = 0, end_2 = 2;
    double              res_2 = sol.maxProbability(n_2, edges_2, sussProb_2, start_node_2, end_2);
    cout << res_2 << endl;
    assert(res_2 == 0.30000);

    // Test_3
    int                 n_3          = 3;
    vector<vector<int>> edges_3      = { { 0, 1 } };
    vector<double>      sussProb_3   = { 0.5 };
    int                 start_node_3 = 0, end_3 = 2;
    double              res_3 = sol.maxProbability(n_3, edges_3, sussProb_3, start_node_3, end_3);
    cout << res_3 << endl;
    assert(res_3 == 0.0);

    return 0;
}
// Accepted
// 19/19 cases passed (148 ms)
// Your runtime beats 29.51 % of cpp submissions
// Your memory usage beats 17.86 % of cpp submissions (74.4 MB)