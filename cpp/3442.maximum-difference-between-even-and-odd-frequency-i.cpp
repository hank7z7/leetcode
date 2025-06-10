/*
 * @lc app=leetcode id=3442 lang=cpp
 *
 * [3442] Maximum Difference Between Even and Odd Frequency I
 *
 * https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/
 *
 * algorithms
 * Easy (49.11%)
 * Likes:    188
 * Dislikes: 39
 * Total Accepted:    86K
 * Total Submissions: 150.5K
 * Testcase Example:  '"aaaaabbc"'
 *
 * You are given a string s consisting of lowercase English letters.
 *
 * Your task is to find the maximum difference diff = freq(a1) - freq(a2)
 * between the frequency of characters a1 and a2 in the string such that:
 *
 *
 * a1 has an odd frequency in the string.
 * a2 has an even frequency in the string.
 *
 *
 * Return this maximum difference.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aaaaabbc"
 *
 * Output: 3
 *
 * Explanation:
 *
 *
 * The character 'a' has an odd frequency of 5, and 'b' has an even frequency
 * of 2.
 * The maximum difference is 5 - 2 = 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abcabcab"
 *
 * Output: 1
 *
 * Explanation:
 *
 *
 * The character 'a' has an odd frequency of 3, and 'c' has an even frequency
 * of 2.
 * The maximum difference is 3 - 2 = 1.
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= s.length <= 100
 * s consists only of lowercase English letters.
 * s contains at least one character with an odd frequency and one with an even
 * frequency.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }
        int odd_max = INT_MIN, odd_min = INT_MAX;
        int even_max = INT_MIN, even_min = INT_MAX;
        for (int f : freq)
        {
            if (f == 0)
                continue;  // Skip characters with zero frequency
            if (f & 1)
            {  // Odd frequency
                odd_max = max(odd_max, f);
                odd_min = min(odd_min, f);
            }
            else
            {  // Even frequency
                even_max = max(even_max, f);
                even_min = min(even_min, f);
            }
        }


        return max({ odd_max - even_min,
                     odd_max - even_max,
                     odd_min - even_min,
                     odd_min - even_max });  // Maximum difference between odd and even frequencies
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution solution;
    // Test_1
    string s = "aaaaabbc";
    int result = solution.maxDifference(s);
    cout << result << endl;
    assert(result == 3);

    // Test_2
    s = "abcabcab";
    result = solution.maxDifference(s);
    cout << result << endl;
    assert(result == 1);

    // Test_3 WA
    s = "tzt";
    result = solution.maxDifference(s);
    cout << result << endl;
    assert(result == -1);

    return 0;
}
// Accepted
// 805/805 cases passed (3 ms)
// Your runtime beats 34.81 % of cpp submissions
// Your memory usage beats 59.15 % of cpp submissions (9.4 MB)