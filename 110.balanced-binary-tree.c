/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (46.61%)
 * Likes:    6649
 * Dislikes: 348
 * Total Accepted:    851.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 *
 *
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -10^4 <= Node.val <= 10^4
 *
 *
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

int maxDepth(struct TreeNode *root) {
    if (!root)
        return 0;

    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    // Return -1 for not balanced
    if (left_depth == -1 || right_depth == -1 ||
        abs(left_depth - right_depth) > 1)
        return -1;
    else
        return (left_depth >= right_depth ? left_depth : right_depth) + 1;
}

// The first version but only beats 69%
// int maxDepth(struct TreeNode *root, bool *is_balanced) {
//     if (root == NULL)
//     {
//         *is_balanced = true;
//         return 0;
//     }
//     bool left_balanced = false, right_balanced = false;
//     int left_depth = maxDepth(root->left, &left_balanced);
//     int right_depth = maxDepth(root->right, &right_balanced);

//     if(left_balanced && right_balanced)
//     {
//         if((abs(left_depth-right_depth) <= 1))
//             *is_balanced = true;
//     }
//     else
//         return (left_depth >= right_depth ? left_depth : right_depth) + 1;

//     // *is_balanced = left_balanced && right_balanced &&
//     (abs(left_depth-right_depth) <= 1); return (left_depth >= right_depth ?
//     left_depth : right_depth) + 1;
// }

bool isBalanced(struct TreeNode *root) { return maxDepth(root) >= 0; }
// @lc code=end

// Accepted
// 228/228 cases passed (7 ms)
// Your runtime beats 86.67 % of c submissions
// Your memory usage beats 99.76 % of c submissions (8.9 MB)