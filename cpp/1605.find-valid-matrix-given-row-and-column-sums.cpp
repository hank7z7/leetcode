/*
 * @lc app=leetcode id=1605 lang=cpp
 *
 * [1605] Find Valid Matrix Given Row and Column Sums
 *
 * https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/
 *
 * algorithms
 * Medium (82.97%)
 * Likes:    2001
 * Dislikes: 82
 * Total Accepted:    128.9K
 * Total Submissions: 155.1K
 * Testcase Example:  '[3,8]\n[4,7]'
 *
 * You are given two arrays rowSum and colSum of non-negative integers where
 * rowSum[i] is the sum of the elements in the i^th row and colSum[j] is the
 * sum of the elements of the j^th column of a 2D matrix. In other words, you
 * do not know the elements of the matrix, but you do know the sums of each row
 * and column.
 *
 * Find any matrix of non-negative integers of size rowSum.length x
 * colSum.length that satisfies the rowSum and colSum requirements.
 *
 * Return a 2D array representing any matrix that fulfills the requirements.
 * It's guaranteed that at least one matrix that fulfills the requirements
 * exists.
 *
 *
 * Example 1:
 *
 *
 * Input: rowSum = [3,8], colSum = [4,7]
 * Output: [[3,0],
 * ⁠        [1,7]]
 * Explanation:
 * 0^th row: 3 + 0 = 3 == rowSum[0]
 * 1^st row: 1 + 7 = 8 == rowSum[1]
 * 0^th column: 3 + 1 = 4 == colSum[0]
 * 1^st column: 0 + 7 = 7 == colSum[1]
 * The row and column sums match, and all matrix elements are non-negative.
 * Another possible matrix is: [[1,2],
 * ⁠                            [3,5]]
 *
 *
 * Example 2:
 *
 *
 * Input: rowSum = [5,7,10], colSum = [8,6,8]
 * Output: [[0,5,0],
 * ⁠        [6,1,0],
 * ⁠        [2,0,8]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= rowSum.length, colSum.length <= 500
 * 0 <= rowSum[i], colSum[i] <= 10^8
 * sum(rowSum) == sum(colSum)
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int n = (int)rowSum.size();
        int m = (int)colSum.size();

        vector<int> currRowSum(n, 0);
        vector<int> currColSum(m, 0);
        vector<vector<int>> res(n, vector<int>(m, 0));
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            res[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= res[i][j];
            colSum[j] -= res[i][j];
            rowSum[i] == 0 ? i++ : j++;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> rowSum_1 = {3, 8};
    vector<int> colSum_1 = {4, 7};
    vector<vector<int>> res_1 = sol.restoreMatrix(rowSum_1, colSum_1);
    for (auto row : res_1)
    {
        for (auto elem : row)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;

    // Test_2
    vector<int> rowSum_2 = {5, 7, 10};
    vector<int> colSum_2 = {8, 6, 8};
    vector<vector<int>> res_2 = sol.restoreMatrix(rowSum_2, colSum_2);
    for (auto row : res_2)
    {
        for (auto elem : row)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}
// Accepted
// 84/84 cases passed (30 ms)
// Your runtime beats 89.16 % of cpp submissions
// Your memory usage beats 6.09 % of cpp submissions (36.3 MB)