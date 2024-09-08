/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 *
 * https://leetcode.com/problems/split-linked-list-in-parts/description/
 *
 * algorithms
 * Medium (64.28%)
 * Likes:    4016
 * Dislikes: 322
 * Total Accepted:    216.7K
 * Total Submissions: 332.4K
 * Testcase Example:  '[1,2,3]\n5'
 *
 * Given the head of a singly linked list and an integer k, split the linked
 * list into k consecutive linked list parts.
 * 
 * The length of each part should be as equal as possible: no two parts should
 * have a size differing by more than one. This may lead to some parts being
 * null.
 * 
 * The parts should be in the order of occurrence in the input list, and parts
 * occurring earlier should always have a size greater than or equal to parts
 * occurring later.
 * 
 * Return an array of the k parts.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3], k = 5
 * Output: [[1],[2],[3],[],[]]
 * Explanation:
 * The first element output[0] has output[0].val = 1, output[0].next = null.
 * The last element output[4] is null, but its string representation as a
 * ListNode is [].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
 * Output: [[1,2,3,4],[5,6,7],[8,9,10]]
 * Explanation:
 * The input has been split into consecutive parts with size difference at most
 * 1, and earlier parts are a larger size than the later parts.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 1000].
 * 0 <= Node.val <= 1000
 * 1 <= k <= 50
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while(curr)
        {
            count++;
            curr = curr->next;
        }

        int part_size = count / k;
        int remain = count - k * part_size;
        vector<ListNode*> res(k);
        curr = head;
        for(int i = 0; i < k; i++)
        {
            res[i] = curr;
            int move = part_size;
            if(remain > 0)
            {
                move++;
                remain--;
            }
            for(int j = 0; j < move; j++)
            {
                ListNode* next_node = curr->next;
                if(j == move - 1)
                    curr->next = nullptr;
                curr = next_node;
            }
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    ListNode test_1_node_2 = ListNode(3);
    ListNode test_1_node_1 = ListNode(2, &test_1_node_2);
    ListNode test_1_node_0 = ListNode(1, &test_1_node_1);
    int k_1 = 5;
    vector<ListNode*> res_1 = sol.splitListToParts(&test_1_node_0, k_1);
    for(auto ptr : res_1)
    {
        ListNode * curr_node = ptr;
        cout << "[";
        while(curr_node)
        {
            cout << curr_node->val;
            curr_node = curr_node->next;
        }
        cout << "]";
    }
    cout << endl;
    return 0;
}
// Accepted
// 43/43 cases passed (9 ms)
// Your runtime beats 25.85 % of cpp submissions
// Your memory usage beats 61.52 % of cpp submissions (13.9 MB)