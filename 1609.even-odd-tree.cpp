/*
 * @lc app=leetcode id=1609 lang=cpp
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
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	 TreeNode()
	:val(0)
	, left(nullptr)
	, right(nullptr) {
	} TreeNode(int x)
	:val(x)
	, left(nullptr)
	, right(nullptr) {
	}
	TreeNode(int x, TreeNode * left, TreeNode * right)
	:val(x)
	, left(left)
	, right(right) {
	}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 private:
 public:
	bool isEvenOddTree(TreeNode * root) {
		if (!root)
			return false;
		// Level order traversal by queue
		queue < TreeNode * >q;
		bool is_odd = true;
		 q.push(root);
		while (!q.empty()) {
			int level_size = (int)q.size();
			bool first_of_row = true;
			int prev;
			while (level_size-- > 0) {
				TreeNode *curr = q.front();
				 q.pop();
				if (is_odd ^ (curr->val & 1))
					 return false;
				if (first_of_row) {
					first_of_row = false;
				} else {
					if ((is_odd ? (curr->val <= prev)
					     : (curr->val >= prev)))
						return false;
				}
				prev = curr->val;
				if (curr->left)
					q.push(curr->left);
				if (curr->right)
					q.push(curr->right);
			}
			is_odd = !is_odd;
		}
		return true;
	}
};

// @lc code=end
int main(int argc, char **argv)
{
	Solution sol;
	// Test_1
	struct TreeNode tree_1_node_1 = TreeNode(1);
	struct TreeNode tree_1_node_3 = TreeNode(3);
	struct TreeNode tree_1_node_2 =
	    TreeNode(2, &tree_1_node_1, &tree_1_node_3);
	cout << sol.isEvenOddTree(&tree_1_node_2) << endl;

	// Test_2
	struct TreeNode tree_2_node_4 = TreeNode(4);
	struct TreeNode tree_2_node_2 = TreeNode(2, &tree_2_node_4, NULL);
	struct TreeNode tree_2_node_7 = TreeNode(7);
	struct TreeNode tree_2_node_5 = TreeNode(5, &tree_2_node_7, NULL);
	struct TreeNode tree_2_node_6 = TreeNode(6);
	struct TreeNode tree_2_node_3 =
	    TreeNode(2, &tree_2_node_5, &tree_2_node_6);
	struct TreeNode tree_2_node_1 =
	    TreeNode(1, &tree_2_node_2, &tree_2_node_3);
	cout << sol.isEvenOddTree(&tree_2_node_1) << endl;

	// Test_3
	struct TreeNode tree_3_node_1 = TreeNode(1);
	cout << sol.isEvenOddTree(&tree_3_node_1) << endl;
	return 0;
}

// Accepted
// 106/106 cases passed (200 ms)
// Your runtime beats 69.24 % of cpp submissions
// Your memory usage beats 89.27 % of cpp submissions (149.2 MB)
