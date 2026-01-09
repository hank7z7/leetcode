/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
 *
 * https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
 *
 * algorithms
 * Medium (72.65%)
 * Likes:    2978
 * Dislikes: 394
 * Total Accepted:    198.2K
 * Total Submissions: 266.1K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]'
 *
 * Given the root of a binary tree, the depth of each node is the shortest
 * distance to the root.
 * 
 * Return the smallest subtree such that it contains all the deepest nodes in
 * the original tree.
 * 
 * A node is called the deepest if it has the largest depth possible among any
 * node in the entire tree.
 * 
 * The subtree of a node is a tree consisting of that node, plus the set of all
 * descendants of that node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4]
 * Output: [2,7,4]
 * Explanation: We return the node with value 2, colored in yellow in the
 * diagram.
 * The nodes coloured in blue are the deepest nodes of the tree.
 * Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node
 * 2 is the smallest subtree among them, so we return it.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * Explanation: The root is the deepest node in the tree.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [0,1,3,null,2]
 * Output: [2]
 * Explanation: The deepest node in the tree is 2, the valid subtrees are the
 * subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree will be in the range [1, 500].
 * 0 <= Node.val <= 500
 * The values of the nodes in the tree are unique.
 * 
 * 
 * 
 * Note: This question is the same as 1123:
 * https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
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
class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.first > right.first)
            return {left.first + 1, left.second};
        if (right.first > left.first)
            return {right.first + 1, right.second};

        // both sides have same depth
        return {left.first + 1, root};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
// @lc code=end
int main(int argc, char const **argv) {
    Solution sol;
    // Test_1
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode* result = sol.subtreeWithAllDeepest(root);
    cout << result->val << endl;
    assert(result == root->left->right);
    delete(root->left->right->left);
    delete(root->left->right->right);
    delete(root->right->right);
    delete(root->right->left);
    delete(root->left->right);
    delete(root->left->left);
    delete(root->left);
    delete(root->right);
    delete(root);

    // Test_2
    TreeNode* root2 = new TreeNode(1);
    TreeNode* result2 = sol.subtreeWithAllDeepest(root2);
    cout << result2->val << endl;
    assert(result2 == root2);
    delete(root2);

    // Test_3
    TreeNode* root3 = new TreeNode(0);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(3);
    root3->left->right = new TreeNode(2);
    TreeNode* result3 = sol.subtreeWithAllDeepest(root3);
    cout << result3->val << endl;
    assert(result3 == root3->left->right);
    delete(root3->left->right);
    delete(root3->left);
    delete(root3->right);
    delete(root3);

    return 0;
}
