/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (30.73%)
 * Likes:    3204
 * Dislikes: 6379
 * Total Accepted:    413.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer num to its English words representation.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 123
 * Output: "One Hundred Twenty Three"
 *
 *
 * Example 2:
 *
 *
 * Input: num = 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 *
 *
 * Example 3:
 *
 *
 * Input: num = 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= num <= 2^31 - 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    string digits_table[20]
        = { "",         "One",     "Two",     "Three",     "Four",     "Five",    "Six",
            "Seven",    "Eight",   "Nine",    "Ten",       "Eleven",   "Twelve",  "Thirteen",
            "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    string tens_digits_table[10]
        = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    string thousands_digits_table[5] = { "", " Thousand", " Million", " Billion" };

public:
    // 3 digits int to string
    string int_to_str(int num)
    {
        string res            = "";
        int    hundreds_digit = num / 100;
        if (hundreds_digit)
        {
            res = res + (res.length() != 0 ? " " : "") + digits_table[hundreds_digit] + " "
                  + "Hundred";
        }
        int last_two_digit = num % 100;
        int ten_digit      = (num % 100) / 10;
        int digit          = num % 10;
        if (last_two_digit < 20 && last_two_digit > 0)
            res = res + (res.length() != 0 ? " " : "") + digits_table[last_two_digit];
        else
        {
            string ten_str = tens_digits_table[ten_digit];
            res = res + (ten_str.length() != 0 && res.length() != 0 ? " " : "") + ten_str;
            if (digit)
                res = res + (res.length() != 0 ? " " : "") + digits_table[digit];
        }

        return res;
    }
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        string res            = "";
        int    thousand_digit = 0;
        while (num)
        {
            string str = int_to_str(num % 1000);
            if (str.length() != 0)
                res = str + thousands_digits_table[thousand_digit] + (res.length() != 0 ? " " : "")
                      + res;
            num = num / 1000;
            thousand_digit++;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int    num_1 = 123;
    string res_1 = sol.numberToWords(num_1);
    cout << "\"" << res_1 << "\"" << endl;
    assert((res_1 == "One Hundred Twenty Three"));

    // Test_2
    int    num_2 = 12345;
    string res_2 = sol.numberToWords(num_2);
    cout << "\"" << res_2 << "\"" << endl;
    assert((res_2 == "Twelve Thousand Three Hundred Forty Five"));

    // Test_3
    int    num_3 = 1234567;
    string res_3 = sol.numberToWords(num_3);
    cout << "\"" << res_3 << "\"" << endl;
    assert((res_3 == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"));

    // Test_4 (WA 521/601)
    int    num_4 = 0;
    string res_4 = sol.numberToWords(num_4);
    cout << "\"" << res_4 << "\"" << endl;
    assert((res_4 == "Zero"));

    // Test_5 (WA 522/601)
    int    num_5 = 20;
    string res_5 = sol.numberToWords(num_5);
    cout << "\"" << res_5 << "\"" << endl;
    assert((res_5 == "Twenty"));

    // Test_6 (WA 575/601)
    int    num_6 = 100;
    string res_6 = sol.numberToWords(num_6);
    cout << "\"" << res_6 << "\"" << endl;
    assert((res_6 == "One Hundred"));

    // Test_7 (WA 575/601)
    int    num_7 = 1000000;
    string res_7 = sol.numberToWords(num_7);
    cout << "\"" << res_7 << "\"" << endl;
    assert((res_7 == "One Million"));

    return 0;
}
// Accepted
// 601/601 cases passed (6 ms)
// Your runtime beats 27.77 % of cpp submissions
// Your memory usage beats 79.39 % of cpp submissions (10.2 MB)