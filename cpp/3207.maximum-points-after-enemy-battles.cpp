/*
 * @lc app=leetcode id=3207 lang=cpp
 *
 * [3207] Maximum Points After Enemy Battles
 *
 * https://leetcode.com/problems/maximum-points-after-enemy-battles/description/
 *
 * algorithms
 * Medium (24.97%)
 * Likes:    21
 * Dislikes: 12
 * Total Accepted:    14.9K
 * Total Submissions: 56.4K
 * Testcase Example:  '[3,2,2]\n2'
 *
 * You are given an integer array enemyEnergies denoting the energy values of
 * various enemies.
 *
 * You are also given an integer currentEnergy denoting the amount of energy
 * you have initially.
 *
 * You start with 0 points, and all the enemies are unmarked initially.
 *
 * You can perform either of the following operations zero or multiple times to
 * gain points:
 *
 *
 * Choose an unmarked enemy, i, such that currentEnergy >= enemyEnergies[i]. By
 * choosing this option:
 *
 *
 * You gain 1 point.
 * Your energy is reduced by the enemy's energy, i.e. currentEnergy =
 * currentEnergy - enemyEnergies[i].
 *
 *
 * If you have at least 1 point, you can choose an unmarked enemy, i. By
 * choosing this option:
 *
 * Your energy increases by the enemy's energy, i.e. currentEnergy =
 * currentEnergy + enemyEnergies[i].
 * The enemy i is marked.
 *
 *
 *
 *
 * Return an integer denoting the maximum points you can get in the end by
 * optimally performing operations.
 *
 *
 * Example 1:
 *
 *
 * Input: enemyEnergies = [3,2,2], currentEnergy = 2
 *
 * Output: 3
 *
 * Explanation:
 *
 * The following operations can be performed to get 3 points, which is the
 * maximum:
 *
 *
 * First operation on enemy 1: points increases by 1, and currentEnergy
 * decreases by 2. So, points = 1, and currentEnergy = 0.
 * Second operation on enemy 0: currentEnergy increases by 3, and enemy 0 is
 * marked. So, points = 1, currentEnergy = 3, and marked enemies = [0].
 * First operation on enemy 2: points increases by 1, and currentEnergy
 * decreases by 2. So, points = 2, currentEnergy = 1, and marked enemies =
 * [0].
 * Second operation on enemy 2: currentEnergy increases by 2, and enemy 2 is
 * marked. So, points = 2, currentEnergy = 3, and marked enemies = [0, 2].
 * First operation on enemy 1: points increases by 1, and currentEnergy
 * decreases by 2. So, points = 3, currentEnergy = 1, and marked enemies = [0,
 * 2].
 *
 *
 *
 * Example 2:
 *
 *
 * Input: enemyEnergies = [2], currentEnergy = 10
 *
 * Output: 5
 *
 * Explanation:
 *
 * Performing the first operation 5 times on enemy 0 results in the maximum
 * number of points.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= enemyEnergies.length <= 10^5
 * 1 <= enemyEnergies[i] <= 10^9
 * 0 <= currentEnergy <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
    {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        long long points = 0;
        int left = 0, right = enemyEnergies.size() - 1;

        while (left <= right)
        {
            if (currentEnergy >= enemyEnergies[left])
            {
                // Gain a point by attacking
                points += currentEnergy / enemyEnergies[left];
                currentEnergy = currentEnergy % enemyEnergies[left];
            }
            else if (points > 0)
            {
                // Increase energy by marking an enemy
                currentEnergy += enemyEnergies[right];
                right--;
            }
            else
            {
                // Can't attack or mark anymore
                break;
            }
        }

        return points;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> enemyEnergies_1 = {3, 2, 2};
    int currentEnergy_1 = 2;
    long long res_1 = sol.maximumPoints(enemyEnergies_1, currentEnergy_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    vector<int> enemyEnergies_2 = {2};
    int currentEnergy_2 = 10;
    long long res_2 = sol.maximumPoints(enemyEnergies_2, currentEnergy_2);
    cout << res_2 << endl;
    assert(res_2 == 5);

    return 0;
}
// Accepted
// 579/579 cases passed (115 ms)
// Your runtime beats 41.67 % of cpp submissions
// Your memory usage beats 50 % of cpp submissions (76.2 MB)