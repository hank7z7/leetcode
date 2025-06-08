/*
 * @lc app=leetcode id=3170 lang=cpp
 *
 * [3170] Lexicographically Minimum String After Removing Stars
 *
 * https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/
 *
 * algorithms
 * Medium (35.21%)
 * Likes:    451
 * Dislikes: 65
 * Total Accepted:    77.5K
 * Total Submissions: 163.6K
 * Testcase Example:  '"aaba*"'
 *
 * You are given a string s. It may contain any number of '*' characters. Your
 * task is to remove all '*' characters.
 *
 * While there is a '*', do the following operation:
 *
 *
 * Delete the leftmost '*' and the smallest non-'*' character to its left. If
 * there are several smallest characters, you can delete any of them.
 *
 *
 * Return the lexicographically smallest resulting string after removing all
 * '*' characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aaba*"
 *
 * Output: "aab"
 *
 * Explanation:
 *
 * We should delete one of the 'a' characters with '*'. If we choose s[3], s
 * becomes the lexicographically smallest.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abc"
 *
 * Output: "abc"
 *
 * Explanation:
 *
 * There is no '*' in the string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists only of lowercase English letters and '*'.
 * The input is generated such that it is possible to delete all '*'
 * characters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    struct Compare
    {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) const
        {
            if (a.first == b.first)
                return a.second < b.second;  // smaller index comes first
            return a.first > b.first;        // bigger char comes first
        }
    };
    string clearStars(string s)
    {
        int n = (int) s.length();
        // <char, index>
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                if (!pq.empty())
                {
                    // remove the smallest character
                    pq.pop();
                }
            }
            else
            {
                // add the current character to the priority queue
                pq.push({ s[i], i });
            }
        }

        vector<pair<char, int>> pairs;  // store the result characters
        while (!pq.empty())
        {
            auto [ch, idx] = pq.top();
            pq.pop();
            pairs.push_back({ ch, idx });
        }

        sort(pairs.begin(),
             pairs.end(),
             [](const pair<char, int>& a, const pair<char, int>& b)
             {
                 return a.second < b.second;  // sort by index
             });
        string res;
        for (const auto& p : pairs)
        {
            res += p.first;  // append the character to the result
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s1 = "aaba*";
    cout << sol.clearStars(s1) << endl;  // Expected output: "aab"
    assert(sol.clearStars(s1) == "aab");

    // Test_2
    string s2 = "abc";
    cout << sol.clearStars(s2) << endl;  // Expected output: "abc"
    assert(sol.clearStars(s2) == "abc");
    return 0;
}
// Accepted
// 602/602 cases passed (146 ms)
// Your runtime beats 43.82 % of cpp submissions
// Your memory usage beats 47.19 % of cpp submissions (29.2 MB)