/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (49.46%)
 * Likes:    14969
 * Dislikes: 1274
 * Total Accepted:    2.7M
 * Total Submissions: 5.5M
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
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int       val;
    ListNode* next;
    ListNode(int x)
    : val(x)
    , next(NULL)
    {
    }
    ListNode(int x, struct ListNode* y)
    : val(x)
    , next(y)
    {
    }
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        unordered_set<struct ListNode*> us;
        while (head != NULL)
        {
            // Mark visited node
            // if(head->val == INT_MAX)
            //     return true;
            // head->val = INT_MAX;
            if (us.find(head) != us.end())
            {
                return true;
            }
            us.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct ListNode ll_1_node_3 = ListNode(-4);
    struct ListNode ll_1_node_2 = ListNode(0, &ll_1_node_3);
    struct ListNode ll_1_node_1 = ListNode(2, &ll_1_node_2);
    struct ListNode ll_1_node_0 = ListNode(3, &ll_1_node_1);
    ll_1_node_3.next            = &ll_1_node_1;
    cout << sol.hasCycle(&ll_1_node_0) << endl;

    // Test_2
    struct ListNode ll_2_node_1 = ListNode(2);
    struct ListNode ll_2_node_0 = ListNode(1, &ll_2_node_1);
    ll_2_node_1.next            = &ll_2_node_0;
    cout << sol.hasCycle(&ll_2_node_0) << endl;

    // Test_3
    struct ListNode ll_3_node_0 = ListNode(1);
    cout << sol.hasCycle(&ll_3_node_0) << endl;

    return 0;
}
// Accepted
// 26/26 cases passed (11 ms)
// Your runtime beats 43.85 % of cpp submissions
// Your memory usage beats 53.92 % of cpp submissions (10.6 MB)

// Unordered_set
// Accepted
// 26/26 cases passed (20 ms)
// Your runtime beats 7.15 % of cpp submissions
// Your memory usage beats 5.66 % of cpp submissions (14.2 MB)