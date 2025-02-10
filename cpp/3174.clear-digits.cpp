/*
 * @lc app=leetcode id=3174 lang=cpp
 *
 * [3174] Clear Digits
 *
 * https://leetcode.com/problems/clear-digits/description/
 *
 * algorithms
 * Easy (73.54%)
 * Likes:    180
 * Dislikes: 4
 * Total Accepted:    83.3K
 * Total Submissions: 108.9K
 * Testcase Example:  '"abc"'
 *
 * You are given a string s.
 * 
 * Your task is to remove all digits by doing this operation repeatedly:
 * 
 * 
 * Delete the first digit and the closest non-digit character to its left.
 * 
 * 
 * Return the resulting string after removing all digits.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abc"
 * 
 * Output: "abc"
 * 
 * Explanation:
 * 
 * There is no digit in the string.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cb34"
 * 
 * Output: ""
 * 
 * Explanation:
 * 
 * First, we apply the operation on s[2], and s becomes "c4".
 * 
 * Then we apply the operation on s[1], and s becomes "".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s consists only of lowercase English letters and digits.
 * The input is generated such that it is possible to delete all digits.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string clearDigits(string s) {
        string res;
        for(auto &c : s)
        {
            if(!isdigit(c))
                res.push_back(c);
            else
                res.pop_back();
        }
        return res;
    }
};
// @lc code=end
// Accepted
// 688/688 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 87.14 % of cpp submissions (8.3 MB)
