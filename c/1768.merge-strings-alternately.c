/*
 * @lc app=leetcode id=1768 lang=c
 *
 * [1768] Merge Strings Alternately
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start

char* mergeAlternately(char* word1, char* word2)
{
    int   l_1    = strlen(word1);
    int   l_2    = strlen(word2);
    char* result = (char*) malloc(sizeof(char) * (l_1 + l_2 + 1));
    int   idx    = 0;
    for (int i = 0; i < l_1; i++)
    {
        result[idx] = word1[i];
        idx++;
        if (i < l_2)
        {
            result[idx] = word2[i];
            idx++;
        }
    }
    if (l_1 < l_2)
    {
        for (int i = l_1; i < l_2; i++)
        {
            result[idx] = word2[i];
            idx++;
        }
    }
    result[idx] = '\0';

    return result;
}
// @lc code=end
int main(int argc, char** argv)
{
    // Test 1
    char  test_1_word_1[] = "abc";
    char  test_1_word_2[] = "pqr";
    char* result_1        = mergeAlternately(test_1_word_1, test_1_word_2);
    printf("%s\n", result_1);
    free(result_1);

    // Test 2
    char  test_2_word_1[] = "ab";
    char  test_2_word_2[] = "pqrs";
    char* result_2        = mergeAlternately(test_2_word_1, test_2_word_2);
    printf("%s\n", result_2);
    free(result_2);

    // Test 3
    char  test_3_word_1[] = "abcd";
    char  test_3_word_2[] = "pq";
    char* result_3        = mergeAlternately(test_3_word_1, test_3_word_2);
    printf("%s\n", result_3);
    free(result_3);

    return 0;
}
// Accepted
// 108/108 cases passed (4 ms)
// Your runtime beats 10.07 % of c submissions
// Your memory usage beats 98.54 % of c submissions (5.4 MB)