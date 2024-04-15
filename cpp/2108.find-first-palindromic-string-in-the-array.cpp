/*
 * @lc app=leetcode id=2108 lang=cpp
 *
 * [2108] Find First Palindromic String in the Array
 *
 * https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
 *
 * algorithms
 * Easy (79.19%)
 * Likes:    1462
 * Dislikes: 50
 * Total Accepted:    245.5K
 * Total Submissions: 292.2K
 * Testcase Example:  '["abc","car","ada","racecar","cool"]'
 *
 * Given an array of strings words, return the first palindromic string in the
 * array. If there is no such string, return an empty string "".
 *
 * A string is palindromic if it reads the same forward and backward.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abc","car","ada","racecar","cool"]
 * Output: "ada"
 * Explanation: The first string that is palindromic is "ada".
 * Note that "racecar" is also palindromic, but it is not the first.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["notapalindrome","racecar"]
 * Output: "racecar"
 * Explanation: The first and only string that is palindromic is "racecar".
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["def","ghi"]
 * Output: ""
 * Explanation: There are no palindromic strings, so the empty string is
 * returned.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] consists only of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    static bool is_palidrome(string s)
    {
        size_t l = s.size();
        for (size_t i = 0; i < (l / 2); i++)
        {
            if (s[i] != s[l - 1 - i])
                return false;
        }
        return true;
    }

public:
    static string firstPalindrome(vector<string>& words)
    {
        for (size_t i = 0; i < words.size(); i++)
            if (is_palidrome(words[i]))
                return words[i];
        return "";
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    // Test_1
    vector<string> words_1 = { "abc", "car", "ada", "racecar", "cool" };
    std::cout << Solution::firstPalindrome(words_1) << std::endl;

    // Test_2
    vector<string> words_2 = { "notapalindrome", "racecar" };
    std::cout << Solution::firstPalindrome(words_2) << std::endl;

    // Test_3
    vector<string> words_3 = { "def", "ghi" };
    std::cout << Solution::firstPalindrome(words_3) << std::endl;
    return 0;
}
// Accepted
// 266/266 cases passed (52 ms)
// Your runtime beats 37.56 % of cpp submissions
// Your memory usage beats 16.9 % of cpp submissions (26.7 MB)