/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (52.26%)
 * Likes:    6460
 * Dislikes: 2222
 * Total Accepted:    2.3M
 * Total Submissions: 4.3M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is palindrome integer.
 *
 * An integer is a palindrome when it reads the same backward as forward.
 *
 *
 * For example, 121 is a palindrome while 123 is not.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 *
 *
 * Example 2:
 *
 *
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= x <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you solve it without converting the integer to a string?
 */

// #include <bits/stdc++.h>
// @lc code=start

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    else {
        int bits = 0;
        int x_string[10]; // INT_MAX=2147483647 (10 bits)
        
        // Transfer integer to string, bits = number of digits
        while(x > 0)
        {
            x_string[bits++] = x % 10;
            x = x / 10;
        }

        // Check palindrome
        bool palindrome = true;
        for(int i = 0; i < bits / 2; i++)
        {
            if(x_string[i] != x_string[bits-1-i])
            {
                palindrome = false;
                break;
            }
        }
        return palindrome;
    }
}
// @lc code=end

// int main()
// {
//     int x = 10;
//     bool y = isPalindrome(x);

//     return 0;
// }

// Accepted
// 11510/11510 cases passed (11 ms)
// Your runtime beats 90.36 % of c submissions
// Your memory usage beats 68.01 % of c submissions (5.9 MB)