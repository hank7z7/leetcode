/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 *
 * https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
 *
 * algorithms
 * Medium (61.08%)
 * Likes:    2856
 * Dislikes: 112
 * Total Accepted:    133.7K
 * Total Submissions: 208.9K
 * Testcase Example:  '4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4'
 *
 * There are n cities numbered from 0 to n-1. Given the array edges where
 * edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted
 * edge between cities fromi and toi, and given the integer distanceThreshold.
 *
 * Return the city with the smallest number of cities that are reachable
 * through some path and whose distance is at most distanceThreshold, If there
 * are multiple such cities, return the city with the greatest number.
 *
 * Notice that the distance of a path connecting cities i and j is equal to the
 * sum of the edges' weights along that path.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold =
 * 4
 * Output: 3
 * Explanation: The figure above describes the graph. 
 * The neighboring cities at a distanceThreshold = 4 for each city are:
 * City 0 -> [City 1, City 2] 
 * City 1 -> [City 0, City 2, City 3] 
 * City 2 -> [City 0, City 1, City 3] 
 * City 3 -> [City 1, City 2] 
 * Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we
 * have to return city 3 since it has the greatest number.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]],
 * distanceThreshold = 2
 * Output: 0
 * Explanation: The figure above describes the graph. 
 * The neighboring cities at a distanceThreshold = 2 for each city are:
 * City 0 -> [City 1] 
 * City 1 -> [City 0, City 4] 
 * City 2 -> [City 3, City 4] 
 * City 3 -> [City 2, City 4]
 * City 4 -> [City 1, City 2, City 3] 
 * The city 0 has 1 neighboring city at a distanceThreshold = 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 100
 * 1 <= edges.length <= n * (n - 1) / 2
 * edges[i].length == 3
 * 0 <= fromi < toi < n
 * 1 <= weighti, distanceThreshold <= 10^4
 * All pairs (fromi, toi) are distinct.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        // Distance Matrix
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX / 2));
        // Distance to itself is zero
        for (int i = 0; i < n; i++)
            matrix[i][i] = 0;

        for (const auto& edge : edges)
        {
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }

        // Floyd-Warshall Algo
        // Update distances for each intermediate city
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    // Update shortest path from i to j through k
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        int cityWithFewestReachable = -1;
        int fewestReachableCount    = n;
        // Count number of cities reachable within the distance threshold for
        // each city
        for (int i = 0; i < n; i++)
        {
            int reachableCount = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }  // Skip self
                if (matrix[i][j] <= distanceThreshold)
                {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount)
            {
                fewestReachableCount    = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int                 n_1 = 4;
    vector<vector<int>> edges_1{ { 0, 1, 3 }, { 1, 2, 1 }, { 1, 3, 4 }, { 2, 3, 1 } };
    int                 distanceThreadshold_1 = 0;
    int                 res_1 = sol.findTheCity(n_1, edges_1, distanceThreadshold_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    int                 n_2 = 4;
    vector<vector<int>> edges_2{ { 0, 1, 3 }, { 1, 2, 1 }, { 1, 3, 4 }, { 2, 3, 1 } };
    int                 distanceThreadshold_2 = 0;
    int                 res_2 = sol.findTheCity(n_2, edges_2, distanceThreadshold_2);
    cout << res_2 << endl;
    assert(res_2 == 3);
}
// Accepted
// 54/54 cases passed (25 ms)
// Your runtime beats 67.65 % of cpp submissions
// Your memory usage beats 79.53 % of cpp submissions (15.5 MB)