/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (61.38%)
 * Likes:    9727
 * Dislikes: 517
 * Total Accepted:    897K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list.
 * 
 * The first node is considered odd, and the second node is even, and so on.
 * 
 * Note that the relative order inside both the even and odd groups should
 * remain as it was in the input.
 * 
 * You must solve the problem in O(1) extra space complexity and O(n) time
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the linked list is in the range [0, 10^4].
 * -10^6 <= Node.val <= 10^6
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* oddEvenList(ListNode* head)
    {
        struct ListNode* odd      = NULL;
        struct ListNode* odd_head = NULL;
        struct ListNode* even     = NULL;
        struct ListNode* curr     = head;
        int              node_num = 0;
        while (curr)
        {
            if (node_num & 1)
            {
                if (odd)
                {
                    odd->next = curr;
                    odd       = odd->next;
                }
                else
                {
                    odd      = curr;
                    odd_head = curr;
                }
            }
            else
            {
                if (even)
                {
                    even->next = curr;
                    even       = even->next;
                }
                else
                {
                    even = curr;
                }
            }
            node_num++;
            curr = curr->next;
        }
        if (even)
            even->next = odd_head;
        if (odd)
            odd->next = NULL;
        return head;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct ListNode  test_1_node_4 = ListNode(5);
    struct ListNode  test_1_node_3 = ListNode(4, &test_1_node_4);
    struct ListNode  test_1_node_2 = ListNode(3, &test_1_node_3);
    struct ListNode  test_1_node_1 = ListNode(2, &test_1_node_2);
    struct ListNode  test_1_node_0 = ListNode(1, &test_1_node_1);
    struct ListNode* result_1      = sol.oddEvenList(&test_1_node_0);
    while (result_1)
    {
        cout << result_1->val << " ";
        result_1 = result_1->next;
    }
    cout << endl;

    // Test_2
    struct ListNode  test_2_node_6 = ListNode(7);
    struct ListNode  test_2_node_5 = ListNode(6, &test_2_node_6);
    struct ListNode  test_2_node_4 = ListNode(5, &test_2_node_5);
    struct ListNode  test_2_node_3 = ListNode(4, &test_2_node_4);
    struct ListNode  test_2_node_2 = ListNode(3, &test_2_node_3);
    struct ListNode  test_2_node_1 = ListNode(2, &test_2_node_2);
    struct ListNode  test_2_node_0 = ListNode(1, &test_2_node_1);
    struct ListNode* result_2      = sol.oddEvenList(&test_2_node_0);
    while (result_2)
    {
        cout << result_2->val << " ";
        result_2 = result_2->next;
    }
    cout << endl;

    // Test_3
    struct ListNode  test_3_node_1 = ListNode(1);
    struct ListNode  test_3_node_0 = ListNode(2, &test_3_node_1);
    struct ListNode* result_3      = sol.oddEvenList(&test_3_node_0);
    while (result_3)
    {
        cout << result_3->val << " ";
        result_3 = result_3->next;
    }
    cout << endl;

    // Test_4
    struct ListNode  test_4_node_0 = ListNode(1);
    struct ListNode* result_4      = sol.oddEvenList(&test_4_node_0);
    while (result_4)
    {
        cout << result_4->val << " ";
        result_4 = result_4->next;
    }
    cout << endl;

    // Test_5
    struct ListNode* result_5 = sol.oddEvenList(NULL);
    while (result_5)
    {
        cout << result_5->val << " ";
        result_5 = result_5->next;
    }
    cout << endl;

    return 0;
}
// Accepted
// 70/70 cases passed (4 ms)
// Your runtime beats 91.28 % of cpp submissions
// Your memory usage beats 97.06 % of cpp submissions (13.9 MB)