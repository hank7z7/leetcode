/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 */
#include <bits/stdc++.h>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double>   result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            long sum  = 0;
            int  size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* tmp = q.front();
                sum += tmp->val;
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            result.push_back((double) sum / size);
        }
        return result;
    }
};

// @lc code=end

int main() { return 0; }

// Accepted
// 66/66 cases passed (22 ms)
// Your runtime beats 65.88 % of cpp submissions
// Your memory usage beats 32.32 % of cpp submissions (22.5 MB)
