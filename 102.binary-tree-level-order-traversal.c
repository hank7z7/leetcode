/*
 * @lc app=leetcode id=102 lang=c
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (65.43%)
 * Likes:    14585
 * Dislikes: 290
 * Total Accepted:    2M
 * Total Submissions: 3M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 *
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define max(a, b)                                                                                  \
    ({                                                                                             \
        __typeof__(a) _a = (a);                                                                    \
        __typeof__(b) _b = (b);                                                                    \
        _a > _b ? _a : _b;                                                                         \
    })

int find_depth(struct TreeNode* root)
{
    if (!root)
        return 0;
    return max(find_depth(root->left), find_depth(root->right)) + 1;
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL)
    {
        *returnSize        = 0;
        *returnColumnSizes = 0;
        return NULL;
    }
    int   depth        = find_depth(root);
    int** result       = (int**) malloc(sizeof(int*) * depth);
    *returnSize        = depth;
    *returnColumnSizes = (int*) malloc(sizeof(int) * depth);

    int level = 0;
    int front = 0;
    int end   = 0;
    // Max number of nodes is 2000, so we need 2001 elements queue
    struct TreeNode** queue = (struct TreeNode**) malloc(sizeof(struct TreeNode*) * 2001);
    queue[end++]            = root;
    // Queue is not empty
    while (front < end)
    {
        // printf("front %d, end %d\n", front, end);
        int level_length            = end - front;
        (*returnColumnSizes)[level] = level_length;
        result[level]               = (int*) malloc(sizeof(int) * level_length);
        for (int i = 0; i < level_length; i++)
        {
            // result[level][i] = queue[front + i]->val;
            if (queue[front + i]->left)
            {
                // printf("push back:%d\n", queue[front + i]->left->val);
                queue[end++] = queue[front + i]->left;
            }
            if (queue[front + i]->right)
            {
                // printf("push back:%d\n", queue[front + i]->right->val);
                queue[end++] = queue[front + i]->right;
            }
            // printf("pop out:%d\n", queue[front + i]->val);
            result[level][i] = queue[front + i]->val;
        }
        front += level_length;
        level++;
    }

    free(queue);
    return result;
}
// @lc code=end
int main(int argc, char** argv) { return 0; }

// Accepted
// 35/35 cases passed (5 ms)
// Your runtime beats 79.41 % of c submissions
// Your memory usage beats 70.59 % of c submissions (8.9 MB)