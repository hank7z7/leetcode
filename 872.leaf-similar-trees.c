/*
 * @lc app=leetcode id=872 lang=c
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (67.94%)
 * Likes:    3818
 * Dislikes: 90
 * Total Accepted:    381K
 * Total Submissions: 547K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n' +
  '[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree, from left to right order, the
 * values of those leaves form a leaf value sequence.
 *
 *
 *
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 *
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 *
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 *
 *
 * Example 1:
 *
 *
 * Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 =
 * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root1 = [1,2,3], root2 = [1,3,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each tree will be in the range [1, 200].
 * Both of the given trees will have values in the range [0, 200].
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
void dfs_leave(struct TreeNode* root, int* leaves, int* top)
{
    if (root)
    {
        if (root->left)
            dfs_leave(root->left, leaves, top);
        if (root->right)
            dfs_leave(root->right, leaves, top);
        if (!root->left && !root->right)
        {
            leaves[*top] = root->val;
            *top         = *top + 1;
        }
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    int leaves_1[100] = { 0 };
    int top_1         = 0;
    int leaves_2[100] = { 0 };
    int top_2         = 0;

    dfs_leave(root1, leaves_1, &top_1);
    dfs_leave(root2, leaves_2, &top_2);

    if (top_1 == top_2)
    {
        for (int i = 0; i < top_1; i++)
        {
            if (leaves_1[i] != leaves_2[i])
                return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}
// @lc code=end

int main(int argc, char** argv)
{
    // Test 1
    struct TreeNode t1_1_3;
    t1_1_3.val   = 3;
    t1_1_3.left  = NULL;
    t1_1_3.right = NULL;
    struct TreeNode t1_1_5;
    t1_1_5.val   = 5;
    t1_1_5.left  = NULL;
    t1_1_5.right = NULL;
    struct TreeNode t1_1_1;
    t1_1_1.val   = 1;
    t1_1_1.left  = NULL;
    t1_1_1.right = NULL;
    struct TreeNode t1_1_6;
    t1_1_6.val   = 6;
    t1_1_6.left  = NULL;
    t1_1_6.right = NULL;
    struct TreeNode t1_1_2;
    t1_1_2.val   = 2;
    t1_1_2.left  = NULL;
    t1_1_2.right = NULL;
    struct TreeNode t1_1_7;
    t1_1_7.val   = 7;
    t1_1_7.left  = NULL;
    t1_1_7.right = NULL;
    struct TreeNode t1_1_4;
    t1_1_4.val   = 4;
    t1_1_4.left  = NULL;
    t1_1_4.right = NULL;
    struct TreeNode t1_1_9;
    t1_1_9.val   = 9;
    t1_1_9.left  = NULL;
    t1_1_9.right = NULL;
    struct TreeNode t1_1_8;
    t1_1_8.val   = 8;
    t1_1_8.left  = NULL;
    t1_1_8.right = NULL;
    t1_1_3.left  = &t1_1_5;
    t1_1_3.right = &t1_1_1;
    t1_1_5.left  = &t1_1_6;
    t1_1_5.right = &t1_1_2;
    t1_1_2.left  = &t1_1_7;
    t1_1_2.right = &t1_1_4;
    t1_1_1.left  = &t1_1_9;
    t1_1_1.right = &t1_1_8;

    struct TreeNode t1_2_3;
    t1_2_3.val   = 3;
    t1_2_3.left  = NULL;
    t1_2_3.right = NULL;
    struct TreeNode t1_2_5;
    t1_2_5.val   = 5;
    t1_2_5.left  = NULL;
    t1_2_5.right = NULL;
    struct TreeNode t1_2_1;
    t1_2_1.val   = 1;
    t1_2_1.left  = NULL;
    t1_2_1.right = NULL;
    struct TreeNode t1_2_6;
    t1_2_6.val   = 6;
    t1_2_6.left  = NULL;
    t1_2_6.right = NULL;
    struct TreeNode t1_2_2;
    t1_2_2.val   = 2;
    t1_2_2.left  = NULL;
    t1_2_2.right = NULL;
    struct TreeNode t1_2_7;
    t1_2_7.val   = 7;
    t1_2_7.left  = NULL;
    t1_2_7.right = NULL;
    struct TreeNode t1_2_4;
    t1_2_4.val   = 4;
    t1_2_4.left  = NULL;
    t1_2_4.right = NULL;
    struct TreeNode t1_2_9;
    t1_2_9.val   = 9;
    t1_2_9.left  = NULL;
    t1_2_9.right = NULL;
    struct TreeNode t1_2_8;
    t1_2_8.val   = 8;
    t1_2_8.left  = NULL;
    t1_2_8.right = NULL;
    t1_2_3.left  = &t1_2_5;
    t1_2_3.right = &t1_2_1;
    t1_2_5.left  = &t1_2_6;
    t1_2_5.right = &t1_2_7;
    t1_2_1.left  = &t1_2_4;
    t1_2_1.right = &t1_2_2;
    t1_2_2.left  = &t1_2_9;
    t1_2_2.right = &t1_2_8;

    printf("%d\n", leafSimilar(&t1_1_3, &t1_2_3));

    // Test 2
    struct TreeNode t2_1_1;
    t2_1_1.val   = 1;
    t2_1_1.left  = NULL;
    t2_1_1.right = NULL;
    struct TreeNode t2_1_2;
    t2_1_2.val   = 2;
    t2_1_2.left  = NULL;
    t2_1_2.right = NULL;
    struct TreeNode t2_1_3;
    t2_1_3.val   = 3;
    t2_1_3.left  = NULL;
    t2_1_3.right = NULL;
    t2_1_1.left  = &t2_1_2;
    t2_1_1.right = &t2_1_3;
    struct TreeNode t2_2_1;
    t2_2_1.val   = 1;
    t2_2_1.left  = NULL;
    t2_2_1.right = NULL;
    struct TreeNode t2_2_3;
    t2_2_3.val   = 3;
    t2_2_3.left  = NULL;
    t2_2_3.right = NULL;
    struct TreeNode t2_2_2;
    t2_2_2.val   = 3;
    t2_2_2.left  = NULL;
    t2_2_2.right = NULL;
    t2_2_1.left  = &t2_2_3;
    t2_2_1.right = &t2_2_2;

    printf("%d\n", leafSimilar(&t2_1_1, &t2_2_1));

    return 0;
}
// Accepted
// 43/43 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 99.74 % of c submissions (6.7 MB)