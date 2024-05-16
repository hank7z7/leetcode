/*
 * @lc app=leetcode id=2331 lang=cpp
 *
 * [2331] Evaluate Boolean Binary Tree
 *
 * https://leetcode.com/problems/evaluate-boolean-binary-tree/description/
 *
 * algorithms
 * Easy (77.77%)
 * Likes:    1207
 * Dislikes: 34
 * Total Accepted:    125.5K
 * Total Submissions: 153.6K
 * Testcase Example:  '[2,1,3,null,null,0,1]'
 *
 * You are given the root of a full binary tree with the following
 * properties:
 * 
 * 
 * Leaf nodes have either the value 0 or 1, where 0 represents False and 1
 * represents True.
 * Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean
 * OR and 3 represents the boolean AND.
 * 
 * 
 * The evaluation of a node is as follows:
 * 
 * 
 * If the node is a leaf node, the evaluation is the value of the node, i.e.
 * True or False.
 * Otherwise, evaluate the node's two children and apply the boolean operation
 * of its value with the children's evaluations.
 * 
 * 
 * Return the boolean result of evaluating the root node.
 * 
 * A full binary tree is a binary tree where each node has either 0 or 2
 * children.
 * 
 * A leaf node is a node that has zero children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [2,1,3,null,null,0,1]
 * Output: true
 * Explanation: The above diagram illustrates the evaluation process.
 * The AND node evaluates to False AND True = False.
 * The OR node evaluates to True OR False = True.
 * The root node evaluates to True, so we return true.
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0]
 * Output: false
 * Explanation: The root node is a leaf node and it evaluates to false, so we
 * return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * 0 <= Node.val <= 3
 * Every node has either 0 or 2 children.
 * Leaf nodes have a value of 0 or 1.
 * Non-leaf nodes have a value of 2 or 3.
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
    bool evaluateTree(TreeNode* root)
    {
        // Full binary tree, check left whether this is a leaf
        if (root->left)
        {
            if (root->val == 2)
                return evaluateTree(root->left) | evaluateTree(root->right);
            else if (root->val == 3)
                return evaluateTree(root->left) & evaluateTree(root->right);
        }
        else
        {
            if (root->val == 0)
                return false;
            else
                return true;
        }
        return true;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct TreeNode test_1_node_6 = TreeNode(1);
    struct TreeNode test_1_node_5 = TreeNode(0);
    struct TreeNode test_1_node_2 = TreeNode(3, &test_1_node_5, &test_1_node_6);
    struct TreeNode test_1_node_1 = TreeNode(1);
    struct TreeNode test_1_node_0 = TreeNode(2, &test_1_node_1, &test_1_node_2);
    cout << sol.evaluateTree(&test_1_node_0) << endl;

    // Test_2
    struct TreeNode test_2_node_0 = TreeNode(0);
    cout << sol.evaluateTree(&test_2_node_0) << endl;

    return 0;
}
// Accepted
// 75/75 cases passed (8 ms)
// Your runtime beats 82.42 % of cpp submissions
// Your memory usage beats 24.21 % of cpp submissions (17.5 MB)