/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
 *
 * https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
 *
 * algorithms
 * Medium (85.90%)
 * Likes:    3769
 * Dislikes: 153
 * Total Accepted:    184.1K
 * Total Submissions: 214K
 * Testcase Example:  '[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]'
 *
 * Given the root of a Binary Search Tree (BST), convert it to a Greater Tree
 * such that every key of the original BST is changed to the original key plus
 * the sum of all keys greater than the original key in BST.
 * 
 * As a reminder, a binary search tree is a tree that satisfies these
 * constraints:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
 * Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0,null,1]
 * Output: [1,null,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 100].
 * 0 <= Node.val <= 100
 * All the values in the tree are unique.
 * 
 * 
 * 
 * Note: This question is the same as 538:
 * https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    int inorder_traversal(TreeNode* root, int sum)
    {
        int res = sum;
        if (root)
        {
            int right_sum = inorder_traversal(root->right, sum);
            root->val += right_sum;
            res = inorder_traversal(root->left, root->val);
        }

        return res;
    }

public:
    TreeNode* bstToGst(TreeNode* root)
    {
        inorder_traversal(root, 0);
        return root;
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
    TreeNode  test_1_node_14 = TreeNode(8);
    TreeNode  test_1_node_10 = TreeNode(3);
    TreeNode  test_1_node_6  = TreeNode(7, NULL, &test_1_node_14);
    TreeNode  test_1_node_5  = TreeNode(5);
    TreeNode  test_1_node_4  = TreeNode(2, NULL, &test_1_node_10);
    TreeNode  test_1_node_3  = TreeNode(0);
    TreeNode  test_1_node_2  = TreeNode(6, &test_1_node_5, &test_1_node_6);
    TreeNode  test_1_node_1  = TreeNode(1, &test_1_node_3, &test_1_node_4);
    TreeNode  test_1_node_0  = TreeNode(4, &test_1_node_1, &test_1_node_2);
    TreeNode* res_1          = sol.bstToGst(&test_1_node_0);
    print_tree_postorder(res_1);
    cout << endl;

    return 0;
}
// Accepted
// 30/30 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 42.71 % of cpp submissions (10.2 MB)