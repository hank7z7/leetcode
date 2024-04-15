/*
 * @lc app=leetcode id=2864 lang=cpp
 *
 * [2864] Maximum Odd Binary Number
 *
 * https://leetcode.com/problems/maximum-odd-binary-number/description/
 *
 * algorithms
 * Easy (73.29%)
 * Likes:    332
 * Dislikes: 6
 * Total Accepted:    74.3K
 * Total Submissions: 92.7K
 * Testcase Example:  '"010"'
 *
 * You are given a binary string s that contains at least one '1'.
 *
 * You have to rearrange the bits in such a way that the resulting binary
 * number is the maximum odd binary number that can be created from this
 * combination.
 *
 * Return a string representing the maximum odd binary number that can be
 * created from the given combination.
 *
 * Note that the resulting string can have leading zeros.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "010"
 * Output: "001"
 * Explanation: Because there is just one '1', it must be in the last position.
 * So the answer is "001".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "0101"
 * Output: "1001"
 * Explanation: One of the '1's must be in the last position. The maximum
 * number that can be made with the remaining digits is "100". So the answer is
 * "1001".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s consists only of '0' and '1'.
 * s contains at least one '1'.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int one_count = 0;
        int l         = (int) s.size();
        for (int i = 0; i < l; i++)
            if (s[i] == '1')
                one_count++;
        fill(s.begin(), s.end(), '0');
        s[l - 1] = '1';
        for (int i = 0; i < (one_count - 1); i++)
            s[i] = '1';
        return s;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "010\0";
    cout << sol.maximumOddBinaryNumber(s_1) << endl;

    // Test_2
    string s_2 = "0101\0";
    cout << sol.maximumOddBinaryNumber(s_2) << endl;

    return 0;
}
// Accepted
// 985/985 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 55.89 % of cpp submissions (8.4 MB)