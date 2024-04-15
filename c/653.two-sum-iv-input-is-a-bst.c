/*
 * @lc app=leetcode id=653 lang=c
 *
 * [653] Two Sum IV - Input is a BST
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
void inorder(struct TreeNode *node, int *nums, int *idx)
{
	if (!node)
		return;
	inorder(node->left, nums, idx);
	nums[(*idx)++] = node->val;
	inorder(node->right, nums, idx);
}

bool findTarget(struct TreeNode *root, int k)
{
	int nums[10000] = { 0 };
	int index = 0;
	inorder(root, nums, &index);

	for (int i = 0, j = index - 1; i < j;) {
		int two_sum = nums[i] + nums[j];
		if (two_sum == k)
			return true;
		(two_sum < k) ? ++i : --j;
	}
	return false;
}

// @lc code=end

// Accepted
// 422/422 cases passed (40 ms)
// Your runtime beats 54.74 % of c submissions
// Your memory usage beats 5.26 % of c submissions (35.9 MB)
