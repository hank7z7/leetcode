/*
 * @lc app=leetcode id=1780 lang=cpp
 *
 * [1780] Check if Number is a Sum of Powers of Three
 *
 * https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/
 *
 * algorithms
 * Medium (67.98%)
 * Likes:    1185
 * Dislikes: 48
 * Total Accepted:    89.7K
 * Total Submissions: 120.1K
 * Testcase Example:  '12'
 *
 * Given an integer n, return true if it is possible to represent n as the sum
 * of distinct powers of three. Otherwise, return false.
 *
 * An integer y is a power of three if there exists an integer x such that y ==
 * 3^x.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: true
 * Explanation: 12 = 3^1 + 3^2
 *
 *
 * Example 2:
 *
 *
 * Input: n = 91
 * Output: true
 * Explanation: 91 = 3^0 + 3^2 + 3^4
 *
 *
 * Example 3:
 *
 *
 * Input: n = 21
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^7
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n)
        {
            if (n % 3 == 2)
                return false;
            n /= 3;
        }
        return true;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int test_1 = 12;
    int res_1 = sol.checkPowersOfThree(test_1);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    int test_2 = 91;
    int res_2 = sol.checkPowersOfThree(test_2);
    cout << res_2 << endl;
    assert(res_2 == true);

    // Test_3
    int test_3 = 21;
    int res_3 = sol.checkPowersOfThree(test_3);
    cout << res_3 << endl;
    assert(res_3 == false);

    return 0;
}
// Accepted
// 129/129 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.84 % of cpp submissions (7.8 MB)