/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 *
 * https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/
 *
 * algorithms
 * Medium (72.00%)
 * Likes:    2115
 * Dislikes: 101
 * Total Accepted:    135.3K
 * Total Submissions: 178.8K
 * Testcase Example:  '"][]["'
 *
 * You are given a 0-indexed string s of even length n. The string consists of
 * exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.
 *
 * A string is called balanced if and only if:
 *
 *
 * It is the empty string, or
 * It can be written as AB, where both A and B are balanced strings, or
 * It can be written as [C], where C is a balanced string.
 *
 *
 * You may swap the brackets at any two indices any number of times.
 *
 * Return the minimum number of swaps to make s balanced.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "][]["
 * Output: 1
 * Explanation: You can make the string balanced by swapping index 0 with index
 * 3.
 * The resulting string is "[[]]".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "]]][[["
 * Output: 2
 * Explanation: You can do the following to make the string balanced:
 * - Swap index 0 with index 4. s = "[]][][".
 * - Swap index 1 with index 5. s = "[[][]]".
 * The resulting string is "[[][]]".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "[]"
 * Output: 0
 * Explanation: The string is already balanced.
 *
 *
 *
 * Constraints:
 *
 *
 * n == s.length
 * 2 <= n <= 10^6
 * n is even.
 * s[i] is either '[' or ']'.
 * The number of opening brackets '[' equals n / 2, and the number of closing
 * brackets ']' equals n / 2.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSwaps(const string& s)
    {
        int stackSize = 0;

        for (auto& ch : s)
        {
            // If character is opening bracket, increment the stack size.
            if (ch == '[')
                stackSize++;
            else
            {
                // If the character is closing bracket, and we have an opening
                // bracket, decrease the stack size.
                if (stackSize > 0)
                    stackSize--;
            }
        }
        return (stackSize + 1) / 2;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "][][";
    int res_1 = sol.minSwaps(s_1);
    cout << res_1 << endl;
    assert(res_1 == 1);

    // Test_2
    string s_2 = "]]][[[";
    int res_2 = sol.minSwaps(s_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    // Test_3
    string s_3 = "[]";
    int res_3 = sol.minSwaps(s_3);
    cout << res_3 << endl;
    assert(res_3 == 0);

    return 0;
}
// Accepted
// 59/59 cases passed (98 ms)
// Your runtime beats 80.19 % of cpp submissions
// Your memory usage beats 99.57 % of cpp submissions (27.3 MB)