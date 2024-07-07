/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 *
 * https://leetcode.com/problems/water-bottles/description/
 *
 * algorithms
 * Easy (61.09%)
 * Likes:    1500
 * Dislikes: 121
 * Total Accepted:    181.3K
 * Total Submissions: 261.5K
 * Testcase Example:  '9\n3'
 *
 * There are numBottles water bottles that are initially full of water. You can
 * exchange numExchange empty water bottles from the market with one full water
 * bottle.
 *
 * The operation of drinking a full water bottle turns it into an empty
 * bottle.
 *
 * Given the two integers numBottles and numExchange, return the maximum number
 * of water bottles you can drink.
 *
 *
 * Example 1:
 *
 *
 * Input: numBottles = 9, numExchange = 3
 * Output: 13
 * Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
 * Number of water bottles you can drink: 9 + 3 + 1 = 13.
 *
 *
 * Example 2:
 *
 *
 * Input: numBottles = 15, numExchange = 4
 * Output: 19
 * Explanation: You can exchange 4 empty bottles to get 1 full water bottle.
 * Number of water bottles you can drink: 15 + 3 + 1 = 19.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numBottles <= 100
 * 2 <= numExchange <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int res = 0;
        int empty = 0;
        while (numBottles > 0)
        {
            int drink = numBottles;
            res += drink;
            numBottles = (drink + empty) / numExchange;
            empty = (drink + empty) % numExchange;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int numBottles_1 = 9;
    int numExchange_1 = 3;
    int res_1 = sol.numWaterBottles(numBottles_1, numExchange_1);
    cout << res_1 << endl;
    assert(res_1 == 13);

    // Test_2
    int numBottles_2 = 15;
    int numExchange_2 = 4;
    int res_2 = sol.numWaterBottles(numBottles_2, numExchange_2);
    cout << res_2 << endl;
    assert(res_2 == 19);

    // Test_3
    int numBottles_3 = 15;
    int numExchange_3 = 8;
    int res_3 = sol.numWaterBottles(numBottles_3, numExchange_3);
    cout << res_3 << endl;
    assert(res_3 == 17);

    return 0;
}
// Accepted
// 64/64 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.3 % of cpp submissions (7.1 MB)