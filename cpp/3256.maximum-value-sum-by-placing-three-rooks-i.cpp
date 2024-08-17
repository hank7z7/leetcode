/*
 * @lc app=leetcode id=3256 lang=cpp
 *
 * [3256] Maximum Value Sum by Placing Three Rooks I
 *
 * https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-i/description/
 *
 * algorithms
 * Hard (6.92%)
 * Likes:    29
 * Dislikes: 5
 * Total Accepted:    2.8K
 * Total Submissions: 37.2K
 * Testcase Example:  '[[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]'
 *
 * You are given a m x n 2D array board representing a chessboard, where
 * board[i][j] represents the value of the cell (i, j).
 *
 * Rooks in the same row or column attack each other. You need to place three
 * rooks on the chessboard such that the rooks do not attack each other.
 *
 * Return the maximum sum of the cell values on which the rooks are placed.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]
 *
 * Output: 4
 *
 * Explanation:
 *
 *
 *
 * We can place the rooks in the cells (0, 2), (1, 3), and (2, 1) for a sum of
 * 1 + 1 + 2 = 4.
 *
 *
 * Example 2:
 *
 *
 * Input: board = [[1,2,3],[4,5,6],[7,8,9]]
 *
 * Output: 15
 *
 * Explanation:
 *
 * We can place the rooks in the cells (0, 0), (1, 1), and (2, 2) for a sum of
 * 1 + 5 + 9 = 15.
 *
 *
 * Example 3:
 *
 *
 * Input: board = [[1,1,1],[1,1,1],[1,1,1]]
 *
 * Output: 3
 *
 * Explanation:
 *
 * We can place the rooks in the cells (0, 2), (1, 1), and (2, 0) for a sum of
 * 1 + 1 + 1 = 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= m == board.length <= 100
 * 3 <= n == board[i].length <= 100
 * -10^9 <= board[i][j] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long maximumValueSum(vector<vector<int>> &board)
    {
        const int m = (int)board.size();
        const int n = (m == 0 ? 0 : (int)board[0].size());
        vector<pair<int, int>> idx;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                idx.push_back({i, j});
        sort(idx.begin(), idx.end(),
             [&board](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return board[a.first][a.second] > board[b.first][b.second];
             });

        long long res = LLONG_MIN;
        for (int i = 0; i < (m * n - 2); i++)
        {
            for (int j = i + 1; j < (m * n - 1); j++)
            {
                if (idx[i].first == idx[j].first ||
                    idx[i].second == idx[j].second)
                    continue;
                long long currSum =
                    (long long)board[idx[i].first][idx[i].second] +
                    (long long)board[idx[j].first][idx[j].second];
                for (int k = j + 1; k < (m * n); k++)
                {
                    if (idx[i].first == idx[k].first ||
                        idx[i].second == idx[k].second ||
                        idx[j].first == idx[k].first ||
                        idx[j].second == idx[k].second)
                        continue;
                    cout << (long long)board[idx[i].first][idx[i].second] << " "
                         << (long long)board[idx[j].first][idx[j].second]
                         << " " << (long long)board[idx[k].first][idx[k].second] << endl;
                    currSum += (long long)board[idx[k].first][idx[k].second];
                    if (currSum > res)
                    {
                        res = currSum;
                    }
                    break;
                }
                // if((long long)board[idx[i].first][idx[i].second] +
                //         (long long)board[idx[j + 1].first][idx[j + 1].second] < res)
                //     break;
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
    vector<vector<int>> board_1 = {{-3, 1, 1, 1}, {-3, 1, -3, 1}, {-3, 2, 1, 1}};
    long long res_1 = sol.maximumValueSum(board_1);
    cout << res_1 << endl;
    assert(res_1 == 4);

    // Test_2
    vector<vector<int>> board_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    long long res_2 = sol.maximumValueSum(board_2);
    cout << res_2 << endl;
    assert(res_2 == 15);

    // Test_3
    vector<vector<int>> board_3 = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    long long res_3 = sol.maximumValueSum(board_3);
    cout << res_3 << endl;
    assert(res_3 == 3);

    // Test_4
    vector<vector<int>> board_4 = {{70, -16, 31}, {2, 75, 37}, {67, -95, -44}};
    long long res_4 = sol.maximumValueSum(board_4);
    cout << res_4 << endl;
    assert(res_4 == 173);

    // Test_5
    vector<vector<int>> board_5 = {{41, -15, 36}, {32, 58, 76}, {34, -26, -26}};
    long long res_5 = sol.maximumValueSum(board_5);
    cout << res_5 << endl;
    assert(res_5 == 128);

    // Test_6
    vector<vector<int>> board_6 = {{-29, -38, 1}, {-67, -87, -30}, {-69, 25, -22}};
    long long res_6 = sol.maximumValueSum(board_6);
    cout << res_6 << endl;
    assert(res_6 == -34);

    // Test_7 (TLE)
    vector<vector<int>> board_7 = {{61, 0, 66, 64, 72, -36, -27, 73, -50, 6, 75, 34, -97, 72, 67, -6, 18, 35, 1, -58, 89, 85, -35, -42, 41, -24, -80, 81, 14, -100, -16, 26, 62, 63, -74, -10, 93, -41, -76, 11, -4, 21, 90, -90, -28, 75, -22, -16, 90, 2, -30, -43, -94, -28, -84}, {40, -23, 82, 28, 54, 65, -93, -95, -38, -11, -91, -93, -42, -63, 59, -48, 71, 55, -68, 44, -14, 26, 32, 38, 89, -86, -87, -27, 85, 72, 79, -59, 90, 48, -87, 79, 0, -79, -53, -12, 36, -21, -12, 21, 66, -11, 41, -87, 91, -57, 69, -82, 14, 90, -72}, {-28, -77, -13, -89, 76, 69, -68, -63, 38, 93, -47, -83, 17, 18, 32, -55, 34, 33, 95, -8, 92, -17, -80, 62, -6, 26, -2, -96, -81, 67, 85, -51, 30, -97, -85, 61, 61, -3, -56, 49, -44, 46, 25, 26, -61, -52, 52, -30, -70, 12, 33, 19, 54, -22, -69}, {19, -81, 60, -52, -2, -13, -1, 73, 31, 1, -78, -19, -19, -19, 81, 12, 54, 41, -91, 74, 55, -15, -1, 2, -5, 13, 55, 17, 76, 4, 63, 86, -65, -93, 64, 51, 97, -76, 32, -3, 7, 63, 94, -72, -74, -73, 42, -77, -7, 25, -17, -82, 25, -23, 26}, {-79, 80, 39, -17, -51, 63, -16, 81, -45, 29, 49, 54, -65, -89, 61, -41, 57, -33, 71, -100, 62, 18, 31, 2, -76, -40, -61, -21, -21, 89, -60, -10, 45, 97, 74, 80, -34, 19, -19, -13, -83, -51, 98, 93, -47, -8, -33, -100, 63, 87, 41, 18, 9, -49, -96}, {-61, -71, 20, -45, -42, -60, 89, -11, 42, -1, 64, 15, -13, -38, 52, -7, -54, 87, -31, 55, -1, 16, 93, -96, -57, 99, -45, 4, -66, 11, 83, -10, -1, -79, -92, 68, 67, 98, 32, 57, 90, -81, 26, 38, -96, -56, 73, -80, 69, 44, 25, 53, -67, 59, -51}, {64, -8, -21, 22, 16, 15, 31, -16, 69, 59, -11, 88, 7, -37, 67, -89, -84, 49, -8, -81, -13, -58, 25, 49, -49, -38, -39, -50, -1, 56, -80, 1, 24, 29, -84, 53, -62, -62, -68, -71, -67, 33, -31, -18, -3, 20, 61, 95, -49, 84, 15, 5, -99, -27, -77}, {-13, 34, -43, -14, 56, -62, 36, 42, -32, -89, -98, -67, 52, 54, 45, -47, -70, 47, 44, -40, 82, 82, -58, -36, -11, 42, 65, -51, -84, -38, 78, -4, 24, -17, 20, 65, 5, 39, 56, -2, -48, -91, -6, 6, 44, 42, -3, -43, 33, 47, 73, -53, -36, -27, -47}, {56, -88, -70, -99, 86, 65, -52, 17, 24, 80, 81, 14, -73, 57, 58, -87, 2, 68, 85, 93, 60, 27, -28, 14, -37, 48, -37, 20, 49, -32, -22, -22, 8, 27, -15, -42, -48, 58, 82, 23, 49, 13, 43, -86, 10, -72, 5, -6, 87, 4, -44, 45, 34, -9, -12}, {86, -84, -78, -41, 12, -72, 3, -18, 43, -1, 96, -72, -95, -34, -13, 13, -4, 11, -23, -38, -88, -20, 97, -81, -83, 54, -50, 58, -80, 11, -76, -98, 93, -52, -76, -78, -70, -9, 81, 50, 86, 84, 22, 16, 98, -41, -94, 66, -3, -65, -82, -2, 29, -41, 61}, {28, -86, -75, 9, -73, 0, 44, 7, 89, -91, 92, -41, 54, 82, 89, -77, 1, 42, 23, 18, 85, 67, -64, -99, 48, -6, 8, -5, 27, -85, -23, 37, -8, 19, 33, 51, 22, 36, 68, -33, -41, -88, 83, -91, 10, -6, -37, 58, -32, 47, -63, -46, 87, 18, -32}, {-59, -72, -73, -37, 32, -69, -94, 63, 73, -42, -89, -99, -56, -60, -75, 81, 10, 94, -23, -86, -84, 82, 52, 65, 70, 51, 8, -29, -78, -5, 63, -40, 71, -24, 46, 21, 88, 27, -88, -57, -83, 66, 77, -91, -99, 82, -23, -20, -20, -3, -89, -87, -67, 64, -18}, {-1, 38, 77, 86, -4, 39, 89, 62, 31, -83, -63, 13, 60, -17, -68, -95, -45, 73, 73, 99, -36, -40, 14, 15, -56, -71, -52, -90, 1, 42, 12, 7, 100, -53, 53, -7, 7, -11, 86, 22, 6, -53, 63, 27, -96, -90, 73, -61, 32, -81, -22, -5, 89, 65, -77}, {-9, -69, -12, 60, -7, 17, 10, -5, -91, 26, -50, -59, 69, -13, 54, -90, -3, 5, 61, -89, -79, -77, 76, 11, -37, 57, 18, 68, 91, 91, 28, -99, 27, 75, -41, 73, -22, -46, -83, -87, -82, -15, -34, -98, -74, 58, 24, 54, 79, -68, -99, -77, 18, 14, -88}, {-45, -2, 82, 80, 90, 53, -42, -47, -29, -53, -38, -54, 19, -54, -74, -8, 54, -98, 24, 26, -8, -76, -76, 56, 82, -90, 27, 23, 35, 34, -64, 83, -43, 25, -19, 42, -44, 92, 35, -32, 21, 54, 7, 42, 78, -8, 99, -19, 7, 42, -15, 42, 53, -95, -57}, {32, 26, -30, 12, 51, 45, 95, -35, 27, 18, -83, 55, 87, -24, -2, 89, -56, -41, 96, 41, 79, -1, -80, -36, 34, -38, 26, -86, -99, -89, 47, 16, -24, -13, 33, 82, 11, 88, -59, 6, -30, 92, 42, 37, 47, -42, -69, -98, -17, 74, 97, -8, 9, -11, -66}, {83, -2, -98, -20, 28, -33, -46, -12, 76, 3, -27, -83, -3, -51, -36, -29, -82, 53, 23, 21, 24, 29, -48, -4, 83, -75, -27, 87, 5, 9, 87, -79, 63, 46, 90, -9, -4, 60, 10, -9, 85, 12, -93, -55, 7, 5, -17, -34, -91, 17, -99, -18, 41, -13, -37}, {29, -4, -2, 94, 68, -25, -65, 69, -82, 31, -81, -31, 95, 80, -52, 100, 46, 71, -59, 58, -9, 94, 29, 90, 64, 20, 10, 91, -59, -4, -31, 71, 20, 81, 44, 48, 22, -40, -11, -12, 36, 0, 20, 44, 44, 75, 45, 80, -29, -58, -33, -71, -5, 8, 22}, {-14, -99, 52, -77, -19, -19, 32, -28, -24, -35, -86, 58, 57, 85, -92, -91, -80, -80, -20, -85, 37, -14, -97, 68, -22, -31, 21, -4, 14, 43, 95, 0, -88, -82, -37, 63, 38, -29, 53, -50, -38, 20, 68, 95, 100, 42, 26, -81, -1, 31, 98, -92, -41, -9, -77}, {60, 95, -65, -10, -56, 94, -8, -25, -2, 30, -74, 84, -61, -33, -28, 84, 63, -20, 12, 61, -24, 6, -74, 83, 20, -7, -48, 49, 12, 7, 84, -34, -89, -19, 86, 94, 13, 20, -1, 55, 92, 21, 37, -90, 12, 75, 34, -68, 72, -56, -51, 48, 60, 68, -36}};
    long long res_7 = sol.maximumValueSum(board_7);
    cout << res_7 << endl;
    assert(res_7 == 300);

    // Test_8 (TLE)
    vector<vector<int>> board_8 = {{-1000000000, -1000000000, -1000000000}, {-1000000000, -1000000000, -1000000000}, {-1000000000, -1000000000, -1000000000}};
    long long res_8 = sol.maximumValueSum(board_8);
    cout << res_8 << endl;
    assert(res_8 == -3000000000);

    return 0;
}
