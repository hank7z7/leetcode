/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 *
 * https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
 *
 * algorithms
 * Medium (80.96%)
 * Likes:    3406
 * Dislikes: 94
 * Total Accepted:    261.9K
 * Total Submissions: 323.6K
 * Testcase Example:  '[5,4,2,1]'
 *
 * In a linked list of size n, where n is even, the i^th node (0-indexed) of
 * the linked list is known as the twin of the (n-1-i)^th node, if 0 <= i <= (n
 * / 2) - 1.
 * 
 * 
 * For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the
 * twin of node 2. These are the only nodes with twins for n = 4.
 * 
 * 
 * The twin sum is defined as the sum of a node and its twin.
 * 
 * Given the head of a linked list with even length, return the maximum twin
 * sum of the linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [5,4,2,1]
 * Output: 6
 * Explanation:
 * Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin
 * sum = 6.
 * There are no other nodes with twins in the linked list.
 * Thus, the maximum twin sum of the linked list is 6. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [4,2,2,3]
 * Output: 7
 * Explanation:
 * The nodes with twins present in this linked list are:
 * - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
 * - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
 * Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,100000]
 * Output: 100001
 * Explanation:
 * There is only one node with a twin in the linked list having twin sum of 1 +
 * 100000 = 100001.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is an even integer in the range [2,
 * 10^5].
 * 1 <= Node.val <= 10^5
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
private:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
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
    int pairSum(ListNode* head)
    {
        ListNode* curr   = head;
        ListNode* middle = middleNode(curr);
        middle           = reverseList(middle);

        int result = INT_MIN;
        while (middle)
        {
            result = max(result, curr->val + middle->val);
            middle = middle->next;
            curr   = curr->next;
        }

        return result;
        // Linked list to array method
        /*
        ListNode* curr = head;
        vector<int> arr;
        while(curr)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        int result = INT_MIN;
        int n = (int)arr.size();
        for(int i = 0; i < n / 2; i++)
            result = max(result, arr[i] + arr[n - 1 - i]);
        return result;
        */
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    struct ListNode test_1_node_3 = ListNode(1);
    struct ListNode test_1_node_2 = ListNode(2, &test_1_node_3);
    struct ListNode test_1_node_1 = ListNode(4, &test_1_node_2);
    struct ListNode test_1_node_0 = ListNode(5, &test_1_node_1);
    cout << sol.pairSum(&test_1_node_0) << endl;


    // Test_2
    struct ListNode test_2_node_3 = ListNode(3);
    struct ListNode test_2_node_2 = ListNode(2, &test_2_node_3);
    struct ListNode test_2_node_1 = ListNode(2, &test_2_node_2);
    struct ListNode test_2_node_0 = ListNode(4, &test_2_node_1);
    cout << sol.pairSum(&test_2_node_0) << endl;

    // Test_3
    struct ListNode test_3_node_1 = ListNode(1);
    struct ListNode test_3_node_0 = ListNode(2, &test_3_node_1);
    cout << sol.pairSum(&test_3_node_0) << endl;

    return 0;
}
// Middle and Reverse method
// Accepted
// 46/46 cases passed (189 ms)
// Your runtime beats 38.99 % of cpp submissions
// Your memory usage beats 89 % of cpp submissions (118.9 MB)


// Linked list to array method
// Accepted
// 46/46 cases passed (187 ms)
// Your runtime beats 44.8 % of cpp submissions
// Your memory usage beats 11.11 % of cpp submissions (129.2 MB)