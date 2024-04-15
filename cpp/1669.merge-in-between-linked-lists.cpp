/*
 * @lc app=leetcode id=1669 lang=cpp
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
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
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      a, b;
    // Test_1
    struct ListNode test_1_list1_node5 = ListNode(5);
    struct ListNode test_1_list1_node4 = ListNode(9, &test_1_list1_node5);
    struct ListNode test_1_list1_node3 = ListNode(6, &test_1_list1_node4);
    struct ListNode test_1_list1_node2 = ListNode(13, &test_1_list1_node3);
    struct ListNode test_1_list1_node1 = ListNode(1, &test_1_list1_node2);
    struct ListNode test_1_list1_node0 = ListNode(10, &test_1_list1_node1);
    struct ListNode test_1_list2_node2 = ListNode(1000002);
    struct ListNode test_1_list2_node1 = ListNode(1000001, &test_1_list2_node2);
    struct ListNode test_1_list2_node0 = ListNode(1000000, &test_1_list2_node1);
    a                                  = 3;
    b                                  = 4;
    struct ListNode* result_1 = sol.mergeInBetween(&test_1_list1_node0, a, b, &test_1_list2_node0);
    cout << "[";
    while (result_1 != NULL)
    {
        cout << result_1->val << " ";
        result_1 = result_1->next;
    }
    cout << "]" << endl;

    // Test_2
    struct ListNode test_2_list1_node6 = ListNode(6);
    struct ListNode test_2_list1_node5 = ListNode(5, &test_2_list1_node6);
    struct ListNode test_2_list1_node4 = ListNode(4, &test_2_list1_node5);
    struct ListNode test_2_list1_node3 = ListNode(3, &test_2_list1_node4);
    struct ListNode test_2_list1_node2 = ListNode(2, &test_2_list1_node3);
    struct ListNode test_2_list1_node1 = ListNode(1, &test_2_list1_node2);
    struct ListNode test_2_list1_node0 = ListNode(0, &test_2_list1_node1);
    struct ListNode test_2_list2_node4 = ListNode(1000004);
    struct ListNode test_2_list2_node3 = ListNode(1000003, &test_2_list2_node4);
    struct ListNode test_2_list2_node2 = ListNode(1000002, &test_2_list2_node3);
    struct ListNode test_2_list2_node1 = ListNode(1000001, &test_2_list2_node2);
    struct ListNode test_2_list2_node0 = ListNode(1000000, &test_2_list2_node1);
    a                                  = 2;
    b                                  = 5;
    struct ListNode* result_2 = sol.mergeInBetween(&test_2_list1_node0, a, b, &test_2_list2_node0);
    cout << "[";
    while (result_2 != NULL)
    {
        cout << result_2->val << " ";
        result_2 = result_2->next;
    }
    cout << "]" << endl;
    return 0;
}
// Accepted
// 61/61 cases passed (191 ms)
// Your runtime beats 20.1 % of cpp submissions
// Your memory usage beats 44.8 % of cpp submissions (98.1 MB)