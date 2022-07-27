/*
 * @lc app=leetcode id=111 lang=c
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (42.32%)
 * Likes:    4501
 * Dislikes: 979
 * Total Accepted:    798.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^5].
 * -1000 <= Node.val <= 1000
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

int minDepth(struct TreeNode *root)
{
	if (root == NULL)
		return 0;

	int left_depth = minDepth(root->left);
	int right_depth = minDepth(root->right);
	if (left_depth == 0)
		return right_depth + 1;
	if (right_depth == 0)
		return left_depth + 1;
	return (left_depth < right_depth ? left_depth : right_depth) + 1;

}

// @lc code=end

// Accepted
// 52/52 cases passed (187 ms)
// Your runtime beats 94.18 % of c submissions
// Your memory usage beats 33.01 % of c submissions (75.9 MB)
