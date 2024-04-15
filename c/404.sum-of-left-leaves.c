/*
 * @lc app=leetcode id=404 lang=c
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (54.88%)
 * Likes:    3664
 * Dislikes: 254
 * Total Accepted:    375.8K
 * Total Submissions: 673.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the sum of all left leaves.
 * 
 * A leaf is a node with no children. A left leaf is a leaf that is the left
 * child of another node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 24
 * Explanation: There are two left leaves in the binary tree, with values 9 and
 * 15 respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
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
void traversal(struct TreeNode *root, int *val, bool isleft)
{
	if (root) {
		//array[(*returnSize)++] = root->val; // Pre order
		if ((root->left == NULL) && (root->right == NULL) && isleft) {
			*val += root->val;
			// return;   
		} else {
			traversal(root->left, val, true);
			traversal(root->right, val, false);
		}
	}
}

int sumOfLeftLeaves(struct TreeNode *root)
{
	int result = 0;
	traversal(root, &result, false);
	return result;
}

// @lc code=end

// Accepted
// 100/100 cases passed (4 ms)
// Your runtime beats 49.7 % of c submissions
// Your memory usage beats 60.95 % of c submissions (6.3 MB)
