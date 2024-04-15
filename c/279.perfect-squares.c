/*
 * @lc app=leetcode id=279 lang=c
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (53.15%)
 * Likes:    10637
 * Dislikes: 434
 * Total Accepted:    761.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '12'
 *
 * Given an integer n, return the least number of perfect square numbers that
 * sum to n.
 * 
 * A perfect square is an integer that is the square of an integer; in other
 * words, it is the product of some integer with itself. For example, 1, 4, 9,
 * and 16 are perfect squares while 3 and 11 are not.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */
#include <stdio.h>
// @lc code=start
int numSquares(int n) {
    
}
// @lc code=end
int main(int argc, char** argv)
{
    int n;
    int result;
    // Test_1
    n = 12;
    result = numSquares(n);
    printf("%d\n", result);

    // Test_2
    n = 13;
    result = numSquares(n);
    printf("%d\n", result);

    return 0;
}
