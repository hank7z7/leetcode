/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 *
 * https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/
 *
 * algorithms
 * Medium (52.31%)
 * Likes:    1401
 * Dislikes: 36
 * Total Accepted:    85.4K
 * Total Submissions: 144.7K
 * Testcase Example:  '8\n[[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]'
 *
 * You are given a positive integer n representing the number of nodes of a
 * Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1
 * (inclusive).
 *
 * You are also given a 2D integer array edges, where edges[i] = [fromi, toi]
 * denotes that there is a unidirectional edge from fromi to toi in the graph.
 *
 * Return a list answer, where answer[i] is the list of ancestors of the i^th
 * node, sorted in ascending order.
 *
 * A node u is an ancestor of another node v if u can reach v via a set of
 * edges.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 8, edgeList =
 * [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
 * Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
 * Explanation:
 * The above diagram represents the input graph.
 * - Nodes 0, 1, and 2 do not have any ancestors.
 * - Node 3 has two ancestors 0 and 1.
 * - Node 4 has two ancestors 0 and 2.
 * - Node 5 has three ancestors 0, 1, and 3.
 * - Node 6 has five ancestors 0, 1, 2, 3, and 4.
 * - Node 7 has four ancestors 0, 1, 2, and 3.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5, edgeList =
 * [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
 * Explanation:
 * The above diagram represents the input graph.
 * - Node 0 does not have any ancestor.
 * - Node 1 has one ancestor 0.
 * - Node 2 has two ancestors 0 and 1.
 * - Node 3 has three ancestors 0, 1, and 2.
 * - Node 4 has four ancestors 0, 1, 2, and 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 * 0 <= edges.length <= min(2000, n * (n - 1) / 2)
 * edges[i].length == 2
 * 0 <= fromi, toi <= n - 1
 * fromi != toi
 * There are no duplicate edges.
 * The graph is directed and acyclic.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        // Create adjacency list
        vector<vector<int>> adjacencyList(n);
        for (int i = 0; i < n; i++)
        {
            adjacencyList[i] = {};
        }

        // Fill the adjacency list and indegree array based on the edges
        vector<int> indegree(n, 0);
        for (auto &edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
            indegree[to]++;
        }

        queue<int> nodesWithZeroIndegree;
        for (int i = 0; i < (int)indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                nodesWithZeroIndegree.push(i);
            }
        }

        // List to store the topological order of nodes
        vector<int> topologicalOrder;
        while (!nodesWithZeroIndegree.empty())
        {
            int currentNode = nodesWithZeroIndegree.front();
            nodesWithZeroIndegree.pop();
            topologicalOrder.push_back(currentNode);

            // Reduce indegree of neighboring nodes and add them to the queue
            // if they have no more incoming edges
            for (int neighbor : adjacencyList[currentNode])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    nodesWithZeroIndegree.push(neighbor);
                }
            }
        }

        // Initialize the result list and set list for storing ancestors
        vector<vector<int>> ancestorsList(n);
        vector<set<int>> ancestorsSetList(n);

        // Fill the set list with ancestors using the topological order
        for (int node : topologicalOrder)
        {
            for (int neighbor : adjacencyList[node])
            {
                // Add immediate parent, and other ancestors
                ancestorsSetList[neighbor].insert(node);
                ancestorsSetList[neighbor].insert(
                    ancestorsSetList[node].begin(),
                    ancestorsSetList[node].end());
            }
        }

        // Convert sets to lists and sort them
        for (int i = 0; i < (int)ancestorsList.size(); i++)
        {
            ancestorsList[i].assign(ancestorsSetList[i].begin(),
                                    ancestorsSetList[i].end());
            sort(ancestorsList[i].begin(), ancestorsList[i].end());
        }

        return ancestorsList;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int n_1 = 8;
    vector<vector<int>> edges_1 = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};
    vector<vector<int>> res_1 = sol.getAncestors(n_1, edges_1);
    cout << "[";
    for (auto i = 0; i < (int)res_1.size(); i++)
    {
        vector<int> node = res_1[i];
        cout << ((i == 0 ? "" : ",")) << "[";
        for (auto j = 0; j < (int)node.size(); j++)
        {
            int ancestor = node[j];
            cout << (j == 0 ? "" : ",") << ancestor;
        }
        cout << "]";
    }
    cout << "]" << endl;
    assert((res_1 == vector<vector<int>>{{}, {}, {}, {0, 1}, {0, 2}, {0, 1, 3}, {0, 1, 2, 3, 4}, {0, 1, 2, 3}}));

    // Test_2
    int n_2 = 5;
    vector<vector<int>> edges_2 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    vector<vector<int>> res_2 = sol.getAncestors(n_2, edges_2);
    cout << "[";
    for (auto i = 0; i < (int)res_2.size(); i++)
    {
        vector<int> node = res_2[i];
        cout << ((i == 0 ? "" : ",")) << "[";
        for (auto j = 0; j < (int)node.size(); j++)
        {
            int ancestor = node[j];
            cout << (j == 0 ? "" : ",") << ancestor;
        }
        cout << "]";
    }
    cout << "]" << endl;
    assert((res_2 == vector<vector<int>>{{}, {0}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3}}));

    return 0;
}
