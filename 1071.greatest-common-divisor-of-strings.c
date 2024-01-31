/*
 * @lc app=leetcode id=1071 lang=c
 *
 * [1071] Greatest Common Divisor of Strings
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// @lc code=start
#define max(a, b)                                                                                  \
    ({                                                                                             \
        __typeof__(a) _a = (a);                                                                    \
        __typeof__(b) _b = (b);                                                                    \
        _a > _b ? _a : _b;                                                                         \
    })
#define min(a, b)                                                                                  \
    ({                                                                                             \
        __typeof__(a) _a = (a);                                                                    \
        __typeof__(b) _b = (b);                                                                    \
        _a < _b ? _a : _b;                                                                         \
    })

char* gcdOfStrings(char* str1, char* str2)
{
    int   l_1          = strlen(str1);
    int   l_2          = strlen(str2);
    int   l_result     = 1;
    int   l_result_max = 0;
    char* result       = (char*) malloc(sizeof(char) * (l_1 + l_2 + 1));
    memset(result, '\0', sizeof(char) * (l_1 + l_2 + 1));
    for (int i = 0; i < min(l_1, l_2); i++, l_result++)
    {
        result[i] = str1[i];
        // Can divide both str
        bool valid = true;
        if ((l_1 % l_result == 0) || (l_2 % l_result == 0))
        {
            for (int j = 0; j < l_1; j += l_result)
            {
                if (strncmp(str1 + j, result, l_result) != 0)
                {
                    valid = false;
                    break;
                }
            }
            for (int j = 0; j < l_2; j += l_result)
            {
                if (strncmp(str2 + j, result, l_result) != 0)
                {
                    valid = false;
                    break;
                }
            }
        }
        else
        {
            valid = false;
        }
        if (valid)
        {
            l_result_max = l_result;
        }
    }
    result[l_result_max] = '\0';

    return result;
}
// @lc code=end

int main(int argc, char** argv)
{
    // Test 1
    char  test_1_word_1[] = "ABCABC";
    char  test_1_word_2[] = "ABC";
    char* result_1        = gcdOfStrings(test_1_word_1, test_1_word_2);
    printf("%s\n", result_1);
    free(result_1);

    // Test 2
    char  test_2_word_1[] = "ABABAB";
    char  test_2_word_2[] = "ABAB";
    char* result_2        = gcdOfStrings(test_2_word_1, test_2_word_2);
    printf("%s\n", result_2);
    free(result_2);

    // Test 3
    char  test_3_word_1[] = "LEET";
    char  test_3_word_2[] = "CODE";
    char* result_3        = gcdOfStrings(test_3_word_1, test_3_word_2);
    printf("%s\n", result_3);
    free(result_3);

    return 0;
}
// Accepted
// 123/123 cases passed (5 ms)
// Your runtime beats 15.53 % of c submissions
// Your memory usage beats 95.1 % of c submissions (5.7 MB)