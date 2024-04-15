/*
 * @lc app=leetcode id=451 lang=c
 *
 * [451] Sort Characters By Frequency
 */
#include <stdio.h>
#include "uthash.h"
// @lc code=start
struct hash_entry
{
    // The key of hashmap
    int key;
    // For value of hashmap
    int            count;
    UT_hash_handle hh;
};

int value_cmp(const struct hash_entry* a, const struct hash_entry* b)
{
    return a->count < b->count;
}

char* frequencySort(char* s)
{
    struct hash_entry* hashmap = NULL;
    size_t             l       = strlen(s);
    for (size_t i = 0; i < l; i++)
    {
        struct hash_entry* tmp_hash_node = NULL;
        int                c             = (int) s[i];
        HASH_FIND_INT(hashmap, &c, tmp_hash_node);
        if (tmp_hash_node == NULL)
        {
            tmp_hash_node        = (struct hash_entry*) malloc(sizeof(struct hash_entry));
            tmp_hash_node->count = 1;
            tmp_hash_node->key   = c;
            HASH_ADD_INT(hashmap, key, tmp_hash_node);
        }
        else
        {
            tmp_hash_node->count++;
        }
    }

    HASH_SORT(hashmap, value_cmp);

    int                top    = 0;
    char*              result = malloc(sizeof(char) * (l + 1));
    struct hash_entry *current, *tmp;
    HASH_ITER(hh, hashmap, current, tmp)
    {
        for (int i = 0; i < current->count; i++)
        {
            result[top] = (char) current->key;
            top++;
        }
    }
    result[top] = '\0';

    // Traverse hash table and free malloc
    HASH_ITER(hh, hashmap, current, tmp)
    {
        HASH_DEL(hashmap, current);
        free(current);
    }
    return result;
}
// @lc code=end

int main(int argc, char** argv)
{
    // Test_1
    char* s_1      = "tree";
    char* result_1 = frequencySort(s_1);
    printf("%s\n", result_1);
    free(result_1);

    // Test_2
    char* s_2      = "cccaaa";
    char* result_2 = frequencySort(s_2);
    printf("%s\n", result_2);
    free(result_2);

    // Test_3
    char* s_3      = "Aabb";
    char* result_3 = frequencySort(s_3);
    printf("%s\n", result_3);
    free(result_3);

    // Test_4
    char* s_4      = "raaeaedere";
    char* result_4 = frequencySort(s_4);
    printf("%s\n", result_4);
    free(result_4);

    return 0;
}
// Accepted
// 33/33 cases passed (8 ms)
// Your runtime beats 43.59 % of c submissions
// Your memory usage beats 89.74 % of c submissions (6.6 MB)