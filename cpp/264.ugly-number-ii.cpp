/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (46.30%)
 * Likes:    6290
 * Dislikes: 371
 * Total Accepted:    402.7K
 * Total Submissions: 843.3K
 * Testcase Example:  '10'
 *
 * An ugly number is a positive integer whose prime factors are limited to 2,
 * 3, and 5.
 *
 * Given an integer n, return the n^th ugly number.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first
 * 10 ugly numbers.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 * Explanation: 1 has no prime factors, therefore all of its prime factors are
 * limited to 2, 3, and 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1690
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n);
        dp[0] = 1;
        int mul_2_idx = 0;
        int mul_3_idx = 0;
        int mul_5_idx = 0;
        for (int i = 1; i < n; i++)
        {
            int mul_2_val = dp[mul_2_idx] * 2;
            int mul_3_val = dp[mul_3_idx] * 3;
            int mul_5_val = dp[mul_5_idx] * 5;
            dp[i] = min(mul_2_val, min(mul_3_val, mul_5_val));
            if (dp[i] == mul_2_val)
                mul_2_idx++;
            if (dp[i] == mul_3_val)
                mul_3_idx++;
            if (dp[i] == mul_5_val)
                mul_5_idx++;
        }

        return dp[n - 1];
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int n_1 = 10;
    int res_1 = sol.nthUglyNumber(n_1);
    cout << res_1 << endl;
    assert(res_1 == 12);

    // Test_2
    int n_2 = 1;
    int res_2 = sol.nthUglyNumber(n_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    // Test_3
    int n_3 = 27;
    int res_3 = sol.nthUglyNumber(n_3);
    cout << res_3 << endl;
    assert(res_3 == 64);

    // Test_4
    int n_4 = 11;
    int res_4 = sol.nthUglyNumber(n_4);
    cout << res_4 << endl;
    assert(res_4 == 15);

    // Test_5
    int n_5 = 446;
    int res_5 = sol.nthUglyNumber(n_5);
    cout << res_5 << endl;
    assert(res_5 == 524288);

    // Test_6
    int n_6 = 1690;
    int res_6 = sol.nthUglyNumber(n_6);
    cout << res_6 << endl;
    assert(res_6 == 2123366400);

    return 0;
}
// Accepted
// 596/596 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 79.84 % of cpp submissions (9.5 MB)