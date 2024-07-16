/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
 *
 * https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
 *
 * algorithms
 * Medium (48.93%)
 * Likes:    2445
 * Dislikes: 128
 * Total Accepted:    111.9K
 * Total Submissions: 222.8K
 * Testcase Example:  '[5,1,2,3,null,6,4]\n3\n6'
 *
 * You are given the root of a binary tree with n nodes. Each node is uniquely
 * assigned a value from 1 to n. You are also given an integer startValue
 * representing the value of the start node s, and a different integer
 * destValue representing the value of the destination node t.
 * 
 * Find the shortest path starting from node s and ending at node t. Generate
 * step-by-step directions of such path as a string consisting of only the
 * uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific
 * direction:
 * 
 * 
 * 'L' means to go from a node to its left child node.
 * 'R' means to go from a node to its right child node.
 * 'U' means to go from a node to its parent node.
 * 
 * 
 * Return the step-by-step directions of the shortest path from node s to node
 * t.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
 * Output: "UURL"
 * Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,1], startValue = 2, destValue = 1
 * Output: "L"
 * Explanation: The shortest path is: 2 → 1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is n.
 * 2 <= n <= 10^5
 * 1 <= Node.val <= n
 * All the values in the tree are unique.
 * 1 <= startValue, destValue <= n
 * startValue != destValue
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
    bool DFS(TreeNode* n, int val, string &s_path, string &d_path) {
        if (n->val == val)
            return true;
        if (n->left && DFS(n->left, val, s_path, d_path))
            s_path.push_back('L');
        else if (n->right && DFS(n->right, val, s_path, d_path))
            s_path.push_back('R');
        return !s_path.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        stack<pair<TreeNode*, string>> st;
        string                         path_to_start = "";
        string                         path_to_dest  = "";
        DFS(root, startValue, path_to_start, path_to_dest);
        DFS(root, destValue, path_to_dest, path_to_dest);

        while (!path_to_start.empty() && !path_to_dest.empty() && path_to_start.back() == path_to_dest.back()) {
        path_to_start.pop_back();
        path_to_dest.pop_back();
    }
    return string(path_to_start.size(), 'U') + string(rbegin(path_to_dest), rend(path_to_dest));
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    TreeNode test_1_node_6 = TreeNode(4);
    TreeNode test_1_node_5 = TreeNode(6);
    TreeNode test_1_node_3 = TreeNode(3);
    TreeNode test_1_node_2 = TreeNode(2, &test_1_node_5, &test_1_node_6);
    TreeNode test_1_node_1 = TreeNode(1, &test_1_node_3, NULL);
    TreeNode test_1_node_0 = TreeNode(5, &test_1_node_1, &test_1_node_2);
    int      start_1       = 3;
    int      dest_1        = 6;
    string   res_1         = sol.getDirections(&test_1_node_0, start_1, dest_1);
    cout << res_1 << endl;
    assert(res_1 == "UURL");

    // Test_2
    TreeNode test_2_node_1 = TreeNode(1);
    TreeNode test_2_node_0 = TreeNode(2, &test_2_node_1, NULL);
    int      start_2       = 2;
    int      dest_2        = 1;
    string   res_2         = sol.getDirections(&test_2_node_0, start_2, dest_2);
    cout << res_2 << endl;
    assert(res_2 == "L");

    return 0;
}
// Testcase
// [5,8,3,1,null,4,7,6,null,null,null,null,null,null,2]
// 4
// 3
// Answer
// "UUR"
// Expected Answer
// "U"