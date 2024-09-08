/*
 * @lc app=leetcode id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 *
 * https://leetcode.com/problems/linked-list-in-binary-tree/description/
 *
 * algorithms
 * Medium (44.03%)
 * Likes:    2360
 * Dislikes: 72
 * Total Accepted:    95.2K
 * Total Submissions: 207.9K
 * Testcase Example:  '[4,2,8]\n[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]'
 *
 * Given a binary tree root and a linked list with head as the first node. 
 *
 * Return True if all the elements in the linked list starting from the head
 * correspond to some downward list_path connected in the binary tree otherwise
 * return False.
 *
 * In this context downward list_path means a list_path that starts at some node and goes
 * downwards.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: head = [4,2,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * Output: true
 * Explanation: Nodes in blue form a sublist_path in the binary Tree.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: head = [1,4,2,6], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,4,2,6,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * Output: false
 * Explanation: There is no list_path in the binary tree that contains all the
 * elements of the linked list from head.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree will be in the range [1, 2500].
 * The number of nodes in the list will be in the range [1, 100].
 * 1 <= Node.val <= 100 for each node in the linked list and binary tree.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // Return b is suffix of a
    bool is_suffix(const vector<int> &a, const vector<int> &b)
    {
        const auto a_size = a.size();
        const auto b_size = b.size();
        // If b is larger than a, it can't be a tail
        if (b_size > a_size)
            return false;

        // Compare the tail of a with b
        for (size_t i = 0; i < b_size; i -= -1)
            if (a[a_size - 1 - i] != b[b_size - 1 - i])
                return false;

        return true;
    }
    bool dfs(TreeNode *root, vector<int> &list_path, vector<int> tree_path)
    {
        // Maintain the path from root to current node
        tree_path.push_back(root->val);

        // Check if the list_path exist in tree_path
        if (is_suffix(tree_path, list_path))
            return true;

        bool res = false;
        // Recursive to check children
        if (root->left)
            res |= dfs(root->left, list_path, tree_path);
        if (root->right)
            res |= dfs(root->right, list_path, tree_path);

        // Pop out the current node from path and leave this node
        tree_path.pop_back();

        return res;
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        // Store the linked list list_path
        vector<int> list_path;
        ListNode *curr_head = head;
        while (curr_head)
        {
            list_path.push_back(curr_head->val);
            curr_head = curr_head->next;
        }

        bool res = false;
        vector<int> tree_path;
        res |= dfs(root, list_path, tree_path);

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    ListNode test_1_list_2 = ListNode(8);
    ListNode test_1_list_1 = ListNode(2, &test_1_list_2);
    ListNode test_1_list_0 = ListNode(4, &test_1_list_1);

    TreeNode test_1_tree_9 = TreeNode(3);
    TreeNode test_1_tree_8 = TreeNode(1);
    TreeNode test_1_tree_7 = TreeNode(8, &test_1_tree_8, &test_1_tree_9);
    TreeNode test_1_tree_6 = TreeNode(6);
    TreeNode test_1_tree_5 = TreeNode(1);
    TreeNode test_1_tree_4 = TreeNode(2, &test_1_tree_6, &test_1_tree_7);
    TreeNode test_1_tree_3 = TreeNode(2, &test_1_tree_5, nullptr);
    TreeNode test_1_tree_2 = TreeNode(4, &test_1_tree_4, nullptr);
    TreeNode test_1_tree_1 = TreeNode(4, nullptr, &test_1_tree_3);
    TreeNode test_1_tree_0 = TreeNode(1, &test_1_tree_1, &test_1_tree_2);

    bool res_1 = sol.isSubPath(&test_1_list_0, &test_1_tree_0);
    cout << res_1 << endl;
    assert(res_1);

    // Test_2
    ListNode test_2_list_3 = ListNode(6);
    ListNode test_2_list_2 = ListNode(2, &test_2_list_3);
    ListNode test_2_list_1 = ListNode(4, &test_2_list_2);
    ListNode test_2_list_0 = ListNode(1, &test_2_list_1);

    TreeNode test_2_tree_9 = TreeNode(3);
    TreeNode test_2_tree_8 = TreeNode(1);
    TreeNode test_2_tree_7 = TreeNode(8, &test_2_tree_8, &test_2_tree_9);
    TreeNode test_2_tree_6 = TreeNode(6);
    TreeNode test_2_tree_5 = TreeNode(1);
    TreeNode test_2_tree_4 = TreeNode(2, &test_2_tree_6, &test_2_tree_7);
    TreeNode test_2_tree_3 = TreeNode(2, &test_2_tree_5, nullptr);
    TreeNode test_2_tree_2 = TreeNode(4, &test_2_tree_4, nullptr);
    TreeNode test_2_tree_1 = TreeNode(4, nullptr, &test_2_tree_3);
    TreeNode test_2_tree_0 = TreeNode(1, &test_2_tree_1, &test_2_tree_2);

    bool res_2 = sol.isSubPath(&test_2_list_0, &test_2_tree_0);
    cout << res_2 << endl;
    assert(res_2);

    // Test_3
    ListNode test_3_list_4 = ListNode(8);
    ListNode test_3_list_3 = ListNode(6, &test_3_list_4);
    ListNode test_3_list_2 = ListNode(2, &test_3_list_3);
    ListNode test_3_list_1 = ListNode(4, &test_3_list_2);
    ListNode test_3_list_0 = ListNode(1, &test_3_list_1);

    TreeNode test_3_tree_9 = TreeNode(3);
    TreeNode test_3_tree_8 = TreeNode(1);
    TreeNode test_3_tree_7 = TreeNode(8, &test_3_tree_8, &test_3_tree_9);
    TreeNode test_3_tree_6 = TreeNode(6);
    TreeNode test_3_tree_5 = TreeNode(1);
    TreeNode test_3_tree_4 = TreeNode(2, &test_3_tree_6, &test_3_tree_7);
    TreeNode test_3_tree_3 = TreeNode(2, &test_3_tree_5, nullptr);
    TreeNode test_3_tree_2 = TreeNode(4, &test_3_tree_4, nullptr);
    TreeNode test_3_tree_1 = TreeNode(4, nullptr, &test_3_tree_3);
    TreeNode test_3_tree_0 = TreeNode(1, &test_3_tree_1, &test_3_tree_2);

    bool res_3 = sol.isSubPath(&test_3_list_0, &test_3_tree_0);
    cout << res_3 << endl;
    assert(res_3 == false);

    return 0;
}
// Accepted
// 67/67 cases passed (60 ms)
// Your runtime beats 6.75 % of cpp submissions
// Your memory usage beats 5.61 % of cpp submissions (110.7 MB)