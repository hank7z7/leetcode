/*
 * @lc app=leetcode id=1669 lang=c
 *
 * [1669] Merge In Between Linked Lists
 *
 * https://leetcode.com/problems/merge-in-between-linked-lists/description/
 *
 * algorithms
 * Medium (72.71%)
 * Likes:    1563
 * Dislikes: 191
 * Total Accepted:    99.1K
 * Total Submissions: 133.6K
 * Testcase Example:  '[10,1,13,6,9,5]\n3\n4\n[1000000,1000001,1000002]'
 *
 * You are given two linked lists: list1 and list2 of sizes n and m
 * respectively.
 *
 * Remove list1's nodes from the a^th node to the b^th node, and put list2 in
 * their place.
 *
 * The blue edges and nodes in the following figure indicate the result:
 *
 * Build the result list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 =
 * [1000000,1000001,1000002]
 * Output: [10,1,13,1000000,1000001,1000002,5]
 * Explanation: We remove the nodes 3 and 4 and put the entire list2 in their
 * place. The blue edges and nodes in the above figure indicate the result.
 *
 *
 * Example 2:
 *
 *
 * Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 =
 * [1000000,1000001,1000002,1000003,1000004]
 * Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
 * Explanation: The blue edges and nodes in the above figure indicate the
 * result.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= list1.length <= 10^4
 * 1 <= a <= b < list1.length - 1
 * 1 <= list2.length <= 10^4
 *
 *
 */
#include <stdio.h>
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


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2)
{
    struct ListNode* list1_head = list1;
    struct ListNode* list1_prev = NULL;
    struct ListNode* list1_next = NULL;
    int              curr_node  = 0;
    while (list1 != NULL && curr_node <= (b + 1))
    {
        if (curr_node == (a - 1))
            list1_prev = list1;
        if (curr_node == (b + 1))
            list1_next = list1;
        list1 = list1->next;
        curr_node++;
    }

    list1_prev->next = list2;
    while (list2->next != NULL)
        list2 = list2->next;
    list2->next = list1_next;

    return list1_head;
}
// @lc code=end
int main(int argc, char** argv)
{
    int a, b;
    // Test_1
    struct ListNode test_1_list1_node5;
    test_1_list1_node5.val  = 5;
    test_1_list1_node5.next = NULL;
    struct ListNode test_1_list1_node4;
    test_1_list1_node4.val  = 9;
    test_1_list1_node4.next = &test_1_list1_node5;
    struct ListNode test_1_list1_node3;
    test_1_list1_node3.val  = 6;
    test_1_list1_node3.next = &test_1_list1_node4;
    struct ListNode test_1_list1_node2;
    test_1_list1_node2.val  = 13;
    test_1_list1_node2.next = &test_1_list1_node3;
    struct ListNode test_1_list1_node1;
    test_1_list1_node1.val  = 1;
    test_1_list1_node1.next = &test_1_list1_node2;
    struct ListNode test_1_list1_node0;
    test_1_list1_node0.val  = 10;
    test_1_list1_node0.next = &test_1_list1_node1;
    struct ListNode test_1_list2_node2;
    test_1_list2_node2.val  = 1000002;
    test_1_list2_node2.next = NULL;
    struct ListNode test_1_list2_node1;
    test_1_list2_node1.val  = 1000001;
    test_1_list2_node1.next = &test_1_list2_node2;
    struct ListNode test_1_list2_node0;
    test_1_list2_node0.val    = 1000000;
    test_1_list2_node0.next   = &test_1_list2_node1;
    a                         = 3;
    b                         = 4;
    struct ListNode* result_1 = mergeInBetween(&test_1_list1_node0, a, b, &test_1_list2_node0);
    printf("[");
    while (result_1 != NULL)
    {
        printf("%d ", result_1->val);
        result_1 = result_1->next;
    }
    printf("]\n");

    return 0;
}
// Accepted
// 61/61 cases passed (113 ms)
// Your runtime beats 40.12 % of c submissions
// Your memory usage beats 59.88 % of c submissions (32.8 MB)