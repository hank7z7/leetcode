/*
 * @lc app=leetcode id=2182 lang=cpp
 *
 * [2182] Construct String With Repeat Limit
 *
 * https://leetcode.com/problems/construct-string-with-repeat-limit/description/
 *
 * algorithms
 * Medium (54.53%)
 * Likes:    902
 * Dislikes: 65
 * Total Accepted:    63.6K
 * Total Submissions: 95.4K
 * Testcase Example:  '"cczazcc"\n3'
 *
 * You are given a string s and an integer repeatLimit. Construct a new string
 * repeatLimitedString using the characters of s such that no letter appears
 * more than repeatLimit times in a row. You do not have to use all characters
 * from s.
 *
 * Return the lexicographically largest repeatLimitedString possible.
 *
 * A string a is lexicographically larger than a string b if in the first
 * position where a and b differ, string a has a letter that appears later in
 * the alphabet than the corresponding letter in b. If the first min(a.length,
 * b.length) characters do not differ, then the longer string is the
 * lexicographically larger one.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cczazcc", repeatLimit = 3
 * Output: "zzcccac"
 * Explanation: We use all of the characters from s to construct the
 * repeatLimitedString "zzcccac".
 * The letter 'a' appears at most 1 time in a row.
 * The letter 'c' appears at most 3 times in a row.
 * The letter 'z' appears at most 2 times in a row.
 * Hence, no letter appears more than repeatLimit times in a row and the string
 * is a valid repeatLimitedString.
 * The string is the lexicographically largest repeatLimitedString possible so
 * we return "zzcccac".
 * Note that the string "zzcccca" is lexicographically larger but the letter
 * 'c' appears more than 3 times in a row, so it is not a valid
 * repeatLimitedString.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aababab", repeatLimit = 2
 * Output: "bbabaa"
 * Explanation: We use only some of the characters from s to construct the
 * repeatLimitedString "bbabaa".
 * The letter 'a' appears at most 2 times in a row.
 * The letter 'b' appears at most 2 times in a row.
 * Hence, no letter appears more than repeatLimit times in a row and the string
 * is a valid repeatLimitedString.
 * The string is the lexicographically largest repeatLimitedString possible so
 * we return "bbabaa".
 * Note that the string "bbabaaa" is lexicographically larger but the letter
 * 'a' appears more than 2 times in a row, so it is not a valid
 * repeatLimitedString.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= repeatLimit <= s.length <= 10^5
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
    string repeatLimitedString(const string& s, const int& repeatLimit)
    {
        vector<int> count(26, 0);
        for (auto& c : s)
            count[c - 'a']++;
        string res;

        for (int i = 'z' - 'a'; i >= 'a' - 'a'; i--)
        {
            if (count[i] == 0)
                continue;
            while (count[i])
            {
                int insert = min(count[i], repeatLimit);
                for (int j = 0; j < insert; j++)
                    res.push_back('a' + i);
                count[i] -= insert;

                bool find_a_next = false;
                if (count[i])
                    for (int j = i - 1; j >= 0; j--)
                        if (count[j])
                        {
                            res.push_back('a' + j);
                            count[j]--;
                            find_a_next = true;
                            break;
                        }
                if (!find_a_next && count[i])
                    break;
            }
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "cczazcc";
    int repeatLimit_1 = 3;
    string res_1 = sol.repeatLimitedString(s_1, repeatLimit_1);
    cout << res_1 << endl;
    assert(res_1 == "zzcccac");

    // Test_2
    string s_2 = "aababab";
    int repeatLimit_2 = 2;
    string res_2 = sol.repeatLimitedString(s_2, repeatLimit_2);
    cout << res_2 << endl;
    assert(res_2 == "bbabaa");

    // Test_3
    string s_3 = "robnsdvpuxbapuqgopqvxdrchivlifeepy";
    int repeatLimit_3 = 2;
    string res_3 = sol.repeatLimitedString(s_3, repeatLimit_3);
    cout << res_3 << endl;
    assert(res_3 == "yxxvvuvusrrqqppopponliihgfeeddcbba");

    return 0;
}
// Accepted
// 150/150 cases passed (6 ms)
// Your runtime beats 96.46 % of cpp submissions
// Your memory usage beats 95.59 % of cpp submissions (25.7 MB)