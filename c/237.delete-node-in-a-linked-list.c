/*
 * @lc app=leetcode id=237 lang=c
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
// @lc code=end

// Accepted
// 41/41 cases passed (7 ms)
// Your runtime beats 64.35 % of c submissions
// Your memory usage beats 62.5 % of c submissions (6.3 MB)