/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (42.27%)
 * Likes:    17539
 * Dislikes: 730
 * Total Accepted:    2.3M
 * Total Submissions: 5.4M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 * Follow up: Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        struct ListNode* prev = NULL;
        struct ListNode* curr = head;
        struct ListNode* tail = head;
        // n = 1 : head = tail
        // n = 2 : head->tail
        for (int i = 1; i < n; i++)
            tail = tail->next;

        // Find the nth from end by moving tail to end
        while (tail->next != NULL)
        {
            tail = tail->next;
            prev = curr;
            curr = curr->next;
        }

        // Remove curr
        if (prev)
        {
            // To be removed is not the first node
            prev->next = curr->next;
        }
        else
        {
            // Remove the first node
            head = head->next;
        }

        return head;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      n;
    // Test_1
    n                           = 2;
    struct ListNode  ll1_node_5 = ListNode(5);
    struct ListNode  ll1_node_4 = ListNode(4, &ll1_node_5);
    struct ListNode  ll1_node_3 = ListNode(3, &ll1_node_4);
    struct ListNode  ll1_node_2 = ListNode(2, &ll1_node_3);
    struct ListNode  ll1_node_1 = ListNode(1, &ll1_node_2);
    struct ListNode* ret_1      = sol.removeNthFromEnd(&ll1_node_1, n);
    while (ret_1 != NULL)
    {
        cout << ret_1->val << " ";
        ret_1 = ret_1->next;
    }
    cout << endl;

    // Test_2
    n                           = 1;
    struct ListNode  ll2_node_1 = ListNode(1);
    struct ListNode* ret_2      = sol.removeNthFromEnd(&ll2_node_1, n);
    while (ret_2 != NULL)
    {
        cout << ret_2->val << " ";
        ret_2 = ret_2->next;
    }
    cout << endl;

    // Test_3
    n                           = 2;
    struct ListNode  ll3_node_2 = ListNode(2);
    struct ListNode  ll3_node_1 = ListNode(1, &ll3_node_2);
    struct ListNode* ret_3      = sol.removeNthFromEnd(&ll3_node_1, n);
    while (ret_3 != NULL)
    {
        cout << ret_3->val << " ";
        ret_3 = ret_3->next;
    }
    cout << endl;

    return 0;
}
// Accepted
// 208/208 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 66.71 % of cpp submissions (13.2 MB)