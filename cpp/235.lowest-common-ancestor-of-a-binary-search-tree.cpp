/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (67.20%)
 * Likes:    11531
 * Dislikes: 330
 * Total Accepted:    1.8M
 * Total Submissions: 2.7M
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node
 * of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 * Example 1:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,1], p = 2, q = 1
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the BST.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
private:
    vector<TreeNode *> backtrack;
    vector<TreeNode *> path_p;
    vector<TreeNode *> path_q;

public:
    void dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return;
        backtrack.push_back(root);
        if (root == p)
            path_p = backtrack;
        if (root == q)
            path_q = backtrack;
        if (root->left)
            dfs(root->left, p, q);
        if (root->right)
            dfs(root->right, p, q);
        backtrack.pop_back();
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        backtrack = vector<TreeNode *>();
        path_p = vector<TreeNode *>();
        path_q = vector<TreeNode *>();
        dfs(root, p, q);
        int p_n = path_p.size();
        int q_n = path_q.size();
        int n = min(p_n, q_n);
        TreeNode *last_same = root;
        for (int i = 0; i < n; i++)
        {
            if (path_p[i] == path_q[i])
                last_same = path_p[i];
            else
                break;
        }
        return last_same;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    // Test_1
    return 0;
}
// Accepted
// 30/30 cases passed (16 ms)
// Your runtime beats 94.62 % of cpp submissions
// Your memory usage beats 33.14 % of cpp submissions (23.8 MB)