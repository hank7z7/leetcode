/*
 * @lc app=leetcode id=19 lang=c
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
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int              val;
    struct ListNode* next;
};

void printListNodes(struct ListNode* head)
{
    if (head)
    {
        printf("%d ", head->val);
        printListNodes(head->next);
    }
    else
    {
        printf("\n");
    }
}
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
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
// @lc code=end

int main(int argc, char** argv)
{
    struct ListNode node_1;
    struct ListNode node_2;
    struct ListNode node_3;
    struct ListNode node_4;
    struct ListNode node_5;
    node_1.val  = 1;
    node_1.next = &node_2;
    node_2.val  = 2;
    node_2.next = &node_3;
    node_3.val  = 3;
    node_3.next = &node_4;
    node_4.val  = 4;
    node_4.next = &node_5;
    node_5.val  = 5;
    node_5.next = NULL;

    printListNodes(removeNthFromEnd(&node_1, 5));

    return 0;
}
// AC at first submit
// Accepted
// 208/208 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 59.82 % of c submissions (6.6 MB)