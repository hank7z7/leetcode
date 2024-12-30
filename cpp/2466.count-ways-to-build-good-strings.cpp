/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 *
 * https://leetcode.com/problems/count-ways-to-build-good-strings/description/
 *
 * algorithms
 * Medium (54.44%)
 * Likes:    1901
 * Dislikes: 178
 * Total Accepted:    110.7K
 * Total Submissions: 194.5K
 * Testcase Example:  '3\n3\n1\n1'
 *
 * Given the integers zero, one, low, and high, we can construct a string by
 * starting with an empty string, and then at each step perform either of the
 * following:
 *
 *
 * Append the character '0' zero times.
 * Append the character '1' one times.
 *
 *
 * This can be performed any number of times.
 *
 * A good string is a string constructed by the above process having a length
 * between low and high (inclusive).
 *
 * Return the number of different good strings that can be constructed
 * satisfying these properties. Since the answer can be large, return it modulo
 * 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: low = 3, high = 3, zero = 1, one = 1
 * Output: 8
 * Explanation:
 * One possible valid good string is "011".
 * It can be constructed as follows: "" -> "0" -> "01" -> "011".
 * All binary strings from "000" to "111" are good strings in this example.
 *
 *
 * Example 2:
 *
 *
 * Input: low = 2, high = 3, zero = 1, one = 2
 * Output: 5
 * Explanation: The good strings are "00", "11", "000", "110", and "011".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= low <= high <= 10^5
 * 1 <= zero, one <= low
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define MOD (1000000007)
class Solution
{
public:
    int countGoodStrings(const int low, const int high, const int zero, const int one)
    {
        // A dp table with range from 0 to high
        vector<int> dp(high + 1, 0);
        // Initialze one and zero
        dp[one]++;
        dp[zero]++;

        int res = 0;
        for (int i = 1; i <= high; i++)
        {
            int curr = dp[i];
            if ((i - zero) >= 0)
                curr = (curr + dp[i - zero]) % MOD;
            if ((i - one) >= 0)
                curr = (curr + dp[i - one]) % MOD;
            dp[i] = curr;
            if (i >= low)
                res = (res + dp[i]) % MOD;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int res_1 = sol.countGoodStrings(3, 3, 1, 1);
    cout << res_1 << endl;
    assert(res_1 == 8);

    // Test_2
    int res_2 = sol.countGoodStrings(2, 3, 1, 2);
    cout << res_2 << endl;
    assert(res_2 == 5);

    // Test_3
    int res_3 = sol.countGoodStrings(200, 200, 10, 1);
    cout << res_3 << endl;
    assert(res_3 == 764262396);

    return 0;
}
// Accepted
// 36/36 cases passed (3 ms)
// Your runtime beats 96.09 % of cpp submissions
// Your memory usage beats 75.54 % of cpp submissions (11.6 MB)