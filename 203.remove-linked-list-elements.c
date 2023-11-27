/*
 * @lc app=leetcode id=203 lang=c
 *
 * [203] Remove Linked List Elements
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
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* result = head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    // Start to traverse the linked-list
    while(curr != NULL)
    {
        if(curr->val == val)
        {
            if(prev != NULL)
            {
                prev->next = curr->next;
            }
            else
            {
                // head is val
                if(curr == result)
                    result = curr->next;
            }
        }
        else
        {
            prev = curr;
        }
         curr = curr->next;
    }
    return result;
}
// @lc code=end

int main(int argc, char** argv)
{

    return 0;
}

// Accepted
// 66/66 cases passed (6 ms)
// Your runtime beats 95.91 % of c submissions
// Your memory usage beats 58.18 % of c submissions (8.7 MB)