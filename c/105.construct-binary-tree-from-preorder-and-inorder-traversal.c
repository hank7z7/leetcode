/*
 * @lc app=leetcode id=105 lang=c
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */
#include <bits/stdc++.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
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

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize == 0)
        return NULL;
    
    // Find the first preorder node in inorder
    int left_size = 0;
    int right_size = 0;
    for(int i = 0; i < inorderSize; i++)
        if(preorder[0] == inorder[i])
        {
            left_size = i;
            break;
        }
    right_size = preorderSize - left_size - 1;
    struct TreeNode* result = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    result->val = preorder[0];
    result->left = buildTree(preorder + 1, left_size, inorder, left_size);
    result->right = buildTree(preorder + 1 + left_size, right_size, inorder + 1 + left_size, right_size);
    return result;
}
// @lc code=end

int main(int argc, char** argv)
{
    int size = 5;
    int preorder[size] = {3, 9 ,20, 15, 7};
    int inorder[size] = {9, 3, 15, 20, 7};
    struct TreeNode* result = buildTree(preorder, size, inorder, size);
    return 0;
}

// Accepted
// 203/203 cases passed (14 ms)
// Your runtime beats 30.81 % of c submissions
// Your memory usage beats 67.03 % of c submissions (12.4 MB)