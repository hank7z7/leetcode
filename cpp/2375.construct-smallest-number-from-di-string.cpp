/*
 * @lc app=leetcode id=2375 lang=cpp
 *
 * [2375] Construct Smallest Number From DI String
 *
 * https://leetcode.com/problems/construct-smallest-number-from-di-string/description/
 *
 * algorithms
 * Medium (76.48%)
 * Likes:    1397
 * Dislikes: 70
 * Total Accepted:    109.7K
 * Total Submissions: 129.5K
 * Testcase Example:  '"IIIDIDDD"'
 *
 * You are given a 0-indexed string pattern of length n consisting of the
 * characters 'I' meaning increasing and 'D' meaning decreasing.
 *
 * A 0-indexed string num of length n + 1 is created using the following
 * conditions:
 *
 *
 * num consists of the digits '1' to '9', where each digit is used at most
 * once.
 * If pattern[i] == 'I', then num[i] < num[i + 1].
 * If pattern[i] == 'D', then num[i] > num[i + 1].
 *
 *
 * Return the lexicographically smallest possible string num that meets the
 * conditions.
 *
 *
 * Example 1:
 *
 *
 * Input: pattern = "IIIDIDDD"
 * Output: "123549876"
 * Explanation:
 * At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
 * At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
 * Some possible values of num are "245639871", "135749862", and "123849765".
 * It can be proven that "123549876" is the smallest possible num that meets
 * the conditions.
 * Note that "123414321" is not possible because the digit '1' is used more
 * than once.
 *
 * Example 2:
 *
 *
 * Input: pattern = "DDD"
 * Output: "4321"
 * Explanation:
 * Some possible values of num are "9876", "7321", and "8742".
 * It can be proven that "4321" is the smallest possible num that meets the
 * conditions.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= pattern.length <= 8
 * pattern consists of only the letters 'I' and 'D'.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string smallestNumber(const string &pattern)
    {
        const int n = (int)pattern.length();
        vector<int> d_after_i(n, 0);
        int last_i_idx = -1;
        int start_d = 0; // Count the starting 'D'
        for (int i = 0; i < n; i++)
        {
            if (pattern[i] == 'D')
            {
                if (last_i_idx == -1)
                    start_d++;
                else
                    d_after_i[last_i_idx]++;
            }
            else if (pattern[i] == 'I')
            {
                last_i_idx = i;
            }
        }

        string res;
        char last_top = '1';
        res.push_back(last_top + start_d);
        last_top = res.back();
        for (int i = 0; i < n; i++)
        {
            if (pattern[i] == 'I')
            {
                res.push_back(last_top + 1 + d_after_i[i]);
                last_top = res.back();
            }
            else if (pattern[i] == 'D')
                res.push_back(res.back() - 1);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string pattern_1 = "IIIDIDDD";
    string res_1 = sol.smallestNumber(pattern_1);
    cout << res_1 << endl;
    assert((res_1 == "123549876"));

    // Test_2
    string pattern_2 = "DDD";
    string res_2 = sol.smallestNumber(pattern_2);
    cout << res_2 << endl;
    assert((res_2 == "4321"));
    return 0;
}
// Accepted
// 104/104 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 63.49 % of cpp submissions (8 MB)