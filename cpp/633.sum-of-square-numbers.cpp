/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (33.96%)
 * Likes:    2552
 * Dislikes: 549
 * Total Accepted:    205.8K
 * Total Submissions: 604K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer c, decide whether there're two integers a and b
 * such that a^2 + b^2 = c.
 *
 *
 * Example 1:
 *
 *
 * Input: c = 5
 * Output: true
 * Explanation: 1 * 1 + 2 * 2 = 5
 *
 *
 * Example 2:
 *
 *
 * Input: c = 3
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= c <= 2^31 - 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long left = 0;                           // Left pointer starts at 0
        long right = static_cast<long>(sqrt(c)); // Right pointer starts at the integer square root of c

        while (left <= right)
        {
            long curr_sum = left * left + right * right; // Calculate sum of squares of the two pointers
            if (curr_sum == c)
                return true; // If sum equals c, return true
            if (curr_sum < c)
            {
                left++; // If sum is less than c, move left pointer right
            }
            else
            {
                right--; // If sum is greater than c, move right pointer left
            }
        }

        return false; // If no such pair is found, return false
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int c_1 = 5;
    bool result_1 = sol.judgeSquareSum(c_1);
    cout << result_1 << endl;
    assert(result_1 == true);

    // Test_2
    int c_2 = 3;
    bool result_2 = sol.judgeSquareSum(c_2);
    cout << result_2 << endl;
    assert(result_2 == false);

    return 0;
}
// Accepted
// 127/127 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 61.35 % of cpp submissions (7.1 MB)