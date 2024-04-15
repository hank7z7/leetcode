/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (63.46%)
 * Likes:    7650
 * Dislikes: 126
 * Total Accepted:    775.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 * 
 * Each root-to-leaf path in the tree represents a number.
 * 
 * 
 * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 * 
 * 
 * Return the total sum of all root-to-leaf numbers. Test cases are generated
 * so that the answer will fit in a 32-bit integer.
 * 
 * A leaf node is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3]
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [4,9,0,5,1]
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * 0 <= Node.val <= 9
 * The depth of the tree will not exceed 10.
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
    int sumNumbers(TreeNode* root)
    {
        int result = 0;
        /* BFS */
        queue<pair<TreeNode*, int>> q;
        if (root)
            q.push({ root, 0 });
        while (!q.empty())
        {
            TreeNode* curr     = q.front().first;
            int       curr_sum = q.front().second * 10 + curr->val;
            q.pop();
            if (curr->left)
                q.push({ curr->left, curr_sum });
            if (curr->right)
                q.push({ curr->right, curr_sum });
            if (!curr->left && !curr->right)
                result += curr_sum;
        }

        /* DFS */
        /*
        // Stack for DFS recording (pointer to the node, path sum to the node)
        stack<pair<TreeNode*, int>> st;
        // Initialize the DFS
        if (root)
            st.push({ root, 0 });
        while (!st.empty())
        {
            TreeNode* curr     = st.top().first;
            int       curr_sum = st.top().second * 10 + curr->val;
            st.pop();
            if (curr->left)
                st.push({ curr->left, curr_sum });
            if (curr->right)
                st.push({ curr->right, curr_sum });
            if (!curr->left && !curr->right)
                result += curr_sum;
        }
        */
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct TreeNode test_1_node_2 = TreeNode(2);
    struct TreeNode test_1_node_3 = TreeNode(3);
    struct TreeNode test_1_node_0 = TreeNode(1, &test_1_node_2, &test_1_node_3);
    cout << sol.sumNumbers(&test_1_node_0) << endl;

    // Test_2
    struct TreeNode test_2_node_3 = TreeNode(5);
    struct TreeNode test_2_node_4 = TreeNode(1);
    struct TreeNode test_2_node_1 = TreeNode(9, &test_2_node_3, &test_2_node_4);
    struct TreeNode test_2_node_2 = TreeNode(0);
    struct TreeNode test_2_node_0 = TreeNode(4, &test_2_node_1, &test_2_node_2);
    cout << sol.sumNumbers(&test_2_node_0) << endl;

    return 0;
}
// Accepted
// 108/108 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 31.35 % of cpp submissions (11.1 MB)