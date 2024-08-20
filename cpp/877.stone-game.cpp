/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 *
 * https://leetcode.com/problems/stone-game/description/
 *
 * algorithms
 * Medium (70.80%)
 * Likes:    3285
 * Dislikes: 2895
 * Total Accepted:    250K
 * Total Submissions: 352.7K
 * Testcase Example:  '[5,3,4,5]'
 *
 * Alice and Bob play a game with piles of stones. There are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].
 *
 * The objective of the game is to end with the most stones. The total number
 * of stones across all the piles is odd, so there are no ties.
 *
 * Alice and Bob take turns, with Alice starting first. Each turn, a player
 * takes the entire pile of stones either from the beginning or from the end of
 * the row. This continues until there are no more piles left, at which point
 * the person with the most stones wins.
 *
 * Assuming Alice and Bob play optimally, return true if Alice wins the game,
 * or false if Bob wins.
 *
 *
 * Example 1:
 *
 *
 * Input: piles = [5,3,4,5]
 * Output: true
 * Explanation:
 * Alice starts first, and can only take the first 5 or the last 5.
 * Say she takes the first 5, so that the row becomes [3, 4, 5].
 * If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10
 * points.
 * If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win
 * with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alice, so
 * we return true.
 *
 *
 * Example 2:
 *
 *
 * Input: piles = [3,7,2,3]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles[i]) is odd.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> piles_1 = {5, 3, 4, 5};
    int res_1 = sol.stoneGame(piles_1);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    vector<int> piles_2 = {3, 7, 2, 3};
    int res_2 = sol.stoneGame(piles_2);
    cout << res_2 << endl;
    assert(res_2 == true);

    return 0;
}
// Accepted
// 46/46 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 49.06 % of cpp submissions (9.6 MB)