/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 *
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 *
 * algorithms
 * Medium (58.97%)
 * Likes:    5613
 * Dislikes: 669
 * Total Accepted:    253.5K
 * Total Submissions: 420.7K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]'
 *
 * On a 2D plane, we place n stones at some integer coordinate points. Each
 * coordinate point may have at most one stone.
 *
 * A stone can be removed if it shares either the same row or the same column
 * as another stone that has not been removed.
 *
 * Given an array stones of length n where stones[i] = [xi, yi] represents the
 * location of the i^th stone, return the largest possible number of stones
 * that can be removed.
 *
 *
 * Example 1:
 *
 *
 * Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * Output: 5
 * Explanation: One way to remove 5 stones is as follows:
 * 1. Remove stone [2,2] because it shares the same row as [2,1].
 * 2. Remove stone [2,1] because it shares the same column as [0,1].
 * 3. Remove stone [1,2] because it shares the same row as [1,0].
 * 4. Remove stone [1,0] because it shares the same column as [0,0].
 * 5. Remove stone [0,1] because it shares the same row as [0,0].
 * Stone [0,0] cannot be removed since it does not share a row/column with
 * another stone still on the plane.
 *
 *
 * Example 2:
 *
 *
 * Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * Output: 3
 * Explanation: One way to make 3 moves is as follows:
 * 1. Remove stone [2,2] because it shares the same row as [2,0].
 * 2. Remove stone [2,0] because it shares the same column as [0,0].
 * 3. Remove stone [0,2] because it shares the same row as [0,0].
 * Stones [0,0] and [1,1] cannot be removed since they do not share a
 * row/column with another stone still on the plane.
 *
 *
 * Example 3:
 *
 *
 * Input: stones = [[0,0]]
 * Output: 0
 * Explanation: [0,0] is the only stone on the plane, so you cannot remove
 * it.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= stones.length <= 1000
 * 0 <= xi, yi <= 10^4
 * No two stones are at the same coordinate point.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int dfs(vector<vector<int>>& stones, int index, vector<bool>& visited, int& n)
    {
        visited[index] = true;
        int result     = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i]
                && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
                result += (dfs(stones, i, visited, n) + 1);
        return result;
    }
    int removeStones(vector<vector<int>>& stones)
    {
        int          n = stones.size();
        vector<bool> visited(n, 0);
        int          result = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            result += dfs(stones, i, visited, n);
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> stones_1 = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 2 }, { 2, 1 }, { 2, 2 } };
    int                 res_1    = sol.removeStones(stones_1);
    cout << res_1 << endl;
    assert(res_1 == 5);

    // Test_2
    vector<vector<int>> stones_2 = { { 0, 0 }, { 0, 2 }, { 1, 1 }, { 2, 0 }, { 2, 2 } };
    int                 res_2    = sol.removeStones(stones_2);
    cout << res_2 << endl;
    assert(res_2 == 3);

    return 0;
}
