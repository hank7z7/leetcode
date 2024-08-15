/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 *
 * https://leetcode.com/problems/lemonade-change/description/
 *
 * algorithms
 * Easy (53.57%)
 * Likes:    2594
 * Dislikes: 172
 * Total Accepted:    259.5K
 * Total Submissions: 464.5K
 * Testcase Example:  '[5,5,5,10,20]'
 *
 * At a lemonade stand, each lemonade costs $5. Customers are standing in a
 * queue to buy from you and order one at a time (in the order specified by
 * bills). Each customer will only buy one lemonade and pay with either a $5,
 * $10, or $20 bill. You must provide the correct change to each customer so
 * that the net transaction is that the customer pays $5.
 *
 * Note that you do not have any change in hand at first.
 *
 * Given an integer array bills where bills[i] is the bill the i^th customer
 * pays, return true if you can provide every customer with the correct change,
 * or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: bills = [5,5,5,10,20]
 * Output: true
 * Explanation:
 * From the first 3 customers, we collect three $5 bills in order.
 * From the fourth customer, we collect a $10 bill and give back a $5.
 * From the fifth customer, we give a $10 bill and a $5 bill.
 * Since all customers got correct change, we output true.
 *
 *
 * Example 2:
 *
 *
 * Input: bills = [5,5,10,10,20]
 * Output: false
 * Explanation:
 * From the first two customers in order, we collect two $5 bills.
 * For the next two customers in order, we collect a $10 bill and give back a
 * $5 bill.
 * For the last customer, we can not give the change of $15 back because we
 * only have two $10 bills.
 * Since not every customer received the correct change, the answer is
 * false.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= bills.length <= 10^5
 * bills[i] is either 5, 10, or 20.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int>& bills) {
                // Count of $5 and $10 bills in hand
        int five_count = 0;
        int ten_count = 0;

        // Iterate through each customer's bill
        for (int bill : bills) {
            if (bill == 5) {
                // Just add it to our count
                five_count++;
            } else if (bill == 10) {
                // We need to give $5 change
                if (five_count > 0) {
                    five_count--;
                    ten_count++;
                } else {
                    // Can't provide change, return false
                    return false;
                }
            } else {  // bill == 20
                // We need to give $15 change
                if (ten_count > 0 && five_count > 0) {
                    // Give change as one $10 and one $5
                    five_count--;
                    ten_count--;
                } else if (five_count >= 3) {
                    // Give change as three $5
                    five_count -= 3;
                } else {
                    // Can't provide change, return false
                    return false;
                }
            }
        }
        // If we've made it through all customers, return true
        return true;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> bills_1 = { 5, 5, 5, 10, 20 };
    bool        res_1   = sol.lemonadeChange(bills_1);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    vector<int> bills_2 = { 5, 5, 10, 10, 20 };
    bool        res_2   = sol.lemonadeChange(bills_2);
    cout << res_2 << endl;
    assert(res_2 == false);

    return 0;
}
// Accepted
// 60/60 cases passed (67 ms)
// Your runtime beats 77.92 % of cpp submissions
// Your memory usage beats 50.86 % of cpp submissions (86 MB)