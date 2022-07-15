/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    struct ListNode *result;
    if(list1->val <= list2->val)
    {
        result = list1;
        list1 = list1->next;
    }
    else
    {
        result = list2;
        list2 = list2->next;
    }
        
    struct ListNode *current = result;

    while(list1 != NULL || list2 != NULL)
    {
        if(list1 == NULL)
        {
            current->next = list2;
            break;
        }
        else if(list2 == NULL)
        {
            current->next = list1;
            break;
        }
        else
        {
            if(list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
        }
        current = current->next;
    }
    return result;
}
// @lc code=end

// Accepted
// 208/208 cases passed (3 ms)
// Your runtime beats 86.11 % of c submissions
// Your memory usage beats 8.33 % of c submissions (6.3 MB)