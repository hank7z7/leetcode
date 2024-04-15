/*
 * @lc app=leetcode id=230 lang=c
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (71.06%)
 * Likes:    10856
 * Dislikes: 207
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given the root of a binary search tree, and an integer k, return the k^th
 * smallest value (1-indexed) of all the values of the nodes in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 * 
 * 
 * 
 * Follow up: If the BST is modified often (i.e., we can do insert and delete
 * operations) and you need to find the kth smallest frequently, how would you
 * optimize?
 * 
 */
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
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
void InorderTraversal(struct TreeNode *root, int *count, int *result, int k)
{
	if (!root)
		return;
	else {
		if (root->left)
			InorderTraversal(root->left, count, result, k);
		(*count)++;
		if (*count == k)
			*result = root->val;
		if (root->right)
			InorderTraversal(root->right, count, result, k);
	}
}

int kthSmallest(struct TreeNode *root, int k)
{
	// Inorder Traversal is the increasing array
	int result = 0;
	int count = 0;
	InorderTraversal(root, &count, &result, k);

	return result;
}

// @lc code=end

int main(int argc, char **argv)
{
	return 0;
}

// Accepted
// 93/93 cases passed (12 ms)
// Your runtime beats 36.63 % of c submissions
// Your memory usage beats 39.6 % of c submissions (11.1 MB)
