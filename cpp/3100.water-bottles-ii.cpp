/*
 * @lc app=leetcode id=3100 lang=cpp
 *
 * [3100] Water Bottles II
 *
 * https://leetcode.com/problems/water-bottles-ii/description/
 *
 * algorithms
 * Medium (55.28%)
 * Likes:    3
 * Dislikes: 2
 * Total Accepted:    14.7K
 * Total Submissions: 26.5K
 * Testcase Example:  '13\n6'
 *
 * You are given two integers numBottles and numExchange.
 *
 * numBottles represents the number of full water bottles that you initially
 * have. In one operation, you can perform one of the following
 * operations:
 *
 *
 * Drink any number of full water bottles turning them into empty bottles.
 * Exchange numExchange empty bottles with one full water bottle. Then,
 * increase numExchange by one.
 *
 *
 * Note that you cannot exchange multiple batches of empty bottles for the same
 * value of numExchange. For example, if numBottles == 3 and numExchange == 1,
 * you cannot exchange 3 empty water bottles for 3 full bottles.
 *
 * Return the maximum number of water bottles you can drink.
 *
 *
 * Example 1:
 *
 *
 * Input: numBottles = 13, numExchange = 6
 * Output: 15
 * Explanation: The table above shows the number of full water bottles, empty
 * water bottles, the value of numExchange, and the number of bottles drunk.
 *
 *
 * Example 2:
 *
 *
 * Input: numBottles = 10, numExchange = 3
 * Output: 13
 * Explanation: The table above shows the number of full water bottles, empty
 * water bottles, the value of numExchange, and the number of bottles
 * drunk.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numBottles <= 100
 * 1 <= numExchange <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int drunk = 0;
        int empty = 0;
        while (numBottles > 0)
        {
            drunk += numBottles;
            empty += numBottles;
            numBottles = 0;
            while (empty >= numExchange)
            {
                numBottles++;
                empty -= numExchange;
                numExchange++;
            }
        }
        return drunk;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int numBottles_1 = 13;
    int numExchange_1 = 6;
    cout << sol.maxBottlesDrunk(numBottles_1, numExchange_1) << endl;

    // Test_2
    int numBottles_2 = 10;
    int numExchange_2 = 3;
    cout << sol.maxBottlesDrunk(numBottles_2, numExchange_2) << endl;
    return 0;
}
// Accepted
// 958/958 cases passed (5 ms)
// Your runtime beats 20 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (7.5 MB)