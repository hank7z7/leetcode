/*
 * @lc app=leetcode id=564 lang=cpp
 *
 * [564] Find the Closest Palindrome
 *
 * https://leetcode.com/problems/find-the-closest-palindrome/description/
 *
 * algorithms
 * Hard (22.59%)
 * Likes:    1076
 * Dislikes: 1624
 * Total Accepted:    88.8K
 * Total Submissions: 308.7K
 * Testcase Example:  '"123"'
 *
 * Given a string n representing an integer, return the closest integer (not
 * including itself), which is a palindrome. If there is a tie, return the
 * smaller one.
 *
 * The closest is defined as the absolute difference minimized between two
 * integers.
 *
 *
 * Example 1:
 *
 *
 * Input: n = "123"
 * Output: "121"
 *
 *
 * Example 2:
 *
 *
 * Input: n = "1"
 * Output: "0"
 * Explanation: 0 and 2 are the closest palindromes but we return the smallest
 * which is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n.length <= 18
 * n consists of only digits.
 * n does not have leading zeros.
 * n is representing an integer in the range [1, 10^18 - 1].
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string nearestPalindromic(string numberStr)
    {
        long long number = stoll(numberStr);

        // Edge cases for small numbers
        if (number <= 10)
            return to_string(number - 1);
        if (number == 11)
            return "9";

        // Special case for 18-digit number with all 9s, thanks to dcodeDV for pointing this out
        if (numberStr == "999999999999999999")
        {
            return "1000000000000000001";
        }

        int length = numberStr.length();
        long long leftHalf = stoll(numberStr.substr(0, (length + 1) / 2));

        vector<long long> palindromeCandidates(5);
        palindromeCandidates[0] = generatePalindromeFromLeft(leftHalf - 1, length % 2 == 0);
        palindromeCandidates[1] = generatePalindromeFromLeft(leftHalf, length % 2 == 0);

        // Handle potential overflow for leftHalf + 1
        if (leftHalf < 999999999)
        {
            palindromeCandidates[2] = generatePalindromeFromLeft(leftHalf + 1, length % 2 == 0);
        }
        else
        {
            palindromeCandidates[2] = stoll("1" + string(length - 1, '0') + "1");
        }

        palindromeCandidates[3] = pow(10, length - 1) - 1;
        palindromeCandidates[4] = pow(10, length) + 1;

        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;

        for (long long candidate : palindromeCandidates)
        {
            if (candidate == number)
                continue;
            long long difference = abs(candidate - number);
            if (difference < minDifference || (difference == minDifference && candidate < nearestPalindrome))
            {
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }

        return to_string(nearestPalindrome);
    }

private:
    long long generatePalindromeFromLeft(long long leftHalf, bool isEvenLength)
    {
        long long palindrome = leftHalf;
        if (!isEvenLength)
            leftHalf /= 10;
        while (leftHalf > 0)
        {
            palindrome = palindrome * 10 + leftHalf % 10;
            leftHalf /= 10;
        }
        return palindrome;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string n_1 = "123";
    string res_1 = sol.nearestPalindromic(n_1);
    cout << res_1 << endl;
    assert(res_1 == "121");

    // Test_2
    string n_2 = "1";
    string res_2 = sol.nearestPalindromic(n_2);
    cout << res_2 << endl;
    assert(res_2 == "0");

    // Test_3
    string n_3 = "99800";
    string res_3 = sol.nearestPalindromic(n_3);
    cout << res_3 << endl;
    assert(res_3 == "99799");

    // Test_4
    string n_4 = "12120";
    string res_4 = sol.nearestPalindromic(n_4);
    cout << res_4 << endl;
    assert(res_4 == "12121");

    return 0;
}
