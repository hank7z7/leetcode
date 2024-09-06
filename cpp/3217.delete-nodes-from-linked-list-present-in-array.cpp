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
    int       val;
    ListNode* next;
    ListNode()
    : val(0)
    , next(NULL)
    {
    }
    ListNode(int x)
    : val(x)
    , next(NULL)
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
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> nums_set;
        for (auto num : nums)
            nums_set.insert(num);
        // Handle the case where the head node needs to be removed
        while (head != NULL && nums_set.count(head->val) > 0)
        {
            ListNode* temp = head;
            head           = head->next;
            delete temp;
        }

        // If the list is empty after removing head nodes, return NULL
        if (head == NULL)
        {
            return NULL;
        }

        // Iterate through the list, removing nodes with values in the set
        ListNode* current = head;
        while (current->next != NULL)
        {
            if (nums_set.find(current->next->val) != nums_set.end())
            {
                // Store the node to be deleted
                ListNode* temp = current->next;
                // Skip the next node by updating the pointer
                current->next = current->next->next;
                // Delete the removed node
                delete temp;
            }
            else
            {
                // Move to the next node
                current = current->next;
            }
        }

        return head;
    }
};
// @lc code=end
int main(int argc, char** argv) { return 0; }
