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
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> val;
        while (head != NULL)
        {
            val.push_back(head->val);
            head = head->next;
        }
        bool ret = true;
        for (int i = 0; i < (int) val.size() / 2; i++)
        {
            if (val[i] != val[(int) val.size() - 1 - i])
            {
                ret = false;
                break;
            }
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

    return 0;
}
// Accepted
// 93/93 cases passed (173 ms)
// Your runtime beats 54.43 % of cpp submissions
// Your memory usage beats 13.75 % of cpp submissions (130.9 MB)