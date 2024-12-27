/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 *
 * https://leetcode.com/problems/best-sightseeing-pair/description/
 *
 * algorithms
 * Medium (59.38%)
 * Likes:    2844
 * Dislikes: 67
 * Total Accepted:    131.9K
 * Total Submissions: 218.2K
 * Testcase Example:  '[8,1,5,2,6]'
 *
 * You are given an integer array values where values[i] represents the value
 * of the i^th sightseeing spot. Two sightseeing spots i and j have a distance
 * j - i between them.
 *
 * The score of a pair (i < j) of sightseeing spots is values[i] + values[j] +
 * i - j: the sum of the values of the sightseeing spots, minus the distance
 * between them.
 *
 * Return the maximum score of a pair of sightseeing spots.
 *
 *
 * Example 1:
 *
 *
 * Input: values = [8,1,5,2,6]
 * Output: 11
 * Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 =
 * 11
 *
 *
 * Example 2:
 *
 *
 * Input: values = [1,2]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= values.length <= 5 * 10^4
 * 1 <= values[i] <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxScoreSightseeingPair(const vector<int>& values)
    {
        const int n = (int) values.size();

        // The left score is initially just the value of the first element.
        int maxLeftScore = values[0];

        int maxScore = 0;

        for (int i = 1; i < n; i++)
        {
            int currentRightScore = values[i] - i;
            // Update the maximum score by combining the best left score so far
            // with the current right score.
            maxScore = max(maxScore, maxLeftScore + currentRightScore);

            int currentLeftScore = values[i] + i;
            // Update the maximum left score up to the current index.
            maxLeftScore = max(maxLeftScore, currentLeftScore);
        }

        return maxScore;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> val_1 = { 8, 1, 5, 2, 6 };
    int res_1 = sol.maxScoreSightseeingPair(val_1);
    cout << res_1 << endl;
    assert(res_1 == 11);

    // Test_2
    vector<int> val_2 = { 1, 2 };
    int res_2 = sol.maxScoreSightseeingPair(val_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    return 0;
}
// Accepted
// 55/55 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 65.45 % of cpp submissions (45.5 MB)