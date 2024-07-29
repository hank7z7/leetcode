/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 *
 * https://leetcode.com/problems/count-number-of-teams/description/
 *
 * algorithms
 * Medium (65.95%)
 * Likes:    2921
 * Dislikes: 207
 * Total Accepted:    146.7K
 * Total Submissions: 216.7K
 * Testcase Example:  '[2,5,3,4,1]'
 *
 * There are n soldiers standing in a line. Each soldier is assigned a unique
 * rating value.
 *
 * You have to form a team of 3 soldiers amongst them under the following
 * rules:
 *
 *
 * Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j],
 * rating[k]).
 * A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] >
 * rating[j] > rating[k]) where (0 <= i < j < k < n).
 *
 *
 * Return the number of teams you can form given the conditions. (soldiers can
 * be part of multiple teams).
 *
 *
 * Example 1:
 *
 *
 * Input: rating = [2,5,3,4,1]
 * Output: 3
 * Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1),
 * (5,3,1).
 *
 *
 * Example 2:
 *
 *
 * Input: rating = [2,1,3]
 * Output: 0
 * Explanation: We can't form any team given the conditions.
 *
 *
 * Example 3:
 *
 *
 * Input: rating = [1,2,3,4]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * n == rating.length
 * 3 <= n <= 1000
 * 1 <= rating[i] <= 10^5
 * All the integers in rating are unique.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numTeams(vector<int>& rating)
    {
        int count = 0;
        int n     = (int) rating.size();
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                if (rating[i] < rating[j])
                {
                    for (int k = j + 1; k < n; k++)
                        if (rating[j] < rating[k])
                            count++;
                }
                else if (rating[i] > rating[j])
                {
                    for (int k = j + 1; k < n; k++)
                        if (rating[j] > rating[k])
                            count++;
                }
            }
        }

        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> rating_1 = { 2, 5, 3, 4, 1 };
    int         res_1    = sol.numTeams(rating_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    vector<int> rating_2 = { 2, 1, 3 };
    int         res_2    = sol.numTeams(rating_2);
    cout << res_2 << endl;
    assert(res_2 == 0);

    // Test_3
    vector<int> rating_3 = { 1, 2, 3, 4 };
    int         res_3    = sol.numTeams(rating_3);
    cout << res_3 << endl;
    assert(res_3 == 4);

    return 0;
}
