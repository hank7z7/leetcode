/*
 * @lc app=leetcode id=2196 lang=cpp
 *
 * [2196] Create Binary Tree From Descriptions
 *
 * https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
 *
 * algorithms
 * Medium (72.67%)
 * Likes:    1118
 * Dislikes: 23
 * Total Accepted:    60.9K
 * Total Submissions: 78.3K
 * Testcase Example:  '[[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]'
 *
 * You are given a 2D integer array descriptions where descriptions[i] =
 * [parenti, childi, isLefti] indicates that parenti is the parent of childi in
 * a binary tree of unique values. Furthermore,
 *
 *
 * If isLefti == 1, then childi is the left child of parenti.
 * If isLefti == 0, then childi is the right child of parenti.
 *
 *
 * Construct the binary tree described by descriptions and return its root.
 *
 * The test cases will be generated such that the binary tree is valid.
 *
 *
 * Example 1:
 *
 *
 * Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
 * Output: [50,20,80,15,17,19]
 * Explanation: The root node is the node with value 50 since it has no parent.
 * The resulting binary tree is shown in the diagram.
 *
 *
 * Example 2:
 *
 *
 * Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
 * Output: [1,2,null,null,3,4]
 * Explanation: The root node is the node with value 1 since it has no parent.
 * The resulting binary tree is shown in the diagram.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= descriptions.length <= 10^4
 * descriptions[i].length == 3
 * 1 <= parenti, childi <= 10^5
 * 0 <= isLefti <= 1
 * The binary tree described by descriptions is valid.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
    : val(0)
    , left(nullptr)
    , right(nullptr)
    {
    }
    TreeNode(int x)
    : val(x)
    , left(nullptr)
    , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x)
    , left(left)
    , right(right)
    {
    }
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        // Maps values to TreeNode pointers
        unordered_map<int, TreeNode*> nodeMap;
        // Stores values which are children in the descriptions
        unordered_set<int> children;

        // Iterate through descriptions to create nodes and set up tree
        // structure
        for (const auto& description : descriptions)
        {
            // Extract parent value, child value, and whether it is a
            // left child (1) or right child (0)
            int  parentValue = description[0];
            int  childValue  = description[1];
            bool isLeft      = description[2];

            // Create parent and child nodes if not already created
            if (nodeMap.count(parentValue) == 0)
            {
                nodeMap[parentValue] = new TreeNode(parentValue);
            }
            if (nodeMap.count(childValue) == 0)
            {
                nodeMap[childValue] = new TreeNode(childValue);
            }

            // Attach child node to parent's left or right branch
            if (isLeft)
            {
                nodeMap[parentValue]->left = nodeMap[childValue];
            }
            else
            {
                nodeMap[parentValue]->right = nodeMap[childValue];
            }

            // Mark child as a child in the set
            children.insert(childValue);
        }

        // Find and return the root node
        for (auto& entry : nodeMap)
        {
            auto& value = entry.first;
            auto& node  = entry.second;
            // Root node found
            if (children.find(value) == children.end())
            {
                return node;
            }
        }

        // Should not occur according to problem statement
        return nullptr;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> descriptions_1
        = { { 20, 15, 1 }, { 20, 17, 0 }, { 50, 20, 1 }, { 50, 80, 0 }, { 80, 19, 1 } };
    TreeNode* res_1 = sol.createBinaryTree(descriptions_1);
    // Test_2
    vector<vector<int>> descriptions_2 = { { 1, 2, 1 }, { 2, 3, 0 }, { 3, 4, 1 } };
    TreeNode*           res_2          = sol.createBinaryTree(descriptions_2);

    return 0;
}
// Accepted
// 85/85 cases passed (653 ms)
// Your runtime beats 86.46 % of cpp submissions
// Your memory usage beats 59.61 % of cpp submissions (276.1 MB)