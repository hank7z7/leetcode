/*
 * @lc app=leetcode id=141 lang=c
 *
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (45.70%)
 * Likes:    9157
 * Dislikes: 841
 * Total Accepted:    1.6M
 * Total Submissions: 3.4M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given head, the head of a linked list, determine if the linked list has a
 * cycle in it.
 * 
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is
 * connected to. Note that pos is not passed as a parameter.
 * 
 * Return true if there is a cycle in the linked list. Otherwise, return
 * false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 1st node (0-indexed).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 0th node.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of the nodes in the list is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * pos is -1 or a valid index in the linked-list.
 * 
 * 
 * 
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
	while (head != NULL) {
		// If !head cannot pass, why?
		if (head->val == INT_MAX)
			return true;

		head->val = INT_MAX;
		head = head->next;
	}
	return false;
}

// @lc code=end

// Accepted
// 21/21 cases passed (14 ms)
// Your runtime beats 62.71 % of c submissions
// Your memory usage beats 60.98 % of c submissions (7.9 MB)
