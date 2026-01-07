/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 *
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 *
 * algorithms
 * Medium (48.01%)
 * Likes:    3285
 * Dislikes: 112
 * Total Accepted:    174.1K
 * Total Submissions: 340.2K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a binary tree, split the binary tree into two subtrees by
 * removing one edge such that the product of the sums of the subtrees is
 * maximized.
 * 
 * Return the maximum product of the sums of the two subtrees. Since the answer
 * may be too large, return it modulo 10^9 + 7.
 * 
 * Note that you need to maximize the answer before taking the mod and not
 * after taking it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: 110
 * Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
 * Their product is 110 (11*10)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,2,3,4,null,null,5,6]
 * Output: 90
 * Explanation: Remove the red edge and get 2 binary trees with sum 15 and
 * 6.Their product is 90 (15*6)
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 5 * 10^4].
 * 1 <= Node.val <= 10^4
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
    vector<long long> sub_sum;
    long long subtree_sum(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        else
        {
            long long sum = (long long)root->val + subtree_sum(root->left) + subtree_sum(root->right);
            sub_sum.push_back(sum);
            return sum;
        }
    }
    int maxProduct(TreeNode* root) {
        sub_sum.clear();
        long long total = subtree_sum(root);
        long long max_product = 0;
        for(auto& s : sub_sum)
        {
            long long curr_product = s * (total - s);
            max_product = max(max_product, curr_product);
        }

        return (int)(max_product %  1000000007);
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;

    return 0;
}
// Accepted
// 54/54 cases passed (4 ms)
// Your runtime beats 65.02 % of cpp submissions
// Your memory usage beats 15.96 % of cpp submissions (83.4 MB)