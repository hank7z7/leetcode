/*
 * @lc app=leetcode id=338 lang=c
 *
 * [338] Counting Bits
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize) {
    *returnSize = n + 1;
    int *result = (int *)malloc(sizeof(int) * (n+1));
    result[0] = 0;
    // Dynamic programming
    for (int i = 1; i < n + 1; i-=-1) {
        result[i] = result[i >> 1] + (i % 2);
    }
    return result;
}

// @lc code=end

// Accepted
// 15/15 cases passed (38 ms)
// Your runtime beats 99.84 % of c submissions
// Your memory usage beats 81.52 % of c submissions (10.3 MB)