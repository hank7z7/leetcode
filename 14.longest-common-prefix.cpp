/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (41.82%)
 * Likes:    16450
 * Dislikes: 4322
 * Total Accepted:    2.9M
 * Total Submissions: 6.9M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 *
 * Example 1:
 *
 *
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    static string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
            return "";

        string result = "";
        for (size_t i = 0; i < strs[0].size(); i++)
        {
            for (const auto& it : strs)
            {
                if (it.length() <= i || it[i] != strs[0][i])
                    return result;
            }
            result += strs[0][i];
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char** argv)
{
    vector<string> strs1;
    strs1.push_back("flower");
    strs1.push_back("flow");
    strs1.push_back("flight");
    cout << Solution::longestCommonPrefix(strs1) << endl;

    vector<string> strs2;
    strs2.clear();
    strs2.push_back("dog");
    strs2.push_back("racecar");
    strs2.push_back("car");
    cout << Solution::longestCommonPrefix(strs2) << endl;
}
// Accepted
// 124/124 cases passed (3 ms)
// Your runtime beats 72.02 % of cpp submissions
// Your memory usage beats 38.97 % of cpp submissions (9.7 MB)