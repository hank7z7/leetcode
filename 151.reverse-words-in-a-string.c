/*
 * @lc app=leetcode id=151 lang=c
 *
 * [151] Reverse Words in a String
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// @lc code=start
bool  is_space(char c) { return (c == ' '); }
char* reverseWords(char* s)
{
    char* result = (char*) malloc(sizeof(char) * (strlen(s) + 1));
    // memset(result, '\0', sizeof(char) * (strlen(s) + 1));
    int result_top  = 0;
    int copy_length = 0;
    for (int i = strlen(s); i >= 0; i--)
    {
        if (is_space(s[i]))
        {
            s[i]        = '\0';
            copy_length = strlen(s + i + 1);
            if (copy_length > 0)
            {
                if (result_top > 0)
                {
                    result[result_top] = ' ';
                    result_top++;
                }
                strcpy(result + result_top, s + i + 1);
                result_top += copy_length;
            }
        }
    }
    copy_length = strlen(s);
    if (copy_length > 0)
    {
        if (result_top > 0)
        {
            result[result_top] = ' ';
            result_top++;
        }
        strcpy(result + result_top, s);
        result_top += copy_length;
    }
    result[result_top] = '\0';
    return result;
}
// @lc code=end
int main(int argc, char** argv)
{
    // Test 1
    char  s_1[]    = "the sky is blue";
    char* result_1 = reverseWords(s_1);
    printf("%s\n", result_1);
    free(result_1);

    // Test 2
    char  s_2[]    = "  hello world  ";
    char* result_2 = reverseWords(s_2);
    printf("%s\n", result_2);
    free(result_2);

    // Test 3
    char  s_3[]    = "a good   example";
    char* result_3 = reverseWords(s_3);
    printf("%s\n", result_3);
    free(result_3);

    return 0;
}
// Accepted
// 58/58 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 80.82 % of c submissions (6.4 MB)