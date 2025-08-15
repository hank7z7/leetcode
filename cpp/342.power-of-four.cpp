/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (49.14%)
 * Likes:    4230
 * Dislikes: 408
 * Total Accepted:    891.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '16'
 *
 * Given an integer n, return true if it is a power of four. Otherwise, return
 * false.
 *
 * An integer n is a power of four, if there exists an integer x such that n ==
 * 4^x.
 *
 *
 * Example 1:
 * Input: n = 16
 * Output: true
 * Example 2:
 * Input: n = 5
 * Output: false
 * Example 3:
 * Input: n = 1
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you solve it without loops/recursion?
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if(n == 1 << 0 ||
            n== 1 << 2 ||
            n == 1 << 4 ||
            n == 1 << 6 ||
            n == 1 << 8 ||
            n == 1 << 10 ||
            n == 1 << 12 ||
            n == 1 << 14 ||
            n == 1 << 16 ||
            n == 1 << 18 ||
            n == 1 << 20 ||
            n == 1 << 22 ||
            n == 1 << 24 ||
            n == 1 << 26 ||
            n == 1 << 28 ||
            n == 1 << 30)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n = 16;
    bool res = sol.isPowerOfFour(n);
    cout << res << endl;  // Expected output: true
    assert(res == true);

    // Test_2
    n = 5;
    res = sol.isPowerOfFour(n);
    cout << res << endl;  // Expected output: false
    assert(res == false);

    // Test_3
    n = 1;
    res = sol.isPowerOfFour(n);
    cout << res << endl;  // Expected output: true
    assert(res == true);

    // Test_4
    n = 8;
    res = sol.isPowerOfFour(n);
    cout << res << endl;  // Expected output: false
    assert(res == false);

    return 0;
}
// Accepted
// 1063/1063 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 82.36 % of cpp submissions (7.8 MB)