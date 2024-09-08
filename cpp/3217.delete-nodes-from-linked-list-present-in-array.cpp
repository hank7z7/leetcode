/*
 * @lc app=leetcode id=3217 lang=cpp
 *
 * [3217] Delete Nodes From Linked List Present in Array
 *
 * https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/
 *
 * algorithms
 * Medium (61.27%)
 * Likes:    359
 * Dislikes: 14
 * Total Accepted:    99.3K
 * Total Submissions: 147.2K
 * Testcase Example:  '[1,2,3]\n[1,2,3,4,5]'
 *
 * You are given an array of integers nums and the head of a linked list.
 * Return the head of the modified linked list after removing all nodes from
 * the linked list that have a value that exists in nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3], head = [1,2,3,4,5]
 *
 * Output: [4,5]
 *
 * Explanation:
 *
 *
 *
 * Remove the nodes with values 1, 2, and 3.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], head = [1,2,1,2,1,2]
 *
 * Output: [2,2,2]
 *
 * Explanation:
 *
 *
 *
 * Remove the nodes with value 1.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [5], head = [1,2,3,4]
 *
 * Output: [1,2,3,4]
 *
 * Explanation:
 *
 *
 *
 * No node has value 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * All elements in nums are unique.
 * The number of nodes in the given list is in the range [1, 10^5].
 * 1 <= Node.val <= 10^5
 * The input is generated such that there is at least one node in the linked
 * list that has a value not present in nums.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> nums_set;
        for (auto num : nums)
            nums_set.insert(num);

        // Create a dummy head;
        ListNode dummy_node = ListNode(0, head);
        ListNode *prev_node = &dummy_node;
        ListNode *curr_node = head;
        ListNode *next_node = nullptr;

        while (curr_node)
        {
            next_node = curr_node->next;

            if (nums_set.find(curr_node->val) != nums_set.end())
            {
                prev_node->next = next_node;
                delete curr_node;
                curr_node = next_node;
            }
            else
            {
                prev_node = curr_node;
                curr_node = next_node;
            }
        }

        return dummy_node.next;
    }
};
// @lc code=end

bool areSame(ListNode *a, ListNode *b)
{
    // Traverse both lists
    while (a && b)
    {
        // If values at the current nodes are different, return false
        if (a->val != b->val)
        {
            return false;
        }
        // Move to the next nodes
        a = a->next;
        b = b->next;
    }

    // If both lists have reached the end (nullptr), return true
    // Otherwise, one list is longer than the other, return false
    return a == nullptr && b == nullptr;
}

int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 2, 3};
    ListNode *test_1_node_4 = new ListNode(5);
    ListNode *test_1_node_3 = new ListNode(4, test_1_node_4);
    ListNode *test_1_node_2 = new ListNode(3, test_1_node_3);
    ListNode *test_1_node_1 = new ListNode(2, test_1_node_2);
    ListNode *test_1_node_0 = new ListNode(1, test_1_node_1);
    ListNode *res_1 = sol.modifiedList(nums_1, test_1_node_0);
    ListNode *curr = res_1;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Check the answer
    ListNode ans_1_node_1 = ListNode(5);
    ListNode ans_1_node_0 = ListNode(4, &ans_1_node_1);
    assert(areSame(res_1, &ans_1_node_0));

    // Delete result
    curr = res_1;
    while (curr)
    {
        ListNode *d = curr;
        curr = curr->next;
        delete d;
    }

    // Test_2
    vector<int> nums_2 = {1};
    ListNode *test_2_node_5 = new ListNode(2);
    ListNode *test_2_node_4 = new ListNode(1, test_2_node_5);
    ListNode *test_2_node_3 = new ListNode(2, test_2_node_4);
    ListNode *test_2_node_2 = new ListNode(1, test_2_node_3);
    ListNode *test_2_node_1 = new ListNode(2, test_2_node_2);
    ListNode *test_2_node_0 = new ListNode(1, test_2_node_1);
    ListNode *res_2 = sol.modifiedList(nums_2, test_2_node_0);
    ListNode *curr_2 = res_2;
    while (curr_2)
    {
        cout << curr_2->val << " ";
        curr_2 = curr_2->next;
    }
    cout << endl;

    // Check the answer
    ListNode ans_2_node_2 = ListNode(2);
    ListNode ans_2_node_1 = ListNode(2, &ans_2_node_2);
    ListNode ans_2_node_0 = ListNode(2, &ans_2_node_1);
    assert(areSame(res_2, &ans_2_node_0));

    // Delete result
    curr_2 = res_2;
    while (curr_2)
    {
        ListNode *d = curr_2;
        curr_2 = curr_2->next;
        delete d;
    }

    // Test_3
    vector<int> nums_3 = {1, 2, 3, 4};
    ListNode *test_3_node_3 = new ListNode(4);
    ListNode *test_3_node_2 = new ListNode(3, test_3_node_3);
    ListNode *test_3_node_1 = new ListNode(2, test_3_node_2);
    ListNode *test_3_node_0 = new ListNode(1, test_3_node_1);
    ListNode *res_3 = sol.modifiedList(nums_3, test_3_node_0);
    ListNode *curr_3 = res_3;
    while (curr_3)
    {
        cout << curr_3->val << " ";
        curr_3 = curr_3->next;
    }
    cout << endl;

    // Check the answer
    assert(areSame(res_3, nullptr));

    // Delete result
    curr_3 = res_3;
    while (curr_3)
    {
        ListNode *d = curr_3;
        curr_3 = curr_3->next;
        delete d;
    }

    return 0;
}
