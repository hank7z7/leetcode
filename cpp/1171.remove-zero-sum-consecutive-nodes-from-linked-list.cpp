#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        struct ListNode                            dummy_head = ListNode(0, head);
        struct ListNode*                           curr       = head;
        long long                                  prefix_sum = 0;
        unordered_map<long long, struct ListNode*> um;
        um[prefix_sum] = &dummy_head;
        while (curr != NULL)
        {
            // cout << curr->val << endl;
            prefix_sum += (long long) curr->val;
            // Find the same prefix sum, remove nodes between last same and current
            if (um.find(prefix_sum) != um.end())
            {
                // Remove keys between last same prefix to current
                struct ListNode* last             = um[prefix_sum];
                long long        prefix_from_last = prefix_sum;
                while (last->next != curr)
                {
                    prefix_from_last += last->next->val;
                    um.erase(prefix_from_last);
                    last = last->next;
                }
                um[prefix_sum]->next = curr->next;
            }
            else
            {
                // cout << "Add address of " << prefix_sum << endl;
                um[prefix_sum] = curr;
            }
            curr = curr->next;
        }
        return dummy_head.next;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1 [1,2,-3,3,1]
    struct ListNode  test_1_node_4 = ListNode(1);
    struct ListNode  test_1_node_3 = ListNode(3, &test_1_node_4);
    struct ListNode  test_1_node_2 = ListNode(-3, &test_1_node_3);
    struct ListNode  test_1_node_1 = ListNode(2, &test_1_node_2);
    struct ListNode  test_1_node_0 = ListNode(1, &test_1_node_1);
    struct ListNode* test_1_ret    = sol.removeZeroSumSublists(&test_1_node_0);
    while (test_1_ret != NULL)
    {
        cout << test_1_ret->val << " ";
        test_1_ret = test_1_ret->next;
    }
    cout << endl;

    // Test_2 [1,2,3,-3,4]
    struct ListNode  test_2_node_4 = ListNode(4);
    struct ListNode  test_2_node_3 = ListNode(-3, &test_2_node_4);
    struct ListNode  test_2_node_2 = ListNode(3, &test_2_node_3);
    struct ListNode  test_2_node_1 = ListNode(2, &test_2_node_2);
    struct ListNode  test_2_node_0 = ListNode(1, &test_2_node_1);
    struct ListNode* test_2_ret    = sol.removeZeroSumSublists(&test_2_node_0);
    while (test_2_ret != NULL)
    {
        cout << test_2_ret->val << " ";
        test_2_ret = test_2_ret->next;
    }
    cout << endl;

    // Test_3 [1,2,3,-3,-2]
    struct ListNode  test_3_node_4 = ListNode(-2);
    struct ListNode  test_3_node_3 = ListNode(-3, &test_3_node_4);
    struct ListNode  test_3_node_2 = ListNode(3, &test_3_node_3);
    struct ListNode  test_3_node_1 = ListNode(2, &test_3_node_2);
    struct ListNode  test_3_node_0 = ListNode(1, &test_3_node_1);
    struct ListNode* test_3_ret    = sol.removeZeroSumSublists(&test_3_node_0);
    while (test_3_ret != NULL)
    {
        cout << test_3_ret->val << " ";
        test_3_ret = test_3_ret->next;
    }
    cout << endl;

    // Wrong answer first!
    // Test_4 [1,3,2,-3,-2,5,5,-5,1]
    struct ListNode  test_4_node_8 = ListNode(1);
    struct ListNode  test_4_node_7 = ListNode(-5, &test_4_node_8);
    struct ListNode  test_4_node_6 = ListNode(5, &test_4_node_7);
    struct ListNode  test_4_node_5 = ListNode(5, &test_4_node_6);
    struct ListNode  test_4_node_4 = ListNode(-2, &test_4_node_5);
    struct ListNode  test_4_node_3 = ListNode(-3, &test_4_node_4);
    struct ListNode  test_4_node_2 = ListNode(2, &test_4_node_3);
    struct ListNode  test_4_node_1 = ListNode(3, &test_4_node_2);
    struct ListNode  test_4_node_0 = ListNode(1, &test_4_node_1);
    struct ListNode* test_4_ret    = sol.removeZeroSumSublists(&test_4_node_0);
    while (test_4_ret != NULL)
    {
        cout << test_4_ret->val << " ";
        test_4_ret = test_4_ret->next;
    }
    cout << endl;

    return 0;
}
// Time: O(N)
// Space: O(N)
// Success
// Details 
// Runtime: 4 ms, faster than 90.42% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
// Memory Usage: 15.1 MB, less than 16.76% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.