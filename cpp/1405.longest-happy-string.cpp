/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 *
 * https://leetcode.com/problems/longest-happy-string/description/
 *
 * algorithms
 * Medium (57.50%)
 * Likes:    2321
 * Dislikes: 280
 * Total Accepted:    125.2K
 * Total Submissions: 204.1K
 * Testcase Example:  '1\n1\n7'
 *
 * A string s is called happy if it satisfies the following conditions:
 *
 *
 * s only contains the letters 'a', 'b', and 'c'.
 * s does not contain any of "aaa", "bbb", or "ccc" as a substring.
 * s contains at most a occurrences of the letter 'a'.
 * s contains at most b occurrences of the letter 'b'.
 * s contains at most c occurrences of the letter 'c'.
 *
 *
 * Given three integers a, b, and c, return the longest possible happy string.
 * If there are multiple longest happy strings, return any of them. If there is
 * no such string, return the empty string "".
 *
 * A substring is a contiguous sequence of characters within a string.
 *
 *
 * Example 1:
 *
 *
 * Input: a = 1, b = 1, c = 7
 * Output: "ccaccbcc"
 * Explanation: "ccbccacc" would also be a correct answer.
 *
 *
 * Example 2:
 *
 *
 * Input: a = 7, b = 1, c = 0
 * Output: "aabaa"
 * Explanation: It is the only correct answer in this case.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= a, b, c <= 100
 * a + b + c > 0
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        int curra = 0, currb = 0, currc = 0;
        // Maximum total iterations possible is given by the sum of a, b and c.
        int totalIterations = a + b + c;
        string ans = "";

        for (int i = 0; i < totalIterations; i++)
        {
            if ((a >= b and a >= c and curra != 2)
                or (a > 0 and (currb == 2 or currc == 2)))
            {
                // If 'a' is maximum and it's streak is less than 2, or if
                // streak of 'b' or 'c' is 2, then 'a' will be the next
                // character.
                ans += 'a';
                a--;
                curra++;
                currb = 0;
                currc = 0;
            }
            else if ((b >= a and b >= c and currb != 2)
                     or (b > 0 and (currc == 2 or curra == 2)))
            {
                // If 'b' is maximum and it's streak is less than 2, or if
                // streak of 'a' or 'c' is 2, then 'b' will be the next
                // character.
                ans += 'b';
                b--;
                currb++;
                curra = 0;
                currc = 0;
            }
            else if ((c >= a and c >= b and currc != 2)
                     or (c > 0 and (curra == 2 or currb == 2)))
            {
                // If 'c' is maximum and it's streak is less than 2, or if
                // streak of 'a' or 'b' is 2, then 'c' will be the next
                // character.
                ans += 'c';
                c--;
                currc++;
                curra = 0;
                currb = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string res_1 = sol.longestDiverseString(1, 1, 7);
    cout << res_1 << endl;
    assert(res_1 == "ccaccbcc");

    // Test_2
    string res_2 = sol.longestDiverseString(7, 1, 0);
    cout << res_2 << endl;
    assert(res_2 == "aabaa");

    return 0;
}
