/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 *
 * https://leetcode.com/problems/spiral-matrix-iv/description/
 *
 * algorithms
 * Medium (75.76%)
 * Likes:    830
 * Dislikes: 30
 * Total Accepted:    56.3K
 * Total Submissions: 72.9K
 * Testcase Example:  '3\n5\n[3,0,2,6,8,1,7,9,4,2,5,5,0]'
 *
 * You are given two integers m and n, which represent the dimensions of a
 * matrix.
 * 
 * You are also given the head of a linked list of integers.
 * 
 * Generate an m x n matrix that contains the integers in the linked list
 * presented in spiral order (clockwise), starting from the top-left of the
 * matrix. If there are remaining empty spaces, fill them with -1.
 * 
 * Return the generated matrix.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
 * Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
 * Explanation: The diagram above shows how the values are printed in the
 * matrix.
 * Note that the remaining spaces in the matrix are filled with -1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 1, n = 4, head = [0,1,2]
 * Output: [[0,1,2,-1]]
 * Explanation: The diagram above shows how the values are printed from left to
 * right in the matrix.
 * The last space in the matrix is set to -1.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 10^5
 * 1 <= m * n <= 10^5
 * The number of nodes in the list is in the range [1, m * n].
 * 0 <= Node.val <= 1000
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
    {
        vector<vector<int>> res(m, vector<int>(n, -1));

        // Current indexes
        int       i = 0, j = 0;
        int       round = 0;
        ListNode* curr  = head;
        while (curr)
        {
            int rd = n - 1 - round * 2;  // Right distance
            // Go right
            while (curr && rd > 0)
            {
                res[i][j] = curr->val;
                // Update indexes
                j++;
                rd--;
                curr = curr->next;
            }

            int dd = m - 1 - round * 2;  // Down distance
            // Go down
            while (curr && dd)
            {
                res[i][j] = curr->val;
                // Update indexes
                i++;
                dd--;
                curr = curr->next;
            }

            int ld = n - 1 - round * 2;  // Left distance
            // Go down
            while (curr && ld)
            {
                res[i][j] = curr->val;
                // Update indexes
                j--;
                ld--;
                curr = curr->next;
            }

            int ud = m - 1 - round * 2 - 1;  // Up distance
            // Go down
            while (curr && ud)
            {
                res[i][j] = curr->val;
                // Update indexes
                i--;
                ud--;
                curr = curr->next;
            }

            // Go right and go next round
            if (curr)
            {
                res[i][j] = curr->val;
                j++;
                curr = curr->next;
            }

            round++;
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int                 m_1 = 3, n_1 = 5;
    ListNode            ll_1_node12 = ListNode(0);
    ListNode            ll_1_node11 = ListNode(5, &ll_1_node12);
    ListNode            ll_1_node10 = ListNode(5, &ll_1_node11);
    ListNode            ll_1_node9  = ListNode(2, &ll_1_node10);
    ListNode            ll_1_node8  = ListNode(4, &ll_1_node9);
    ListNode            ll_1_node7  = ListNode(9, &ll_1_node8);
    ListNode            ll_1_node6  = ListNode(7, &ll_1_node7);
    ListNode            ll_1_node5  = ListNode(1, &ll_1_node6);
    ListNode            ll_1_node4  = ListNode(8, &ll_1_node5);
    ListNode            ll_1_node3  = ListNode(6, &ll_1_node4);
    ListNode            ll_1_node2  = ListNode(2, &ll_1_node3);
    ListNode            ll_1_node1  = ListNode(0, &ll_1_node2);
    ListNode            ll_1_node0  = ListNode(3, &ll_1_node1);
    vector<vector<int>> res_1       = sol.spiralMatrix(m_1, n_1, &ll_1_node0);
    for (auto r : res_1)
    {
        for (auto elem : r)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;
    assert((res_1
            == vector<vector<int>>{ { 3, 0, 2, 6, 8 }, { 5, 0, -1, -1, 1 }, { 5, 2, 4, 9, 7 } }));

    // Test_1
    int                 m_2 = 1, n_2 = 4;
    ListNode            ll_2_node2 = ListNode(2);
    ListNode            ll_2_node1 = ListNode(1, &ll_2_node2);
    ListNode            ll_2_node0 = ListNode(0, &ll_2_node1);
    vector<vector<int>> res_2      = sol.spiralMatrix(m_2, n_2, &ll_2_node0);
    for (auto r : res_2)
    {
        for (auto elem : r)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;
    assert((res_2 == vector<vector<int>>{ { 0, 1, 2, -1 } }));

    return 0;
}
// Accepted
// 50/50 cases passed (159 ms)
// Your runtime beats 73.51 % of cpp submissions
// Your memory usage beats 17.37 % of cpp submissions (130.7 MB)