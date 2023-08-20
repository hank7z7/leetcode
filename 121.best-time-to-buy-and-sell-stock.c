/*
 * @lc app=leetcode id=121 lang=c
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (53.92%)
 * Likes:    27679
 * Dislikes: 910
 * Total Accepted:    3.7M
 * Total Submissions: 6.8M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you
 * must buy before you sell.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit =
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 *
 *
 */

// @lc code=start
int maxProfit(int *prices, int pricesSize)
{
	int min_from_now = 100000;
	int max_profit = 0;
	int i;

	for (i = 0; i < pricesSize; i++) {
		int price_i = prices[i];
		if (price_i < min_from_now) {
			min_from_now = price_i;
		}
		if (price_i > min_from_now) {
			if ((price_i - min_from_now) > max_profit) {
				max_profit = price_i - min_from_now;
			}
		}
	}

	return max_profit;
}

// @lc code=end
// Accepted
// 212/212 cases passed (95 ms)
// Your runtime beats 86.25 % of c submissions
// Your memory usage beats 18.5 % of c submissions (13 MB)

