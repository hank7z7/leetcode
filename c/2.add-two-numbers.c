/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (41.88%)
 * Likes:    29660
 * Dislikes: 5786
 * Total Accepted:    4.2M
 * Total Submissions: 10M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int              val;
    struct ListNode* next;
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* result = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* curr   = result;
    struct ListNode* prev   = result;
    int              carry  = 0;
    while (l1 != NULL || l2 != NULL)
    {
        curr->val = carry;
        if (l1 != NULL)
        {
            curr->val += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            curr->val += l2->val;
            l2 = l2->next;
        }
        carry      = curr->val / 10;
        curr->val  = curr->val % 10;
        curr->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        prev       = curr;
        curr       = curr->next;
    }
    if (carry != 0)
    {
        curr->val  = carry;
        curr->next = NULL;
    }
    else
    {
        free(curr);
        prev->next = NULL;
    }

    return result;
}
// @lc code=end

void printListNodes(struct ListNode* head)
{
    if (head)
    {
        printf("%d ", head->val);
        printListNodes(head->next);
        free(head);
    }
    else
    {
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    struct ListNode node_1;
    struct ListNode node_2;
    struct ListNode node_3;
    struct ListNode node_4;
    struct ListNode node_5;
    struct ListNode node_6;
    node_1.val  = 2;
    node_2.val  = 4;
    node_3.val  = 3;
    node_4.val  = 5;
    node_5.val  = 6;
    node_6.val  = 4;
    node_1.next = &node_2;
    node_2.next = &node_3;
    node_3.next = NULL;
    node_4.next = &node_5;
    node_5.next = &node_6;
    node_6.next = NULL;

    printListNodes(addTwoNumbers(&node_1, &node_4));

    return 0;
}

// Accepted
// 1568/1568 cases passed (11 ms)
// Your runtime beats 64.03 % of c submissions
// Your memory usage beats 67.09 % of c submissions (8.3 MB)