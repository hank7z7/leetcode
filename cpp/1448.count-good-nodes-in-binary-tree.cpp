/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 *
 * https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
 *
 * algorithms
 * Medium (73.10%)
 * Likes:    5692
 * Dislikes: 158
 * Total Accepted:    474.8K
 * Total Submissions: 650K
 * Testcase Example:  '[3,1,4,3,null,1,5]'
 *
 * Given a binary tree root, a node X in the tree is named good if in the path
 * from root to X there are no nodes with a value greater than X.
 * 
 * Return the number of good nodes in the binary tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [3,1,4,3,null,1,5]
 * Output: 4
 * Explanation: Nodes in blue are good.
 * Root Node (3) is always a good node.
 * Node 4 -> (3,4) is the maximum value in the path starting from the root.
 * Node 5 -> (3,4,5) is the maximum value in the path
 * Node 3 -> (3,1,3) is the maximum value in the path.
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [3,3,null,4,2]
 * Output: 3
 * Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than
 * it.
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: 1
 * Explanation: Root is considered as good.
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the binary tree is in the range [1, 10^5].
 * Each node's value is between [-10^4, 10^4].
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
private:
    int DFS(TreeNode* head, int max_val)
    {
        int count = 0;
        if (head)
        {
            if (head->val >= max_val)
                count++;
            count += DFS(head->left, max(max_val, head->val));
            count += DFS(head->right, max(max_val, head->val));
        }
        return count;
    }

public:
    int goodNodes(TreeNode* root)
    {
        int result = 0;
        result     = DFS(root, INT_MIN);
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct TreeNode test_1_node_3 = TreeNode(3);
    struct TreeNode test_1_node_4 = TreeNode(1);
    struct TreeNode test_1_node_5 = TreeNode(5);
    struct TreeNode test_1_node_1 = TreeNode(1, &test_1_node_3, NULL);
    struct TreeNode test_1_node_2 = TreeNode(4, &test_1_node_4, &test_1_node_5);
    struct TreeNode test_1_node_0 = TreeNode(3, &test_1_node_1, &test_1_node_2);
    cout << sol.goodNodes(&test_1_node_0) << endl;

    // Test_2
    struct TreeNode test_2_node_3 = TreeNode(2);
    struct TreeNode test_2_node_2 = TreeNode(4);
    struct TreeNode test_2_node_1 = TreeNode(3, &test_2_node_2, &test_2_node_3);
    struct TreeNode test_2_node_0 = TreeNode(3, &test_2_node_1, NULL);
    cout << sol.goodNodes(&test_2_node_0) << endl;

    return 0;
}
// Accepted
// 63/63 cases passed (110 ms)
// Your runtime beats 13.29 % of cpp submissions
// Your memory usage beats 11.5 % of cpp submissions (85.8 MB)