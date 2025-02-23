/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (60.75%)
 * Likes:    11012
 * Dislikes: 227
 * Total Accepted:    1.9M
 * Total Submissions: 3.2M
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given the roots of two binary trees p and q, write a function to check if
 * they are the same or not.
 *
 * Two binary trees are considered the same if they are structurally identical,
 * and the nodes have the same value.
 *
 *
 * Example 1:
 *
 *
 * Input: p = [1,2,3], q = [1,2,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: p = [1,2], q = [1,null,2]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: p = [1,2,1], q = [1,1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in both trees is in the range [0, 100].
 * -10^4 <= Node.val <= 10^4
 *
 *
 */
#include <bits/stdc++.h>

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p != NULL && q != NULL)
        {
            if (p->val == q->val)
            {
                bool l = isSameTree(p->left, q->left);
                bool r = isSameTree(p->right, q->right);
                if (l && r)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    struct TreeNode tree_1_node_1 = TreeNode(1);
    struct TreeNode tree_1_node_2 = TreeNode(2);
    struct TreeNode tree_1_node_3 = TreeNode(3);
    tree_1_node_1.left = &tree_1_node_2;
    tree_1_node_1.right = &tree_1_node_3;
    struct TreeNode tree_2_node_1 = TreeNode(1);
    struct TreeNode tree_2_node_2 = TreeNode(2);
    struct TreeNode tree_2_node_3 = TreeNode(3);
    tree_2_node_1.left = &tree_2_node_2;
    tree_2_node_1.right = &tree_2_node_3;
    std::cout << sol.isSameTree(&tree_1_node_1, &tree_2_node_1) << std::endl;

    return 0;
}
// Accepted
// 63/63 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 25.4 % of cpp submissions (11.7 MB)