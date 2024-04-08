/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
 *
 * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
 *
 * algorithms
 * Medium (58.79%)
 * Likes:    4026
 * Dislikes: 75
 * Total Accepted:    364.7K
 * Total Submissions: 619.7K
 * Testcase Example:  '[1,3,4,7,1,2,6]'
 *
 * You are given the head of a linked list. Delete the middle node, and return
 * the head of the modified linked list.
 *
 * The middle node of a linked list of size n is the ⌊n / 2⌋^th node from the
 * start using 0-based indexing, where ⌊x⌋ denotes the largest integer less
 * than or equal to x.
 *
 *
 * For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2,
 * respectively.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,3,4,7,1,2,6]
 * Output: [1,3,4,1,2,6]
 * Explanation:
 * The above figure represents the given linked list. The indices of the nodes
 * are written below.
 * Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
 * We return the new list after removing this node.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4]
 * Output: [1,2,4]
 * Explanation:
 * The above figure represents the given linked list.
 * For n = 4, node 2 with value 3 is the middle node, which is marked in red.
 *
 *
 * Example 3:
 *
 *
 * Input: head = [2,1]
 * Output: [2]
 * Explanation:
 * The above figure represents the given linked list.
 * For n = 2, node 1 with value 1 is the middle node, which is marked in red.
 * Node 0 with value 2 is the only node remaining after removing node 1.
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 10^5].
 * 1 <= Node.val <= 10^5
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
    ListNode* deleteMiddle(ListNode* head)
    {
        struct ListNode* prev = NULL;
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        while (fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast->next)
                fast = fast->next;
        }
        if (prev)
            prev->next = slow->next;
        else
            head = prev;
        return head;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct ListNode  test_1_node_6 = ListNode(6);
    struct ListNode  test_1_node_5 = ListNode(2, &test_1_node_6);
    struct ListNode  test_1_node_4 = ListNode(1, &test_1_node_5);
    struct ListNode  test_1_node_3 = ListNode(7, &test_1_node_4);
    struct ListNode  test_1_node_2 = ListNode(4, &test_1_node_3);
    struct ListNode  test_1_node_1 = ListNode(3, &test_1_node_2);
    struct ListNode  test_1_node_0 = ListNode(1, &test_1_node_1);
    struct ListNode* result_1      = sol.deleteMiddle(&test_1_node_0);
    while (result_1)
    {
        cout << result_1->val << " ";
        result_1 = result_1->next;
    }
    cout << endl;

    // Test_2
    struct ListNode  test_2_node_3 = ListNode(4);
    struct ListNode  test_2_node_2 = ListNode(3, &test_2_node_3);
    struct ListNode  test_2_node_1 = ListNode(2, &test_2_node_2);
    struct ListNode  test_2_node_0 = ListNode(1, &test_2_node_1);
    struct ListNode* result_2      = sol.deleteMiddle(&test_2_node_0);
    while (result_2)
    {
        cout << result_2->val << " ";
        result_2 = result_2->next;
    }
    cout << endl;

    // Test_3
    struct ListNode  test_3_node_1 = ListNode(1);
    struct ListNode  test_3_node_0 = ListNode(2, &test_3_node_1);
    struct ListNode* result_3      = sol.deleteMiddle(&test_3_node_0);
    while (result_3)
    {
        cout << result_3->val << " ";
        result_3 = result_3->next;
    }
    cout << endl;

    // Test_4
    struct ListNode  test_4_node_0 = ListNode(1);
    struct ListNode* result_4      = sol.deleteMiddle(&test_4_node_0);
    while (result_4)
    {
        cout << result_4->val << " ";
        result_4 = result_4->next;
    }
    cout << endl;

    return 0;
}
// Accepted
// 70/70 cases passed (568 ms)
// Your runtime beats 9.85 % of cpp submissions
// Your memory usage beats 77.71 % of cpp submissions (298.3 MB)