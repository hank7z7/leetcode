/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 *
 * https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/
 *
 * algorithms
 * Easy (58.51%)
 * Likes:    611
 * Dislikes: 30
 * Total Accepted:    81.9K
 * Total Submissions: 120.7K
 * Testcase Example:  '"leeetcode"'
 *
 * A fancy string is a string where no three consecutive characters are equal.
 * 
 * Given a string s, delete the minimum possible number of characters from s to
 * make it fancy.
 * 
 * Return the final string after the deletion. It can be shown that the answer
 * will always be unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leeetcode"
 * Output: "leetcode"
 * Explanation:
 * Remove an 'e' from the first group of 'e's to create "leetcode".
 * No three consecutive characters are equal, so return "leetcode".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaabaaaa"
 * Output: "aabaa"
 * Explanation:
 * Remove an 'a' from the first group of 'a's to create "aabaaaa".
 * Remove two 'a's from the second group of 'a's to create "aabaa".
 * No three consecutive characters are equal, so return "aabaa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "aab"
 * Output: "aab"
 * Explanation: No three consecutive characters are equal, so return "aab".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists only of lowercase English letters.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string makeFancyString(const string& s) {
        string res = "";
        int i = 0;
        for(auto &c : s)
        {
            if(i > 1 && c == res[i - 1] && res[i - 1] == res[i - 2])
                continue;
            res.push_back(c);
            i++;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "leeetcode";
    string res_1 = sol.makeFancyString(s_1);
    cout << res_1 << endl;
    assert(res_1 == "leetcode");

    // Test_2
    string s_2 = "aaabaaaa";
    string res_2 = sol.makeFancyString(s_2);
    cout << res_2 << endl;
    assert(res_2 == "aabaa");

    // Test_3
    string s_3 = "aab";
    string res_3 = sol.makeFancyString(s_3);
    cout << res_3 << endl;
    assert(res_3 == "aab");

    return 0;
}
// Accepted
// 306/306 cases passed (39 ms)
// Your runtime beats 20.78 % of cpp submissions
// Your memory usage beats 91.86 % of cpp submissions (37.3 MB)