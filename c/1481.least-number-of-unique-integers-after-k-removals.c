/*
 * @lc app=leetcode id=1481 lang=c
 *
 * [1481] Least Number of Unique Integers after K Removals
 */
#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
// @lc code=start
struct hash_entry
{
    int            key;
    int            idx;
    UT_hash_handle hh;
};

int cmp(const void* a, const void* b) { return *(int*) a - *(int*) b; }

int findLeastNumOfUniqueInts(int* arr, int arrSize, int k)
{
    struct hash_entry* hashmap   = NULL;
    int*               count     = (int*) malloc(sizeof(int) * arrSize);
    int                count_top = 0;
    for (int i = 0; i < arrSize; i++)
    {
        struct hash_entry* hash_node = NULL;
        int                key       = arr[i];
        HASH_FIND_INT(hashmap, &key, hash_node);
        // Key doesn't exist
        if (hash_node == NULL)
        {
            // Add key
            hash_node      = (struct hash_entry*) malloc(sizeof(struct hash_entry));
            hash_node->key = key;
            hash_node->idx = count_top;
            HASH_ADD_INT(hashmap, key, hash_node);

            // Update count table
            count[count_top] = 1;
            count_top++;
        }
        else
        {
            count[hash_node->idx]++;
        }
    }

    // Traverse the hashmap and free the hash nodes
    struct hash_entry *current, *tmp;
    HASH_ITER(hh, hashmap, current, tmp)
    {
        HASH_DEL(hashmap, current);
        free(current);
    }

    qsort(count, count_top, sizeof(int), cmp);

    int result = count_top;
    for (int i = 0; i < count_top; i++)
    {
        k -= count[i];
        if (k < 0)
            break;
        result--;
    }
    free(count);
    return result;
}
// @lc code=end
#define SIZE_1 (3)
#define SIZE_2 (7)
int main(int argc, char** argv)
{
    int k;
    int size;
    // Test_1
    size              = SIZE_1;
    k                 = 1;
    int arr_1[SIZE_1] = { 5, 5, 4 };
    printf("%d\n", findLeastNumOfUniqueInts(arr_1, size, k));

    // Test_2
    size              = SIZE_2;
    k                 = 3;
    int arr_2[SIZE_2] = { 4, 3, 1, 1, 3, 3, 2 };
    printf("%d\n", findLeastNumOfUniqueInts(arr_2, size, k));

    return 0;
}
// Accepted
// 43/43 cases passed (162 ms)
// Your runtime beats 75 % of c submissions
// Your memory usage beats 25 % of c submissions (45.3 MB)