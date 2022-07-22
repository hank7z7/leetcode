/*
 * @lc app=leetcode id=70 lang=c
 *
 * [70] Climbing Stairs
 */

// @lc code=start

int climbStairs(int n) {
    // Easy DP problem
    // P(n) = P(n-1) + P(n-2)
    int step[2] = {1, 2};
    int curr_step = 3;
    if (n < 3)
        return step[n - 1];
    while (curr_step < n) {
        int third_step = step[0] + step[1];
        step[0] = step[1];
        step[1] = third_step;
        curr_step++;
    }
    return step[0] + step[1];
}
// @lc code=end

// Accepted
// 45/45 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 49.93 % of c submissions (5.6 MB)