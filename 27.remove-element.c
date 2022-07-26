/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// #include <bits/stdc++.h>
// @lc code=start
int removeElement(int* nums, int numsSize, int val){
    // Early return
    if(numsSize == 0)
        return 0;
    
    // A simple queue structure
    int queue[numsSize];
    int front = 0, rear = 0, repeat_count = 0;

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == val)
        {
            // Enqueue
            queue[rear++] = i;
            repeat_count++;
        }
        else if(rear > front)
        {
            // Swap to queue.front
            nums[queue[front++]] = nums[i];
            queue[rear++] = i;
        }
    }

    return numsSize - repeat_count;
}
// @lc code=end

// int main()
// {
//     int nums[8] = {0, 1, 2, 2, 3, 0, 4, 2};
//     int numsSize = 8;
//     int val = 2;
//     int k = removeElement(nums, numsSize, val);

//     return 0;
// }

// Accepted
// 113/113 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 31.48 % of c submissions (6.2 MB)