/*
 * @lc app=leetcode id=2467 lang=cpp
 *
 * [2467] Most Profitable Path in a Tree
 *
 * https://leetcode.com/problems/most-profitable-path-in-a-tree/description/
 *
 * algorithms
 * Medium (49.55%)
 * Likes:    784
 * Dislikes: 87
 * Total Accepted:    20.3K
 * Total Submissions: 37.7K
 * Testcase Example:  '[[0,1],[1,2],[1,3],[3,4]]\n3\n[-2,4,2,-4,6]'
 *
 * There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at
 * node 0. You are given a 2D integer array edges of length n - 1 where
 * edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi
 * in the tree.
 * 
 * At every node i, there is a gate. You are also given an array of even
 * integers amount, where amount[i] represents:
 * 
 * 
 * the price needed to open the gate at node i, if amount[i] is negative,
 * or,
 * the cash reward obtained on opening the gate at node i, otherwise.
 * 
 * 
 * The game goes on as follows:
 * 
 * 
 * Initially, Alice is at node 0 and Bob is at node bob.
 * At every second, Alice and Bob each move to an adjacent node. Alice moves
 * towards some leaf node, while Bob moves towards node 0.
 * For every node along their path, Alice and Bob either spend money to open
 * the gate at that node, or accept the reward. Note that:
 * 
 * If the gate is already open, no price will be required, nor will there be
 * any cash reward.
 * If Alice and Bob reach the node simultaneously, they share the price/reward
 * for opening the gate there. In other words, if the price to open the gate is
 * c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the
 * gate is c, both of them receive c / 2 each.
 * 
 * 
 * If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches
 * node 0, he stops moving. Note that these events are independent of each
 * other.
 * 
 * 
 * Return the maximum net income Alice can have if she travels towards the
 * optimal leaf node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
 * Output: 6
 * Explanation: 
 * The above diagram represents the given tree. The game goes as follows:
 * - Alice is initially on node 0, Bob on node 3. They open the gates of their
 * respective nodes.
 * ⁠ Alice's net income is now -2.
 * - Both Alice and Bob move to node 1. 
 * Since they reach here simultaneously, they open the gate together and share
 * the reward.
 * Alice's net income becomes -2 + (4 / 2) = 0.
 * - Alice moves on to node 3. Since Bob already opened its gate, Alice's
 * income remains unchanged.
 * Bob moves on to node 0, and stops moving.
 * - Alice moves on to node 4 and opens the gate there. Her net income becomes
 * 0 + 6 = 6.
 * Now, neither Alice nor Bob can make any further moves, and the game ends.
 * It is not possible for Alice to get a higher net income.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: edges = [[0,1]], bob = 1, amount = [-7280,2350]
 * Output: -7280
 * Explanation: 
 * Alice follows the path 0->1 whereas Bob follows the path 1->0.
 * Thus, Alice opens the gate at node 0 only. Hence, her net income is
 * -7280. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * edges represents a valid tree.
 * 1 <= bob < n
 * amount.length == n
 * amount[i] is an even integer in the range [-10^4, 10^4].
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int n = (int)edges.size() + 1;
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // DFS to find bob's path to node 0
        vector<pair<int, int>> bob_path;
        vector<bool> visited(n, false);
        function<bool(int, int)> dfs = [&](int u, int parent) {
            visited[u] = true;
            // Record the path
            bob_path.push_back({u, parent});
            // Bob reached node 0
            if(u == 0)
                return true;
            
            // DFS
            for (int v : adj[u]) {
                if (!visited[v]) {
                    cout << "next node" << v << endl;
                    bool find_node_0 = dfs(v, u);
                    if(find_node_0)
                        return true;
                }
            }
            bob_path.pop_back();
            visited[u] = false;
            return false;
        };
        dfs(bob, -1);
        for(auto &p : bob_path) {
            cout << p.first << " " << p.second << endl;
        }
        vector<int> alice_distances(n, 0);
        return 0;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // Test_1
    vector<vector<int>> test_1_edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    int test_1_bob = 3;
    vector<int> test_1_amount = {-2, 4, 2, -4, 6};
    int test_1_res = sol.mostProfitablePath(test_1_edges, test_1_bob, test_1_amount);
    cout << test_1_res << endl;
    assert((test_1_res == 6));

    // Test_2
    vector<vector<int>> test_2_edges = {{0, 1}};
    int test_2_bob = 1;
    vector<int> test_2_amount = {-7280, 2350};
    int test_2_res = sol.mostProfitablePath(test_2_edges, test_2_bob, test_2_amount);
    cout << test_2_res << endl;
    assert((test_2_res == -7280));

    return 0;
}
