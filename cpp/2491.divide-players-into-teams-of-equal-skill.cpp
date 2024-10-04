/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 *
 * https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/
 *
 * algorithms
 * Medium (60.16%)
 * Likes:    637
 * Dislikes: 15
 * Total Accepted:    69.5K
 * Total Submissions: 106.4K
 * Testcase Example:  '[3,2,5,1,3,4]'
 *
 * You are given a positive integer array skill of even length n where skill[i]
 * denotes the skill of the i^th player. Divide the players into n / 2 teams of
 * size 2 such that the total skill of each team is equal.
 *
 * The chemistry of a team is equal to the product of the skills of the players
 * on that team.
 *
 * Return the sum of the chemistry of all the teams, or return -1 if there is
 * no way to divide the players into teams such that the total skill of each
 * team is equal.
 *
 *
 * Example 1:
 *
 *
 * Input: skill = [3,2,5,1,3,4]
 * Output: 22
 * Explanation:
 * Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where
 * each team has a total skill of 6.
 * The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8
 * + 9 = 22.
 *
 *
 * Example 2:
 *
 *
 * Input: skill = [3,4]
 * Output: 12
 * Explanation:
 * The two players form a team with a total skill of 7.
 * The chemistry of the team is 3 * 4 = 12.
 *
 *
 * Example 3:
 *
 *
 * Input: skill = [1,1,2,3]
 * Output: -1
 * Explanation:
 * There is no way to divide the players into teams such that the total skill
 * of each team is equal.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= skill.length <= 10^5
 * skill.length is even.
 * 1 <= skill[i] <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long dividePlayers(vector<int>& skill)
    {
        const int n = (int) skill.size();
        const int teams = n / 2;
        // skill -> count
        unordered_map<int, int> um;
        int total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            total_sum += skill[i];
            um[skill[i]]++;
        }
        const int team_skill = total_sum / teams;

        long long res = 0;
        for (auto it : um)
        {
            if( it.second != um[team_skill - it.first])
                return -1;
            if (it.second > 0 && it.second == um[team_skill - it.first])
            {
                cout << it.first << " " << team_skill - it.first << endl;
                res += ((long long) it.second * (long long) it.first * (long long) (team_skill - it.first));
                it.second = 0;
                um[team_skill - it.first] = 0;
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> skill_1 = { 3, 2, 5, 1, 3, 4 };
    int res_1 = sol.dividePlayers(skill_1);
    cout << res_1 << endl;
    assert(res_1 == 22);

    // Test_2
    vector<int> skill_2 = { 3, 4 };
    int res_2 = sol.dividePlayers(skill_2);
    cout << res_2 << endl;
    assert(res_2 == 12);

    // Test_3
    vector<int> skill_3 = { 1, 1, 2, 3 };
    int res_3 = sol.dividePlayers(skill_3);
    cout << res_3 << endl;
    assert(res_3 == -1);

    return 0;
}
