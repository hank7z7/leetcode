/*
 * @lc app=leetcode id=1657 lang=c
 *
 * [1657] Determine if Two Strings Are Close
 *
 * https://leetcode.com/problems/determine-if-two-strings-are-close/description/
 *
 * algorithms
 * Medium (53.46%)
 * Likes:    3180
 * Dislikes: 210
 * Total Accepted:    226.1K
 * Total Submissions: 415.5K
 * Testcase Example:  '"abc"\n"bca"'
 *
 * Two strings are considered close if you can attain one from the other using
 * the following operations:
 *
 *
 * Operation 1: Swap any two existing characters.
 *
 *
 * For example, abcde -> aecdb
 *
 *
 * Operation 2: Transform every occurrence of one existing character into
 * another existing character, and do the same with the other
 * character.
 *
 * For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into
 * a's)
 *
 *
 *
 *
 * You can use the operations on either string as many times as necessary.
 *
 * Given two strings, word1 and word2, return true if word1 and word2 are
 * close, and false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "abc", word2 = "bca"
 * Output: true
 * Explanation: You can attain word2 from word1 in 2 operations.
 * Apply Operation 1: "abc" -> "acb"
 * Apply Operation 1: "acb" -> "bca"
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "a", word2 = "aa"
 * Output: false
 * Explanation: It is impossible to attain word2 from word1, or vice versa, in
 * any number of operations.
 *
 *
 * Example 3:
 *
 *
 * Input: word1 = "cabbba", word2 = "abbccc"
 * Output: true
 * Explanation: You can attain word2 from word1 in 3 operations.
 * Apply Operation 1: "cabbba" -> "caabbb"
 * Apply Operation 2: "caabbb" -> "baaccc"
 * Apply Operation 2: "baaccc" -> "abbccc"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 10^5
 * word1 and word2 contain only lowercase English letters.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// @lc code=start
#define LETTER_SIZE 26

int cmp(const void* a, const void* b) { return *(int*) a - *(int*) b; }

bool closeStrings(char* word1, char* word2)
{
    int word1_length = strlen(word1);
    int word2_length = strlen(word2);
    if (word1_length != word2_length)
        return false;

    int count_1[LETTER_SIZE] = { 0 };
    int count_2[LETTER_SIZE] = { 0 };
    for (int i = 0; i < word1_length; i++)
    {
        count_1[word1[i] - 'a']++;
        count_2[word2[i] - 'a']++;
    }

    // Operation 2: two same sets of letters
    for (int i = 0; i < LETTER_SIZE; i++)
    {
        if ((count_1[i] == 0 && count_2[i] != 0) || (count_1[i] != 0 && count_2[i] == 0))
            return false;
    }

    qsort(count_1, LETTER_SIZE, sizeof(int), cmp);
    qsort(count_2, LETTER_SIZE, sizeof(int), cmp);
    // Operation 2 allows you to freely reassign the letters' frequencies.
    for (int i = 0; i < LETTER_SIZE; i++)
    {
        if (count_1[i] != count_2[i])
            return false;
    }

    return true;
}
// @lc code=end

int main(int argc, char** argv)
{
    char test_1_word1[] = "abc\0";
    char test_1_word2[] = "bca\0";
    printf("%d\n", closeStrings(test_1_word1, test_1_word2));

    char test_2_word1[] = "a\0";
    char test_2_word2[] = "aa\0";
    printf("%d\n", closeStrings(test_2_word1, test_2_word2));

    char test_3_word1[] = "cabbba\0";
    char test_3_word2[] = "abbccc\0";
    printf("%d\n", closeStrings(test_3_word1, test_3_word2));

    return 0;
}

// Accepted
// 153/153 cases passed (22 ms)
// Your runtime beats 51.92 % of c submissions
// Your memory usage beats 92.31 % of c submissions (10.2 MB)