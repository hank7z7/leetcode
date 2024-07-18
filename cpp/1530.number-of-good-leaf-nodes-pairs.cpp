/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
 *
 * https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
 *
 * algorithms
 * Medium (63.67%)
 * Likes:    2174
 * Dislikes: 91
 * Total Accepted:    109.4K
 * Total Submissions: 156.4K
 * Testcase Example:  '[1,2,3,null,4]\n3'
 *
 * You are given the root of a binary tree and an integer distance. A pair of
 * two different leaf nodes of a binary tree is said to be good if the length
 * of the shortest path between them is less than or equal to distance.
 * 
 * Return the number of good leaf node pairs in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,4], distance = 3
 * Output: 1
 * Explanation: The leaf nodes of the tree are 3 and 4 and the length of the
 * shortest path between them is 3. This is the only good pair.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3,4,5,6,7], distance = 3
 * Output: 2
 * Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The
 * pair [4,6] is not good because the length of ther shortest path between them
 * is 4.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
 * Output: 1
 * Explanation: The only good pair is [2,5].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 2^10].
 * 1 <= Node.val <= 100
 * 1 <= distance <= 10
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
    // Return vector containing available distances from the current node
    vector<int> dfs(TreeNode *root, int distance, int &count)
    {
        // Distance to NULL is 0
        if (!root)
            return {0};

        // Distance to this leaf is 1
        if (!root->left && !root->right)
            return {1};

        vector<int> left = dfs(root->left, distance, count);
        vector<int> right = dfs(root->right, distance, count);

        for (int x : left)
        {
            for (int y : right)
            {
                if (x > 0 && y > 0)
                {
                    if (x + y <= distance)
                        count++;
                }
            }
        }

        vector<int> res;
        for (int x : left)
        {
            if (x > 0 && x < distance)
            {
                res.push_back(x + 1);
            }
        }

        for (int x : right)
        {
            if (x > 0 && x < distance)
            {
                res.push_back(x + 1);
            }
        }

        return res;
    }
    int countPairs(TreeNode *root, int distance)
    {
        int res = 0;
        dfs(root, distance, res);
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    TreeNode test_1_node_4 = TreeNode(4);
    TreeNode test_1_node_3 = TreeNode(3);
    TreeNode test_1_node_2 = TreeNode(2, NULL, &test_1_node_4);
    TreeNode test_1_node_1 = TreeNode(1, &test_1_node_2, &test_1_node_3);
    int distance_1 = 3;
    int res_1 = sol.countPairs(&test_1_node_1, distance_1);
    cout << res_1 << endl;
    assert(res_1 == 1);

    // Test_2
    TreeNode test_2_node_7 = TreeNode(7);
    TreeNode test_2_node_6 = TreeNode(6);
    TreeNode test_2_node_5 = TreeNode(5);
    TreeNode test_2_node_4 = TreeNode(4);
    TreeNode test_2_node_3 = TreeNode(3, &test_2_node_6, &test_2_node_7);
    TreeNode test_2_node_2 = TreeNode(2, &test_2_node_4, &test_2_node_5);
    TreeNode test_2_node_1 = TreeNode(1, &test_2_node_2, &test_2_node_3);
    int distance_2 = 3;
    int res_2 = sol.countPairs(&test_2_node_1, distance_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    return 0;
}
// Accepted
// 113/113 cases passed (40 ms)
// Your runtime beats 84.6 % of cpp submissions
// Your memory usage beats 52.54 % of cpp submissions (34.7 MB)