/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */
// #include <bits/stdc++.h>
// @lc code=start
int searchInsert(int *nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;
    // Binary search
    while (r > l) {
        if (r < (l + 16)) {
            for (int i = l; i <= r; i++) {
                if (nums[i] >= target)
                    return i;
            }
        }
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (nums[r] == target)
        return r;
    else if (nums[r] < target)
        return r + 1;
    else
        return r;
    return 0;
}
// @lc code=end

// int main()
// {
//     int nums[4] = {1, 3, 5, 6};
//     int target = 2;
//     int result = searchInsert(nums, 4, target);

//     return 0;
// }

// Accepted
// 64/64 cases passed (3 ms)
// Your runtime beats 93.49 % of c submissions
// Your memory usage beats 10.52 % of c submissions (6.3 MB)