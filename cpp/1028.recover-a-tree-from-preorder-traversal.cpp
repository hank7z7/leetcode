/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
 *
 * https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Hard (75.34%)
 * Likes:    1899
 * Dislikes: 56
 * Total Accepted:    86.8K
 * Total Submissions: 109.1K
 * Testcase Example:  '"1-2--3--4-5--6--7"'
 *
 * We run a preorder depth-first search (DFS) on the root of a binary tree.
 *
 * At each node in this traversal, we output D dashes (where D is the depth of
 * this node), then we output the value of this node.  If the depth of a node
 * is D, the depth of its immediate child is D + 1.  The depth of the root node
 * is 0.
 *
 * If a node has only one child, that child is guaranteed to be the left
 * child.
 *
 * Given the output traversal of this traversal, recover the tree and return
 * its root.
 *
 *
 * Example 1:
 *
 *
 * Input: traversal = "1-2--3--4-5--6--7"
 * Output: [1,2,5,3,4,6,7]
 *
 *
 * Example 2:
 *
 *
 * Input: traversal = "1-2--3---4-5--6---7"
 * Output: [1,2,5,3,null,6,null,4,null,7]
 *
 *
 * Example 3:
 *
 *
 * Input: traversal = "1-401--349---90--88"
 * Output: [1,401,null,349,88,90]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the original tree is in the range [1, 1000].
 * 1 <= Node.val <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
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
    TreeNode *recoverFromPreorder(string traversal)
    {
        stack<TreeNode *> stack;
        const int n = (int)traversal.length();
        int index = 0;
        TreeNode *res;
        while (index < n)
        {
            // Count the number of dashes
            int depth = 0;
            while (index < n && traversal[index] == '-')
            {
                depth++;
                index++;
            }

            // Extract the node value
            int value = 0;
            while (index < n && isdigit(traversal[index]))
            {
                value = value * 10 + (traversal[index] - '0');
                index++;
            }

            // Create the current node
            TreeNode *node = new TreeNode(value);

            // Adjust the stack to the correct depth
            while (stack.size() > depth)
            {
                stack.pop();
            }

            // Attach the node to the parent
            if (!stack.empty())
            {
                if (stack.top()->left == nullptr)
                {
                    stack.top()->left = node;
                }
                else
                {
                    stack.top()->right = node;
                }
            }

            // Record the root
            if (stack.empty())
                res = node;
            // Push the current node onto the stack
            stack.push(node);
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string traversal_1 = "1-2--3---4-5--6---7";
    TreeNode *root_1 = sol.recoverFromPreorder(traversal_1);

    return 0;
}
// Accepted
// 105/105 cases passed (4 ms)
// Your runtime beats 50.33 % of cpp submissions
// Your memory usage beats 93.87 % of cpp submissions (20.7 MB)