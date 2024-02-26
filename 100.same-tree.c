/*
 * @lc app=leetcode id=100 lang=c
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (55.42%)
 * Likes:    6455
 * Dislikes: 147
 * Total Accepted:    1.1M
 * Total Submissions: 2M
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
#include <stdio.h>
#include <stdbool.h>
struct TreeNode
{
    int              val;
    struct TreeNode* left;
    struct TreeNode* right;
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;
    if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
        return true;
    else
        return false;
}
// @lc code=end
int main(int argc, char** argv)
{
    // Test_1
    struct TreeNode tree_1_node_1;
    tree_1_node_1.val = 1;
    struct TreeNode tree_1_node_2;
    tree_1_node_2.val = 2;
    struct TreeNode tree_1_node_3;
    tree_1_node_3.val   = 3;
    tree_1_node_1.left  = &tree_1_node_2;
    tree_1_node_1.right = &tree_1_node_3;
    tree_1_node_2.left  = NULL;
    tree_1_node_2.right = NULL;
    tree_1_node_3.left  = NULL;
    tree_1_node_3.right = NULL;

    struct TreeNode tree_2_node_1;
    tree_2_node_1.val = 1;
    struct TreeNode tree_2_node_2;
    tree_2_node_2.val = 2;
    struct TreeNode tree_2_node_3;
    tree_2_node_3.val   = 3;
    tree_2_node_1.left  = &tree_2_node_2;
    tree_2_node_1.right = &tree_2_node_3;
    tree_2_node_2.left  = NULL;
    tree_2_node_2.right = NULL;
    tree_2_node_3.left  = NULL;
    tree_2_node_3.right = NULL;
    printf("%d\n", isSameTree(&tree_1_node_1, &tree_2_node_1));

    tree_2_node_1.left = NULL;
    printf("%d\n", isSameTree(&tree_1_node_1, &tree_2_node_1));

    return 0;
}
// Accepted
// 60/60 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 90.7 % of c submissions (5.6 MB)