/*
 * @lc app=leetcode id=2787 lang=cpp
 *
 * [2787] Ways to Express an Integer as Sum of Powers
 *
 * https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/
 *
 * algorithms
 * Medium (34.31%)
 * Likes:    611
 * Dislikes: 26
 * Total Accepted:    56K
 * Total Submissions: 126.3K
 * Testcase Example:  '10\n2'
 *
 * Given two positive integers n and x.
 *
 * Return the number of ways n can be expressed as the sum of the x^th power of
 * unique positive integers, in other words, the number of sets of unique
 * integers [n1, n2, ..., nk] where n = n1^x + n2^x + ... + nk^x.
 *
 * Since the result can be very large, return it modulo 10^9 + 7.
 *
 * For example, if n = 160 and x = 3, one way to express n is n = 2^3 + 3^3 +
 * 5^3.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10, x = 2
 * Output: 1
 * Explanation: We can express n as the following: n = 3^2 + 1^2 = 10.
 * It can be shown that it is the only way to express 10 as the sum of the 2^nd
 * power of unique integers.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4, x = 1
 * Output: 2
 * Explanation: We can express n in the following ways:
 * - n = 4^1 = 4.
 * - n = 3^1 + 1^1 = 4.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 300
 * 1 <= x <= 5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Base case: one way to sum to 0 (using no numbers)
        vector<int> powers;
        for (int i = 1; pow(i, x) <= n; ++i)
        {
            powers.push_back(pow(i, x));
        }
        for (int power : powers)
        {
            for (int j = n; j >= power; --j)
            {
                if (j - power < 0)
                    continue;  // Avoid negative indices
                dp[j] += dp[j - power];
                dp[j] %= 1000000007;  // To avoid overflow
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
    int n = 10, x = 2;
    cout << sol.numberOfWays(n, x) << endl;  // Expected output: 1

    // Test_2
    n = 4, x = 1;
    cout << sol.numberOfWays(n, x) << endl;  // Expected output: 2

    return 0;
}
// Accepted
// 1502/1502 cases passed (22 ms)
// Your runtime beats 83.01 % of cpp submissions
// Your memory usage beats 68.85 % of cpp submissions (13.1 MB)