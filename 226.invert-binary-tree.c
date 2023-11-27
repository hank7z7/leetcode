/*
 * @lc app=leetcode id=226 lang=c
 *
 * [226] Invert Binary Tree
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
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* result = root;
    if(result != NULL)
    {
        // Must check the result is not NULL
        struct TreeNode* curr_left = root->left;
        struct TreeNode* curr_right = root->right;
        result->left = invertTree(curr_right);
        result->right = invertTree(curr_left);
    }
    return result;
}
// @lc code=end

int main(int argc, char** argv)
{

    return 0;
}

// Accepted
// 77/77 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 23.27 % of c submissions (6.9 MB)