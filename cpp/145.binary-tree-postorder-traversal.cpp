/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (72.04%)
 * Likes:    7089
 * Dislikes: 199
 * Total Accepted:    1.4M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
private:
    void traverse(vector<int> &arr, TreeNode *root)
    {
        if (root)
        {
            traverse(arr, root->left);
            traverse(arr, root->right);
            arr.push_back(root->val);
        }
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        traverse(res, root);
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    TreeNode test_1_node_5 = TreeNode(3);
    TreeNode test_1_node_2 = TreeNode(2, &test_1_node_5, NULL);
    TreeNode test_1_node_0 = TreeNode(1, NULL, &test_1_node_2);
    vector<int> res_1 = sol.postorderTraversal(&test_1_node_0);
    for (auto i : res_1)
        cout << i << " ";
    cout << endl;
    assert((res_1 == vector<int>{3, 2, 1}));

    // Test_2
    vector<int> res_2 = sol.postorderTraversal(NULL);
    for (auto i : res_2)
        cout << i << " ";
    cout << endl;
    assert((res_2 == vector<int>{}));

    // Test_3
    TreeNode test_3_node_0 = TreeNode(1);
    vector<int> res_3 = sol.postorderTraversal(&test_3_node_0);
    for (auto i : res_3)
        cout << i << " ";
    cout << endl;
    assert((res_3 == vector<int>{1}));

    return 0;
}
// Accepted
// 69/69 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 16.62 % of cpp submissions (10.3 MB)