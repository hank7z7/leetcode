/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.03%)
 * Likes:    2944
 * Dislikes: 128
 * Total Accepted:    133.4K
 * Total Submissions: 179.9K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Given two integer arrays, preorder and postorder where preorder is the
 * preorder traversal of a binary tree of distinct values and postorder is the
 * postorder traversal of the same tree, reconstruct and return the binary
 * tree.
 *
 * If there exist multiple answers, you can return any of them.
 *
 *
 * Example 1:
 *
 *
 * Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 *
 *
 * Example 2:
 *
 *
 * Input: preorder = [1], postorder = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= preorder.length <= 30
 * 1 <= preorder[i] <= preorder.length
 * All the values of preorder are unique.
 * postorder.length == preorder.length
 * 1 <= postorder[i] <= postorder.length
 * All the values of postorder are unique.
 * It is guaranteed that preorder and postorder are the preorder traversal and
 * postorder traversal of the same binary tree.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        stack<TreeNode *> st;
        const int n = (int)preorder.size();
        TreeNode *root = NULL;
        int post_idx = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = new TreeNode(preorder[i]);
            if (i == 0)
                root = node;
            if (!st.empty())
            {
                if (!st.top()->left)
                {
                    st.top()->left = node;
                }
                else if (!st.top()->right)
                {
                    st.top()->right = node;
                }
            }

            st.push(node);

            while (!st.empty() && st.top()->val == postorder[post_idx])
            {
                st.pop();
                post_idx++;
            }
        }
        return root;
    }
};
// @lc code=end
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p != NULL && q != NULL)
    {
        if (p->val == q->val)
        {
            cout << p->val << endl;
            bool l = isSameTree(p->left, q->left);
            bool r = isSameTree(p->right, q->right);
            if (l && r)
                return true;
        }
    }
    return false;
}
void delete_tree(TreeNode *root)
{
    if (!root)
        return;
    if (root->left)
        delete_tree(root->left);
    if (root->right)
        delete_tree(root->right);
    delete (root);
}
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> test_1_preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> test_1_postorder = {4, 5, 2, 6, 7, 3, 1};
    TreeNode *test_1_res = sol.constructFromPrePost(test_1_preorder, test_1_postorder);
    TreeNode test_1_node_6 = TreeNode(7);
    TreeNode test_1_node_5 = TreeNode(6);
    TreeNode test_1_node_4 = TreeNode(5);
    TreeNode test_1_node_3 = TreeNode(4);
    TreeNode test_1_node_2 = TreeNode(3, &test_1_node_5, &test_1_node_6);
    TreeNode test_1_node_1 = TreeNode(2, &test_1_node_3, &test_1_node_4);
    TreeNode test_1_node_0 = TreeNode(1, &test_1_node_1, &test_1_node_2);
    bool res_1 = isSameTree(&test_1_node_0, test_1_res);
    cout << res_1 << endl;
    assert(res_1 == true);
    delete_tree(test_1_res);

    // Test_2
    vector<int> test_2_preorder = {1};
    vector<int> test_2_postorder = {1};
    TreeNode *test_2_res = sol.constructFromPrePost(test_2_preorder, test_2_postorder);
    TreeNode test_2_node_0 = TreeNode(1);
    bool res_2 = isSameTree(&test_2_node_0, test_2_res);
    cout << res_2 << endl;
    assert(res_2 == true);
    delete_tree(test_2_res);

    return 0;
}
// Accepted
// 306/306 cases passed (3 ms)
// Your runtime beats 39.83 % of cpp submissions
// Your memory usage beats 98.92 % of cpp submissions (27.8 MB)