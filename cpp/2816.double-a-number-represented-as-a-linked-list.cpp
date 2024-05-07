/*
 * @lc app=leetcode id=2816 lang=cpp
 *
 * [2816] Double a Number Represented as a Linked List
 *
 * https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/
 *
 * algorithms
 * Medium (49.45%)
 * Likes:    736
 * Dislikes: 16
 * Total Accepted:    83.9K
 * Total Submissions: 146.3K
 * Testcase Example:  '[1,8,9]'
 *
 * You are given the head of a non-empty linked list representing a
 * non-negative integer without leading zeroes.
 *
 * Return the head of the linked list after doubling it.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,8,9]
 * Output: [3,7,8]
 * Explanation: The figure above corresponds to the given linked list which
 * represents the number 189. Hence, the returned linked list represents the
 * number 189 * 2 = 378.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [9,9,9]
 * Output: [1,9,9,8]
 * Explanation: The figure above corresponds to the given linked list which
 * represents the number 999. Hence, the returned linked list reprersents the
 * number 999 * 2 = 1998.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 10^4]
 * 0 <= Node.val <= 9
 * The input is generated such that the list represents a number that does not
 * have leading zeros, except the number 0 itself.
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
private:
public:
    ListNode* doubleIt(ListNode* head)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev  = dummy;
        ListNode* curr  = head;
        while (curr)
        {
            int carry = curr->val * 2 / 10;
            prev->val += carry;
            curr->val = curr->val * 2 % 10;

            prev = curr;
            curr = curr->next;
        }

        ListNode* result;
        if (dummy->val == 0)
            result = dummy->next;
        else
            result = dummy;
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct ListNode  test_1_node_2 = ListNode(9);
    struct ListNode  test_1_node_1 = ListNode(8, &test_1_node_2);
    struct ListNode  test_1_node_0 = ListNode(1, &test_1_node_1);
    struct ListNode* test_1_result = sol.doubleIt(&test_1_node_0);
    while (test_1_result)
    {
        cout << test_1_result->val << " ";
        test_1_result = test_1_result->next;
    }
    cout << endl;

    // Test_2
    struct ListNode  test_2_node_2 = ListNode(9);
    struct ListNode  test_2_node_1 = ListNode(9, &test_2_node_2);
    struct ListNode  test_2_node_0 = ListNode(9, &test_2_node_1);
    struct ListNode* test_2_result = sol.doubleIt(&test_2_node_0);
    while (test_2_result)
    {
        cout << test_2_result->val << " ";
        test_2_result = test_2_result->next;
    }
    cout << endl;

    return 0;
}
// Accepted
// 1265/1265 cases passed (169 ms)
// Your runtime beats 72.88 % of cpp submissions
// Your memory usage beats 72.53 % of cpp submissions (120.7 MB)