/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 *
 * https://leetcode.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (67.71%)
 * Likes:    2800
 * Dislikes: 126
 * Total Accepted:    375.8K
 * Total Submissions: 547.6K
 * Testcase Example:  '5'
 *
 * The complement of an integer is the integer you get when you flip all the
 * 0's to 1's and all the 1's to 0's in its binary representation.
 *
 *
 * For example, The integer 5 is "101" in binary and its complement is "010"
 * which is the integer 2.
 *
 *
 * Given an integer num, return its complement.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 *
 *
 * Example 2:
 *
 *
 * Input: num = 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and
 * its complement is 0. So you need to output 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num < 2^31
 *
 *
 *
 * Note: This question is the same as 1009:
 * https://leetcode.com/problems/complement-of-base-10-integer/
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        // A builtin method
        // n                                    = 00000101
        // (unsigned)~0 >> __builtin_clz(n)     = 00000111
        // (unsigned)~0 >> __builtin_clz(n) ^ n = 00000010
        return (unsigned) ~0 >> __builtin_clz(num) ^ num;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      num, res;
    // Test_1
    num = 5;
    res = sol.findComplement(num);
    cout << res << endl;
    assert(res == 2);

    // Test_1
    num = 1;
    res = sol.findComplement(num);
    cout << res << endl;
    assert(res == 0);

    return 0;
}
// Accepted
// 149/149 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 65.77 % of cpp submissions (7.3 MB)