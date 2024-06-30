/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 *
 * https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/
 *
 * algorithms
 * Hard (63.99%)
 * Likes:    2158
 * Dislikes: 30
 * Total Accepted:    73.4K
 * Total Submissions: 110.2K
 * Testcase Example:  '4\n[[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]'
 *
 * Alice and Bob have an undirected graph of n nodes and three types of
 * edges:
 * 
 * 
 * Type 1: Can be traversed by Alice only.
 * Type 2: Can be traversed by Bob only.
 * Type 3: Can be traversed by both Alice and Bob.
 * 
 * 
 * Given an array edges where edges[i] = [typei, ui, vi] represents a
 * bidirectional edge of type typei between nodes ui and vi, find the maximum
 * number of edges you can remove so that after removing the edges, the graph
 * can still be fully traversed by both Alice and Bob. The graph is fully
 * traversed by Alice and Bob if starting from any node, they can reach all
 * other nodes.
 * 
 * Return the maximum number of edges you can remove, or return -1 if Alice and
 * Bob cannot fully traverse the graph.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
 * Output: 2
 * Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will
 * still be fully traversable by Alice and Bob. Removing any additional edge
 * will not make it so. So the maximum number of edges we can remove is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
 * Output: 0
 * Explanation: Notice that removing any edge will not make the graph fully
 * traversable by Alice and Bob.
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
 * Output: -1
 * Explanation: In the current graph, Alice cannot reach node 4 from the other
 * nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the
 * graph fully traversable.
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 1 <= edges.length <= min(10^5, 3 * n * (n - 1) / 2)
 * edges[i].length == 3
 * 1 <= typei <= 3
 * 1 <= ui < vi <= n
 * All tuples (typei, ui, vi) are distinct.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        class UnionFind {
        public:
            vector<int> parent, size;
            int components;
            UnionFind(int n) {
                components = n;
                parent.resize(n + 1);
                size.resize(n + 1, 1);
                for (int i = 0; i <= n; ++i) {
                    parent[i] = i;
                }
            }

            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }

            bool unite(int x, int y) {
                int rootX = find(x), rootY = find(y);
                if (rootX == rootY) return false;
                if (size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                components--;
                return true;
            }

            bool isConnected() {
                return components == 1;
            }
        };
        
        UnionFind alice(n), bob(n);
        int edgesRequired = 0;
        
        // Process type 3 edges first
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        
        // Process type 1 and type 2 edges
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            } else if (edge[0] == 2) {
                if (bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        
        // Check if both are fully connected
        if (alice.isConnected() && bob.isConnected()) {
            return edges.size() - edgesRequired;
        }
        
        return -1;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n_1 = 4;
    vector<vector<int>> edges_1 = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    int res_1 = sol.maxNumEdgesToRemove(n_1, edges_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    int n_2 = 4;
    vector<vector<int>> edges_2 = {{3,1,2},{3,2,3},{1,1,4},{2,1,4}};
    int res_2 = sol.maxNumEdgesToRemove(n_2, edges_2);
    cout << res_2 << endl;
    assert(res_2 == 0);

    // Test_3
    int n_3 = 4;
    vector<vector<int>> edges_3 = {{3,2,3},{1,1,2},{2,3,4}};
    int res_3 = sol.maxNumEdgesToRemove(n_3, edges_3);
    cout << res_3 << endl;
    assert(res_3 == -1);

    return 0;
}
// Accepted
// 85/85 cases passed (344 ms)
// Your runtime beats 80.32 % of cpp submissions
// Your memory usage beats 80.14 % of cpp submissions (142.6 MB)