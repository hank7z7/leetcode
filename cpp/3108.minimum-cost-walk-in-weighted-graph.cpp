/*
 * @lc app=leetcode id=3108 lang=cpp
 *
 * [3108] Minimum Cost Walk in Weighted Graph
 *
 * https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/
 *
 * algorithms
 * Hard (45.86%)
 * Likes:    428
 * Dislikes: 31
 * Total Accepted:    42.9K
 * Total Submissions: 69.6K
 * Testcase Example:  '5\n[[0,1,7],[1,3,7],[1,2,1]]\n[[0,3],[3,4]]'
 *
 * There is an undirected weighted graph with n vertices labeled from 0 to n -
 * 1.
 *
 * You are given the integer n and an array edges, where edges[i] = [ui, vi,
 * wi] indicates that there is an edge between vertices ui and vi with a weight
 * of wi.
 *
 * A walk on a graph is a sequence of vertices and edges. The walk starts and
 * ends with a vertex, and each edge connects the vertex that comes before it
 * and the vertex that comes after it. It's important to note that a walk may
 * visit the same edge or vertex more than once.
 *
 * The cost of a walk starting at node u and ending at node v is defined as the
 * bitwise AND of the weights of the edges traversed during the walk. In other
 * words, if the sequence of edge weights encountered during the walk is w0,
 * w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk,
 * where & denotes the bitwise AND operator.
 *
 * You are also given a 2D array query, where query[i] = [si, ti]. For each
 * query, you need to find the minimum cost of the walk starting at vertex si
 * and ending at vertex ti. If there exists no such walk, the answer is -1.
 *
 * Return the array answer, where answer[i] denotes the minimum cost of a walk
 * for query i.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]
 *
 * Output: [1,-1]
 *
 * Explanation:
 *
 * To achieve the cost of 1 in the first query, we need to move on the
 * following edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3
 * (weight 7).
 *
 * In the second query, there is no walk between nodes 3 and 4, so the answer
 * is -1.
 *
 * Example 2:
 *
 *
 *
 * Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]
 *
 * Output: [0]
 *
 * Explanation:
 *
 * To achieve the cost of 0 in the first query, we need to move on the
 * following edges: 1->2 (weight 1), 2->1 (weight 6), 1->2 (weight 1).
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 10^5
 * 0 <= edges.length <= 10^5
 * edges[i].length == 3
 * 0 <= ui, vi <= n - 1
 * ui != vi
 * 0 <= wi <= 10^5
 * 1 <= query.length <= 10^5
 * query[i].length == 2
 * 0 <= si, ti <= n - 1
 * si != ti
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries)
    {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges)
        {
            adjList[edge[0]].push_back({ edge[1], edge[2] });
            adjList[edge[1]].push_back({ edge[0], edge[2] });
        }

        vector<bool> visited(n, false);

        // Array to store the component ID of each node
        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        // Perform BFS for each unvisited node to identify components and
        // calculate their costs
        for (int node = 0; node < n; node++)
        {
            // If the node hasn't been visited, it's a new component
            if (!visited[node])
            {
                // Get the component cost and mark all nodes in the component
                componentCost.push_back(
                    getComponentCost(node, adjList, visited, components, componentId));
                // Increment the component ID for the next component
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries)
        {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end])
            {
                // If they are in the same component, return the precomputed
                // cost for the component
                answer.push_back(componentCost[components[start]]);
            }
            else
            {
                // If they are in different components, return -1
                answer.push_back(-1);
            }
        }

        return answer;
    }

private:
    // Helper function to calculate the cost of a component using BFS
    int getComponentCost(int source,
                         vector<vector<pair<int, int>>>& adjList,
                         vector<bool>& visited,
                         vector<int>& components,
                         int componentId)
    {
        queue<int> nodesQueue;

        // Initialize the component cost to the number that has only 1s in its
        // binary representation
        int componentCost = INT_MAX;

        nodesQueue.push(source);
        visited[source] = true;

        // Perform BFS to explore the component and calculate the cost
        while (!nodesQueue.empty())
        {
            int node = nodesQueue.front();
            nodesQueue.pop();

            // Mark the node as part of the current component
            components[node] = componentId;

            // Explore all neighbors of the current node
            for (auto& [neighbor, weight] : adjList[node])
            {
                // Update the component cost by performing a bitwise AND of the
                // edge weights
                componentCost &= weight;

                // If the neighbor hasn't been visited, mark it as visited and
                // add it to the queue
                if (visited[neighbor])
                    continue;
                visited[neighbor] = true;
                nodesQueue.push(neighbor);
            }
        }

        return componentCost;
    }
};
// @lc code=end
int main(int argc, char const* argv[])
{
    Solution sol;
    // Test_1
    int n = 5;
    vector<vector<int>> edges = { { 0, 1, 7 }, { 1, 3, 7 }, { 1, 2, 1 } };
    vector<vector<int>> query = { { 0, 3 }, { 3, 4 } };
    vector<int> res = sol.minimumCost(n, edges, query);
    for (auto x : res)
        cout << x << " ";
    cout << endl;
    assert(res == vector<int>({ 1, -1 }));

    // Test_2
    n = 3;
    edges = { { 0, 2, 7 }, { 0, 1, 15 }, { 1, 2, 6 }, { 1, 2, 1 } };
    query = { { 1, 2 } };
    res = sol.minimumCost(n, edges, query);
    for (auto x : res)
        cout << x << " ";
    cout << endl;
    assert(res == vector<int>({ 0 }));
    return 0;
}
