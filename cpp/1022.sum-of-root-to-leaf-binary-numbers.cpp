/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 *
 * https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
 *
 * algorithms
 * Easy (73.66%)
 * Likes:    3616
 * Dislikes: 203
 * Total Accepted:    291.6K
 * Total Submissions: 388.6K
 * Testcase Example:  '[1,0,1,0,1,0,1]'
 *
 * You are given the root of a binary tree where each node has a value 0 or 1.
 * Each root-to-leaf path represents a binary number starting with the most
 * significant bit.
 * 
 * 
 * For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent
 * 01101 in binary, which is 13.
 * 
 * 
 * For all leaves in the tree, consider the numbers represented by the path
 * from the root to that leaf. Return the sum of these numbers.
 * 
 * The test cases are generated so that the answer fits in a 32-bits
 * integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,0,1,0,1,0,1]
 * Output: 22
 * Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val is 0 or 1.
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
class Solution {
public:
    void dfs(TreeNode* node, int num, int& res) {
        if (!node) {
            return;
        }
        num = (num << 1) | node->val;
        if (!node->left && !node->right) {
            res += num;
            return;
        }
        dfs(node->left, num, res);
        dfs(node->right, num, res);
    }
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv) {
    Solution sol;
    // Test_1
    TreeNode* root_1 = new TreeNode(1);
    root_1->left = new TreeNode(0);
    root_1->right = new TreeNode(1);
    root_1->left->left = new TreeNode(0);
    root_1->left->right = new TreeNode(1);
    root_1->right->left = new TreeNode(0);
    root_1->right->right = new TreeNode(1);
    int res = sol.sumRootToLeaf(root_1);
    cout << res << endl;
    assert(res == 22);
    delete root_1->left->left;
    delete root_1->left->right;
    delete root_1->right->left;
    delete root_1->right->right;
    delete root_1->left;
    delete root_1->right;
    delete root_1;

    // Test_2
    TreeNode* root_2 = new TreeNode(0);
    res = sol.sumRootToLeaf(root_2);
    cout << res << endl;
    assert(res == 0);
    delete root_2;

    return 0;
}
// Accepted
// 63/63 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 75.77 % of cpp submissions (17.3 MB)