/*
 * @lc app=leetcode id=1492 lang=c
 *
 * [1492] The kth Factor of n
 *
 * https://leetcode.com/problems/the-kth-factor-of-n/description/
 *
 * algorithms
 * Medium (66.69%)
 * Likes:    1675
 * Dislikes: 288
 * Total Accepted:    198.8K
 * Total Submissions: 298K
 * Testcase Example:  '12\n3'
 *
 * You are given two positive integers n and k. A factor of an integer n is
 * defined as an integer i where n % i == 0.
 *
 * Consider a list of all factors of n sorted in ascending order, return the
 * k^th factor in this list or return -1 if n has less than k factors.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 12, k = 3
 * Output: 3
 * Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3^rd factor is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 7, k = 2
 * Output: 7
 * Explanation: Factors list is [1, 7], the 2^nd factor is 7.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 4, k = 4
 * Output: -1
 * Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should
 * return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= n <= 1000
 *
 *
 *
 * Follow up:
 *
 * Could you solve this problem in less than O(n) complexity?
 *
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
int kthFactor(const int n, const int k)
{
    // first half of factors
    int* fac_1 = (int*) malloc(sizeof(int) * (n / 2 + 1));
    int  top_1 = 0;
    // second half of factors
    int* fac_2 = (int*) malloc(sizeof(int) * (n / 2 + 1));
    int  top_2 = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            fac_1[top_1] = i;
            top_1++;
            if (i != (n / i))
            {
                fac_2[top_2] = n / i;
                top_2++;
            }
        }
    }
    for (int i = 0; i < top_1; i++)
        printf("%d ", fac_1[i]);
    printf("\n");
    for (int i = 0; i < top_2; i++)
        printf("%d ", fac_2[i]);
    printf("\n");

    int ret = -1;
    if (k <= (top_1))
        ret = fac_1[k - 1];
    else if (k <= (top_1 + top_2))
        ret = fac_2[(top_2) - (k - top_1)];
    free(fac_1);
    free(fac_2);
    return ret;
}
// @lc code=end
int main(int argc, char** argv)
{
    int n, k;
    // Test_1
    n = 12;
    k = 3;
    printf("%d\n", kthFactor(n, k));

    // Test_2
    n = 7;
    k = 2;
    printf("%d\n", kthFactor(n, k));

    // Test_3
    n = 4;
    k = 4;
    printf("%d\n", kthFactor(n, k));

    // Test_4
    n = 1;
    k = 1;
    printf("%d\n", kthFactor(n, k));
    return 0;
}
// Accepted
// 208/208 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 18.62 % of c submissions (6.4 MB)