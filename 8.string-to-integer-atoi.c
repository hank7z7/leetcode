/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (16.96%)
 * Likes:    4105
 * Dislikes: 12763
 * Total Accepted:    1.4M
 * Total Submissions: 8.3M
 * Testcase Example:  '"42"'
 *
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit
 * signed integer (similar to C/C++'s atoi function).
 * 
 * The algorithm for myAtoi(string s) is as follows:
 * 
 * 
 * Read in and ignore any leading whitespace.
 * Check if the next character (if not already at the end of the string) is '-'
 * or '+'. Read this character in if it is either. This determines if the final
 * result is negative or positive respectively. Assume the result is positive
 * if neither is present.
 * Read in next the characters until the next non-digit character or the end of
 * the input is reached. The rest of the string is ignored.
 * Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If
 * no digits were read, then the integer is 0. Change the sign as necessary
 * (from step 2).
 * If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1],
 * then clamp the integer so that it remains in the range. Specifically,
 * integers less than -2^31 should be clamped to -2^31, and integers greater
 * than 2^31 - 1 should be clamped to 2^31 - 1.
 * Return the integer as the final result.
 * 
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered a whitespace character.
 * Do not ignore any characters other than the leading whitespace or the rest
 * of the string after the digits.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "42"
 * Output: 42
 * Explanation: The underlined characters are what is read in, the caret is the
 * current reader position.
 * Step 1: "42" (no characters read because there is no leading whitespace)
 * ⁠        ^
 * Step 2: "42" (no characters read because there is neither a '-' nor '+')
 * ⁠        ^
 * Step 3: "42" ("42" is read in)
 * ⁠          ^
 * The parsed integer is 42.
 * Since 42 is in the range [-2^31, 2^31 - 1], the final result is 42.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "   -42"
 * Output: -42
 * Explanation:
 * Step 1: "   -42" (leading whitespace is read and ignored)
 * ⁠           ^
 * Step 2: "   -42" ('-' is read, so the result should be negative)
 * ⁠            ^
 * Step 3: "   -42" ("42" is read in)
 * ⁠              ^
 * The parsed integer is -42.
 * Since -42 is in the range [-2^31, 2^31 - 1], the final result is -42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "4193 with words"
 * Output: 4193
 * Explanation:
 * Step 1: "4193 with words" (no characters read because there is no leading
 * whitespace)
 * ⁠        ^
 * Step 2: "4193 with words" (no characters read because there is neither a '-'
 * nor '+')
 * ⁠        ^
 * Step 3: "4193 with words" ("4193" is read in; reading stops because the next
 * character is a non-digit)
 * ⁠            ^
 * The parsed integer is 4193.
 * Since 4193 is in the range [-2^31, 2^31 - 1], the final result is 4193.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 200
 * s consists of English letters (lower-case and upper-case), digits (0-9), '
 * ', '+', '-', and '.'.
 * 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

// @lc code=start
int myAtoi(char* s) {
    long long result = 0;
    int num_of_bits = 0;
    int sign = 1;
    bool first_not_zero = false;
    // Ignore all space prefix
    while(*s == ' ')
    {
        s++;
    }

    // Sign bit
    if(*s == '-')
    {
        sign = -1;
        s++;
    }
    else if(*s == '+')
    {
        s++;
    }

    // If more than two signs, or space after integer, don't enter the while loop
    while(isdigit(*s))
    {
        if(*s != '0')
            first_not_zero = true;
        if(first_not_zero)
            num_of_bits++;
        if(num_of_bits > 10)
        {
            if(sign == 1)
                return INT_MAX;
            else if(sign == -1)
                return INT_MIN;
            break;
        }
        result = result * 10 + (*s - '0');
        s++;
    }

    result *= sign;
    if(result > INT_MAX)
        return INT_MAX;
    else if(result < INT_MIN)
        return INT_MIN;
    else
        return (int)(result);
}
// @lc code=end

int main(int argc, char** argv)
{
    char input_1[] = "42\0";
    char input_2[] = "   -42\0";
    char input_3[] = "4193 with words\0";
    char input_4[] = "wordswith4193\0";
    char input_5[] = "-2147483648\0";
    char input_6[] = "-91283472332\0";
    char input_7[] = "2147483647\0";
    char input_8[] = "2147483648\0";
    char input_9[] = "3.14159\0";
    char input_10[] = "+1\0";
    char input_11[] = "+-12\0";
    char input_18[] = "00000-42a1234\0";
    char input_19[] = "  0000000000012345678\0";
    char input_22[] = "-000000000000000000000000000000000000000000000000001\0";
    char input_44[] = "21474836460\0";
    char input_48[] = "   +0 123\0";
    char input_1072[] = "-5-\0";
    char input_1075[] = "-13+8\0";
    char input_1078[] = "21474836++\0";
    char input_1079[] = "  +  413\0";
    char input_1082[] = "  0000000000012345678\0";

    printf("%d\n", myAtoi(input_1));
    printf("%d\n", myAtoi(input_2));
    printf("%d\n", myAtoi(input_3));
    printf("%d\n", myAtoi(input_4));
    printf("%d\n", myAtoi(input_5));
    printf("%d\n", myAtoi(input_6));
    printf("%d\n", myAtoi(input_7));
    printf("%d\n", myAtoi(input_8));
    printf("%d\n", myAtoi(input_9));
    printf("%d\n", myAtoi(input_10));
    printf("%d\n", myAtoi(input_11));
    printf("%d\n", myAtoi(input_18));
    printf("%d\n", myAtoi(input_19));
    printf("%d\n", myAtoi(input_22));
    printf("%d\n", myAtoi(input_44));
    printf("%d\n", myAtoi(input_48));
    printf("%d\n", myAtoi(input_1072));
    printf("%d\n", myAtoi(input_1075));
    printf("%d\n", myAtoi(input_1078));
    printf("%d\n", myAtoi(input_1079));
    printf("%d\n", myAtoi(input_1082));


    return 0;
}