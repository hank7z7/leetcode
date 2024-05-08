/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (63.53%)
 * Likes:    1487
 * Dislikes: 85
 * Total Accepted:    186.5K
 * Total Submissions: 281.9K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * You are given an integer array score of size n, where score[i] is the score
 * of the i^th athlete in a competition. All the scores are guaranteed to be
 * unique.
 *
 * The athletes are placed based on their scores, where the 1^st place athlete
 * has the highest score, the 2^nd place athlete has the 2^nd highest score,
 * and so on. The placement of each athlete determines their rank:
 *
 *
 * The 1^st place athlete's rank is "Gold Medal".
 * The 2^nd place athlete's rank is "Silver Medal".
 * The 3^rd place athlete's rank is "Bronze Medal".
 * For the 4^th place to the n^th place athlete, their rank is their placement
 * number (i.e., the x^th place athlete's rank is "x").
 *
 *
 * Return an array answer of size n where answer[i] is the rank of the i^th
 * athlete.
 *
 *
 * Example 1:
 *
 *
 * Input: score = [5,4,3,2,1]
 * Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
 * Explanation: The placements are [1^st, 2^nd, 3^rd, 4^th, 5^th].
 *
 * Example 2:
 *
 *
 * Input: score = [10,3,8,9,4]
 * Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
 * Explanation: The placements are [1^st, 5^th, 3^rd, 2^nd, 4^th].
 *
 *
 *
 *
 * Constraints:
 *
 *
 * n == score.length
 * 1 <= n <= 10^4
 * 0 <= score[i] <= 10^6
 * All the values in score are unique.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        vector<pair<int, int>> score_index(score.size());
        for (int i = 0; i < (int) score.size(); i++)
            score_index[i] = { score[i], i };
        sort(score_index.begin(),
             score_index.end(),
             [](const pair<int, int> a, const pair<int, int> b) { return a.first > b.first; });

        vector<string> result(score.size());
        for (int i = 0; i < (int) score_index.size(); i++)
        {
            switch (i)
            {
                case 0:
                    result[score_index[i].second] = "Gold Medal";
                    break;
                case 1:
                    result[score_index[i].second] = "Silver Medal";
                    break;
                case 2:
                    result[score_index[i].second] = "Bronze Medal";
                    break;
                default:
                    result[score_index[i].second] = to_string(i + 1);
                    break;
            }
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int>    score_1  = { 5, 4, 3, 2, 1 };
    vector<string> result_1 = sol.findRelativeRanks(score_1);
    for (auto s : result_1)
        cout << s << " ";
    cout << endl;

    // Test_2
    vector<int>    score_2  = { 10, 3, 8, 9, 4 };
    vector<string> result_2 = sol.findRelativeRanks(score_2);
    for (auto s : result_2)
        cout << s << " ";
    cout << endl;
}
// Accepted
// 18/18 cases passed (5 ms)
// Your runtime beats 84.2 % of cpp submissions
// Your memory usage beats 91.98 % of cpp submissions (13.4 MB)