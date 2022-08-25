/*
 * @lc app=leetcode id=606 lang=c
 *
 * [606] Construct String from Binary Tree
 *
 * https://leetcode.com/problems/construct-string-from-binary-tree/description/
 *
 * algorithms
 * Easy (57.59%)
 * Likes:    1475
 * Dislikes: 1848
 * Total Accepted:    136.5K
 * Total Submissions: 234.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given the root of a binary tree, construct a string consisting of
 * parenthesis and integers from a binary tree with the preorder traversal way,
 * and return it.
 * 
 * Omit all the empty parenthesis pairs that do not affect the one-to-one
 * mapping relationship between the string and the original binary tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4]
 * Output: "1(2(4))(3)"
 * Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to
 * omit all the unnecessary empty parenthesis pairs. And it will be
 * "1(2(4))(3)"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3,null,4]
 * Output: "1(2()(4))(3)"
 * Explanation: Almost the same as the first example, except we cannot omit the
 * first parenthesis pair to break the one-to-one mapping relationship between
 * the input and the output.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
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
void traversal(struct TreeNode *root, char *str, int *idx)
{
	if (root != NULL) {
		// Function sprintf return the string length!
		(*idx) += sprintf(str + (*idx), "%d", root->val);

		if (root->left) {
			sprintf(str + (*idx)++, "(");
			traversal(root->left, str, idx);
			sprintf(str + (*idx)++, ")");
		}

		if (root->right) {
			if (!root->left) {
				sprintf(str + (*idx), "()");
				(*idx) += 2;
			}
			sprintf(str + (*idx)++, "(");
			traversal(root->right, str, idx);
			sprintf(str + (*idx)++, ")");
		}
	}
}

char *tree2str(struct TreeNode *root)
{
	char *result = (char *)malloc(sizeof(char) * 25000);
	// memset(result, '\0', sizeof(char) * 100000);
	int index = 0;
	traversal(root, result, &index);
	return result;
}

// @lc code=end

// Accepted
// 160/160 cases passed (18 ms)
// Your runtime beats 68.42 % of c submissions
// Your memory usage beats 89.47 % of c submissions (11 MB)
