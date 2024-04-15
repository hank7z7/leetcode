/*
 * @lc app=leetcode id=3099 lang=cpp
 *
 * [3099] Harshad Number
 *
 * https://leetcode.com/problems/harshad-number/description/
 *
 * algorithms
 * Easy (80.44%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 26.1K
 * Testcase Example:  '18'
 *
 * An integer divisible by the sum of its digits is said to be a Harshad
 * number. You are given an integer x. Return the sum of the digits of x if x
 * is a Harshad number, otherwise, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: x = 18
 *
 * Output: 9
 *
 * Explanation:
 *
 * The sum of digits of x is 9. 18 is divisible by 9. So 18 is a Harshad number
 * and the answer is 9.
 *
 *
 * Example 2:
 *
 *
 * Input: x = 23
 *
 * Output: -1
 *
 * Explanation:
 *
 * The sum of digits of x is 5. 23 is not divisible by 5. So 23 is not a
 * Harshad number and the answer is -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= x <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int sumOfTheDigitsOfHarshadNumber(int x)
    {
        int sum = 0;
        int y = x;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        if ((y % sum) == 0)
            return sum;
        else
            return -1;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int x_1 = 18;
    cout << sol.sumOfTheDigitsOfHarshadNumber(x_1) << endl;

    // Test_2
    int x_2 = 23;
    cout << sol.sumOfTheDigitsOfHarshadNumber(x_2) << endl;

    return 0;
}

// Accepted
// 100/100 cases passed (2 ms)
// Your runtime beats 80 % of cpp submissions
// Your memory usage beats 20 % of cpp submissions (7.1 MB)