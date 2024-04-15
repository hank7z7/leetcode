/*
 * @lc app=leetcode id=637 lang=c
 *
 * [637] Average of Levels in Binary Tree
 */
#include <bits/stdc++.h>

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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int depth(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + fmax(depth(root->left), depth(root->right));
}

double *averageOfLevels(struct TreeNode *root, int *returnSize)
{
	// int d = depth(root);
	int d = 1000;
	double *result = (double *)malloc(sizeof(double) * d);
	(*returnSize) = 0;
	// Try and error to find min queue_size
	int queue_size = 1000;
	struct TreeNode **queue =
	    (struct TreeNode **)malloc(sizeof(struct TreeNode *) * queue_size);
	int front = 0;
	int back = 0;
	// Push first root
	queue[back++] = root;
	int curr_size = 1;

	// While queue is not empty
	while (front != back) {
		long sum = 0;
		// Record this level size
		int this_size = curr_size;
		curr_size = 0;
		for (int i = 0; i < this_size; i++) {
			sum += queue[front]->val;
			if (queue[front]->left) {
				// Push from back
				queue[back] = queue[front]->left;
				back = (back + 1) % queue_size;

				// Record next level size
				curr_size++;
			}
			if (queue[front]->right) {
				// Push from back
				queue[back] = queue[front]->right;
				back = (back + 1) % queue_size;

				// Record next level size
				curr_size++;
			}
			// Pop front
			front = (front + 1) % queue_size;
		}
		result[(*returnSize)++] = (double)sum / this_size;
	}

	return result;
}

// @lc code=end
int main()
{
	return 0;
}

// Accepted
// 66/66 cases passed (8 ms)
// Your runtime beats 93.94 % of c submissions
// Your memory usage beats 53.03 % of c submissions (11 MB)
