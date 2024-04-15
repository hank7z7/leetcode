/*
 * @lc app=leetcode id=589 lang=c
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (76.00%)
 * Likes:    2156
 * Dislikes: 104
 * Total Accepted:    281.1K
 * Total Submissions: 368.4K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given the root of an n-ary tree, return the preorder traversal of its nodes'
 * values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal.
 * Each group of children is separated by the null value (See examples)
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [1,3,5,6,2,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
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
#include <bits/stdc++.h>
struct Node {
	int val;
	int numChildren;
	struct Node **children;
};
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
		arr[(*returnSize)++] = root->val;
		int num = root->numChildren;
		for (int i = 0; i < num; i++) {
			recursive_traversal((root->children)[i], returnSize,
					    arr);
		}
	}
}

int *preorder(struct Node *root, int *returnSize)
{
	int *result = (int *)malloc(sizeof(int) * 10000);
	(*returnSize) = 0;

	// Recursive method
	recursive_traversal(root, returnSize, result);
	// Accepted
	// 38/38 cases passed (13 ms)
	// Your runtime beats 86.67 % of c submissions
	// Your memory usage beats 77.78 % of c submissions (8.4 MB)

	// Iterative method
	// struct Node **stack = (struct Node **)malloc(sizeof(struct Node *) * 1000);
	// memset(stack, 0, sizeof(struct Node *) * 1000);
	// int top = 0;

	// // Push root
	// stack[top++] = NULL;
	// stack[top++] = root;

	// // Loop while stack is not empty
	// while(top > 0)
	// {
	//     // Pop the top and write the value
	//     struct Node *tmp = stack[top];
	//     if(tmp != NULL)
	//         result[(*returnSize)++] = tmp->val;
	//     top --;

	//     // Push children from right to left
	//     int num = tmp->numChildren;
	//     for(int i = num - 1; i >= 0; i--)
	//     {
	//         stack[top++] = (tmp->children)[i];
	//     }
	// }
	return result;
}

// @lc code=end
