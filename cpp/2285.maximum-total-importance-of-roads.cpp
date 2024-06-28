/*
 * @lc app=leetcode id=2285 lang=cpp
 *
 * [2285] Maximum Total Importance of Roads
 *
 * https://leetcode.com/problems/maximum-total-importance-of-roads/description/
 *
 * algorithms
 * Medium (61.10%)
 * Likes:    852
 * Dislikes: 41
 * Total Accepted:    52.9K
 * Total Submissions: 81.4K
 * Testcase Example:  '5\n[[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]'
 *
 * You are given an integer n denoting the number of cities in a country. The
 * cities are numbered from 0 to n - 1.
 * 
 * You are also given a 2D integer array roads where roads[i] = [ai, bi]
 * denotes that there exists a bidirectional road connecting cities ai and bi.
 * 
 * You need to assign each city with an integer value from 1 to n, where each
 * value can only be used once. The importance of a road is then defined as the
 * sum of the values of the two cities it connects.
 * 
 * Return the maximum total importance of all roads possible after assigning
 * the values optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
 * Output: 43
 * Explanation: The figure above shows the country and the assigned values of
 * [2,4,5,3,1].
 * - The road (0,1) has an importance of 2 + 4 = 6.
 * - The road (1,2) has an importance of 4 + 5 = 9.
 * - The road (2,3) has an importance of 5 + 3 = 8.
 * - The road (0,2) has an importance of 2 + 5 = 7.
 * - The road (1,3) has an importance of 4 + 3 = 7.
 * - The road (2,4) has an importance of 5 + 1 = 6.
 * The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
 * It can be shown that we cannot obtain a greater total importance than 43.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 5, roads = [[0,3],[2,4],[1,3]]
 * Output: 20
 * Explanation: The figure above shows the country and the assigned values of
 * [4,3,2,5,1].
 * - The road (0,3) has an importance of 4 + 5 = 9.
 * - The road (2,4) has an importance of 2 + 1 = 3.
 * - The road (1,3) has an importance of 3 + 5 = 8.
 * The total importance of all roads is 9 + 3 + 8 = 20.
 * It can be shown that we cannot obtain a greater total importance than
 * 20.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 5 * 10^4
 * 1 <= roads.length <= 5 * 10^4
 * roads[i].length == 2
 * 0 <= ai, bi <= n - 1
 * ai != bi
 * There are no duplicate roads.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
        vector<int> count(n, 0);
        for(auto road : roads)
        {
            count[road[0]]++;
            count[road[1]]++;
        }
        
        sort(count.begin(), count.end());
        
        long long res = 0;
        for(int i = 0; i < n; i++)
            res += (long long)(i + 1) * (long long)count[i];

        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n_1 = 5;
    vector<vector<int>> roads_1 = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    long long res_1 = sol.maximumImportance(n_1, roads_1);
    cout << res_1 << endl;
    assert(res_1 == 43);

    // Test_2
    int n_2 = 5;
    vector<vector<int>> roads_2 = {{0, 3}, {2, 4}, {1, 3}};
    long long res_2 = sol.maximumImportance(n_2, roads_2);
    cout << res_2 << endl;
    assert(res_2 == 20);

    return 0;
}
// Accepted
// 58/58 cases passed (264 ms)
// Your runtime beats 74.83 % of cpp submissions
// Your memory usage beats 63.28 % of cpp submissions (132.6 MB)