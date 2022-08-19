/*
 * @lc app=leetcode id=530 lang=c
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (56.18%)
 * Likes:    2296
 * Dislikes: 130
 * Total Accepted:    172.3K
 * Total Submissions: 304.9K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum absolute
 * difference between the values of any two different nodes in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [4,2,6,1,3]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 10^4].
 * 0 <= Node.val <= 10^5
 * 
 * 
 * 
 * Note: This question is the same as 783:
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
#define MIN(a,b) (((a)<(b))?(a):(b))

void Inorder_Traversal(struct TreeNode *root, int *prev, int *min)
{
	if (root->left != NULL)
		Inorder_Traversal(root->left, prev, min);
	if ((*prev) >= 0)
		(*min) = MIN((*min), root->val - (*prev));
	(*prev) = root->val;
	if (root->right != NULL)
		Inorder_Traversal(root->right, prev, min);
}

int getMinimumDifference(struct TreeNode *root)
{
	int min = INT_MAX;
	int prev = -1;
	Inorder_Traversal(root, &prev, &min);

	return min;
}

// @lc code=end

// Accepted
// 188/188 cases passed (12 ms)
// Your runtime beats 82.19 % of c submissions
// Your memory usage beats 49.32 % of c submissions (10.3 MB)
