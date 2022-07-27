/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (51.40%)
 * Likes:    10257
 * Dislikes: 243
 * Total Accepted:    1.3M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * Follow up: Could you solve it both recursively and iteratively?
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
bool CheckSymmetric(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;
    else if (CheckSymmetric(p->left, q->right) && CheckSymmetric(p->right, q->left))
        return true;
    else
        return false;
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
        return true;
    if(CheckSymmetric(root->left, root->right))
        return true;
    else
        return false;
}
// @lc code=end

// Accepted
// 198/198 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 97.01 % of c submissions (6.7 MB)