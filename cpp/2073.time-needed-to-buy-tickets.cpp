/*
 * @lc app=leetcode id=2073 lang=cpp
 *
 * [2073] Time Needed to Buy Tickets
 *
 * https://leetcode.com/problems/time-needed-to-buy-tickets/description/
 *
 * algorithms
 * Easy (63.08%)
 * Likes:    1007
 * Dislikes: 88
 * Total Accepted:    78.7K
 * Total Submissions: 120.4K
 * Testcase Example:  '[2,3,2]\n2'
 *
 * There are n people in a line queuing to buy tickets, where the 0^th person
 * is at the front of the line and the (n - 1)^th person is at the back of the
 * line.
 *
 * You are given a 0-indexed integer array tickets of length n where the number
 * of tickets that the i^th person would like to buy is tickets[i].
 *
 * Each person takes exactly 1 second to buy a ticket. A person can only buy 1
 * ticket at a time and has to go back to the end of the line (which happens
 * instantaneously) in order to buy more tickets. If a person does not have any
 * tickets left to buy, the person will leave the line.
 *
 * Return the time taken for the person at position k (0-indexed) to finish
 * buying tickets.
 *
 *
 * Example 1:
 *
 *
 * Input: tickets = [2,3,2], k = 2
 * Output: 6
 * Explanation:
 * - In the first pass, everyone in the line buys a ticket and the line becomes
 * [1, 2, 1].
 * - In the second pass, everyone in the line buys a ticket and the line
 * becomes [0, 1, 0].
 * The person at position 2 has successfully bought 2 tickets and it took 3 + 3
 * = 6 seconds.
 *
 *
 * Example 2:
 *
 *
 * Input: tickets = [5,1,1,1], k = 0
 * Output: 8
 * Explanation:
 * - In the first pass, everyone in the line buys a ticket and the line becomes
 * [4, 0, 0, 0].
 * - In the next 4 passes, only the person in position 0 is buying tickets.
 * The person at position 0 has successfully bought 5 tickets and it took 4 + 1
 * + 1 + 1 + 1 = 8 seconds.
 *
 *
 *
 * Constraints:
 *
 *
 * n == tickets.length
 * 1 <= n <= 100
 * 1 <= tickets[i] <= 100
 * 0 <= k < n
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int timeRequiredToBuy(const vector<int>& tickets, const int k)
    {
        int count = 0;
        for (int i = 0; i < (int) tickets.size(); i++)
        {
            if (i <= k)
            {
                if (tickets[i] >= tickets[k])
                    count += tickets[k];
                else
                    count += tickets[i];
            }
            else
            {
                if (tickets[i] >= (tickets[k] - 1))
                    count += (tickets[k] - 1);
                else
                    count += tickets[i];
            }
        }
        // Simulation method
        /*
        while (tickets[k] != 0)
        {
            for (int i = 0; i < (int) tickets.size(); i++)
            {
                if (tickets[i] != 0)
                {
                    tickets[i]--;
                    count++;
                }
                if (tickets[k] == 0)
                    break;
            }
        }
        */
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> tickets_1 = { 2, 3, 2 };
    int         k_1       = 2;
    cout << sol.timeRequiredToBuy(tickets_1, k_1) << endl;

    // Test_2
    vector<int> tickets_2 = { 5, 1, 1, 1 };
    int         k_2       = 0;
    cout << sol.timeRequiredToBuy(tickets_2, k_2) << endl;

    // Test_3
    vector<int> tickets_3 = { 84, 49, 5, 24, 70, 77, 87, 8 };
    int         k_3       = 3;
    cout << sol.timeRequiredToBuy(tickets_3, k_3) << endl;

    return 0;
}
// Accepted
// 65/65 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.56 % of cpp submissions (9.3 MB)

// Simulation method
// Accepted
// 65/65 cases passed (4 ms)
// Your runtime beats 41.19 % of cpp submissions
// Your memory usage beats 67.56 % of cpp submissions (9.4 MB)