/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head) {
        struct ListNode *current = head, *to_be_removed;
        while (current->next) {
            if (current->val == current->next->val) {
                to_be_removed = current->next;
                current->next = to_be_removed->next;
                // free(to_be_removed); // Not needed for AC
            } else {
                current = current->next;
            }
        }
    }
    return head;
}
// @lc code=end

// Accepted
// 166/166 cases passed (7 ms)
// Your runtime beats 66.48 % of c submissions
// Your memory usage beats 59.24 % of c submissions (6.4 MB)