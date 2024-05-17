/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
 *
 * https://leetcode.com/problems/delete-leaves-with-a-given-value/description/
 *
 * algorithms
 * Medium (74.21%)
 * Likes:    2594
 * Dislikes: 53
 * Total Accepted:    179.9K
 * Total Submissions: 233.7K
 * Testcase Example:  '[1,2,3,2,null,2,4]\n2'
 *
 * Given a binary tree root and an integer target, delete all the leaf nodes
 * with value target.
 *
 * Note that once you delete a leaf node with value target, if its parent node
 * becomes a leaf node and has the value target, it should also be deleted (you
 * need to continue doing that until you cannot).
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [1,2,3,2,null,2,4], target = 2
 * Output: [1,null,3,null,4]
 * Explanation: Leaf nodes in green with value (target = 2) are removed
 * (Picture in left).
 * After removing, new nodes become leaf nodes with value (target = 2) (Picture
 * in center).
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: root = [1,3,3,3,2], target = 3
 * Output: [1,3,null,null,2]
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: root = [1,2,null,2,null,2], target = 2
 * Output: [1]
 * Explanation: Leaf nodes in green with value (target = 2) are removed at each
 * step.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 3000].
 * 1 <= Node.val, target <= 1000
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
    TreeNode *removeLeafNodes(TreeNode *root, int &target)
    {
        if (!root)
            return NULL;
        else
        {
            root->left = removeLeafNodes(root->left, target);
            root->right = removeLeafNodes(root->right, target);
        }

        if (root && root->val == target && !root->left && !root->right)
        {
            return NULL;
        }

        return root;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    stack<TreeNode *> st;
    // Test_1
    struct TreeNode test_1_node_6 = TreeNode(4);
    struct TreeNode test_1_node_5 = TreeNode(2);
    struct TreeNode test_1_node_3 = TreeNode(2);
    struct TreeNode test_1_node_2 = TreeNode(3, &test_1_node_5, &test_1_node_6);
    struct TreeNode test_1_node_1 = TreeNode(4, &test_1_node_3, NULL);
    struct TreeNode test_1_node_0 = TreeNode(4, &test_1_node_1, &test_1_node_2);
    int target_1 = 3;
    struct TreeNode *result_1 = sol.removeLeafNodes(&test_1_node_0, target_1);
    st.push(result_1);
    while (!st.empty())
    {
        struct TreeNode *top_node = st.top();
        st.pop();
        cout << top_node->val << " ";
        if (top_node->left)
            st.push(top_node->left);
        if (top_node->right)
            st.push(top_node->right);
    }
    cout << endl;

    // Test_2
    struct TreeNode test_2_node_4 = TreeNode(2);
    struct TreeNode test_2_node_3 = TreeNode(3);
    struct TreeNode test_2_node_2 = TreeNode(3);
    struct TreeNode test_2_node_1 = TreeNode(3, &test_2_node_3, &test_2_node_4);
    struct TreeNode test_2_node_0 = TreeNode(1, &test_2_node_1, &test_2_node_2);
    int target_2 = 3;
    struct TreeNode *result_2 = sol.removeLeafNodes(&test_2_node_0, target_2);
    st.push(result_2);
    while (!st.empty())
    {
        struct TreeNode *top_node = st.top();
        st.pop();
        cout << top_node->val << " ";
        if (top_node->left)
            st.push(top_node->left);
        if (top_node->right)
            st.push(top_node->right);
    }
    cout << endl;

    // Test_3
    struct TreeNode test_3_node_3 = TreeNode(2);
    struct TreeNode test_3_node_2 = TreeNode(2, &test_3_node_3, NULL);
    struct TreeNode test_3_node_1 = TreeNode(2, &test_3_node_2, NULL);
    struct TreeNode test_3_node_0 = TreeNode(1, &test_3_node_1, NULL);
    int target_3 = 2;
    struct TreeNode *result_3 = sol.removeLeafNodes(&test_3_node_0, target_3);
    st.push(result_3);
    while (!st.empty())
    {
        struct TreeNode *top_node = st.top();
        st.pop();
        cout << top_node->val << " ";
        if (top_node->left)
            st.push(top_node->left);
        if (top_node->right)
            st.push(top_node->right);
    }
    cout << endl;

    return 0;
}
// Accepted
// 50/50 cases passed (11 ms)
// Your runtime beats 64.37 % of cpp submissions
// Your memory usage beats 83.5 % of cpp submissions (21.1 MB)