/*
 * @lc app=leetcode id=1922 lang=cpp
 *
 * [1922] Count Good Numbers
 *
 * https://leetcode.com/problems/count-good-numbers/description/
 *
 * algorithms
 * Medium (48.76%)
 * Likes:    1931
 * Dislikes: 529
 * Total Accepted:    160.9K
 * Total Submissions: 298.5K
 * Testcase Example:  '1'
 *
 * A digit string is good if the digits (0-indexed) at even indices are even
 * and the digits at odd indices are prime (2, 3, 5, or 7).
 *
 *
 * For example, "2582" is good because the digits (2 and 8) at even positions
 * are even and the digits (5 and 2) at odd positions are prime. However,
 * "3245" is not good because 3 is at an even index but is not even.
 *
 *
 * Given an integer n, return the total number of good digit strings of length
 * n. Since the answer may be large, return it modulo 10^9 + 7.
 *
 * A digit string is a string consisting of digits 0 through 9 that may contain
 * leading zeros.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: 5
 * Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4
 * Output: 400
 *
 *
 * Example 3:
 *
 *
 * Input: n = 50
 * Output: 564908303
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^15
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    static constexpr int mod = 1000000007;

public:
    int countGoodNumbers(long long n)
    {
        // use fast exponentiation to calculate x^y % mod
        auto quickmul = [](int x, long long y) -> int
        {
            int ret = 1, mul = x;
            while (y > 0)
            {
                if (y % 2 == 1)
                {
                    ret = (long long) ret * mul % mod;
                }
                mul = (long long) mul * mul % mod;
                y /= 2;
            }
            return ret;
        };

        return (long long) quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
    }
};
// @lc code=end
int main(int argc, char* argv[])
{
    Solution sol;
    // Test_1
    long long n = 1;
    int res = sol.countGoodNumbers(n);
    cout << res << endl;
    assert(res == 5);

    // Test_2
    n = 4;
    res = sol.countGoodNumbers(n);
    cout << res << endl;
    assert(res == 400);

    // Test_3
    n = 50;
    res = sol.countGoodNumbers(n);
    cout << res << endl;
    assert(res == 564908303);

    return 0;
}
// Accepted
// 166/166 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.45 % of cpp submissions (7.7 MB)