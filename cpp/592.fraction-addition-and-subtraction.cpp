/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 *
 * https://leetcode.com/problems/fraction-addition-and-subtraction/description/
 *
 * algorithms
 * Medium (53.65%)
 * Likes:    554
 * Dislikes: 583
 * Total Accepted:    58.9K
 * Total Submissions: 99.1K
 * Testcase Example:  '"-1/2+1/2"'
 *
 * Given a string expression representing an expression of fraction addition
 * and subtraction, return the calculation result in string format.
 *
 * The final result should be an irreducible fraction. If your final result is
 * an integer, change it to the format of a fraction that has a denominator 1.
 * So in this case, 2 should be converted to 2/1.
 *
 *
 * Example 1:
 *
 *
 * Input: expression = "-1/2+1/2"
 * Output: "0/1"
 *
 *
 * Example 2:
 *
 *
 * Input: expression = "-1/2+1/2+1/3"
 * Output: "1/3"
 *
 *
 * Example 3:
 *
 *
 * Input: expression = "1/3-1/2"
 * Output: "-1/6"
 *
 *
 *
 * Constraints:
 *
 *
 * The input string only contains '0' to '9', '/', '+' and '-'. So does the
 * output.
 * Each fraction (input and output) has the format ±numerator/denominator. If
 * the first input fraction or the output is positive, then '+' will be
 * omitted.
 * The input only contains valid irreducible fractions, where the numerator and
 * denominator of each fraction will always be in the range [1, 10]. If the
 * denominator is 1, it means this fraction is actually an integer in a
 * fraction format defined above.
 * The number of given fractions will be in the range [1, 10].
 * The numerator and denominator of the final result are guaranteed to be valid
 * and in the range of 32-bit int.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string fractionAddition(string expression)
    {
        istringstream iss(expression);
        int           numerator, denominator;
        char          slash;
        int           res_numerator   = 0;
        int           res_denominator = 1;
        while (iss >> numerator >> slash >> denominator)
        {
            // Must calculate numerator first
            res_numerator = res_numerator * denominator + numerator * res_denominator;
            res_denominator *= denominator;
            int gcd = std::gcd(abs(res_numerator), res_denominator);
            res_numerator /= gcd;
            res_denominator /= gcd;
        }

        string res;
        res += to_string(res_numerator);
        res += "/";
        res += to_string(res_denominator);
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string expression_1 = "-1/2+1/2+1/3";
    string res_1        = sol.fractionAddition(expression_1);
    cout << res_1 << endl << flush;
    assert(res_1 == "1/3");

    // Test_2
    string expression_2 = "1/3-1/2";
    string res_2        = sol.fractionAddition(expression_2);
    cout << res_2 << endl << flush;
    assert(res_2 == "-1/6");

    // Test_3
    string expression_3 = "-1/2+1/2";
    string res_3        = sol.fractionAddition(expression_3);
    cout << res_3 << endl << flush;
    assert(res_3 == "0/1");

    return 0;
}
// Accepted
// 105/105 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 70.54 % of cpp submissions (7.6 MB)