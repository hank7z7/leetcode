/*
 * @lc app=leetcode id=617 lang=c
 *
 * [617] Merge Two Binary Trees
 *
 * https://leetcode.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (77.79%)
 * Likes:    7151
 * Dislikes: 255
 * Total Accepted:    609.1K
 * Total Submissions: 777.3K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * You are given two binary trees root1 and root2.
 * 
 * Imagine that when you put one of them to cover the other, some nodes of the
 * two trees are overlapped while the others are not. You need to merge the two
 * trees into a new binary tree. The merge rule is that if two nodes overlap,
 * then sum node values up as the new value of the merged node. Otherwise, the
 * NOT null node will be used as the node of the new tree.
 * 
 * Return the merged tree.
 * 
 * Note: The merging process must start from the root nodes of both trees.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
 * Output: [3,4,5,5,4,null,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root1 = [1], root2 = [1,2]
 * Output: [2,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in both trees is in the range [0, 2000].
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

struct TreeNode *mergeTrees(struct TreeNode *root1, struct TreeNode *root2)
{
	if (!root1 && !root2)
		return NULL;
	else {
		if (!root2)
			return root1;
		if (!root1)
			return root2;
		struct TreeNode *result =
		    (struct TreeNode *)malloc(sizeof(struct TreeNode));
		result->val = root1->val + root2->val;
		result->left = mergeTrees(root1->left, root2->left);
		result->right = mergeTrees(root1->right, root2->right);
		return result;
	}
}

// @lc code=end

// Accepted
// 182/182 cases passed (41 ms)
// Your runtime beats 52.08 % of c submissions
// Your memory usage beats 20 % of c submissions (20 MB)
