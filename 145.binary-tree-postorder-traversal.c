/*
 * @lc app=leetcode id=145 lang=c
 *
 * [145] Binary Tree Postorder Traversal
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
        traversal(root->left, array, returnSize);
        traversal(root->right, array, returnSize);
        array[(*returnSize)++] = root->val; // Post order
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;

    // Recusion method
    traversal(root, result, returnSize);
    result = realloc(result, (*returnSize) * sizeof(int));
    // Comment out to save time

    return result;
}
// @lc code=end

// Accepted
// 68/68 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 20.66 % of c submissions (6.1 MB)