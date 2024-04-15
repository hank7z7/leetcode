/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (47.55%)
 * Likes:    11354
 * Dislikes: 583
 * Total Accepted:    835.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 *
 *
 *
 * Follow up: Could you do it in one pass?
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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        struct ListNode* left_node   = NULL;
        struct ListNode* right_node  = NULL;
        struct ListNode* prefix_node = NULL;
        struct ListNode* suffix_node = NULL;
        struct ListNode* prev_node   = NULL;
        struct ListNode* curr_node   = head;
        int              node_num    = 1;
        while (curr_node != NULL)
        {
            struct ListNode* nex_node = curr_node->next;
            if (node_num == (left - 1))
                prefix_node = curr_node;
            if (node_num == (right + 1))
                suffix_node = curr_node;
            if (node_num == left)
            {
                curr_node->next = NULL;
                left_node       = curr_node;
            }
            if (node_num == right)
            {
                curr_node->next = prev_node;
                right_node      = curr_node;
            }
            if (node_num > left && node_num < right)
            {
                curr_node->next = prev_node;
            }

            prev_node = curr_node;
            curr_node = nex_node;
            node_num++;
        }
        if (prefix_node != NULL)
            prefix_node->next = right_node;
        left_node->next = suffix_node;
        if (left == 1)
            return right_node;
        return head;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct ListNode  test_1_node_5 = ListNode(5);
    struct ListNode  test_1_node_4 = ListNode(4, &test_1_node_5);
    struct ListNode  test_1_node_3 = ListNode(3, &test_1_node_4);
    struct ListNode  test_1_node_2 = ListNode(2, &test_1_node_3);
    struct ListNode  test_1_node_1 = ListNode(1, &test_1_node_2);
    struct ListNode* result_1      = sol.reverseBetween(&test_1_node_1, 2, 4);
    while (result_1 != NULL)
    {
        cout << result_1->val << " ";
        result_1 = result_1->next;
    }
    cout << endl;

    // Test_2
    struct ListNode  test_2_node_1 = ListNode(5);
    struct ListNode* result_2      = sol.reverseBetween(&test_2_node_1, 1, 1);
    while (result_2 != NULL)
    {
        cout << result_2->val << " ";
        result_2 = result_2->next;
    }
    cout << endl;
    return 0;
}
// Accepted
// 44/44 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 89.88 % of cpp submissions (9.2 MB)