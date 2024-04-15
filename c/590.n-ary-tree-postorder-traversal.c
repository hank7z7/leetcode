/*
 * @lc app=leetcode id=590 lang=c
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (76.03%)
 * Likes:    1762
 * Dislikes: 87
 * Total Accepted:    196.7K
 * Total Submissions: 256.2K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given the root of an n-ary tree, return the postorder traversal of its
 * nodes' values.
 *
 * Nary-Tree input serialization is represented in their level order traversal.
 * Each group of children is separated by the null value (See examples)
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [5,6,3,2,4,1]
 *
 *
 * Example 2:
 *
 *
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * 0 <= Node.val <= 10^4
 * The height of the n-ary tree is less than or equal to 1000.
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void recursive_traversal(struct Node *root, int *returnSize, int *arr)
{
	if (root != NULL) {
		int num = root->numChildren;
		for (int i = 0; i < num; i++) {
			recursive_traversal((root->children)[i], returnSize,
					    arr);
		}
		arr[(*returnSize)++] = root->val;
	}
}

int *postorder(struct Node *root, int *returnSize)
{
	int *result = (int *)malloc(sizeof(int) * 10000);
	(*returnSize) = 0;

	// Recursive method
	recursive_traversal(root, returnSize, result);
	return result;
}

// @lc code=end

// Accepted
// 38/38 cases passed (11 ms)
// Your runtime beats 97.3 % of c submissions
// Your memory usage beats 48.65 % of c submissions (8.6 MB)
