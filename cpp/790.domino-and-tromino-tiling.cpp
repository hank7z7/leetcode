/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 *
 * https://leetcode.com/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (48.59%)
 * Likes:    3748
 * Dislikes: 1210
 * Total Accepted:    195.8K
 * Total Submissions: 392.8K
 * Testcase Example:  '3'
 *
 * You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You
 * may rotate these shapes.
 *
 * Given an integer n, return the number of ways to tile an 2 x n board. Since
 * the answer may be very large, return it modulo 10^9 + 7.
 *
 * In a tiling, every square must be covered by a tile. Two tilings are
 * different if and only if there are two 4-directionally adjacent cells on the
 * board such that exactly one of the tilings has both squares occupied by a
 * tile.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 5
 * Explanation: The five different ways are show above.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numTilings(int n)
    {
        // 1, 2, 5, 11
        // DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3] * 2
        const int mod = 1e9 + 7;
        int curr = 1, prev1 = 5, prev2 = 2, prev3 = 1;
        if (n == 1)
            return prev3;
        if (n == 2)
            return prev2;
        if (n == 3)
            return prev1;
        for (int i = 4; i <= n; i++)
        {
            curr = (2 * prev1 % mod + prev3) % mod;
            // cout << curr << " ";
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        // cout << endl;
        return curr;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n = 3;
    int res = sol.numTilings(n);
    cout << "Test_1: " << res << endl;
    assert(res == 5);

    // Test_2
    n = 1;
    res = sol.numTilings(n);
    cout << "Test_2: " << res << endl;
    assert(res == 1);

    // Test_3
    n = 4;
    res = sol.numTilings(n);
    cout << "Test_3: " << res << endl;
    assert(res == 11);

    return 0;
}
// Accepted
// 39/39 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.98 % of cpp submissions (7.8 MB)