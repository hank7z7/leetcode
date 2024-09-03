/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After convert
 *
 * https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/
 *
 * algorithms
 * Easy (62.91%)
 * Likes:    834
 * Dislikes: 78
 * Total Accepted:    116.8K
 * Total Submissions: 163.5K
 * Testcase Example:  '"iiii"\n1'
 *
 * You are given a string s consisting of lowercase English letters, and an
 * integer k.
 *
 * First, convert s into an integer by replacing each letter with its position
 * in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26).
 * Then, convert the integer by replacing it with the sum of its digits.
 * Repeat the convert operation k times in total.
 *
 * For example, if s = "zbax" and k = 2, then the resulting integer would be 8
 * by the following operations:
 *
 *
 * convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
 * convert #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
 * convert #2: 17 ➝ 1 + 7 ➝ 8
 *
 *
 * Return the resulting integer after performing the operations described
 * above.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "iiii", k = 1
 * Output: 36
 * Explanation: The operations are as follows:
 * - convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
 * - convert #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
 * Thus the resulting integer is 36.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "leetcode", k = 2
 * Output: 6
 * Explanation: The operations are as follows:
 * - convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝
 * 12552031545
 * - convert #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
 * - convert #2: 33 ➝ 3 + 3 ➝ 6
 * Thus the resulting integer is 6.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "zbax", k = 2
 * Output: 8
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * 1 <= k <= 10
 * s consists of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int getLucky(string s, int k)
    {
        vector<int> convert;
        for (auto c : s)
        {
            int curr = c - 'a' + 1;
            if (curr / 10)
                convert.push_back(curr / 10);
            convert.push_back(curr % 10);
        }

        for (int i = 0; i < k; i++)
        {
            int sum = accumulate(convert.begin(), convert.end(), 0);
            convert.clear();
            while (sum)
            {
                convert.push_back(sum % 10);
                sum /= 10;
            }
            reverse(convert.begin(), convert.end());
        }

        int res = 0;
        for (int i = 0; i < (int) convert.size(); i++)
        {
            res *= 10;
            res += convert[i];
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1   = "zbax";
    int    k_1   = 2;
    int    res_1 = sol.getLucky(s_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 8);

    // Test_2
    string s_2   = "iiii";
    int    k_2   = 1;
    int    res_2 = sol.getLucky(s_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 36);

    // Test_3
    string s_3   = "leetcode";
    int    k_3   = 2;
    int    res_3 = sol.getLucky(s_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == 6);

    return 0;
}
// Accepted
// 216/216 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.87 % of cpp submissions (8.2 MB)