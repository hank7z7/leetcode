/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (51.83%)
 * Likes:    15933
 * Dislikes: 861
 * Total Accepted:    1.8M
 * Total Submissions: 3.4M
 * Testcase Example:  '[1,2,2,1]'
 *
 * Given the head of a singly linked list, return true if it is a palindrome or
 * false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,2,1]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [1, 10^5].
 * 0 <= Node.val <= 9
 * 
 * 
 * 
 * Follow up: Could you do it in O(n) time and O(1) space?
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
private:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
        }
        return slow;
    }

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

public:
    // Time: O(N + N/2)
    // Space: O(1)
    bool isPalindrome(ListNode* head)
    {
        struct ListNode* mid         = middleNode(head);
        struct ListNode* reverse_mid = reverseList(mid);
        bool             ret         = true;
        struct ListNode* curr        = reverse_mid;
        while (curr != NULL && head != curr)
        {
            if (head->val != curr->val || head == reverse_mid)
            {
                ret = false;
                break;
            }
            head = head->next;
            curr = curr->next;
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct ListNode test_1_node_4 = ListNode(1);
    struct ListNode test_1_node_3 = ListNode(2, &test_1_node_4);
    struct ListNode test_1_node_2 = ListNode(2, &test_1_node_3);
    struct ListNode test_1_node_1 = ListNode(1, &test_1_node_2);
    cout << sol.isPalindrome(&test_1_node_1) << endl;

    // Test_2
    struct ListNode test_2_node_2 = ListNode(2);
    struct ListNode test_2_node_1 = ListNode(1, &test_2_node_2);
    cout << sol.isPalindrome(&test_2_node_1) << endl;

    // Test_3
    struct ListNode test_3_node_1 = ListNode(1);
    cout << sol.isPalindrome(&test_3_node_1) << endl;

    return 0;
}
// Reverse middle node method
// Accepted
// 93/93 cases passed (143 ms)
// Your runtime beats 94.24 % of cpp submissions
// Your memory usage beats 70.02 % of cpp submissions (116.6 MB)

// vector and two pointer method
// Accepted
// 93/93 cases passed (173 ms)
// Your runtime beats 54.43 % of cpp submissions
// Your memory usage beats 13.75 % of cpp submissions (130.9 MB)