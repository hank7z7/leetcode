/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (57.80%)
 * Likes:    5169
 * Dislikes: 292
 * Total Accepted:    540.3K
 * Total Submissions: 917.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the sum of all left leaves.
 * 
 * A leaf is a node with no children. A left leaf is a leaf that is the left
 * child of another node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 24
 * Explanation: There are two left leaves in the binary tree, with values 9 and
 * 15 respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * -1000 <= Node.val <= 1000
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        int count = 0;
        // DFS stack (pointer, is left leave)
        stack<pair<TreeNode *, bool>> st;
        if (root)
            st.push({root, false});
        // Iterative DFS
        while (!st.empty())
        {
            TreeNode *top_node = st.top().first;
            bool is_left = st.top().second;
            st.pop();
            if (top_node->left)
                st.push({top_node->left, true});
            if (top_node->right)
                st.push({top_node->right, false});
            if (!top_node->left && !top_node->right && is_left)
                count += top_node->val;
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    struct TreeNode test_1_node_4 = TreeNode(7);
    struct TreeNode test_1_node_3 = TreeNode(15);
    struct TreeNode test_1_node_2 = TreeNode(20, &test_1_node_3, &test_1_node_4);
    struct TreeNode test_1_node_1 = TreeNode(9);
    struct TreeNode test_1_node_0 = TreeNode(3, &test_1_node_1, &test_1_node_2);
    cout << sol.sumOfLeftLeaves(&test_1_node_0) << endl;

    // Test_2
    struct TreeNode test_2_node_0 = TreeNode(1);
    cout << sol.sumOfLeftLeaves(&test_2_node_0) << endl;

    return 0;
}
// Accepted
// 100/100 cases passed (8 ms)
// Your runtime beats 8.78 % of cpp submissions
// Your memory usage beats 15.62 % of cpp submissions (14.8 MB)