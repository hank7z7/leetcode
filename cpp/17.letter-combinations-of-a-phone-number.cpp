/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (60.13%)
 * Likes:    18098
 * Dislikes: 966
 * Total Accepted:    2M
 * Total Submissions: 3.3M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits)
    {
        // Initialize a null string for concat
        vector<string> ret;
        if (!digits.empty())
            ret.push_back("");
        vector<int> record;
        for (auto c : digits)
        {
            vector<string> new_comb;
            int digit = c - '0';
            for (auto str : ret)
                for (auto to_add : map[digit])
                    new_comb.push_back(str + to_add);
            ret.swap(new_comb);
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string digits_1 = "23";
    for (auto str : sol.letterCombinations(digits_1))
        cout << str << " ";
    cout << endl;

    // WA
    // Test_2
    string digits_2 = "";
    for (auto str : sol.letterCombinations(digits_2))
        cout << str << " ";
    cout << endl;

    // Test_3
    string digits_3 = "2";
    for (auto str : sol.letterCombinations(digits_3))
        cout << str << " ";

    // WA
    // Test_4
    string digits_4 = "";
    for (auto str : sol.letterCombinations(digits_4))
        cout << str << " ";
    cout << endl;
}
// Accepted
// 25/25 cases passed (3 ms)
// Your runtime beats 37.44 % of cpp submissions
// Your memory usage beats 90.75 % of cpp submissions (7.9 MB)