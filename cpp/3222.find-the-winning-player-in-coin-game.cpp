/*
 * @lc app=leetcode id=3222 lang=cpp
 *
 * [3222] Find the Winning Player in Coin Game
 *
 * https://leetcode.com/problems/find-the-winning-player-in-coin-game/description/
 *
 * algorithms
 * Easy (45.89%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 52.7K
 * Testcase Example:  '2\n7'
 *
 * You are given two positive integers x and y, denoting the number of coins
 * with values 75 and 10 respectively.
 *
 * Alice and Bob are playing a game. Each turn, starting with Alice, the player
 * must pick up coins with a total value 115. If the player is unable to do so,
 * they lose the game.
 *
 * Return the name of the player who wins the game if both players play
 * optimally.
 *
 *
 * Example 1:
 *
 *
 * Input: x = 2, y = 7
 *
 * Output: "Alice"
 *
 * Explanation:
 *
 * The game ends in a single turn:
 *
 *
 * Alice picks 1 coin with a value of 75 and 4 coins with a value of 10.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: x = 4, y = 11
 *
 * Output: "Bob"
 *
 * Explanation:
 *
 * The game ends in 2 turns:
 *
 *
 * Alice picks 1 coin with a value of 75 and 4 coins with a value of 10.
 * Bob picks 1 coin with a value of 75 and 4 coins with a value of 10.
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= x, y <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string losingPlayer(int x, int y)
    {
        int x_turn = x;
        int y_turn = y / 4;
        int min_turn = min(x_turn, y_turn);
        if (min_turn % 2 == 0)
            return "Bob";
        else
            return "Alice";
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int x_1 = 2, y_1 = 7;
    string res_1 = sol.losingPlayer(x_1, y_1);
    cout << res_1 << endl;
    assert(res_1 == "Alice");

    // Test_2
    int x_2 = 4, y_2 = 11;
    string res_2 = sol.losingPlayer(x_2, y_2);
    cout << res_2 << endl;
    assert(res_2 == "Bob");

    return 0;
}
// Accepted
// 852/852 cases passed (5 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 25 % of cpp submissions (7.4 MB)