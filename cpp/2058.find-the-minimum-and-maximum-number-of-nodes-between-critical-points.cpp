/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
 *
 * https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
 *
 * algorithms
 * Medium (58.55%)
 * Likes:    1181
 * Dislikes: 63
 * Total Accepted:    162K
 * Total Submissions: 232.2K
 * Testcase Example:  '[3,1]'
 *
 * A critical point in a linked list is defined as either a local maxima or a
 * local minima.
 *
 * A node is a local maxima if the current node has a value strictly greater
 * than the previous node and the next node.
 *
 * A node is a local minima if the current node has a value strictly smaller
 * than the previous node and the next node.
 *
 * Note that a node can only be a local maxima/minima if there exists both a
 * previous node and a next node.
 *
 * Given a linked list head, return an array of length 2 containing
 * [minDistance, maxDistance] where minDistance is the minimum distance between
 * any two distinct critical points and maxDistance is the maximum distance
 * between any two distinct critical points. If there are fewer than two
 * critical points, return [-1, -1].
 *
 *
 * Example 1:
 *
 *
 * Input: head = [3,1]
 * Output: [-1,-1]
 * Explanation: There are no critical points in [3,1].
 *
 *
 * Example 2:
 *
 *
 * Input: head = [5,3,1,2,5,1,2]
 * Output: [1,3]
 * Explanation: There are three critical points:
 * - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3
 * and 2.
 * - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater
 * than 2 and 1.
 * - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5
 * and 2.
 * The minimum distance is between the fifth and the sixth node. minDistance =
 * 6 - 5 = 1.
 * The maximum distance is between the third and the sixth node. maxDistance =
 * 6 - 3 = 3.
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,3,2,2,3,2,2,2,7]
 * Output: [3,3]
 * Explanation: There are two critical points:
 * - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is
 * greater than 1 and 2.
 * - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater
 * than 2 and 2.
 * Both the minimum and maximum distances are between the second and the fifth
 * node.
 * Thus, minDistance and maxDistance is 5 - 2 = 3.
 * Note that the last node is not considered a local maxima because it does not
 * have a next node.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [2, 10^5].
 * 1 <= Node.val <= 10^5
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
    , next(nullptr)
    {
    }
    ListNode(int x)
    : val(x)
    , next(nullptr)
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        vector<int> res  = { -1, -1 };
        ListNode*   prev = NULL;
        ListNode*   curr = head;
        ListNode*   next = curr->next;
        int         idx  = 0;
        vector<int> critical;
        while (curr)
        {
            if (prev != NULL && next != NULL)
            {
                if ((curr->val > prev->val && curr->val > next->val)
                    || (curr->val < prev->val && curr->val < next->val))
                {
                    critical.push_back(idx);
                }
            }

            prev = curr;
            curr = curr->next;
            if (curr)
                next = curr->next;
            else
                next = NULL;
            idx++;
        }

        if (critical.size() >= 2)
        {
            res[0] = critical[1] - critical[0];
            for (size_t i = 1; i < critical.size(); i++)
                res[0] = min(res[0], critical[i] - critical[i - 1]);
            res[1] = critical.back() - critical.front();
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    ListNode    test_1_node_1 = ListNode(1);
    ListNode    test_1_node_0 = ListNode(3, &test_1_node_1);
    vector<int> res_1         = sol.nodesBetweenCriticalPoints(&test_1_node_0);
    for (auto res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<int>{ -1, -1 }));

    // Test_2
    ListNode    test_2_node_6 = ListNode(2);
    ListNode    test_2_node_5 = ListNode(1, &test_2_node_6);
    ListNode    test_2_node_4 = ListNode(5, &test_2_node_5);
    ListNode    test_2_node_3 = ListNode(2, &test_2_node_4);
    ListNode    test_2_node_2 = ListNode(1, &test_2_node_3);
    ListNode    test_2_node_1 = ListNode(3, &test_2_node_2);
    ListNode    test_2_node_0 = ListNode(5, &test_2_node_1);
    vector<int> res_2         = sol.nodesBetweenCriticalPoints(&test_2_node_0);
    for (auto res : res_2)
        cout << res << " ";
    cout << endl;
    assert((res_2 == vector<int>{ 1, 3 }));

    // Test_3
    ListNode    test_3_node_8 = ListNode(7);
    ListNode    test_3_node_7 = ListNode(2, &test_3_node_8);
    ListNode    test_3_node_6 = ListNode(2, &test_3_node_7);
    ListNode    test_3_node_5 = ListNode(2, &test_3_node_6);
    ListNode    test_3_node_4 = ListNode(3, &test_3_node_5);
    ListNode    test_3_node_3 = ListNode(2, &test_3_node_4);
    ListNode    test_3_node_2 = ListNode(2, &test_3_node_3);
    ListNode    test_3_node_1 = ListNode(3, &test_3_node_2);
    ListNode    test_3_node_0 = ListNode(1, &test_3_node_1);
    vector<int> res_3         = sol.nodesBetweenCriticalPoints(&test_3_node_0);
    for (auto res : res_3)
        cout << res << " ";
    cout << endl;
    assert((res_3 == vector<int>{ 3, 3 }));

    return 0;
}
// Accepted
// 139/139 cases passed (165 ms)
// Your runtime beats 63.17 % of cpp submissions
// Your memory usage beats 41.56 % of cpp submissions (119.6 MB)