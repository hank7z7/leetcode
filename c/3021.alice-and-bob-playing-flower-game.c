/*
 * @lc app=leetcode id=3021 lang=c
 *
 * [3021] Alice and Bob Playing Flower Game
 *
 * https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/
 *
 * algorithms
 * Medium (46.88%)
 * Likes:    76
 * Dislikes: 58
 * Total Accepted:    17.2K
 * Total Submissions: 36.8K
 * Testcase Example:  '3\n2'
 *
 * Alice and Bob are playing a turn-based game on a circular field surrounded
 * by flowers. The circle represents the field, and there are x flowers in the
 * clockwise direction between Alice and Bob, and y flowers in the
 * anti-clockwise direction between them.
 *
 * The game proceeds as follows:
 *
 *
 * Alice takes the first turn.
 * In each turn, a player must choose either the clockwise or anti-clockwise
 * direction and pick one flower from that side.
 * At the end of the turn, if there are no flowers left at all, the current
 * player captures their opponent and wins the game.
 *
 *
 * Given two integers, n and m, the task is to compute the number of possible
 * pairs (x, y) that satisfy the conditions:
 *
 *
 * Alice must win the game according to the described rules.
 * The number of flowers x in the clockwise direction must be in the range
 * [1,n].
 * The number of flowers y in the anti-clockwise direction must be in the range
 * [1,m].
 *
 *
 * Return the number of possible pairs (x, y) that satisfy the conditions
 * mentioned in the statement.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, m = 2
 * Output: 3
 * Explanation: The following pairs satisfy conditions described in the
 * statement: (1,2), (3,2), (2,1).
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, m = 1
 * Output: 0
 * Explanation: No pairs satisfy the conditions described in the statement.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n, m <= 10^5
 *
 *
 */
#include <stdio.h>
// @lc code=start
long long flowerGame(int n, int m)
{
    long long n_even = (long long) n / 2;
    long long n_odd  = (long long) n / 2 + ((long long) n & 1);
    long long m_even = (long long) m / 2;
    long long m_odd  = (long long) m / 2 + ((long long) m & 1);
    return n_even * m_odd + n_odd * m_even;
}
// @lc code=end
int main(int argc, char** argv)
{
    int n, m;
    // Test 1
    n = 3;
    m = 2;
    printf("%lld\n", flowerGame(n, m));

    // Test 2
    n = 1;
    m = 1;
    printf("%lld\n", flowerGame(n, m));
    return 0;
}
// Accepted
// 537/537 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 21.95 % of c submissions (5.7 MB)