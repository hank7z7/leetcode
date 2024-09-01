/*
 * @lc app=leetcode id=2022 lang=cpp
 *
 * [2022] Convert 1D Array Into 2D Array
 *
 * https://leetcode.com/problems/convert-1d-array-into-2d-array/description/
 *
 * algorithms
 * Easy (62.04%)
 * Likes:    1064
 * Dislikes: 76
 * Total Accepted:    174.2K
 * Total Submissions: 250.7K
 * Testcase Example:  '[1,2,3,4]\n2\n2'
 *
 * You are given a 0-indexed 1-dimensional (1D) integer array original, and two
 * integers, m and n. You are tasked with creating a 2-dimensional (2D) array
 * with  m rows and n columns using all the elements from original.
 *
 * The elements from indices 0 to n - 1 (inclusive) of original should form the
 * first row of the constructed 2D array, the elements from indices n to 2 * n
 * - 1 (inclusive) should form the second row of the constructed 2D array, and
 * so on.
 *
 * Return an m x n 2D array constructed according to the above procedure, or an
 * empty 2D array if it is impossible.
 *
 *
 * Example 1:
 *
 *
 * Input: original = [1,2,3,4], m = 2, n = 2
 * Output: [[1,2],[3,4]]
 * Explanation: The constructed 2D array should contain 2 rows and 2 columns.
 * The first group of n=2 elements in original, [1,2], becomes the first row in
 * the constructed 2D array.
 * The second group of n=2 elements in original, [3,4], becomes the second row
 * in the constructed 2D array.
 *
 *
 * Example 2:
 *
 *
 * Input: original = [1,2,3], m = 1, n = 3
 * Output: [[1,2,3]]
 * Explanation: The constructed 2D array should contain 1 row and 3 columns.
 * Put all three elements in original into the first row of the constructed 2D
 * array.
 *
 *
 * Example 3:
 *
 *
 * Input: original = [1,2], m = 1, n = 1
 * Output: []
 * Explanation: There are 2 elements in original.
 * It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D
 * array.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= original.length <= 5 * 10^4
 * 1 <= original[i] <= 10^5
 * 1 <= m, n <= 4 * 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int sz = (int)original.size();
        vector<vector<int>> res;
        if (sz != m * n)
            return res;
        res = vector<vector<int>>(m, vector<int>(n));
        int idx = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = original[idx++];
            }
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> arr_1 = {1, 2, 3, 4};
    int m_1 = 2, n_1 = 2;
    vector<vector<int>> res_1 = sol.construct2DArray(arr_1, m_1, n_1);
    for (auto r : res_1)
    {
        for (auto c : r)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;
    assert((res_1 == vector<vector<int>>{{1, 2}, {3, 4}}));

    // Test_2
    vector<int> arr_2 = {1, 2, 3};
    int m_2 = 1, n_2 = 3;
    vector<vector<int>> res_2 = sol.construct2DArray(arr_2, m_2, n_2);
    for (auto r : res_2)
    {
        for (auto c : r)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;
    assert((res_2 == vector<vector<int>>{{1, 2, 3}}));

    // Test_3
    vector<int> arr_3 = {1, 2};
    int m_3 = 1, n_3 = 1;
    vector<vector<int>> res_3 = sol.construct2DArray(arr_3, m_3, n_3);
    for (auto r : res_3)
    {
        for (auto c : r)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;
    assert((res_3 == vector<vector<int>>{}));

    return 0;
}
// Accepted
// 107/107 cases passed (79 ms)
// Your runtime beats 69.46 % of cpp submissions
// Your memory usage beats 89.37 % of cpp submissions (87.9 MB)