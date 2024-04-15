/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (45.32%)
 * Likes:    6059
 * Dislikes: 813
 * Total Accepted:    937.3K
 * Total Submissions: 2M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return true if the
 * tree has a root-to-leaf path such that adding up all the values along the
 * path equals targetSum.
 * 
 * A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * Output: true
 * Explanation: The root-to-leaf path with the target sum is shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3], targetSum = 5
 * Output: false
 * Explanation: There two root-to-leaf paths in the tree:
 * (1 --> 2): The sum is 3.
 * (1 --> 3): The sum is 4.
 * There is no root-to-leaf path with sum = 5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [], targetSum = 0
 * Output: false
 * Explanation: Since the tree is empty, there are no root-to-leaf paths.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
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

bool hasPathSum(struct TreeNode *root, int targetSum)
{
	// Empty root and targetSum = 0 is false
	if (!root)
		return false;
	else if (root->left == NULL && root->right == NULL
		 && root->val == targetSum)
		return true;
	else
		return (hasPathSum(root->left, targetSum - root->val)
			|| hasPathSum(root->right, targetSum - root->val));
}

// @lc code=end

// Accepted
// 117/117 cases passed (4 ms)
// Your runtime beats 91.1 % of c submissions
// Your memory usage beats 76.71 % of c submissions (8 MB)
