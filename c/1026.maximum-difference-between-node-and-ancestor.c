/*
 * @lc app=leetcode id=1026 lang=c
 *
 * [1026] Maximum Difference Between Node and Ancestor
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct TreeNode
{
    int              val;
    struct TreeNode* left;
    struct TreeNode* right;
};
// @lc code=start
#define max(a, b)                                                                                  \
    ({                                                                                             \
        __typeof__(a) _a = (a);                                                                    \
        __typeof__(b) _b = (b);                                                                    \
        _a > _b ? _a : _b;                                                                         \
    })
#define min(a, b)                                                                                  \
    ({                                                                                             \
        __typeof__(a) _a = (a);                                                                    \
        __typeof__(b) _b = (b);                                                                    \
        _a < _b ? _a : _b;                                                                         \
    })


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int find_max_min(struct TreeNode* root, int* min_val, int* max_val)
{
    int l_min  = INT_MAX;
    int l_max  = INT_MIN;
    int r_min  = INT_MAX;
    int r_max  = INT_MIN;
    int diff   = 0;
    int result = INT_MIN;
    if (root->left)
    {
        diff     = find_max_min(root->left, &l_min, &l_max);
        result   = max(result, diff);
        result   = max(result, abs(root->val - l_min));
        result   = max(result, abs(root->val - l_max));
        *max_val = max(*max_val, max(root->val, l_max));
        *min_val = min(*min_val, min(root->val, l_min));
    }
    if (root->right)
    {
        diff     = find_max_min(root->right, &r_min, &r_max);
        result   = max(result, diff);
        result   = max(result, abs(root->val - r_min));
        result   = max(result, abs(root->val - r_max));
        *max_val = max(*max_val, max(root->val, r_max));
        *min_val = min(*min_val, min(root->val, r_min));
    }
    if (!root->left && !root->right)
    {
        *max_val = root->val;
        *min_val = root->val;
    }

    return result;
}
int maxAncestorDiff(struct TreeNode* root)
{
    int min = INT_MAX;
    int max = INT_MIN;

    return find_max_min(root, &min, &max);
}
// @lc code=end

int main(int argc, char** argv)
{
    struct TreeNode node8;
    node8.val   = 8;
    node8.left  = NULL;
    node8.right = NULL;
    struct TreeNode node3;
    node3.val   = 3;
    node3.left  = NULL;
    node3.right = NULL;
    struct TreeNode node10;
    node10.val   = 10;
    node10.left  = NULL;
    node10.right = NULL;
    struct TreeNode node1;
    node1.val   = 1;
    node1.left  = NULL;
    node1.right = NULL;
    struct TreeNode node6;
    node6.val   = 6;
    node6.left  = NULL;
    node6.right = NULL;
    struct TreeNode node14;
    node14.val   = 14;
    node14.left  = NULL;
    node14.right = NULL;
    struct TreeNode node4;
    node4.val   = 4;
    node4.left  = NULL;
    node4.right = NULL;
    struct TreeNode node7;
    node7.val   = 7;
    node7.left  = NULL;
    node7.right = NULL;
    struct TreeNode node13;
    node13.val   = 13;
    node13.left  = NULL;
    node13.right = NULL;
    node8.left   = &node3;
    node8.right  = &node10;
    node3.left   = &node1;
    node3.right  = &node6;
    node10.right = &node14;
    node6.left   = &node4;
    node6.right  = &node7;
    node14.left  = &node13;

    printf("%d\n", maxAncestorDiff(&node8));

    return 0;
}
// Accepted
// 28/28 cases passed (7 ms)
// Your runtime beats 13.64 % of c submissions
// Your memory usage beats 9.09 % of c submissions (9.4 MB)