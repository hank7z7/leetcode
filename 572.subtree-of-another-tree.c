/*
 * @lc app=leetcode id=572 lang=c
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (45.27%)
 * Likes:    5998
 * Dislikes: 328
 * Total Accepted:    536.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * Given the roots of two binary trees root and subRoot, return true if there
 * is a subtree of root with the same structure and node values of subRoot and
 * false otherwise.
 * 
 * A subtree of a binary tree tree is a tree that consists of a node in tree
 * and all of this node's descendants. The tree tree could also be considered
 * as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,4,5,1,2], subRoot = [4,1,2]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the root tree is in the range [1, 2000].
 * The number of nodes in the subRoot tree is in the range [1, 1000].
 * -10^4 <= root.val <= 10^4
 * -10^4 <= subRoot.val <= 10^4
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
bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;

	if (p->val != q->val)
		return false;
	if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
		return true;
	else
		return false;
}

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot)
{
	if (!root)
		return false;
	return (root->val == subRoot->val && isSameTree(root, subRoot)) ||
	    isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// @lc code=end

// Accepted
// 182/182 cases passed (17 ms)
// Your runtime beats 86.63 % of c submissions
// Your memory usage beats 53.48 % of c submissions (11 MB)