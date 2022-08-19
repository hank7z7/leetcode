/*
 * @lc app=leetcode id=543 lang=c
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (53.93%)
 * Likes:    9146
 * Dislikes: 567
 * Total Accepted:    840K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the root of a binary tree, return the length of the diameter of the
 * tree.
 * 
 * The diameter of a binary tree is the length of the longest path between any
 * two nodes in a tree. This path may or may not pass through the root.
 * 
 * The length of a path between two nodes is represented by the number of edges
 * between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
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
#define MAX(a,b) (((a)>(b))?(a):(b))

// Return the max depth of this tree
int Traversal(struct TreeNode *root, int *diameter)
{
	if (root == NULL)
		return 0;
	int l_depth = Traversal(root->left, diameter);
	int r_depth = Traversal(root->right, diameter);
	int depth_sum = l_depth + r_depth;
	(*diameter) = MAX(depth_sum, (*diameter));

	return MAX(l_depth, r_depth) + 1;
}

int diameterOfBinaryTree(struct TreeNode *root)
{
	int diameter_max = INT_MIN;
	int x = Traversal(root, &diameter_max);

	return diameter_max;
}

// @lc code=end

// Accepted
// 104/104 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 45.77 % of c submissions (8.2 MB)