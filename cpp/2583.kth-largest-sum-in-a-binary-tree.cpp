/*
 * @lc app=leetcode id=2583 lang=cpp
 *
 * [2583] Kth Largest Sum in a Binary Tree
 *
 * https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (47.76%)
 * Likes:    630
 * Dislikes: 21
 * Total Accepted:    57.5K
 * Total Submissions: 111.2K
 * Testcase Example:  '[5,8,9,2,1,3,7,4,6]\n2'
 *
 * You are given the root of a binary tree and a positive integer k.
 *
 * The level sum in the tree is the sum of the values of the nodes that are on
 * the same level.
 *
 * Return the k^th largest level sum in the tree (not necessarily distinct). If
 * there are fewer than k levels in the tree, return -1.
 *
 * Note that two nodes are on the same level if they have the same distance
 * from the root.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,8,9,2,1,3,7,4,6], k = 2
 * Output: 13
 * Explanation: The level sums are the following:
 * - Level 1: 5.
 * - Level 2: 8 + 9 = 17.
 * - Level 3: 2 + 1 + 3 + 7 = 13.
 * - Level 4: 4 + 6 = 10.
 * The 2^nd largest level sum is 13.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,null,3], k = 1
 * Output: 3
 * Explanation: The largest level sum is 3.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is n.
 * 2 <= n <= 10^5
 * 1 <= Node.val <= 10^6
 * 1 <= k <= n
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
private:
    int max_level = 0;
    vector<long long> level_sum;
    void traverse(TreeNode* root, int level)
    {
        if (root)
        {
            max_level = max(max_level, level);
            level_sum[level] += (long long) root->val;
            traverse(root->left, level + 1);
            traverse(root->right, level + 1);
        }
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        level_sum = vector<long long>(100000, 0);
        traverse(root, 0);
        cout << max_level;
        if (k > (max_level + 1))
            return -1;
        sort(level_sum.begin(),
             level_sum.begin() + max_level + 1,
             greater<long long>());
        return level_sum[k - 1];
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1

    return 0;
}
// Accepted
// 45/45 cases passed (23 ms)
// Your runtime beats 97.56 % of cpp submissions
// Your memory usage beats 5.08 % of cpp submissions (195.8 MB)