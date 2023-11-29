/*
 * @lc app=leetcode id=143 lang=c
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (54.06%)
 * Likes:    9914
 * Dislikes: 332
 * Total Accepted:    780K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,4]'
 *
 * You are given the head of a singly linked-list. The list can be represented
 * as:
 * 
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * 
 * Reorder the list to be on the following form:
 * 
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * 
 * You may not modify the values in the list's nodes. Only nodes themselves may
 * be changed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 1000
 * 
 * 
 */
#include <bits/stdc++.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
        return head;

    // Iteration method
    struct ListNode* curr_node = head;
    struct ListNode* prev_node = NULL;
    struct ListNode* next_node = curr_node->next;
    while(curr_node->next != NULL)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    curr_node->next = prev_node;

    return curr_node;
}

void reorderList(struct ListNode* head) {
    if(head != NULL)
    {
        struct ListNode *mid = head;
        struct ListNode *tail = head;
        while(tail->next != NULL)
        {
            if(tail->next->next != NULL)
                tail = tail->next->next;
            else
                tail = tail->next;
            mid = mid->next;
        }
        
        struct ListNode *reverse_mid = reverseList(mid);
        struct ListNode *curr_head = head;
        struct ListNode *curr_next = NULL;
        struct ListNode *reverse_mid_next = NULL;
        while(reverse_mid != NULL)
        {
            curr_next = curr_head->next;
            reverse_mid_next = reverse_mid->next;
            curr_head->next = reverse_mid;
            if(reverse_mid_next == NULL)
            {
                curr_head->next->next = reverse_mid_next;
            }
            else
            {
                curr_head->next->next = curr_next;
            }
            reverse_mid = reverse_mid_next;
            curr_head = curr_next;
        }
    }
}
// @lc code=end

int main(int argc, char **argv)
{
    struct ListNode *Node_1 = (ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *Node_2 = (ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *Node_3 = (ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *Node_4 = (ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *Node_5 = (ListNode*)malloc(sizeof(struct ListNode));

    Node_1->val = 1;
    Node_1->next = Node_2;
    Node_2->val = 2;
    Node_2->next = Node_3;
    Node_3->val = 3;
    Node_3->next = Node_4;
    Node_4->val = 4;
    Node_4->next = Node_5;
    Node_5->val = 5;
    Node_5->next = NULL;


    reorderList(Node_1);

    free(Node_1);
    free(Node_2);
    free(Node_3);
    free(Node_4);
    free(Node_5);

    return 0;
}

// Accepted
// 12/12 cases passed (14 ms)
// Your runtime beats 80.13 % of c submissions
// Your memory usage beats 45.51 % of c submissions (9.8 MB)