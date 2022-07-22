/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void traversal(struct TreeNode* root, int* array, int* returnSize)
{
    if(root)
    {
        traversal(root->left, array, returnSize);
        array[(*returnSize)++] = root->val; // AddressSantizer: () of pointer is needed!
        traversal(root->right, array, returnSize);
    }
}


int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* result = (int*) malloc(sizeof(int) * 100);
    *returnSize = 0;
    
    // Recusion method
    traversal(root, result, returnSize);
    result = realloc(result, (*returnSize) * sizeof(int));

    return result;
}
// @lc code=end

// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 67.46 % of c submissions (5.8 MB)