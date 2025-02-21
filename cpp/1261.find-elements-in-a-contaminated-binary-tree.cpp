/*
 * @lc app=leetcode id=1261 lang=cpp
 *
 * [1261] Find Elements in a Contaminated Binary Tree
 *
 * https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/
 *
 * algorithms
 * Medium (77.51%)
 * Likes:    1157
 * Dislikes: 111
 * Total Accepted:    112.2K
 * Total Submissions: 137.1K
 * Testcase Example:  '["FindElements","find","find"]\n[[[-1,null,-1]],[1],[2]]'
 *
 * Given a binary tree with the following rules:
 *
 *
 * root.val == 0
 * For any treeNode:
 *
 * If treeNode.val has a value x and treeNode.left != null, then
 * treeNode.left.val == 2 * x + 1
 * If treeNode.val has a value x and treeNode.right != null, then
 * treeNode.right.val == 2 * x + 2
 *
 *
 *
 *
 * Now the binary tree is contaminated, which means all treeNode.val have been
 * changed to -1.
 *
 * Implement the FindElements class:
 *
 *
 * FindElements(TreeNode* root) Initializes the object with a contaminated
 * binary tree and recovers it.
 * bool find(int target) Returns true if the target value exists in the
 * recovered binary tree.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["FindElements","find","find"]
 * [[[-1,null,-1]],[1],[2]]
 * Output
 * [null,false,true]
 * Explanation
 * FindElements findElements = new FindElements([-1,null,-1]);
 * findElements.find(1); // return False
 * findElements.find(2); // return True
 *
 * Example 2:
 *
 *
 * Input
 * ["FindElements","find","find","find"]
 * [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
 * Output
 * [null,true,true,false]
 * Explanation
 * FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
 * findElements.find(1); // return True
 * findElements.find(3); // return True
 * findElements.find(5); // return False
 *
 * Example 3:
 *
 *
 * Input
 * ["FindElements","find","find","find","find"]
 * [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
 * Output
 * [null,true,false,false,true]
 * Explanation
 * FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
 * findElements.find(2); // return True
 * findElements.find(3); // return False
 * findElements.find(4); // return False
 * findElements.find(5); // return True
 *
 *
 *
 * Constraints:
 *
 *
 * TreeNode.val == -1
 * The height of the binary tree is less than or equal to 20
 * The total number of nodes is between [1, 10^4]
 * Total calls of find() is between [1, 10^4]
 * 0 <= target <= 10^6
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
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
class FindElements
{
private:
    unordered_set<int> us;

public:
    void traverse(TreeNode* root, int val)
    {
        if (root == nullptr)
            return;
        us.insert(val);
        traverse(root->left, 2 * val + 1);
        traverse(root->right, 2 * val + 2);
    }

    FindElements(TreeNode* root) { traverse(root, 0); }

    bool find(int target) { return us.find(target) != us.end(); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end
int main(int argc, char** argv)
{
    // Test_1
    TreeNode* root_1 = new TreeNode(-1);
    root_1->right = new TreeNode(-1);
    FindElements* obj_1 = new FindElements(root_1);
    cout << obj_1->find(1) << endl;
    cout << obj_1->find(2) << endl;
    delete (root_1->right);
    delete (root_1);
    delete (obj_1);

    return 0;
}
// Accepted
// 31/31 cases passed (11 ms)
// Your runtime beats 58.69 % of cpp submissions
// Your memory usage beats 60.19 % of cpp submissions (34.5 MB)