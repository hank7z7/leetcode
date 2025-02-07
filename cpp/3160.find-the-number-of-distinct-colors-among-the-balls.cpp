/*
 * @lc app=leetcode id=3160 lang=cpp
 *
 * [3160] Find the Number of Distinct Colors Among the Balls
 *
 * https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/
 *
 * algorithms
 * Medium (41.18%)
 * Likes:    350
 * Dislikes: 39
 * Total Accepted:    68K
 * Total Submissions: 137.3K
 * Testcase Example:  '4\n[[1,4],[2,5],[1,3],[3,4]]'
 *
 * You are given an integer limit and a 2D array queries of size n x 2.
 *
 * There are limit + 1 balls with distinct labels in the range [0, limit].
 * Initially, all balls are uncolored. For every query in queries that is of
 * the form [x, y], you mark ball x with the color y. After each query, you
 * need to find the number of distinct colors among the balls.
 *
 * Return an array result of length n, where result[i] denotes the number of
 * distinct colors after i^th query.
 *
 * Note that when answering a query, lack of a color will not be considered as
 * a color.
 *
 *
 * Example 1:
 *
 *
 * Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]
 *
 * Output: [1,2,2,3]
 *
 * Explanation:
 *
 *
 *
 *
 * After query 0, ball 1 has color 4.
 * After query 1, ball 1 has color 4, and ball 2 has color 5.
 * After query 2, ball 1 has color 3, and ball 2 has color 5.
 * After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color
 * 4.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]
 *
 * Output: [1,2,2,3,4]
 *
 * Explanation:
 *
 *
 *
 *
 * After query 0, ball 0 has color 1.
 * After query 1, ball 0 has color 1, and ball 1 has color 2.
 * After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
 * After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3
 * has color 4.
 * After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has
 * color 4, and ball 4 has color 5.
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= limit <= 10^9
 * 1 <= n == queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= queries[i][0] <= limit
 * 1 <= queries[i][1] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        // index -> color
        unordered_map<int, int> um1;
        // color -> count
        unordered_map<int, int> um2;
        vector<int> res;
        for (auto& querie : queries)
        {
            int curr_idx = querie[0];
            int new_color = querie[1];
            if (um1.find(curr_idx) != um1.end())
            {
                int prev_color = um1[curr_idx];
                um2[prev_color]--;
                if (um2[prev_color] == 0)
                    um2.erase(prev_color);
            }

            um1[curr_idx] = new_color;
            um2[new_color]++;

            res.push_back((int) um2.size());
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int limit_1 = 4;
    vector<vector<int>> queries_1 = { { 1, 4 }, { 2, 5 }, { 1, 3 }, { 3, 4 } };
    vector<int> res_1 = sol.queryResults(limit_1, queries_1);
    for (auto& res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<int>{ 1, 2, 2, 3 }));

    // Test_2
    int limit_2 = 4;
    vector<vector<int>> queries_2 = { { 0, 1 }, { 1, 2 }, { 2, 2 }, { 3, 4 }, { 4, 5 } };
    vector<int> res_2 = sol.queryResults(limit_2, queries_2);
    for (auto& res : res_2)
        cout << res << " ";
    cout << endl;
    assert((res_2 == vector<int>{ 1, 2, 2, 3, 4 }));

    return 0;
}
// Accepted
// 551/551 cases passed (106 ms)
// Your runtime beats 81.99 % of cpp submissions
// Your memory usage beats 49.84 % of cpp submissions (157.7 MB)