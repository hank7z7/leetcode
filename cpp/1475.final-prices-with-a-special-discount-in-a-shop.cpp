/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 *
 * https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
 *
 * algorithms
 * Easy (78.61%)
 * Likes:    2546
 * Dislikes: 129
 * Total Accepted:    257.3K
 * Total Submissions: 312.7K
 * Testcase Example:  '[8,4,6,2,3]'
 *
 * You are given an integer array prices where prices[i] is the price of the
 * i^th item in a shop.
 *
 * There is a special discount for items in the shop. If you buy the i^th item,
 * then you will receive a discount equivalent to prices[j] where j is the
 * minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you
 * will not receive any discount at all.
 *
 * Return an integer array answer where answer[i] is the final price you will
 * pay for the i^th item of the shop, considering the special discount.
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [8,4,6,2,3]
 * Output: [4,2,4,2,3]
 * Explanation:
 * For item 0 with price[0]=8 you will receive a discount equivalent to
 * prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
 * For item 1 with price[1]=4 you will receive a discount equivalent to
 * prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
 * For item 2 with price[2]=6 you will receive a discount equivalent to
 * prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
 * For items 3 and 4 you will not receive any discount at all.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [1,2,3,4,5]
 * Output: [1,2,3,4,5]
 * Explanation: In this case, for all items, you will not receive any discount
 * at all.
 *
 *
 * Example 3:
 *
 *
 * Input: prices = [10,1,1,6]
 * Output: [9,0,1,6]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 500
 * 1 <= prices[i] <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> finalPrices(const vector<int> &prices)
    {
        const int n = (int)prices.size();
        // Create a copy of prices array to store discounted prices
        vector<int> result = prices;

        stack<int> stack;

        for (int i = 0; i < n; i++)
        {
            // Process items that can be discounted by current price
            while (!stack.empty() && prices[stack.top()] >= prices[i])
            {
                // Apply discount to previous item using current price
                result[stack.top()] -= prices[i];
                stack.pop();
            }
            // Add current index to stack
            stack.push(i);
        }

        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> prices_1 = {8, 4, 6, 2, 3};
    vector<int> res_1 = sol.finalPrices(prices_1);
    for (auto &res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<int>{4, 2, 4, 2, 3}));

    // Test_2
    vector<int> prices_2 = {1, 2, 3, 4, 5};
    vector<int> res_2 = sol.finalPrices(prices_2);
    for (auto &res : res_2)
        cout << res << " ";
    cout << endl;
    assert((res_2 == vector<int>{1, 2, 3, 4, 5}));

    // Test_3
    vector<int> prices_3 = {10, 1, 1, 6};
    vector<int> res_3 = sol.finalPrices(prices_3);
    for (auto &res : res_3)
        cout << res << " ";
    cout << endl;
    assert((res_3 == vector<int>{9, 0, 1, 6}));

    return 0;
}
// Accepted
// 103/103 cases passed (3 ms)
// Your runtime beats 16 % of cpp submissions
// Your memory usage beats 9.86 % of cpp submissions (14.3 MB)