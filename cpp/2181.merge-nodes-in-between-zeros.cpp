/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
 *
 * https://leetcode.com/problems/merge-nodes-in-between-zeros/description/
 *
 * algorithms
 * Medium (85.83%)
 * Likes:    2139
 * Dislikes: 44
 * Total Accepted:    217.3K
 * Total Submissions: 243.1K
 * Testcase Example:  '[0,3,1,0,4,5,2,0]'
 *
 * You are given the head of a linked list, which contains a series of integers
 * separated by 0's. The beginning and end of the linked list will have
 * Node.val == 0.
 * 
 * For every two consecutive 0's, merge all the nodes lying in between them
 * into a single node whose value is the sum of all the merged nodes. The
 * modified list should not contain any 0's.
 * 
 * Return the head of the modified linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [0,3,1,0,4,5,2,0]
 * Output: [4,11]
 * Explanation: 
 * The above figure represents the given linked list. The modified list
 * contains
 * - The sum of the nodes marked in green: 3 + 1 = 4.
 * - The sum of the nodes marked in red: 4 + 5 + 2 = 11.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [0,1,0,3,0,2,2,0]
 * Output: [1,3,4]
 * Explanation: 
 * The above figure represents the given linked list. The modified list
 * contains
 * - The sum of the nodes marked in green: 1 = 1.
 * - The sum of the nodes marked in red: 3 = 3.
 * - The sum of the nodes marked in yellow: 2 + 2 = 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [3, 2 * 10^5].
 * 0 <= Node.val <= 1000
 * There are no two consecutive nodes with Node.val == 0.
 * The beginning and end of the linked list have Node.val == 0.
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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *res = head->next;
        ListNode *curr = head->next;
        ListNode *next = head->next;

        int sum = 0;
        while (next)
        {
            if (next->val == 0)
            {
                curr->val = sum;
                if (next->next)
                    curr->next = next;
                else
                    curr->next = NULL;
                curr = next;
                sum = 0;
            }
            else
            {
                sum += next->val;
            }
            next = next->next;
        }

        return res;
    }
};
// @lc code=end
void print_listnode(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val;
        if (curr->next)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    ListNode test_1_node_7 = ListNode(0);
    ListNode test_1_node_6 = ListNode(2, &test_1_node_7);
    ListNode test_1_node_5 = ListNode(5, &test_1_node_6);
    ListNode test_1_node_4 = ListNode(4, &test_1_node_5);
    ListNode test_1_node_3 = ListNode(0, &test_1_node_4);
    ListNode test_1_node_2 = ListNode(1, &test_1_node_3);
    ListNode test_1_node_1 = ListNode(3, &test_1_node_2);
    ListNode test_1_node_0 = ListNode(0, &test_1_node_1);
    ListNode *test_1_res = sol.mergeNodes(&test_1_node_0);
    print_listnode(test_1_res);

    // Test_2
    ListNode test_2_node_7 = ListNode(0);
    ListNode test_2_node_6 = ListNode(2, &test_2_node_7);
    ListNode test_2_node_5 = ListNode(2, &test_2_node_6);
    ListNode test_2_node_4 = ListNode(0, &test_2_node_5);
    ListNode test_2_node_3 = ListNode(3, &test_2_node_4);
    ListNode test_2_node_2 = ListNode(0, &test_2_node_3);
    ListNode test_2_node_1 = ListNode(1, &test_2_node_2);
    ListNode test_2_node_0 = ListNode(0, &test_2_node_1);
    ListNode *test_2_res = sol.mergeNodes(&test_2_node_0);
    print_listnode(test_2_res);

    return 0;
}
// Accepted
// 39/39 cases passed (414 ms)
// Your runtime beats 80.82 % of cpp submissions
// Your memory usage beats 88.28 % of cpp submissions (256.5 MB)