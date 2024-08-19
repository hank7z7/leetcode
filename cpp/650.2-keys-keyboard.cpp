/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 *
 * https://leetcode.com/problems/2-keys-keyboard/description/
 *
 * algorithms
 * Medium (54.20%)
 * Likes:    3730
 * Dislikes: 225
 * Total Accepted:    172.9K
 * Total Submissions: 307.6K
 * Testcase Example:  '3'
 *
 * There is only one character 'A' on the screen of a notepad. You can perform
 * one of two operations on this notepad for each step:
 *
 *
 * Copy All: You can copy all the characters present on the screen (a partial
 * copy is not allowed).
 * Paste: You can paste the characters which are copied last time.
 *
 *
 * Given an integer n, return the minimum number of operations to get the
 * character 'A' exactly n times on the screen.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 3
 * Explanation: Initially, we have one character 'A'.
 * In step 1, we use Copy All operation.
 * In step 2, we use Paste operation to get 'AA'.
 * In step 3, we use Paste operation to get 'AAA'.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 0
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
    int minSteps(int n)
    {
        // dp[i] denotes the min steps when n == i
        vector<int> dp(n + 1, INT_MAX);
        // Initialze dp
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 1; i <= n; i++)
        {
            // Find all prime factors
            for (int j = 1; j * j <= i; j++)
            {
                // We get two factors j and i / j
                if (i % j == 0)
                {
                    // (1) copy number j of 'A's and (i / j -1) paste
                    // to get number i of 'A'
                    dp[i] = min(dp[i], dp[j] + i / j);
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n_1   = 3;
    int res_1 = sol.minSteps(n_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    int n_2   = 1;
    int res_2 = sol.minSteps(n_2);
    cout << res_2 << endl;
    assert(res_2 == 0);

    // Test_3
    int n_3   = 1;
    int res_3 = sol.minSteps(n_3);
    cout << res_3 << endl;
    assert(res_3 == 0);

    // Test_4
    int n_4   = 18;
    int res_4 = sol.minSteps(n_4);
    cout << res_4 << endl;
    assert(res_4 == 8);

    return 0;
}
// Accepted
// 126/126 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 40.71 % of cpp submissions (8.1 MB)