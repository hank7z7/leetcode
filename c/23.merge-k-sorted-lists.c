/*
 * @lc app=leetcode id=23 lang=c
 *
 * [23] Merge k Sorted Lists
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode
{
    int              val;
    struct ListNode* next;
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int find_next_node(struct ListNode** lists, int listsSize, int* return_index)
{
    int min   = INT_MAX;
    int index = -1;
    for (int i = 0; i < listsSize; i++)
    {
        if (lists[i])
        {
            if (lists[i]->val < min)
            {
                min   = lists[i]->val;
                index = i;
            }
        }
    }

    *return_index = index;
    return index;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;
    struct ListNode* result    = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* current   = result;
    int              next_node = 0;
    while (find_next_node(lists, listsSize, &next_node) >= 0)
    {
        current->next    = lists[next_node];
        lists[next_node] = lists[next_node]->next;
        current          = current->next;
    }

    // Becareful all lists are null linked list!
    return current == result ? NULL : result->next;
}
// @lc code=end

int main(int argc, char** argv) { return 0; }
// Accepted
// 133/133 cases passed (206 ms)
// Your runtime beats 33.5 % of c submissions
// Your memory usage beats 30.25 % of c submissions (9 MB)