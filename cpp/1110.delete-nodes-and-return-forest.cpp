/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 *
 * https://leetcode.com/problems/delete-nodes-and-return-forest/description/
 *
 * algorithms
 * Medium (69.20%)
 * Likes:    4290
 * Dislikes: 125
 * Total Accepted:    281.1K
 * Total Submissions: 396.6K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n[3,5]'
 *
 * Given the root of a binary tree, each node in the tree has a distinct
 * value.
 * 
 * After deleting all nodes with a value in to_delete, we are left with a
 * forest (a disjoint union of trees).
 * 
 * Return the roots of the trees in the remaining forest. You may return the
 * result in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
 * Output: [[1,2,null,4],[6],[7]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,4,null,3], to_delete = [3]
 * Output: [[1,2,4]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is at most 1000.
 * Each node has a distinct value between 1 and 1000.
 * to_delete.length <= 1000
 * to_delete contains distinct values between 1 and 1000.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        if (!root)
        {
            return {};
        }

        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*>  forest;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty())
        {
            TreeNode* currentNode = nodesQueue.front();
            nodesQueue.pop();

            if (currentNode->left)
            {
                nodesQueue.push(currentNode->left);
                // Disconnect the left child if it needs to be deleted
                if (toDeleteSet.find(currentNode->left->val) != toDeleteSet.end())
                {
                    currentNode->left = nullptr;
                }
            }

            if (currentNode->right)
            {
                nodesQueue.push(currentNode->right);
                // Disconnect the right child if it needs to be deleted
                if (toDeleteSet.find(currentNode->right->val) != toDeleteSet.end())
                {
                    currentNode->right = nullptr;
                }
            }

            // If the current node needs to be deleted, add its non-null
            // children to the forest
            if (toDeleteSet.find(currentNode->val) != toDeleteSet.end())
            {
                if (currentNode->left)
                {
                    forest.push_back(currentNode->left);
                }
                if (currentNode->right)
                {
                    forest.push_back(currentNode->right);
                }
            }
        }

        // Ensure the root is added to the forest if it is not to be deleted
        if (toDeleteSet.find(root->val) == toDeleteSet.end())
        {
            forest.push_back(root);
        }

        return forest;
    }
};
// @lc code=end
void print_tree_postorder(TreeNode* root)
{
    if (root)
    {
        cout << root->val << " ";
        print_tree_postorder(root->left);
        print_tree_postorder(root->right);
    }
}

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    TreeNode          test_1_node_6 = TreeNode(7);
    TreeNode          test_1_node_5 = TreeNode(6);
    TreeNode          test_1_node_4 = TreeNode(5);
    TreeNode          test_1_node_3 = TreeNode(4);
    TreeNode          test_1_node_2 = TreeNode(3, &test_1_node_5, &test_1_node_6);
    TreeNode          test_1_node_1 = TreeNode(2, &test_1_node_3, &test_1_node_4);
    TreeNode          test_1_node_0 = TreeNode(7, &test_1_node_1, &test_1_node_2);
    vector<int>       to_delete_1   = { 3, 5 };
    vector<TreeNode*> res_1         = sol.delNodes(&test_1_node_0, to_delete_1);
    for (auto node : res_1)
    {
        print_tree_postorder(node);
        cout << endl;
    }
    cout << endl;

    // Test_2
    TreeNode          test_2_node_4 = TreeNode(3);
    TreeNode          test_2_node_2 = TreeNode(4, NULL, NULL);
    TreeNode          test_2_node_1 = TreeNode(2, NULL, &test_2_node_4);
    TreeNode          test_2_node_0 = TreeNode(1, &test_2_node_1, &test_2_node_2);
    vector<int>       to_delete_2   = { 3 };
    vector<TreeNode*> res_2         = sol.delNodes(&test_2_node_0, to_delete_2);
    for (auto node : res_2)
    {
        print_tree_postorder(node);
        cout << endl;
    }
    cout << endl;

    return 0;
}
// Accepted
// 111/111 cases passed (23 ms)
// Your runtime beats 18.33 % of cpp submissions
// Your memory usage beats 20.14 % of cpp submissions (27.3 MB)