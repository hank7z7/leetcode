/*
 * @lc app=leetcode id=559 lang=c
 *
 * [559] Maximum Depth of N-ary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (70.94%)
 * Likes:    2156
 * Dislikes: 75
 * Total Accepted:    224.5K
 * Total Submissions: 314.5K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given a n-ary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 * 
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The total number of nodes is in the range [0, 10^4].
 * The depth of the n-ary tree is less than or equal to 1000.
 * 
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

int maxDepth(struct Node *root)
{
	if (root == NULL)
		return 0;
	else {
		int num = root->numChildren;
		int max_depth = 0;
		for (int i = 0; i < num; i++) {
			int depth = maxDepth((root->children)[i]);
			if (depth > max_depth)
				max_depth = depth;
		}
		return max_depth + 1;
	}
}

// @lc code=end

// Accepted
// 38/38 cases passed (8 ms)
// Your runtime beats 52 % of c submissions
// Your memory usage beats 50 % of c submissions (7.1 MB)
