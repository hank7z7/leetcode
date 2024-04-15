/*
 * @lc app=leetcode id=228 lang=c
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Easy (46.30%)
 * Likes:    2171
 * Dislikes: 1219
 * Total Accepted:    305.7K
 * Total Submissions: 656.4K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * You are given a sorted unique integer array nums.
 * 
 * A range [a,b] is the set of all integers from a to b (inclusive).
 * 
 * Return the smallest sorted list of ranges that cover all the numbers in the
 * array exactly. That is, each element of nums is covered by exactly one of
 * the ranges, and there is no integer x such that x is in one of the ranges
 * but not in nums.
 * 
 * Each range [a,b] in the list should be output as:
 * 
 * 
 * "a->b" if a != b
 * "a" if a == b
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: The ranges are:
 * [0,2] --> "0->2"
 * [4,5] --> "4->5"
 * [7,7] --> "7"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: The ranges are:
 * [0,0] --> "0"
 * [2,4] --> "2->4"
 * [6,6] --> "6"
 * [8,9] --> "8->9"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 20
 * -2^31 <= nums[i] <= 2^31 - 1
 * All the values of nums are unique.
 * nums is sorted in ascending order.
 * 
 * 
 */
// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    char **result = (char**)malloc(sizeof(char *) * numsSize);
    *returnSize = 0;
    if(numsSize == 0)
        return result;
    
    int start = nums[0], end = nums[0];
    int i = 0;
    for(i = 1; i <= numsSize; i++)
    {
        if((i < numsSize) && (nums[i] == nums[i-1]+1))
        {
            end = nums[i];
        }
        else
        {
            // Add one set to result
            char to_string[100];
            if(start != end)
                sprintf(to_string, "%d->%d", start, end);
            else
                sprintf(to_string, "%d", start);
            char *m = malloc(sizeof(char) * (strlen(to_string) + 1));
            strcpy(m, to_string);
            result[(*returnSize)++] = m;

            
            // Assign new start
            if(i < numsSize)
            {
                start = nums[i];
                end = nums[i];
            }
        }
    }

    return result;
}
// @lc code=end

// Accepted
// 29/29 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 97.94 % of c submissions (5.6 MB)