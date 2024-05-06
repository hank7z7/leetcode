/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
 *
 * https://leetcode.com/problems/remove-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (65.64%)
 * Likes:    1621
 * Dislikes: 46
 * Total Accepted:    100.4K
 * Total Submissions: 141.3K
 * Testcase Example:  '[5,2,13,3,8]'
 *
 * You are given the head of a linked list.
 *
 * Remove every node which has a node with a greater value anywhere to the
 * right side of it.
 *
 * Return the head of the modified linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [5,2,13,3,8]
 * Output: [13,8]
 * Explanation: The nodes that should be removed are 5, 2 and 3.
 * - Node 13 is to the right of node 5.
 * - Node 13 is to the right of node 2.
 * - Node 8 is to the right of node 3.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,1,1,1]
 * Output: [1,1,1,1]
 * Explanation: Every node has value 1, so no nodes are removed.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the given list is in the range [1, 10^5].
 * 1 <= Node.val <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int       val;
    ListNode* next;
    ListNode()
    : val(0)
    , next(nullptr)
    {
    }
    ListNode(int x)
    : val(x)
    , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
    : val(x)
    , next(next)
    {
    }
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
class Solution
{
public:
    ListNode* removeNodes(ListNode* head)
    {
        stack<ListNode*> st;
        ListNode*        curr = head;
        while (curr)
        {
            while (!st.empty() && curr->val > st.top()->val)
                st.pop();
            st.push(curr);
            curr = curr->next;
        }
        ListNode* result = NULL;
        while (!st.empty())
        {
            st.top()->next = result;
            result         = st.top();
            st.pop();
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct ListNode  test_1_node_4 = ListNode(8);
    struct ListNode  test_1_node_3 = ListNode(3, &test_1_node_4);
    struct ListNode  test_1_node_2 = ListNode(13, &test_1_node_3);
    struct ListNode  test_1_node_1 = ListNode(2, &test_1_node_2);
    struct ListNode  test_1_node_0 = ListNode(5, &test_1_node_1);
    struct ListNode* result_1      = sol.removeNodes(&test_1_node_0);
    while (result_1)
    {
        cout << result_1->val << " ";
        result_1 = result_1->next;
    }
    cout << endl;

    return 0;
}
// Accepted
// 32/32 cases passed (294 ms)
// Your runtime beats 30.34 % of cpp submissions
// Your memory usage beats 39.97 % of cpp submissions (167.1 MB)