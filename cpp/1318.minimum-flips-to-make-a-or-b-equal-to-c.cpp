/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 *
 * https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
 *
 * algorithms
 * Medium (71.08%)
 * Likes:    1915
 * Dislikes: 96
 * Total Accepted:    117.4K
 * Total Submissions: 165.2K
 * Testcase Example:  '2\n6\n5'
 *
 * Given 3 positives numbers a, b and c. Return the minimum flips required in
 * some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0
 * to 1 in their binary representation.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: a = 2, b = 6, c = 5
 * Output: 3
 * Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
 *
 * Example 2:
 *
 *
 * Input: a = 4, b = 2, c = 7
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: a = 1, b = 2, c = 3
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= a <= 10^9
 * 1 <= b <= 10^9
 * 1 <= c <= 10^9
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int ret = 0;
        int mask = 1;
        for (int i = 0; i < 31; i++, mask = mask << 1)
        {
            if ((a & mask) == 0 && (b & mask) == 0 && (c & mask) != 0)
            {
                ret++;
            }
            if ((c & mask) == 0)
            {
                if (a & mask)
                    ret++;
                if (b & mask)
                    ret++;
            }
        }
        // cout << endl;
        return ret;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    cout << sol.minFlips(2, 6, 5) << endl;

    // Test_2
    cout << sol.minFlips(4, 2, 7) << endl;

    // Test_3
    cout << sol.minFlips(1, 2, 3) << endl;
    return 0;
}
// Accepted
// 64/64 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 42.37 % of cpp submissions (88 MB)