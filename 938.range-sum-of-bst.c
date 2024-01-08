/*
 * @lc app=leetcode id=938 lang=c
 *
 * [938] Range Sum of BST
 *
 * https://leetcode.com/problems/range-sum-of-bst/description/
 *
 * algorithms
 * Easy (85.98%)
 * Likes:    6665
 * Dislikes: 365
 * Total Accepted:    941K
 * Total Submissions: 1.1M
 * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
 *
 * Given the root node of a binary search tree and two integers low and high,
 * return the sum of values of all nodes with a value in the inclusive range
 * [low, high].
 *
 *
 * Example 1:
 *
 *
 * Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
 * Output: 32
 * Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 =
 * 32.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
 * Output: 23
 * Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 =
 * 23.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 2 * 10^4].
 * 1 <= Node.val <= 10^5
 * 1 <= low <= high <= 10^5
 * All Node.val are unique.
 *
 *
 */
#include <stdio.h>

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
void inorderTraversal(struct TreeNode* root, int low, int high, int* sum)
{
    if (!root)
        return;
    inorderTraversal(root->left, low, high, sum);
    if (root->val >= low && root->val <= high)
        *sum += root->val;
    inorderTraversal(root->right, low, high, sum);
}

int rangeSumBST(struct TreeNode* root, int low, int high)
{
    int sum = 0;
    inorderTraversal(root, low, high, &sum);
    return sum;
}
// @lc code=end

int main(int argc, char** argv) { return 0; }