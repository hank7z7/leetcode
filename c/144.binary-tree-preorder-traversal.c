/*
 * @lc app=leetcode id=144 lang=c
 *
 * [144] Binary Tree Preorder Traversal
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
void traversal(struct TreeNode *root, int *array, int *returnSize) {
    if (root) {
        array[(*returnSize)++] = root->val; // Pre order
        traversal(root->left, array, returnSize);
        traversal(root->right, array, returnSize);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *result = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;

    // Recusion method
    traversal(root, result, returnSize);
    // result = realloc(result, (*returnSize) * sizeof(int)); // Comment out to
    // save time

    return result;
}
// @lc code=end

// Accepted
// 69/69 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 67.14 % of c submissions (5.9 MB)