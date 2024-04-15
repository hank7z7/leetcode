/*
 * @lc app=leetcode id=91 lang=c
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (33.20%)
 * Likes:    10710
 * Dislikes: 4377
 * Total Accepted:    1.1M
 * Total Submissions: 3.3M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z can be encoded into numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 * 
 * 
 * To decode an encoded message, all the digits must be grouped then mapped
 * back into letters using the reverse of the mapping above (there may be
 * multiple ways). For example, "11106" can be mapped into:
 * 
 * 
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 * 
 * 
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
 * into 'F' since "6" is different from "06".
 * 
 * Given a string s containing only digits, return the number of ways to decode
 * it.
 * 
 * The test cases are generated so that the answer fits in a 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "12"
 * Output: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "226"
 * Output: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2
 * 2 6).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "06"
 * Output: 0
 * Explanation: "06" cannot be mapped to "F" because of the leading zero ("6"
 * is different from "06").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 * 
 * 
 */
#include <bits/stdc++.h>
// @lc code=start
bool isAlphabet(char *s)
{
    if(s[0] > '2' || s[0] == '0')
        return false;
    else
    {
        if(s[0] == '2' && s[1] > '6')
            return false;
    }
    return true;
}
int numDecodings(char* s) {
    int result = 0;
    int l = strlen(s);
    int max_prefix = 0;
    bool invalid = false;
    bool previos_is_count = false;
    for(int i = 0; i < l; i++)
    {
        bool single_encode = false;
        bool two_encode = false;
        if(s[i] > '0')
        {
            single_encode = true;
        }
        else
        {
            invalid = true;
        }

        // Check the previous character for double-encode
        if(i > 0)
        {
            if(isAlphabet(&(s[i - 1])))
            {
                two_encode = true;
                invalid = false;
            }
            else
            {
                // Continuous invalid, early resturn
                if(invalid)
                    return 0;
                two_encode = false;
            }
        }
        if((two_encode && single_encode && !invalid) || (!two_encode && single_encode && i == 0))
        {
            if(two_encode)
                previos_is_count = true;
            // printf("i = %d\n", i);
            result++;
        }
        if(!single_encode && two_encode && previos_is_count)
        {
            result--;
            previos_is_count = false;
        }
    }
    // if(invalid)
    //     return 0;
    return result;
}
// @lc code=end
int main(int argc, char** argv)
{
    char input[] = "12";
    int result = 0;
    result = numDecodings(input);
    printf("%d\n", result);

    result = numDecodings("226");
    printf("%d\n", result);
    
    result = numDecodings("06");
    printf("%d\n", result);

    result = numDecodings("10");
    printf("%d\n", result);

    
    result = numDecodings("27");
    printf("%d\n", result);

    result = numDecodings("2101");
    printf("%d\n", result);

    result = numDecodings("1123");
    printf("%d\n", result);
    return 0;
}
// Wrong Answer
// 236/269 cases passed (N/A)
// Testcase
// "1123"
// Answer
// 4
// Expected Answer
// 5