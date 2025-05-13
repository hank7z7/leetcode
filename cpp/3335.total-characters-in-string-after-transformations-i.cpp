/*
 * @lc app=leetcode id=3335 lang=cpp
 *
 * [3335] Total Characters in String After Transformations I
 *
 * https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/
 *
 * algorithms
 * Medium (26.69%)
 * Likes:    267
 * Dislikes: 20
 * Total Accepted:    40.8K
 * Total Submissions: 108.8K
 * Testcase Example:  '"abcyy"\n2'
 *
 * You are given a string s and an integer t, representing the number of
 * transformations to perform. In one transformation, every character in s is
 * replaced according to the following rules:
 *
 *
 * If the character is 'z', replace it with the string "ab".
 * Otherwise, replace it with the next character in the alphabet. For example,
 * 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
 *
 *
 * Return the length of the resulting string after exactly t transformations.
 *
 * Since the answer may be very large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcyy", t = 2
 *
 * Output: 7
 *
 * Explanation:
 *
 *
 * First Transformation (t = 1):
 *
 *
 * 'a' becomes 'b'
 * 'b' becomes 'c'
 * 'c' becomes 'd'
 * 'y' becomes 'z'
 * 'y' becomes 'z'
 * String after the first transformation: "bcdzz"
 *
 *
 * Second Transformation (t = 2):
 *
 * 'b' becomes 'c'
 * 'c' becomes 'd'
 * 'd' becomes 'e'
 * 'z' becomes "ab"
 * 'z' becomes "ab"
 * String after the second transformation: "cdeabab"
 *
 *
 * Final Length of the string: The string is "cdeabab", which has 7
 * characters.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: s = "azbk", t = 1
 *
 * Output: 5
 *
 * Explanation:
 *
 *
 * First Transformation (t = 1):
 *
 *
 * 'a' becomes 'b'
 * 'z' becomes "ab"
 * 'b' becomes 'c'
 * 'k' becomes 'l'
 * String after the first transformation: "babcl"
 *
 *
 * Final Length of the string: The string is "babcl", which has 5
 * characters.
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists only of lowercase English letters.
 * 1 <= t <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t)
    {
        vector<long long> cnt(26, 0);
        for (auto c : s)
            cnt[c - 'a']++;
        for (int i = 0; i < t; i++)
        {
            int z_cnt = cnt[25];
            for (int i = 24; i >= 0; i--)
                cnt[i + 1] = cnt[i];
            // z to a
            cnt[0] = z_cnt % mod;
            // z to b
            cnt[1] = (cnt[1] + z_cnt) % mod;
        }
        long long res = 0;
        for (int i = 0; i < 26; i++)
        {
            res = (res + cnt[i]) % mod;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s = "abcyy";
    int t = 2;
    int res = sol.lengthAfterTransformations(s, t);
    cout << "Test_1: " << res << endl;
    assert(res == 7);

    // Test_2
    s = "azbk";
    t = 1;
    res = sol.lengthAfterTransformations(s, t);
    cout << "Test_2: " << res << endl;
    assert(res == 5);

    return 0;
}
// Accepted
// 824/824 cases passed (85 ms)
// Your runtime beats 78.33 % of cpp submissions
// Your memory usage beats 91.13 % of cpp submissions (19.1 MB)