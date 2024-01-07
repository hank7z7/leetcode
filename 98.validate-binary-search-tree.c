/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (32.23%)
 * Likes:    16065
 * Dislikes: 1310
 * Total Accepted:    2.1M
 * Total Submissions: 6.6M
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST).
 *
 * A valid BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,1,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is
 * 4.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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

bool isValidBST_VAL(struct TreeNode* root, long long min, long long max)
{
    bool result = true;
    if (root->left)
    {
        result &= (root->left->val < root->val) & (root->left->val < max) & (min < root->left->val);
        if (result)
            result &= isValidBST_VAL(root->left, min, root->val);
    }
    if (!result)
        return result;
    if (root->right)
    {
        result
            &= (root->right->val > root->val) & (root->right->val < max) & (min < root->right->val);
        if (result)
            result &= isValidBST_VAL(root->right, root->val, max);
    }

    return result;
}

bool isValidBST(struct TreeNode* root)
{
    if (!root)
        return false;
    return isValidBST_VAL(root, (long long) INT_MIN - 1, (long long) INT_MAX + 1);
}
// @lc code=end

int main(int argc, char** argv) { return 0; }

// Accepted
// 84/84 cases passed (3 ms)
// Your runtime beats 90.63 % of c submissions
// Your memory usage beats 42.58 % of c submissions (9.6 MB)