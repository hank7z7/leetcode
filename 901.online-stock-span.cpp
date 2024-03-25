/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 *
 * https://leetcode.com/problems/online-stock-span/description/
 *
 * algorithms
 * Medium (65.69%)
 * Likes:    6150
 * Dislikes: 389
 * Total Accepted:    297.6K
 * Total Submissions: 452.8K
 * Testcase Example:  '["StockSpanner","next","next","next","next","next","next","next"]\n' +
  '[[],[100],[80],[60],[70],[60],[75],[85]]'
 *
 * Design an algorithm that collects daily price quotes for some stock and
 * returns the span of that stock's price for the current day.
 *
 * The span of the stock's price in one day is the maximum number of
 * consecutive days (starting from that day and going backward) for which the
 * stock price was less than or equal to the price of that day.
 *
 *
 * For example, if the prices of the stock in the last four days is [7,2,1,2]
 * and the price of the stock today is 2, then the span of today is 4 because
 * starting from today, the price of the stock was less than or equal 2 for 4
 * consecutive days.
 * Also, if the prices of the stock in the last four days is [7,34,1,2] and the
 * price of the stock today is 8, then the span of today is 3 because starting
 * from today, the price of the stock was less than or equal 8 for 3
 * consecutive days.
 *
 *
 * Implement the StockSpanner class:
 *
 *
 * StockSpanner() Initializes the object of the class.
 * int next(int price) Returns the span of the stock's price given that today's
 * price is price.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
 * [[], [100], [80], [60], [70], [60], [75], [85]]
 * Output
 * [null, 1, 1, 1, 2, 1, 4, 6]
 *
 * Explanation
 * StockSpanner stockSpanner = new StockSpanner();
 * stockSpanner.next(100); // return 1
 * stockSpanner.next(80);  // return 1
 * stockSpanner.next(60);  // return 1
 * stockSpanner.next(70);  // return 2
 * stockSpanner.next(60);  // return 1
 * stockSpanner.next(75);  // return 4, because the last 4 prices (including
 * today's price of 75) were less than or equal to today's price.
 * stockSpanner.next(85);  // return 6
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= price <= 10^5
 * At most 10^4 calls will be made to next.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class StockSpanner
{
private:
    // price, number of consecutive prices less and equal to it
    stack<pair<int, int>> st;

public:
    StockSpanner() {}

    int next(int price)
    {
        int count = 1;
        while (!st.empty() && (st.top().first <= price))
        {
            count += st.top().second;
            st.pop();
        }
        st.push({ price, count });
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
int main(int argc, char** argv)
{
    StockSpanner obj = StockSpanner();
    cout << obj.next(100) << endl;
    cout << obj.next(80) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(70) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(75) << endl;
    cout << obj.next(85) << endl;
    // free(obj);
    // obj = NULL;

    return 0;
}
// Accepted
// 99/99 cases passed (168 ms)
// Your runtime beats 42.6 % of cpp submissions
// Your memory usage beats 52.58 % of cpp submissions (89 MB)