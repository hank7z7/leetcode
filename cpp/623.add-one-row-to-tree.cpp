/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
 *
 * https://leetcode.com/problems/add-one-row-to-tree/description/
 *
 * algorithms
 * Medium (59.60%)
 * Likes:    3274
 * Dislikes: 247
 * Total Accepted:    211.2K
 * Total Submissions: 341.2K
 * Testcase Example:  '[4,2,6,3,1,5]\n1\n2'
 *
 * Given the root of a binary tree and two integers val and depth, add a row of
 * nodes with value val at the given depth depth.
 * 
 * Note that the root node is at depth 1.
 * 
 * The adding rule is:
 * 
 * 
 * Given the integer depth, for each not null tree node cur at the depth depth
 * - 1, create two tree nodes with value val as cur's left subtree root and
 * right subtree root.
 * cur's original left subtree should be the left subtree of the new left
 * subtree root.
 * cur's original right subtree should be the right subtree of the new right
 * subtree root.
 * If depth == 1 that means there is no depth depth - 1 at all, then create a
 * tree node with value val as the new root of the whole original tree, and the
 * original tree is the new root's left subtree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [4,2,6,3,1,5], val = 1, depth = 2
 * Output: [4,1,1,2,null,null,6,3,1,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [4,2,null,3,1], val = 1, depth = 3
 * Output: [4,2,null,1,1,3,null,null,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * The depth of the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 * -10^5 <= val <= 10^5
 * 1 <= depth <= the depth of tree + 1
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
class Solution
{
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode* new_root = new TreeNode(val, root, NULL);
            return new_root;
        }
        // (Pointer, depth, is left)
        queue<tuple<TreeNode*, int>> q;
        // Initialize BFS
        if (root)
            q.push({ root, 1 });
        while (!q.empty())
        {
            TreeNode* curr       = get<0>(q.front());
            int       curr_depth = get<1>(q.front());

            if (curr_depth == depth - 1)
            {
                TreeNode* new_left_child = new TreeNode(val, curr->left, NULL);
                curr->left               = new_left_child;

                TreeNode* new_right_child = new TreeNode(val, NULL, curr->right);
                curr->right               = new_right_child;
            }

            if (curr->left && curr_depth < depth - 1)
                q.push({ curr->left, curr_depth + 1 });
            if (curr->right && curr_depth < depth - 1)
                q.push({ curr->right, curr_depth + 1 });
            q.pop();
        }

        return root;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct TreeNode  test_1_node_5 = TreeNode(5);
    struct TreeNode  test_1_node_4 = TreeNode(1);
    struct TreeNode  test_1_node_3 = TreeNode(3);
    struct TreeNode  test_1_node_2 = TreeNode(6, &test_1_node_5, NULL);
    struct TreeNode  test_1_node_1 = TreeNode(2, &test_1_node_3, &test_1_node_4);
    struct TreeNode  test_1_node_0 = TreeNode(4, &test_1_node_1, &test_1_node_2);
    int              val_1         = 1;
    int              depth_1       = 2;
    struct TreeNode* result_1      = sol.addOneRow(&test_1_node_0, val_1, depth_1);

    // Test_2
    struct TreeNode  test_2_node_3 = TreeNode(1);
    struct TreeNode  test_2_node_2 = TreeNode(3);
    struct TreeNode  test_2_node_1 = TreeNode(2, &test_2_node_2, &test_2_node_3);
    struct TreeNode  test_2_node_0 = TreeNode(4, &test_2_node_1, NULL);
    int              val_2         = 1;
    int              depth_2       = 3;
    struct TreeNode* result_2      = sol.addOneRow(&test_2_node_0, val_2, depth_2);

    // Test_3
    struct TreeNode  test_3_node_3 = TreeNode(4);
    struct TreeNode  test_3_node_2 = TreeNode(3);
    struct TreeNode  test_3_node_1 = TreeNode(2, &test_3_node_3, NULL);
    struct TreeNode  test_3_node_0 = TreeNode(1, &test_3_node_1, &test_3_node_2);
    int              val_3         = 5;
    int              depth_3       = 4;
    struct TreeNode* result_3      = sol.addOneRow(&test_3_node_0, val_3, depth_3);

    return 0;
}
// Accepted
// 109/109 cases passed (8 ms)
// Your runtime beats 91.46 % of cpp submissions
// Your memory usage beats 14.65 % of cpp submissions (24.7 MB)