/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (74.53%)
 * Likes:    20102
 * Dislikes: 369
 * Total Accepted:    3.6M
 * Total Submissions: 4.7M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2]
 * Output: [2,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 * 
 * 
 * 
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
 * 
 */
#include <bits/stdc++.h>

// Definition for singly-linked list.
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
// @lc code=end

int main(int argc, char** argv)
{
    return 0;
}

// Accepted
// 28/28 cases passed (2 ms)
// Your runtime beats 71.89 % of c submissions
// Your memory usage beats 85.89 % of c submissions (6.9 MB)