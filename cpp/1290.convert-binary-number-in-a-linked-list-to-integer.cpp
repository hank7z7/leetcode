/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 *
 * https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
 *
 * algorithms
 * Easy (81.15%)
 * Likes:    4469
 * Dislikes: 173
 * Total Accepted:    618.8K
 * Total Submissions: 755.4K
 * Testcase Example:  '[1,0,1]'
 *
 * Given head which is a reference node to a singly-linked list. The value of
 * each node in the linked list is either 0 or 1. The linked list holds the
 * binary representation of a number.
 * 
 * Return the decimal value of the number in the linked list.
 * 
 * The most significant bit is at the head of the linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,0,1]
 * Output: 5
 * Explanation: (101) in base 2 = (5) in base 10
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [0]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The Linked List is not empty.
 * Number of nodes will not exceed 30.
 * Each node's value is either 0 or 1.
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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode* curr = head;
        while (curr) {
            res = res << 1;  // Shift left by 1 (multiply by 2)
            res += curr->val;  // Add the current node's value
            curr = curr->next;  // Move to the next node
        }
        return res;  // Return the final decimal value
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    ListNode* head1 = new ListNode(1, new ListNode(0, new ListNode(1)));
    int res = sol.getDecimalValue(head1);
    cout << res << endl;  // Output: 5
    assert(res == 5);
    while(head1) {
        ListNode* temp = head1;
        head1 = head1->next;
        delete temp;  // Clean up memory
    }

    // Test_2
    ListNode* head2 = new ListNode(0);
    res = sol.getDecimalValue(head2);
    cout << res << endl;  // Output: 0
    assert(res == 0);
    while(head2) {
        ListNode* temp = head2;
        head2 = head2->next;
        delete temp;  // Clean up memory
    }

    return 0;
}
// Accepted
// 102/102 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 39.86 % of cpp submissions (10.7 MB)