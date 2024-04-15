/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (67.76%)
 * Likes:    3604
 * Dislikes: 281
 * Total Accepted:    312.3K
 * Total Submissions: 445K
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, return the leftmost value in the last row
 * of the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,1,3]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,4,null,5,6,null,null,7]
 * Output: 7
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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
    int  butom_left;
    int  max_depth;
    void dfs(TreeNode* root, int depth)
    {
        if (!root)
            return;
        if (depth > max_depth)
        {
            max_depth  = depth;
            butom_left = root->val;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

public:
    int findBottomLeftValue(TreeNode* root)
    {
        butom_left = 0;
        max_depth  = 0;
        dfs(root, 1);
        return butom_left;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct TreeNode tree_1_node_1 = TreeNode(1);
    struct TreeNode tree_1_node_3 = TreeNode(3);
    struct TreeNode tree_1_node_2 = TreeNode(2, &tree_1_node_1, &tree_1_node_3);
    cout << sol.findBottomLeftValue(&tree_1_node_2) << endl;

    // Test_2
    struct TreeNode tree_2_node_4 = TreeNode(4);
    struct TreeNode tree_2_node_2 = TreeNode(2, &tree_2_node_4, NULL);
    struct TreeNode tree_2_node_7 = TreeNode(7);
    struct TreeNode tree_2_node_5 = TreeNode(5, &tree_2_node_7, NULL);
    struct TreeNode tree_2_node_6 = TreeNode(6);
    struct TreeNode tree_2_node_3 = TreeNode(2, &tree_2_node_5, &tree_2_node_6);
    struct TreeNode tree_2_node_1 = TreeNode(1, &tree_2_node_2, &tree_2_node_3);
    cout << sol.findBottomLeftValue(&tree_2_node_1) << endl;

    // Test_3
    struct TreeNode tree_3_node_1 = TreeNode(1);
    cout << sol.findBottomLeftValue(&tree_3_node_1) << endl;
    return 0;
}
// Accepted
// 77/77 cases passed (6 ms)
// Your runtime beats 83.03 % of cpp submissions
// Your memory usage beats 88.43 % of cpp submissions (20.1 MB)