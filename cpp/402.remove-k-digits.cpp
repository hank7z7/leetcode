/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 *
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (31.08%)
 * Likes:    8560
 * Dislikes: 390
 * Total Accepted:    365.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"1432219"\n3'
 *
 * Given string num representing a non-negative integer num, and an integer k,
 * return the smallest possible integer after removing k digits from num.
 *
 *
 * Example 1:
 *
 *
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 *
 *
 * Example 2:
 *
 *
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 *
 *
 * Example 3:
 *
 *
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= num.length <= 10^5
 * num consists of only digits.
 * num does not have any leading zeros except for the zero itself.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string result = "";
        for (auto digit : num)
        {
            // WHILE!
            while (k > 0 && !result.empty() && digit < result.back())
            {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        // Handle the remain k
        while (k && !result.empty())
        {
            k--;
            result.pop_back();
        }
        // Handle the leading zeros
        while (!result.empty() && result.front() == '0')
            result.erase(0, 1);
        // Handle the empty string
        if (result.empty())
            result.push_back('0');
        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string num_1 = "1432219";
    int k_1 = 3;
    cout << sol.removeKdigits(num_1, k_1) << endl;

    // Test_2
    string num_2 = "10200";
    int k_2 = 1;
    cout << sol.removeKdigits(num_2, k_2) << endl;

    // Test_3
    string num_3 = "10";
    int k_3 = 3;
    cout << sol.removeKdigits(num_3, k_3) << endl;

    // Test_4
    string num_4 = "112";
    int k_4 = 1;
    cout << sol.removeKdigits(num_4, k_4) << endl;

    // Test_5
    string num_5 = "1234567890";
    int k_5 = 9;
    cout << sol.removeKdigits(num_5, k_5) << endl;

    return 0;
}
// Accepted
// 43/43 cases passed (8 ms)
// Your runtime beats 80.81 % of cpp submissions
// Your memory usage beats 86.82 % of cpp submissions (9.8 MB)