/*
 * @lc app=leetcode id=443 lang=c
 *
 * [443] String Compression
 *
 * https://leetcode.com/problems/string-compression/description/
 *
 * algorithms
 * Medium (53.93%)
 * Likes:    4768
 * Dislikes: 7562
 * Total Accepted:    523.1K
 * Total Submissions: 969.8K
 * Testcase Example:  '["a","a","b","b","c","c","c"]'
 *
 * Given an array of characters chars, compress it using the following
 * algorithm:
 * 
 * Begin with an empty string s. For each group of consecutive repeating
 * characters in chars:
 * 
 * 
 * If the group's length is 1, append the character to s.
 * Otherwise, append the character followed by the group's length.
 * 
 * 
 * The compressed string s should not be returned separately, but instead, be
 * stored in the input character array chars. Note that group lengths that are
 * 10 or longer will be split into multiple characters in chars.
 * 
 * After you are done modifying the input array, return the new length of the
 * array.
 * 
 * You must write an algorithm that uses only constant extra space.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: chars = ["a","a","b","b","c","c","c"]
 * Output: Return 6, and the first 6 characters of the input array should be:
 * ["a","2","b","2","c","3"]
 * Explanation: The groups are "aa", "bb", and "ccc". This compresses to
 * "a2b2c3".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: chars = ["a"]
 * Output: Return 1, and the first character of the input array should be:
 * ["a"]
 * Explanation: The only group is "a", which remains uncompressed since it's a
 * single character.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * Output: Return 4, and the first 4 characters of the input array should be:
 * ["a","b","1","2"].
 * Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to
 * "ab12".
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= chars.length <= 2000
 * chars[i] is a lowercase English letter, uppercase English letter, digit, or
 * symbol.
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
int compress(char* chars, int charsSize) {
    // For consecutive chars length
    int count = 0;
    // For fill back to chars
    int top = 0;
    char str[100];
    for(int i = 0; i < charsSize; i++)
    {
        count++;
        if(i == (charsSize - 1) || chars[i] != chars[i + 1])
        {
            // Fill the char
            chars[top++] = chars[i];
            // Fill the number
            if(count > 1)
            {
                // itoa
                sprintf(str, "%d", count);
                for(int j = 0; j < strlen(str); j++)
                    chars[top++] = str[j];
                // Reset the count
            }
            count = 0;
        }
    }
    return top;
}
// @lc code=end
#define SIZE_1 (7)
#define SIZE_2 (1)
#define SIZE_3 (13)
int main(int argc, char** argv)
{
    int size = 0;
    // Test_1
    size = SIZE_1;
    char chars_1[SIZE_1] = { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
    printf("%d\n", compress(chars_1, size));
    for (size_t i = 0; i < sizeof(chars_1)/sizeof(char); i++)
        printf("%c", chars_1[i]);
    printf("\n");

    // Test _2
    size = SIZE_2;
    char chars_2[] = { 'a' };
    printf("%d\n", compress(chars_2, size));
    for (size_t i = 0; i < sizeof(chars_2)/sizeof(char); i++)
        printf("%c", chars_2[i]);
    printf("\n");

    // Test _3
    size = SIZE_3;
    char chars_3[SIZE_3] = { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
    printf("%d\n", compress(chars_3, size));
    for (size_t i = 0; i < sizeof(chars_3)/sizeof(char); i++)
        printf("%c", chars_3[i]);
    printf("\n");
    return 0;
}
// Accepted
// 76/76 cases passed (6 ms)
// Your runtime beats 77.35 % of c submissions
// Your memory usage beats 83.28 % of c submissions (6.1 MB)