/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
 *
 * https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
 *
 * algorithms
 * Medium (72.57%)
 * Likes:    5398
 * Dislikes: 203
 * Total Accepted:    151K
 * Total Submissions: 201.3K
 * Testcase Example:  '[3,0,0]'
 *
 * You are given the root of a binary tree with n nodes where each node in the
 * tree has node.val coins. There are n coins in total throughout the whole
 * tree.
 * 
 * In one move, we may choose two adjacent nodes and move one coin from one
 * node to another. A move may be from parent to child, or from child to
 * parent.
 * 
 * Return the minimum number of moves required to make every node have exactly
 * one coin.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,0,0]
 * Output: 2
 * Explanation: From the root of the tree, we move one coin to its left child,
 * and one coin to its right child.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0,3,0]
 * Output: 3
 * Explanation: From the left child of the root, we move two coins to the root
 * [taking two moves]. Then, we move one coin from the root of the tree to the
 * right child.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is n.
 * 1 <= n <= 100
 * 0 <= Node.val <= n
 * The sum of all Node.val is n.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    using node2 = tuple<TreeNode *, TreeNode *, bool>; // Node, parent & visited flag
    int distributeCoins(TreeNode *root)
    {
        if (!root)
            return 0;
        vector<node2> stack = {{root, NULL, 0}};
        int moves = 0;
        while (!stack.empty())
        {
            auto [node, parent, visited] = stack.back();
            stack.pop_back();

            if (!visited)
            {
                // Mark the node as visited & repush
                stack.emplace_back(node, parent, 1);

                // Push right and left children onto the stack
                if (node->right)
                    stack.emplace_back(node->right, node, 0);
                if (node->left)
                    stack.emplace_back(node->left, node, 0);
            }
            else
            {
                int x = node->val - 1; // give x coins to parent node
                if (parent)
                    parent->val += x; // now parent's coins
                moves += abs(x);
            }
        }

        return moves;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    struct TreeNode test_1_node_2 = TreeNode(0);
    struct TreeNode test_1_node_1 = TreeNode(0);
    struct TreeNode test_1_node_0 = TreeNode(3, &test_1_node_1, &test_1_node_2);
    cout << sol.distributeCoins(&test_1_node_0) << endl;

    // Test_2
    struct TreeNode test_2_node_2 = TreeNode(0);
    struct TreeNode test_2_node_1 = TreeNode(3);
    struct TreeNode test_2_node_0 = TreeNode(0, &test_2_node_1, &test_2_node_2);
    cout << sol.distributeCoins(&test_2_node_0) << endl;

    return 0;
}
// Accepted
// 148/148 cases passed (3 ms)
// Your runtime beats 80.65 % of cpp submissions
// Your memory usage beats 6.59 % of cpp submissions (15.9 MB)