/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 *
 * https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/
 *
 * algorithms
 * Medium (56.74%)
 * Likes:    996
 * Dislikes: 46
 * Total Accepted:    54.8K
 * Total Submissions: 88.4K
 * Testcase Example:  '"ababccc"'
 *
 * Given a string s, return the maximum number of unique substrings that the
 * given string can be split into.
 *
 * You can split string s into any list of non-empty substrings, where the
 * concatenation of the substrings forms the original string. However, you must
 * split the substrings such that all of them are unique.
 *
 * A substring is a contiguous sequence of characters within a string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ababccc"
 * Output: 5
 * Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc'].
 * Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a'
 * and 'b' multiple times.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aba"
 * Output: 2
 * Explanation: One way to split maximally is ['a', 'ba'].
 *
 *
 * Example 3:
 *
 *
 * Input: s = "aa"
 * Output: 1
 * Explanation: It is impossible to split the string any further.
 *
 *
 *
 * Constraints:
 *
 *
 *
 * 1 <= s.length <= 16
 *
 *
 * s contains only lower case English letters.
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxUniqueSplit(string s)
    {
        int maxi = 1;
        const int n = (int) s.length();
        for (int fences = (1 << (n - 1)) - 1; fences >= 0; fences--)
        {
            if (__builtin_popcount(fences) < maxi)
                continue;

            unordered_set<string> str_set;
            string curr{ s[0] };
            bool unique = true;
            for (int32_t bit = 0; bit < n - 1; ++bit)
            {
                if (fences >> bit & 1)
                {
                    if (!str_set.insert(curr).second)
                    {
                        unique = false;
                        break;
                    }

                    curr.clear();
                }
                curr.push_back(s[bit + 1]);
            }
            if (!str_set.insert(curr).second)
                continue;
            if (unique)
            {
                maxi = max(maxi, (int) str_set.size());
            }
        }
        return maxi;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "ababccc";
    int res_1 = sol.maxUniqueSplit(s_1);
    cout << res_1 << endl;
    assert(res_1 == 5);

    // Test_2
    string s_2 = "aba";
    int res_2 = sol.maxUniqueSplit(s_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    // Test_3
    string s_3 = "aa";
    int res_3 = sol.maxUniqueSplit(s_3);
    cout << res_3 << endl;
    assert(res_3 == 1);

    // Test_4
    string s_4 = "wwwzfvedwfvhsww";
    int res_4 = sol.maxUniqueSplit(s_4);
    cout << res_4 << endl;
    assert(res_4 == 11);

    return 0;
}
