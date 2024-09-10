/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
 *
 * https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
 *
 * algorithms
 * Medium (88.77%)
 * Likes:    593
 * Dislikes: 21
 * Total Accepted:    91.3K
 * Total Submissions: 102K
 * Testcase Example:  '[18,6,10,3]'
 *
 * Given the head of a linked list head, in which each node contains an integer
 * value.
 * 
 * Between every pair of adjacent nodes, insert a new node with a value equal
 * to the greatest common divisor of them.
 * 
 * Return the linked list after insertion.
 * 
 * The greatest common divisor of two numbers is the largest positive integer
 * that evenly divides both numbers.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [18,6,10,3]
 * Output: [18,6,6,2,10,1,3]
 * Explanation: The 1^st diagram denotes the initial linked list and the 2^nd
 * diagram denotes the linked list after inserting the new nodes (nodes in blue
 * are the inserted nodes).
 * - We insert the greatest common divisor of 18 and 6 = 6 between the 1^st and
 * the 2^nd nodes.
 * - We insert the greatest common divisor of 6 and 10 = 2 between the 2^nd and
 * the 3^rd nodes.
 * - We insert the greatest common divisor of 10 and 3 = 1 between the 3^rd and
 * the 4^th nodes.
 * There are no more adjacent nodes, so we return the linked list.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [7]
 * Output: [7]
 * Explanation: The 1^st diagram denotes the initial linked list and the 2^nd
 * diagram denotes the linked list after inserting the new nodes.
 * There are no pairs of adjacent nodes, so we return the initial linked
 * list.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [1, 5000].
 * 1 <= Node.val <= 1000
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr)
        {
            if(curr->next)
            {
                // unique_ptr<ListNode> insert( new ListNode(gcd(curr->val, curr->next->val), curr->next) );
                ListNode* insert = new ListNode(gcd(curr->val, curr->next->val), curr->next);
                curr->next = insert;
                curr = curr->next;
            }
            curr = curr->next;
        }
        return head;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    ListNode* curr;
    // Test_1
    ListNode ll_1_node3 = ListNode(3);
    ListNode ll_1_node2 = ListNode(10, &ll_1_node3);
    ListNode ll_1_node1 = ListNode(6, &ll_1_node2);
    ListNode ll_1_node0 = ListNode(18, &ll_1_node1);
    ListNode* res_1 = sol.insertGreatestCommonDivisors(&ll_1_node0);
    curr = res_1;
    while(curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Test_2
    ListNode ll_2_node0 = ListNode(7);
    ListNode* res_2 = sol.insertGreatestCommonDivisors(&ll_2_node0);
    curr = res_2;
    while(curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    
    return 0;
}
// Accepted
// 582/582 cases passed (35 ms)
// Your runtime beats 79.23 % of cpp submissions
// Your memory usage beats 49.64 % of cpp submissions (35.6 MB)