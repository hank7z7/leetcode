/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 *
 * https://leetcode.com/problems/minimum-cost-for-tickets/description/
 *
 * algorithms
 * Medium (65.24%)
 * Likes:    8222
 * Dislikes: 162
 * Total Accepted:    356.2K
 * Total Submissions: 538.2K
 * Testcase Example:  '[1,4,6,7,8,20]\n[2,7,15]'
 *
 * You have planned some train traveling one year in advance. The days of the
 * year in which you will travel are given as an integer array days. Each day
 * is an integer from 1 to 365.
 *
 * Train tickets are sold in three different ways:
 *
 *
 * a 1-day pass is sold for costs[0] dollars,
 * a 7-day pass is sold for costs[1] dollars, and
 * a 30-day pass is sold for costs[2] dollars.
 *
 *
 * The passes allow that many days of consecutive travel.
 *
 *
 * For example, if we get a 7-day pass on day 2, then we can travel for 7 days:
 * 2, 3, 4, 5, 6, 7, and 8.
 *
 *
 * Return the minimum number of dollars you need to travel every day in the
 * given list of days.
 *
 *
 * Example 1:
 *
 *
 * Input: days = [1,4,6,7,8,20], costs = [2,7,15]
 * Output: 11
 * Explanation: For example, here is one way to buy passes that lets you travel
 * your travel plan:
 * On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
 * On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3,
 * 4, ..., 9.
 * On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
 * In total, you spent $11 and covered all the days of your travel.
 *
 *
 * Example 2:
 *
 *
 * Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * Output: 17
 * Explanation: For example, here is one way to buy passes that lets you travel
 * your travel plan:
 * On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1,
 * 2, ..., 30.
 * On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
 * In total, you spent $17 and covered all the days of your travel.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days is in strictly increasing order.
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define ONE (1)
#define SEVEN (7)
#define THIRTY (30)
#define ONE_DAY (0)
#define SEVEN_DAY (1)
#define THIRTY_DAYS (2)
class Solution
{
public:
    int mincostTickets(const vector<int>& days, const vector<int>& costs)
    {
        // No need to sort days since days is in strictly increasing order

        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, 0);

        int i = 0;
        for (int day = 1; day <= lastDay; day++)
        {
            if (day < days[i])
            {
                dp[day] = dp[day - ONE];
            }
            else
            {
                i++;
                dp[day] = min({ dp[day - ONE] + costs[ONE_DAY],
                                dp[max(0, day - SEVEN)] + costs[SEVEN_DAY],
                                dp[max(0, day - THIRTY)] + costs[THIRTY_DAYS] });
            }
        }

        return dp[lastDay];
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> days_1 = { 1, 4, 6, 7, 8, 20 };
    vector<int> costs_1 = { 2, 7, 15 };
    int res_1 = sol.mincostTickets(days_1, costs_1);
    cout << res_1 << endl;
    assert(res_1 == 11);

    // Test_2
    vector<int> days_2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31 };
    vector<int> costs_2 = { 2, 7, 15 };
    int res_2 = sol.mincostTickets(days_2, costs_2);
    cout << res_2 << endl;
    assert(res_2 == 17);

    return 0;
}
// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 55.34 % of cpp submissions (12.9 MB)