/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 *
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
 *
 * algorithms
 * Medium (51.08%)
 * Likes:    1751
 * Dislikes: 250
 * Total Accepted:    86.2K
 * Total Submissions: 164K
 * Testcase Example:  '[0,1,2,3,4,3,4]'
 *
 * You are given the root of a binary tree where each node has a value in the
 * range [0, 25] representing the letters 'a' to 'z'.
 * 
 * Return the lexicographically smallest string that starts at a leaf of this
 * tree and ends at the root.
 * 
 * As a reminder, any shorter prefix of a string is lexicographically
 * smaller.
 * 
 * 
 * For example, "ab" is lexicographically smaller than "aba".
 * 
 * 
 * A leaf of a node is a node that has no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [0,1,2,3,4,3,4]
 * Output: "dba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [25,1,3,1,3,0,2]
 * Output: "adz"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [2,2,1,null,1,0,null,0]
 * Output: "abc"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 8500].
 * 0 <= Node.val <= 25
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
    string ans = "";
    void   dfs(TreeNode* root, string curr = "")
    {
        if (!root)
            return;
        curr.insert(curr.begin(), 'a' + root->val);
        if (!root->left && !root->right)
        {
            if (ans.empty())
                ans = curr;
            else
                ans = min(ans, curr);
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
        curr.erase(curr.begin());
    }

    string smallestFromLeaf(TreeNode* root)
    {
        dfs(root);
        return ans;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct TreeNode test_1_node_6 = TreeNode(4);
    struct TreeNode test_1_node_5 = TreeNode(3);
    struct TreeNode test_1_node_4 = TreeNode(4);
    struct TreeNode test_1_node_3 = TreeNode(3);
    struct TreeNode test_1_node_2 = TreeNode(2, &test_1_node_5, &test_1_node_6);
    struct TreeNode test_1_node_1 = TreeNode(1, &test_1_node_3, &test_1_node_4);
    struct TreeNode test_1_node_0 = TreeNode(0, &test_1_node_1, &test_1_node_2);
    cout << sol.smallestFromLeaf(&test_1_node_0) << endl;

    // Test_2
    struct TreeNode test_2_node_6 = TreeNode(2);
    struct TreeNode test_2_node_5 = TreeNode(0);
    struct TreeNode test_2_node_4 = TreeNode(3);
    struct TreeNode test_2_node_3 = TreeNode(1);
    struct TreeNode test_2_node_2 = TreeNode(3, &test_2_node_5, &test_2_node_6);
    struct TreeNode test_2_node_1 = TreeNode(1, &test_2_node_3, &test_2_node_4);
    struct TreeNode test_2_node_0 = TreeNode(25, &test_2_node_1, &test_2_node_2);
    cout << sol.smallestFromLeaf(&test_2_node_0) << endl;

    // Test_3
    struct TreeNode test_3_node_5 = TreeNode(0);
    struct TreeNode test_3_node_4 = TreeNode(0);
    struct TreeNode test_3_node_3 = TreeNode(1, &test_3_node_5, NULL);
    struct TreeNode test_3_node_2 = TreeNode(1, &test_3_node_4, NULL);
    struct TreeNode test_3_node_1 = TreeNode(2, NULL, &test_3_node_3);
    struct TreeNode test_3_node_0 = TreeNode(2, &test_3_node_1, &test_3_node_2);
    cout << sol.smallestFromLeaf(&test_3_node_0) << endl;

    return 0;
}
// Accepted
// 70/70 cases passed (8 ms)
// Your runtime beats 65.38 % of cpp submissions
// Your memory usage beats 67.1 % of cpp submissions (20.4 MB)