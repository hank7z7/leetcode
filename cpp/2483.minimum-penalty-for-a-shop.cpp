/*
 * @lc app=leetcode id=2483 lang=cpp
 *
 * [2483] Minimum Penalty for a Shop
 *
 * https://leetcode.com/problems/minimum-penalty-for-a-shop/description/
 *
 * algorithms
 * Medium (67.70%)
 * Likes:    2232
 * Dislikes: 121
 * Total Accepted:    163.3K
 * Total Submissions: 235.4K
 * Testcase Example:  '"YYNY"'
 *
 * You are given the customer visit log of a shop represented by a 0-indexed
 * string customers consisting only of characters 'N' and 'Y':
 * 
 * 
 * if the time^th character is 'Y', it means that customers come at the time^th
 * hour
 * whereas 'N' indicates that no customers come at the time^th hour.
 * 
 * 
 * If the shop closes at the j^th hour (0 <= j <= n), the penalty is calculated
 * as follows:
 * 
 * 
 * For every hour when the shop is open and no customers come, the penalty
 * increases by 1.
 * For every hour when the shop is closed and customers come, the penalty
 * increases by 1.
 * 
 * 
 * Return the earliest hour at which the shop must be closed to incur a minimum
 * penalty.
 * 
 * Note that if a shop closes at the j^th hour, it means the shop is closed at
 * the hour j.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: customers = "YYNY"
 * Output: 2
 * Explanation: 
 * - Closing the shop at the 0^th hour incurs in 1+1+0+1 = 3 penalty.
 * - Closing the shop at the 1^st hour incurs in 0+1+0+1 = 2 penalty.
 * - Closing the shop at the 2^nd hour incurs in 0+0+0+1 = 1 penalty.
 * - Closing the shop at the 3^rd hour incurs in 0+0+1+1 = 2 penalty.
 * - Closing the shop at the 4^th hour incurs in 0+0+1+0 = 1 penalty.
 * Closing the shop at 2^nd or 4^th hour gives a minimum penalty. Since 2 is
 * earlier, the optimal closing time is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: customers = "NNNNN"
 * Output: 0
 * Explanation: It is best to close the shop at the 0^th hour as no customers
 * arrive.
 * 
 * Example 3:
 * 
 * 
 * Input: customers = "YYYY"
 * Output: 4
 * Explanation: It is best to close the shop at the 4^th hour as customers
 * arrive at each hour.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= customers.length <= 10^5
 * customers consists only of characters 'Y' and 'N'.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int bestClosingTime(string customers) {
        const int n = (int)customers.length();
        int bestTime = 0;
        int minPenalty = 0;
        int currPenalty = 0;
        
        for (int time = 0; time <= n; time++) {
            if(time > 0)
            {
                currPenalty += customers[time - 1] == 'Y' ? -1 : 1;
            }
            
            if (currPenalty < minPenalty) {
                bestTime = time;
                minPenalty = currPenalty;
            }
        }
        
        return bestTime;
    }
};
// @lc code=end
int main(int argc, char const **argv) {
    Solution sol;
    // Test_1
    string customers = "YYNY";
    int res = sol.bestClosingTime(customers);
    cout << res << endl; // Expected: 2
    assert(res == 2);

    // Test_2
    customers = "NNNNN";
    res = sol.bestClosingTime(customers);
    cout << res << endl; // Expected: 0
    assert(res == 0);
    return 0;
}
// Accepted
// 42/42 cases passed (4 ms)
// Your runtime beats 81.86 % of cpp submissions
// Your memory usage beats 67.65 % of cpp submissions (13.4 MB)