/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (75.84%)
 * Likes:    20819
 * Dislikes: 410
 * Total Accepted:    3.9M
 * Total Submissions: 5.1M
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
    ListNode* reverseList(ListNode* head)
    {
        struct ListNode* prev_node = NULL;
        while (head != NULL)
        {
            struct ListNode* next_node = head->next;
            head->next                 = prev_node;
            prev_node                  = head;
            if (next_node == NULL)
                break;
            head = next_node;
        }
        return head;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct ListNode  test_1_node_5 = ListNode(5);
    struct ListNode  test_1_node_4 = ListNode(4, &test_1_node_5);
    struct ListNode  test_1_node_3 = ListNode(3, &test_1_node_4);
    struct ListNode  test_1_node_2 = ListNode(2, &test_1_node_3);
    struct ListNode  test_1_node_1 = ListNode(1, &test_1_node_2);
    struct ListNode* result_1      = sol.reverseList(&test_1_node_1);
    while (result_1 != NULL)
    {
        cout << result_1->val << " ";
        result_1 = result_1->next;
    }
    cout << endl;

    // Test_2
    struct ListNode* result_2 = sol.reverseList(NULL);
    while (result_2 != NULL)
    {
        cout << result_2->val << " ";
        result_2 = result_2->next;
    }
    cout << endl;
    return 0;
}
// Accepted
// 28/28 cases passed (4 ms)
// Your runtime beats 56.53 % of cpp submissions
// Your memory usage beats 99.73 % of cpp submissions (11.4 MB)