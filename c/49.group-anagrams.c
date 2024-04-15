/*
 * @lc app=leetcode id=49 lang=c
 *
 * [49] Group Anagrams
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define STR_SIZE 101
#define LOWERCASE_LETTER_SIZE 26

struct hash_entry {
    // For index of result
    int idx;
    // The key of hashmap
    char* key;
    UT_hash_handle hh;
};

int cmp(const void* a, const void* b) { return *(char*) a - *(char*) b; }

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char*** result = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    for(int i = 0; i < strsSize; i++)
    {
        result[i] = (char**)malloc(sizeof(char*) * strsSize);
        (*returnColumnSizes)[i] = strsSize;
        for(int j = 0; j < strsSize; j++)
        {
            result[i][j] = (char*)malloc(sizeof(char) * STR_SIZE);
            memset(result[i][j], '\0', sizeof(char) * STR_SIZE);
        }
    }
    
    struct hash_entry* hashmap = NULL;  /* important! initialize to NULL */
    struct hash_entry* ptr;
    int curr_count[LOWERCASE_LETTER_SIZE];
    int curr_top = 0;
    char* tmp_str = malloc(sizeof(char) * (STR_SIZE));
    for(int i = 0; i < strsSize; i++)
    {
        memset(curr_count, 0, sizeof(int) * LOWERCASE_LETTER_SIZE);
        int l = strlen(strs[i]);
        memcpy(tmp_str, strs[i], l + 1);
        qsort(tmp_str, l, sizeof(char), cmp);
        printf("%s\n", tmp_str);
        // for(int j = 0; j < l; j++)
        //     curr_count[strs[i][j] - 'a']++;

        struct hash_entry * tmp_node = NULL;
        HASH_FIND_STR(hashmap, tmp_str, tmp_node); /* already in the hash? */
        if(tmp_node == NULL)
        {
            // Create new hash
            ptr = (struct hash_entry *)malloc(sizeof(struct hash_entry));
            ptr->key = (char*)malloc(sizeof(char) * (l + 1));
            memcpy(ptr, ptr->key, sizeof(char) * (l + 1));
            ptr->idx = curr_top;
            curr_top++;
            HASH_ADD_STR(hashmap, key, ptr);
        }
        else
        {
            printf("find %s: idx = %d\n", tmp_str, tmp_node->idx);
        }
    }
    free(tmp_str);
    return result;
}
// @lc code=end
#define SIZE_1 6
#define SIZE_2 1
#define SIZE_3 1
int main(int argc, char** argv)
{
    // Test_1
    int size_1 = SIZE_1;
    int returnSize_1 = 0;
    int* returnColumnSizes_1 = NULL;
    char* strs_1[SIZE_1] = {"eat\0","tea\0","tan\0","ate\0","nat\0","bat\0"};
    char*** result_1 = groupAnagrams((char**)strs_1, size_1, &returnSize_1, &returnColumnSizes_1);
    // print result
    for(int i = 0; i < size_1; i++)
    {
        printf("[");
        for(int j = 0; j < returnColumnSizes_1[i]; j++)
        {
            printf("%tmp_node ", result_1[i][j]);
        }
        printf("]");
    }
    printf("\n");
    // free pointers
    for(int i = 0; i < size_1; i++)
    {
        for(int j = 0; j < returnColumnSizes_1[i]; j++)
        {
            free(result_1[i][j]);
        }
        free(result_1[i]);
    }
    free(returnColumnSizes_1);
    free(result_1);

    // Test_2
    int size_2 = SIZE_2;
    int returnSize_2 = 0;
    int* returnColumnSizes_2 = NULL;
    char* strs_2[SIZE_2] = {""};
    char*** result_2 = groupAnagrams((char**)strs_2, size_2, &returnSize_2, &returnColumnSizes_2);
    // print result
    for(int i = 0; i < size_2; i++)
    {
        printf("[");
        for(int j = 0; j < returnColumnSizes_2[i]; j++)
        {
            printf("%tmp_node ", result_2[i][j]);
        }
        printf("]");
    }
    printf("\n");
    // free pointers
    for(int i = 0; i < size_2; i++)
    {
        for(int j = 0; j < returnColumnSizes_2[i]; j++)
        {
            free(result_2[i][j]);
        }
        free(result_2[i]);
    }
    free(returnColumnSizes_2);
    free(result_2);

    // Test_3
    int size_3 = SIZE_3;
    int returnSize_3 = 0;
    int* returnColumnSizes_3 = NULL;
    char* strs_3[SIZE_3] = {""};
    char*** result_3 = groupAnagrams((char**)strs_3, size_3, &returnSize_3, &returnColumnSizes_3);
    // print result
    for(int i = 0; i < size_3; i++)
    {
        printf("[");
        for(int j = 0; j < returnColumnSizes_3[i]; j++)
        {
            printf("%tmp_node ", result_3[i][j]);
        }
        printf("]");
    }
    printf("\n");
    // free pointers
    for(int i = 0; i < size_3; i++)
    {
        for(int j = 0; j < returnColumnSizes_3[i]; j++)
        {
            free(result_3[i][j]);
        }
        free(result_3[i]);
    }
    free(returnColumnSizes_3);
    free(result_3);
    return 0;
}
