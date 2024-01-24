/*
 * @lc app=leetcode id=1457 lang=c
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 */
#include <stdio.h>

struct TreeNode
{
    int              val;
    struct TreeNode* left;
    struct TreeNode* right;
};
// @lc code=start
#define NODE_VAL_RANGE 10

unsigned int mask = 1;

int countSetBits(unsigned int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root, unsigned int* count, int* result)
{
    if (root)
    {
        *count ^= (mask << root->val);
        if (root->left)
        {
            dfs(root->left, count, result);
        }
        if (root->right)
        {
            dfs(root->right, count, result);
        }

        // Is a leaf
        if ((!root->left) && (!root->right))
        {
            // printf("leaf %d\n", root->val);
            int odd_count = countSetBits(*count);
            if (odd_count <= 1)
                (*result)++;
        }

        // Leave this node
        *count ^= (mask << root->val);
    }
    else {}
}

int pseudoPalindromicPaths(struct TreeNode* root)
{
    int          result       = 0;
    unsigned int count_bitset = 0;
    dfs(root, &count_bitset, &result);
    return result;
}
// @lc code=end

int main(int argc, char** argv)
{
    // Test 1
    struct TreeNode test1_node1;
    struct TreeNode test1_node2;
    struct TreeNode test1_node3;
    struct TreeNode test1_node4;
    struct TreeNode test1_node5;
    struct TreeNode test1_node6;
    test1_node1.val   = 2;
    test1_node1.left  = &test1_node2;
    test1_node1.right = &test1_node3;
    test1_node2.val   = 3;
    test1_node2.left  = &test1_node4;
    test1_node2.right = &test1_node5;
    test1_node3.val   = 1;
    test1_node3.left  = NULL;
    test1_node3.right = &test1_node6;
    test1_node4.val   = 3;
    test1_node4.left  = NULL;
    test1_node4.right = NULL;
    test1_node5.val   = 1;
    test1_node5.left  = NULL;
    test1_node5.right = NULL;
    test1_node6.val   = 1;
    test1_node6.left  = NULL;
    test1_node6.right = NULL;
    printf("%d\n", pseudoPalindromicPaths(&test1_node1));

    return 0;
}
// Accepted
// 56/56 cases passed (161 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 60 % of c submissions (100.1 MB)