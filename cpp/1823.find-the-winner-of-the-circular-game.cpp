/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 *
 * https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
 *
 * algorithms
 * Medium (78.51%)
 * Likes:    3478
 * Dislikes: 90
 * Total Accepted:    222.8K
 * Total Submissions: 275.7K
 * Testcase Example:  '5\n2'
 *
 * There are n friends that are playing a game. The friends are sitting in a
 * circle and are numbered from 1 to n in clockwise order. More formally,
 * moving clockwise from the i^th friend brings you to the (i+1)^th friend for
 * 1 <= i < n, and moving clockwise from the n^th friend brings you to the 1^st
 * friend.
 *
 * The rules of the game are as follows:
 *
 *
 * Start at the 1^st friend.
 * Count the next k friends in the clockwise direction including the friend you
 * started at. The counting wraps around the circle and may count some friends
 * more than once.
 * The last friend you counted leaves the circle and loses the game.
 * If there is still more than one friend in the circle, go back to step 2
 * starting from the friend immediately clockwise of the friend who just lost
 * and repeat.
 * Else, the last friend in the circle wins the game.
 *
 *
 * Given the number of friends, n, and an integer k, return the winner of the
 * game.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5, k = 2
 * Output: 3
 * Explanation: Here are the steps of the game:
 * 1) Start at friend 1.
 * 2) Count 2 friends clockwise, which are friends 1 and 2.
 * 3) Friend 2 leaves the circle. Next start is friend 3.
 * 4) Count 2 friends clockwise, which are friends 3 and 4.
 * 5) Friend 4 leaves the circle. Next start is friend 5.
 * 6) Count 2 friends clockwise, which are friends 5 and 1.
 * 7) Friend 1 leaves the circle. Next start is friend 3.
 * 8) Count 2 friends clockwise, which are friends 3 and 5.
 * 9) Friend 5 leaves the circle. Only friend 3 is left, so they are the
 * winner.
 *
 * Example 2:
 *
 *
 * Input: n = 6, k = 5
 * Output: 1
 * Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is
 * friend 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= n <= 500
 *
 *
 *
 * Follow up:
 *
 * Could you solve this problem in linear time with constant space?
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        int res = 0;
        for (int player_num = 2; player_num <= n; ++player_num)
        {
            res = (res + k) % player_num;
        }
        return res + 1;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int n_1 = 5;
    int k_1 = 2;
    int res_1 = sol.findTheWinner(n_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    int n_2 = 6;
    int k_2 = 5;
    int res_2 = sol.findTheWinner(n_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    return 0;
}
// Accepted
// 95/95 cases passed (3 ms)
// Your runtime beats 65.36 % of cpp submissions
// Your memory usage beats 76.96 % of cpp submissions (7.1 MB)