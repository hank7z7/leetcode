/*
 * @lc app=leetcode id=563 lang=c
 *
 * [563] Binary Tree Tilt
 *
 * https://leetcode.com/problems/binary-tree-tilt/description/
 *
 * algorithms
 * Easy (58.40%)
 * Likes:    1752
 * Dislikes: 1969
 * Total Accepted:    174.9K
 * Total Submissions: 296.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given the root of a binary tree, return the sum of every tree node's tilt.
 * 
 * The tilt of a tree node is the absolute difference between the sum of all
 * left subtree node values and all right subtree node values. If a node does
 * not have a left child, then the sum of the left subtree node values is
 * treated as 0. The rule is similar if the node does not have a right
 * child.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3]
 * Output: 1
 * Explanation: 
 * Tilt of node 2 : |0-0| = 0 (no children)
 * Tilt of node 3 : |0-0| = 0 (no children)
 * Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2;
 * right subtree is just right child, so sum is 3)
 * Sum of every tilt : 0 + 0 + 1 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [4,2,9,3,5,null,7]
 * Output: 15
 * Explanation: 
 * Tilt of node 3 : |0-0| = 0 (no children)
 * Tilt of node 5 : |0-0| = 0 (no children)
 * Tilt of node 7 : |0-0| = 0 (no children)
 * Tilt of node 2 : |3-5| = 2 (left subtree is just left child, so sum is 3;
 * right subtree is just right child, so sum is 5)
 * Tilt of node 9 : |0-7| = 7 (no left child, so sum is 0; right subtree is
 * just right child, so sum is 7)
 * Tilt of node 4 : |(3+5+2)-(9+7)| = |10-16| = 6 (left subtree values are 3,
 * 5, and 2, which sums to 10; right subtree values are 9 and 7, which sums to
 * 16)
 * Sum of every tilt : 0 + 0 + 0 + 2 + 7 + 6 = 15
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [21,7,14,1,1,2,2,3,3]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
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
int Traversal(struct TreeNode *root, int *tilt_sum)
{
	if (root == NULL)
		return 0;
	int l_sum = Traversal(root->left, tilt_sum);
	int r_sum = Traversal(root->right, tilt_sum);
	int tilt = abs(l_sum - r_sum);
	(*tilt_sum) += tilt;
	return l_sum + r_sum + root->val;
}

int findTilt(struct TreeNode *root)
{
	int tilt_sum = 0;
	int x = Traversal(root, &tilt_sum);
	return tilt_sum;
}

// @lc code=end

// Accepted
// 77/77 cases passed (15 ms)
// Your runtime beats 87.5 % of c submissions
// Your memory usage beats 58.33 % of c submissions (10.1 MB)
