/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
 *
 * https://leetcode.com/problems/balance-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (81.62%)
 * Likes:    3324
 * Dislikes: 80
 * Total Accepted:    190.4K
 * Total Submissions: 229K
 * Testcase Example:  '[1,null,2,null,3,null,4]'
 *
 * Given the root of a binary search tree, return a balanced binary search tree
 * with the same node values. If there is more than one answer, return any of
 * them.
 * 
 * A binary search tree is balanced if the depth of the two subtrees of every
 * node never differs by more than 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,null,3,null,4,null,null]
 * Output: [2,1,3,null,null,null,4]
 * Explanation: This is not the only correct answer, [3,1,4,null,2] is also
 * correct.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,1,3]
 * Output: [2,1,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * 1 <= Node.val <= 10^5
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
private:
    vector<TreeNode*> sorted_nodes;
    void inorder_traversal(TreeNode* root)
    {
        if (root != NULL)
        {
            inorder_traversal(root->left);
            sorted_nodes.push_back(root);
            inorder_traversal(root->right);
        }
    }
    TreeNode* build_balanceBST(int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode* res = sorted_nodes[mid];
        res->left     = build_balanceBST(start, mid - 1);
        res->right    = build_balanceBST(mid + 1, end);

        return res;
    }

public:
    TreeNode* balanceBST(TreeNode* root)
    {
        inorder_traversal(root);
        TreeNode* res = build_balanceBST(0, (int)sorted_nodes.size() - 1);
        return res;
    }
};
// @lc code=end
void print_tree_postorder(TreeNode* root)
{
    if (root)
    {
        cout << root->val << " ";
        print_tree_postorder(root->left);
        print_tree_postorder(root->right);
    }
}
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    TreeNode  test_1_node_3 = TreeNode(4);
    TreeNode  test_1_node_2 = TreeNode(3, NULL, &test_1_node_3);
    TreeNode  test_1_node_1 = TreeNode(2, NULL, &test_1_node_2);
    TreeNode  test_1_node_0 = TreeNode(1, NULL, &test_1_node_1);
    TreeNode* res_1         = sol.balanceBST(&test_1_node_0);
    print_tree_postorder(res_1);
    cout << endl;

    // Test_2
    TreeNode  test_2_node_2 = TreeNode(3);
    TreeNode  test_2_node_1 = TreeNode(1);
    TreeNode  test_2_node_0 = TreeNode(2, &test_2_node_1, &test_2_node_2);
    TreeNode* res_2         = sol.balanceBST(&test_2_node_0);
    print_tree_postorder(res_2);
    cout << endl;

    return 0;
}
// Accepted
// 17/17 cases passed (84 ms)
// Your runtime beats 71.65 % of cpp submissions
// Your memory usage beats 85.2 % of cpp submissions (46.5 MB)