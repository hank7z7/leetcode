/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (58.84%)
 * Likes:    13284
 * Dislikes: 916
 * Total Accepted:    1.4M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the root of a binary tree, return the length of the diameter of the
 * tree.
 *
 * The diameter of a binary tree is the length of the longest path between any
 * two nodes in a tree. This path may or may not pass through the root.
 *
 * The length of a path between two nodes is represented by the number of edges
 * between them.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
    : val(0)
    , left(nullptr)
    , right(nullptr)
    {
    }
    TreeNode(int x)
    : val(x)
    , left(nullptr)
    , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x)
    , left(left)
    , right(right)
    {
    }
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
private:
    // Return the depth for child tree and record max diameter
    int dfs(TreeNode* root, int& diameter)
    {
        if (!root)
            return 0;
        int l_d  = dfs(root->left, diameter);
        int l_r  = dfs(root->right, diameter);
        diameter = max(diameter, l_d + l_r);
        return max(l_d, l_r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root)
            return 0;
        int max_diameter = INT_MIN;
        // Recursive method
        dfs(root, max_diameter);

        // Iterative method using stack and dfs
        // stack<TreeNode*> st;
        // // Record the visited and the depth
        // unordered_map<TreeNode*, int> visited;
        // visited[NULL] = 0;

        // st.push(root);
        // while(!st.empty())
        // {
        //     TreeNode* curr = st.top();
        //     if(curr->left && visited.find(curr->left) == visited.end())
        //     {
        //         st.push(curr->left);
        //     }
        //     else if(curr->right && visited.find(curr->right) == visited.end())
        //     {
        //         st.push(curr->right);
        //     }
        //     else
        //     {
        //         st.pop();
        //         // If chile is null, the diameter is 0
        //         int l = visited[curr->left];
        //         int r = visited[curr->right];
        //         visited[curr] = max(l, r) + 1;
        //         max_diameter = max(max_diameter, l + r);
        //     }
        // }
        return max_diameter;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct TreeNode tree_1_node_1 = TreeNode(1);
    struct TreeNode tree_1_node_2 = TreeNode(2);
    struct TreeNode tree_1_node_3 = TreeNode(3);
    struct TreeNode tree_1_node_4 = TreeNode(4);
    struct TreeNode tree_1_node_5 = TreeNode(5);
    tree_1_node_1.left            = &tree_1_node_2;
    tree_1_node_1.right           = &tree_1_node_3;
    tree_1_node_2.left            = &tree_1_node_4;
    tree_1_node_2.right           = &tree_1_node_5;
    cout << sol.diameterOfBinaryTree(&tree_1_node_1) << endl;

    return 0;
}
// Recursive method dfs
// Accepted
// 105/105 cases passed (8 ms)
// Your runtime beats 59.39 % of cpp submissions
// Your memory usage beats 70.17 % of cpp submissions (19 MB)

// Iterative method and dfs + stack
// Accepted
// 105/105 cases passed (12 ms)
// Your runtime beats 31.31 % of cpp submissions
// Your memory usage beats 5.09 % of cpp submissions (21.4 MB)