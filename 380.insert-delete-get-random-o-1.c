/*
 * @lc app=leetcode id=380 lang=c
 *
 * [380] Insert Delete GetRandom O(1)
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 *
 * algorithms
 * Medium (52.87%)
 * Likes:    8747
 * Dislikes: 549
 * Total Accepted:    796.6K
 * Total Submissions: 1.5M
 * Testcase Example:
 '["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]\n' +
  '[[],[1],[2],[2],[],[1],[2],[]]'
 *
 * Implement the RandomizedSet class:
 *
 *
 * RandomizedSet() Initializes the RandomizedSet object.
 * bool insert(int val) Inserts an item val into the set if not present.
 * Returns true if the item was not present, false otherwise.
 * bool remove(int val) Removes an item val from the set if present. Returns
 * true if the item was present, false otherwise.
 * int getRandom() Returns a random element from the current set of elements
 * (it's guaranteed that at least one element exists when this method is
 * called). Each element must have the same probability of being returned.
 *
 *
 * You must implement the functions of the class such that each function works
 * in average O(1) time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove",
 * "insert", "getRandom"]
 * [[], [1], [2], [2], [], [1], [2], []]
 * Output
 * [null, true, false, true, 2, true, false, 2]
 *
 * Explanation
 * RandomizedSet randomizedSet = new RandomizedSet();
 * randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was
 * inserted successfully.
 * randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
 * randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now
 * contains [1,2].
 * randomizedSet.getRandom(); // getRandom() should return either 1 or 2
 * randomly.
 * randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now
 * contains [2].
 * randomizedSet.insert(2); // 2 was already in the set, so return false.
 * randomizedSet.getRandom(); // Since 2 is the only number in the set,
 * getRandom() will always return 2.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= val <= 2^31 - 1
 * At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
 * There will be at least one element in the data structure when getRandom is
 * called.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "uthash.h"
// @lc code=start
#define ARRAY_SIZE 5000

typedef struct hashmap
{
    // For the inserted integer
    int key;
    // For the index of key in RandomizedSet arr
    int            value;
    UT_hash_handle hh;
};

typedef struct
{
    // Integer array for randomly removal in constant time
    int*            arr;
    int             size;
    struct hashmap* hashTable;
} RandomizedSet;


RandomizedSet* randomizedSetCreate()
{
    RandomizedSet* result = (RandomizedSet*) malloc(sizeof(RandomizedSet));
    result->arr           = malloc(sizeof(int) * ARRAY_SIZE);
    result->size          = 0;
    result->hashTable     = NULL;

    return result;
}

bool randomizedSetInsert(RandomizedSet* obj, int val)
{
    struct hashmap* hm;
    HASH_FIND_INT(obj->hashTable, &val, hm);
    if (!hm)
    {
        hm = malloc(sizeof(struct hashmap));
        // Restore the hashmap
        hm->key   = val;
        hm->value = obj->size;
        // Insert the RandomizedSet
        obj->arr[obj->size++] = val;
        HASH_ADD_INT(obj->hashTable, key, hm);

        return true;
    }
    else
    {
        return false;
    }
}

bool randomizedSetRemove(RandomizedSet* obj, int val)
{
    struct hashmap *hm1, *hm2;
    HASH_FIND_INT(obj->hashTable, &val, hm1);

    // If val does not exist
    if (hm1)
    {
        // Remove the val and replace with the last element in arr
        obj->arr[hm1->value] = obj->arr[obj->size - 1];
        HASH_FIND_INT(obj->hashTable, &obj->arr[obj->size - 1], hm2);
        hm2->value = hm1->value;
        obj->size--;
        HASH_DEL(obj->hashTable, hm1);

        return true;
    }
    else
    {
        return false;
    }
}

int randomizedSetGetRandom(RandomizedSet* obj) { return obj->arr[rand() % obj->size]; }

void randomizedSetFree(RandomizedSet* obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/
// @lc code=end

int main(int argc, char** argv)
{
    RandomizedSet* obj     = randomizedSetCreate();
    int            val     = 0;
    bool           param_1 = randomizedSetInsert(obj, val);
    printf("%d\n", param_1);
    bool param_2 = randomizedSetRemove(obj, val);
    printf("%d\n", param_2);
    int param_3 = randomizedSetGetRandom(obj);
    printf("%d\n", param_3);
    randomizedSetFree(obj);

    return 0;
}

// Accepted
// 19/19 cases passed (266 ms)
// Your runtime beats 91.47 % of c submissions
// Your memory usage beats 51.94 % of c submissions (81.4 MB)