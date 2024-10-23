/*
 * @lc app=leetcode id=2641 lang=cpp
 *
 * [2641] Cousins in Binary Tree II
 *
 * https://leetcode.com/problems/cousins-in-binary-tree-ii/description/
 *
 * algorithms
 * Medium (67.74%)
 * Likes:    782
 * Dislikes: 26
 * Total Accepted:    48.1K
 * Total Submissions: 66.2K
 * Testcase Example:  '[5,4,9,1,10,null,7]'
 *
 * Given the root of a binary tree, replace the value of each node in the tree
 * with the sum of all its cousins' values.
 * 
 * Two nodes of a binary tree are cousins if they have the same depth with
 * different parents.
 * 
 * Return the root of the modified tree.
 * 
 * Note that the depth of a node is the number of edges in the path from the
 * root node to it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,4,9,1,10,null,7]
 * Output: [0,0,0,7,7,null,11]
 * Explanation: The diagram above shows the initial binary tree and the binary
 * tree after changing the value of each node.
 * - Node with value 5 does not have any cousins so its sum is 0.
 * - Node with value 4 does not have any cousins so its sum is 0.
 * - Node with value 9 does not have any cousins so its sum is 0.
 * - Node with value 1 has a cousin with value 7 so its sum is 7.
 * - Node with value 10 has a cousin with value 7 so its sum is 7.
 * - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,1,2]
 * Output: [0,0,0]
 * Explanation: The diagram above shows the initial binary tree and the binary
 * tree after changing the value of each node.
 * - Node with value 3 does not have any cousins so its sum is 0.
 * - Node with value 1 does not have any cousins so its sum is 0.
 * - Node with value 2 does not have any cousins so its sum is 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^5].
 * 1 <= Node.val <= 10^4
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
class Solution
{
private:
    vector<int> level_sum;
    void get_level_sum(TreeNode* root, int level)
    {
        if (root)
        {
            level_sum[level] += root->val;
            get_level_sum(root->left, level + 1);
            get_level_sum(root->right, level + 1);
        }
    }

    void replace(TreeNode* root, int sibling_val, int level)
    {
        if (root)
        {
            root->val = level_sum[level] - root->val - sibling_val;
            int l_child_val = root->left ? root->left->val : 0;
            int r_child_val = root->right ? root->right->val : 0;
            replace(root->left, r_child_val, level + 1);
            replace(root->right, l_child_val, level + 1);
        }
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        level_sum = vector<int>(100000, 0);
        get_level_sum(root, 0);
        replace(root, 0, 0);

        return root;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    TreeNode test_1_node_6 = TreeNode(7);
    TreeNode test_1_node_4 = TreeNode(10);
    TreeNode test_1_node_3 = TreeNode(1);
    TreeNode test_1_node_2 = TreeNode(9, NULL, &test_1_node_6);
    TreeNode test_1_node_1 = TreeNode(4, &test_1_node_3, &test_1_node_4);
    TreeNode test_1_node_0 = TreeNode(9, &test_1_node_1, &test_1_node_2);
    sol.replaceValueInTree(&test_1_node_0);

    return 0;
}
// Accepted
// 41/41 cases passed (13 ms)
// Your runtime beats 97.55 % of cpp submissions
// Your memory usage beats 22.72 % of cpp submissions (331 MB)