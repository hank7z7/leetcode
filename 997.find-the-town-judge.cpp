/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 *
 * https://leetcode.com/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (49.07%)
 * Likes:    6162
 * Dislikes: 518
 * Total Accepted:    483.9K
 * Total Submissions: 981.6K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * In a town, there are n people labeled from 1 to n. There is a rumor that one
 * of these people is secretly the town judge.
 *
 * If the town judge exists, then:
 *
 *
 * The town judge trusts nobody.
 * Everybody (except for the town judge) trusts the town judge.
 * There is exactly one person that satisfies properties 1 and 2.
 *
 *
 * You are given an array trust where trust[i] = [ai, bi] representing that the
 * person labeled ai trusts the person labeled bi. If a trust relationship does
 * not exist in trust array, then such a trust relationship does not exist.
 *
 * Return the label of the town judge if the town judge exists and can be
 * identified, or return -1 otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2, trust = [[1,2]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, trust = [[1,3],[2,3]]
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3, trust = [[1,3],[2,3],[3,1]]
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 * 0 <= trust.length <= 10^4
 * trust[i].length == 2
 * All the pairs of trust are unique.
 * ai != bi
 * 1 <= ai, bi <= n
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define N_MAX (1000 + 1)
class Solution
{
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        int           l = trust.size();
        bitset<N_MAX> bs;
        vector<int>   be_trusted(n + 1, 0);
        bs.reset();
        bs.set(0);
        for (int i = n + 1; i < N_MAX; i++)
            bs.set(i);
        for (int i = 0; i < l; i++)
        {
            bs.set(trust[i][0]);
            be_trusted[trust[i][1]]++;
        }
        bs.flip();
        if (bs.count() != 1)
            return -1;
        for (int i = 1; i <= n; i++)
            if (bs[i])
            {
                if (be_trusted[i] == (n - 1))
                    return i;
                else
                    return -1;
            }

        return -1;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      n;
    // Test_1
    n                           = 2;
    vector<vector<int>> trust_1 = { { 1, 2 } };
    cout << sol.findJudge(n, trust_1) << endl;

    // Test_2
    n                           = 3;
    vector<vector<int>> trust_2 = { { 1, 3 }, { 2, 3 } };
    cout << sol.findJudge(n, trust_2) << endl;

    // Test_3
    n                           = 3;
    vector<vector<int>> trust_3 = { { 1, 3 }, { 2, 3 }, { 3, 1 } };
    cout << sol.findJudge(n, trust_3) << endl;

    // Test_4
    n                           = 3;
    vector<vector<int>> trust_4 = { { 1, 2 }, { 2, 3 } };
    cout << sol.findJudge(n, trust_4) << endl;

    return 0;
}
// Accepted
// 92/92 cases passed (102 ms)
// Your runtime beats 98.34 % of cpp submissions
// Your memory usage beats 62.99 % of cpp submissions (64.3 MB)