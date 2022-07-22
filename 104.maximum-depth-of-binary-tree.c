/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode *root) {
    if (root == NULL)
        return 0;

    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return (left_depth >= right_depth ? left_depth : right_depth) + 1;
}
// @lc code=end

// Accepted
// 39/39 cases passed (6 ms)
// Your runtime beats 74.37 % of c submissions
// Your memory usage beats 9.06 % of c submissions (8.1 MB)