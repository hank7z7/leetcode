/*
 * @lc app=leetcode id=2392 lang=cpp
 *
 * [2392] Build a Matrix With Conditions
 *
 * https://leetcode.com/problems/build-a-matrix-with-conditions/description/
 *
 * algorithms
 * Hard (61.80%)
 * Likes:    866
 * Dislikes: 27
 * Total Accepted:    26K
 * Total Submissions: 37K
 * Testcase Example:  '3\n[[1,2],[3,2]]\n[[2,1],[3,2]]'
 *
 * You are given a positive integer k. You are also given:
 *
 *
 * a 2D integer array rowConditions of size n where rowConditions[i] = [abovei,
 * belowi], and
 * a 2D integer array colConditions of size m where colConditions[i] = [lefti,
 * righti].
 *
 *
 * The two arrays contain integers from 1 to k.
 *
 * You have to build a k x k matrix that contains each of the numbers from 1 to
 * k exactly once. The remaining cells should have the value 0.
 *
 * The matrix should also satisfy the following conditions:
 *
 *
 * The number abovei should appear in a row that is strictly above the row at
 * which the number belowi appears for all i from 0 to n - 1.
 * The number lefti should appear in a column that is strictly left of the
 * column at which the number righti appears for all i from 0 to m - 1.
 *
 *
 * Return any matrix that satisfies the conditions. If no answer exists, return
 * an empty matrix.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
 * Output: [[3,0,0],[0,0,1],[0,2,0]]
 * Explanation: The diagram above shows a valid example of a matrix that
 * satisfies all the conditions.
 * The row conditions are the following:
 * - Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the
 * matrix.
 * - Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the
 * matrix.
 * The column conditions are the following:
 * - Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in
 * the matrix.
 * - Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in
 * the matrix.
 * Note that there may be multiple correct answers.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions =
 * [[2,1]]
 * Output: []
 * Explanation: From the first two conditions, 3 has to be below 1 but the
 * third conditions needs 3 to be above 1 to be satisfied.
 * No matrix can satisfy all the conditions, so we return the empty matrix.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= k <= 400
 * 1 <= rowConditions.length, colConditions.length <= 10^4
 * rowConditions[i].length == colConditions[i].length == 2
 * 1 <= abovei, belowi, lefti, righti <= k
 * abovei != belowi
 * lefti != righti
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<vector<int>> rowGraph(k + 1), colGraph(k + 1);
        for (auto &rc : rowConditions)
        {
            rowGraph[rc[0]].push_back(rc[1]);
        }
        for (auto &cc : colConditions)
        {
            colGraph[cc[0]].push_back(cc[1]);
        }

        vector<int> rowOrder = topoSort(rowGraph, k);
        vector<int> colOrder = topoSort(colGraph, k);

        if (rowOrder.empty() || colOrder.empty())
            return {};

        vector<vector<int>> result(k, vector<int>(k, 0));
        unordered_map<int, int> rowMap, colMap;
        for (int i = 0; i < k; ++i)
        {
            rowMap[rowOrder[i]] = i;
            colMap[colOrder[i]] = i;
        }

        for (int i = 1; i <= k; ++i)
        {
            result[rowMap[i]][colMap[i]] = i;
        }

        return result;
    }

    vector<int> topoSort(vector<vector<int>> &graph, int k)
    {
        vector<int> inDegree(k + 1, 0), order;
        queue<int> q;
        for (int i = 1; i <= k; ++i)
        {
            for (int j : graph[i])
            {
                ++inDegree[j];
            }
        }
        for (int i = 1; i <= k; ++i)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int adj : graph[node])
            {
                if (--inDegree[adj] == 0)
                    q.push(adj);
            }
        }
        return (int)order.size() == k ? order : vector<int>();
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int k_1 = 3;
    vector<vector<int>> rowConditions_1 = {{1, 2}, {3, 2}};
    vector<vector<int>> colConditions_1 = {{2, 1}, {3, 2}};
    vector<vector<int>> res_1 = sol.buildMatrix(k_1, rowConditions_1, colConditions_1);
    for (auto &row : res_1)
    {
        for (auto &elem : row)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;

    // Test_1
    int k_2 = 3;
    vector<vector<int>> rowConditions_2 = {{1, 2}, {2, 3}, {3, 1}, {2, 3}};
    vector<vector<int>> colConditions_2 = {{2, 1}};
    vector<vector<int>> res_2 = sol.buildMatrix(k_2, rowConditions_2, colConditions_2);
    for (auto &row : res_2)
    {
        for (auto &elem : row)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;
}
// Accepted
// 53/53 cases passed (86 ms)
// Your runtime beats 90.14 % of cpp submissions
// Your memory usage beats 74.93 % of cpp submissions (61.1 MB)