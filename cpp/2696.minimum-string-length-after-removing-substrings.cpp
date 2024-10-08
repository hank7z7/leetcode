/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 *
 * https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/
 *
 * algorithms
 * Easy (69.93%)
 * Likes:    626
 * Dislikes: 17
 * Total Accepted:    108.6K
 * Total Submissions: 143.8K
 * Testcase Example:  '"ABFCACDB"'
 *
 * You are given a string s consisting only of uppercase English letters.
 *
 * You can apply some operations to this string where, in one operation, you
 * can remove any occurrence of one of the substrings "AB" or "CD" from s.
 *
 * Return the minimum possible length of the resulting string that you can
 * obtain.
 *
 * Note that the string concatenates after removing the substring and could
 * produce new "AB" or "CD" substrings.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ABFCACDB"
 * Output: 2
 * Explanation: We can do the following operations:
 * - Remove the substring "ABFCACDB", so s = "FCACDB".
 * - Remove the substring "FCACDB", so s = "FCAB".
 * - Remove the substring "FCAB", so s = "FC".
 * So the resulting length of the string is 2.
 * It can be shown that it is the minimum length that we can obtain.
 *
 * Example 2:
 *
 *
 * Input: s = "ACBBD"
 * Output: 5
 * Explanation: We cannot do any operations on the string so the length remains
 * the same.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s consists only of uppercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minLength(const string& s)
    {
        stack<char> st;
        for (auto& c : s)
        {
            if (!st.empty()
                && ((st.top() == 'C' && c == 'D')
                    || (st.top() == 'A' && c == 'B')))
                st.pop();
            else
                st.push(c);
        }
        return (int) st.size();
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "ABFCACDB";
    int res_1 = sol.minLength(s_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    string s_2 = "ABFCACDB";
    int res_2 = sol.minLength(s_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    return 0;
}
// Accepted
// 1541/1541 cases passed (4 ms)
// Your runtime beats 76.08 % of cpp submissions
// Your memory usage beats 77.53 % of cpp submissions (11.3 MB)