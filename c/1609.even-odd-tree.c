/*
 * @lc app=leetcode id=1609 lang=c
 *
 * [1609] Even Odd Tree
 *
 * https://leetcode.com/problems/even-odd-tree/description/
 *
 * algorithms
 * Medium (55.90%)
 * Likes:    1429
 * Dislikes: 70
 * Total Accepted:    85.5K
 * Total Submissions: 139.9K
 * Testcase Example:  '[1,10,4,3,null,7,9,12,8,6,null,null,2]'
 *
 * A binary tree is named Even-Odd if it meets the following conditions:
 *
 *
 * The root of the binary tree is at level index 0, its children are at level
 * index 1, their children are at level index 2, etc.
 * For every even-indexed level, all nodes at the level have odd integer values
 * in strictly increasing order (from left to right).
 * For every odd-indexed level, all nodes at the level have even integer values
 * in strictly decreasing order (from left to right).
 *
 *
 * Given the root of a binary tree, return true if the binary tree is Even-Odd,
 * otherwise return false.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
 * Output: true
 * Explanation: The node values on each level are:
 * Level 0: [1]
 * Level 1: [10,4]
 * Level 2: [3,7,9]
 * Level 3: [12,8,6,2]
 * Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all
 * even and decreasing, the tree is Even-Odd.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,4,2,3,3,7]
 * Output: false
 * Explanation: The node values on each level are:
 * Level 0: [5]
 * Level 1: [4,2]
 * Level 2: [3,3,7]
 * Node values in level 2 must be in strictly increasing order, so the tree is
 * not Even-Odd.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [5,9,1,3,5,7]
 * Output: false
 * Explanation: Node values in the level 1 should be even integers.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^5].
 * 1 <= Node.val <= 10^6
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
#define QUEUE_NUM (2)
#define NODE_SIZE (100000)
bool isEvenOddTree(struct TreeNode *root)
{
	if (!root)
		return false;
	struct TreeNode *queue[QUEUE_NUM][(NODE_SIZE + 1) / 2];
	int queue_top[QUEUE_NUM] = { 0 };

	int this_queue = 0;
	queue[this_queue][queue_top[this_queue]++] = root;
	bool is_odd = true;
	while (queue_top[this_queue] > 0) {
		int curr_queue_size = queue_top[this_queue];
		int next_queue = (this_queue + 1) & 1;
		int prev;
		for (int i = 0; i < curr_queue_size; i++) {
			int curr = queue[this_queue][i]->val;
			if (is_odd ^ (curr & 1))
				return false;

			if (i > 0 && (is_odd ? (curr <= prev) : (curr >= prev)))
				return false;
			prev = curr;
			if (queue[this_queue][i]->left)
				queue[next_queue][queue_top[next_queue]++] =
				    queue[this_queue][i]->left;
			if (queue[this_queue][i]->right)
				queue[next_queue][queue_top[next_queue]++] =
				    queue[this_queue][i]->right;
		}
		queue_top[this_queue] = 0;
		this_queue = next_queue;
		is_odd = !is_odd;
	}
	return true;
}

// @lc code=end
int main(int argc, char **argv)
{
	struct TreeNode tree_1_node_1;
	struct TreeNode tree_1_node_2;
	struct TreeNode tree_1_node_3;
	struct TreeNode tree_1_node_4;
	struct TreeNode tree_1_node_5;
	tree_1_node_1.val = 1;
	tree_1_node_2.val = 2;
	tree_1_node_3.val = 3;
	tree_1_node_4.val = 4;
	tree_1_node_5.val = 5;
	tree_1_node_1.left = &tree_1_node_2;
	tree_1_node_1.right = &tree_1_node_3;
	tree_1_node_2.left = &tree_1_node_4;
	tree_1_node_2.right = &tree_1_node_5;
	tree_1_node_3.left = NULL;
	tree_1_node_3.right = NULL;
	tree_1_node_4.left = NULL;
	tree_1_node_4.right = NULL;
	tree_1_node_5.left = NULL;
	tree_1_node_5.right = NULL;
	printf("%d\n", isEvenOddTree(&tree_1_node_1));

	return 0;
	return 0;
}
// Accepted
// 106/106 cases passed (118 ms)
// Your runtime beats 50 % of c submissions
// Your memory usage beats 100 % of c submissions (72.3 MB)