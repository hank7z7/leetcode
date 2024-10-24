/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
 *
 * https://leetcode.com/problems/flip-equivalent-binary-trees/description/
 *
 * algorithms
 * Medium (67.06%)
 * Likes:    2539
 * Dislikes: 105
 * Total Accepted:    190.3K
 * Total Submissions: 278.8K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]'
 *
 * For a binary tree T, we can define a flip operation as follows: choose any
 * node, and swap the left and right child subtrees.
 * 
 * A binary tree X is flip equivalent to a binary tree Y if and only if we can
 * make X equal to Y after some number of flip operations.
 * 
 * Given the roots of two binary trees root1 and root2, return true if the two
 * trees are flip equivalent or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 =
 * [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * Output: true
 * Explanation: We flipped at nodes with values 1, 3, and 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root1 = [], root2 = []
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root1 = [], root2 = [1]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each tree is in the range [0, 100].
 * Each tree will have unique node values in the range [0, 99].
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;
        // cout << root1->val << " " << root2->val << endl;
        if (root1 && root2 && (root1->val == root2->val)
            && ((flipEquiv(root1->left, root2->right)
                     && flipEquiv(root1->right, root2->left)
                 || (flipEquiv(root1->left, root2->left)
                     && flipEquiv(root1->right, root2->right)))))
            return true;
        return false;
    }
};

// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    TreeNode test_1_node_10 = TreeNode(8);
    TreeNode test_1_node_9 = TreeNode(7);
    TreeNode test_1_node_5 = TreeNode(6);
    TreeNode test_1_node_4 = TreeNode(5, &test_1_node_9, &test_1_node_10);
    TreeNode test_1_node_3 = TreeNode(4);
    TreeNode test_1_node_2 = TreeNode(3, &test_1_node_5, NULL);
    TreeNode test_1_node_1 = TreeNode(2, &test_1_node_3, &test_1_node_4);
    TreeNode test_1_node_0 = TreeNode(1, &test_1_node_1, &test_1_node_2);
    TreeNode test_2_node_14 = TreeNode(7);
    TreeNode test_2_node_13 = TreeNode(8);
    TreeNode test_2_node_6 = TreeNode(5, &test_2_node_13, &test_2_node_14);
    TreeNode test_2_node_5 = TreeNode(4);
    TreeNode test_2_node_4 = TreeNode(6);
    TreeNode test_2_node_2 = TreeNode(2, &test_2_node_5, &test_2_node_6);
    TreeNode test_2_node_1 = TreeNode(3, NULL, &test_2_node_4);
    TreeNode test_2_node_0 = TreeNode(1, &test_2_node_1, &test_2_node_2);
    bool res_1 = sol.flipEquiv(&test_1_node_0, &test_2_node_0);
    cout << res_1 << endl;
    assert(res_1 == true);

    // test_2
    bool res_2 = sol.flipEquiv(NULL, NULL);
    cout << res_2 << endl;
    assert(res_2 == true);
    return 0;
}
// Accepted
// 77/77 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 61.52 % of cpp submissions (14.5 MB)