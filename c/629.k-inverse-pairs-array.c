/*
 * @lc app=leetcode id=629 lang=c
 *
 * [629] K Inverse Pairs Array
 *
 * https://leetcode.com/problems/k-inverse-pairs-array/description/
 *
 * algorithms
 * Hard (42.58%)
 * Likes:    2404
 * Dislikes: 283
 * Total Accepted:    94.5K
 * Total Submissions: 198.1K
 * Testcase Example:  '3\n0'
 *
 * For an integer array nums, an inverse pair is a pair of integers [i, j]
 * where 0 <= i < j < nums.length and nums[i] > nums[j].
 *
 * Given two integers n and k, return the number of different arrays consist of
 * numbers from 1 to n such that there are exactly k inverse pairs. Since the
 * answer can be huge, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 0
 * Output: 1
 * Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3
 * has exactly 0 inverse pairs.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, k = 1
 * Output: 2
 * Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 * 0 <= k <= 1000
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// @lc code=start
#define MOD 1000000007

int kInversePairs(int n, int k)
{
    int result = 0;
    // dp[i][j]: there are j inversions from 1 to i
    int** dp = (int**) malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int*) malloc(sizeof(int) * (k + 1));
        memset(dp[i], 0, sizeof(int) * (k + 1));
    }

    // Example
    /*
    n = 4
    then
    n = 5
    there are five positions for number 5
    xxxx5   => Create 0 inversion (dp[n - 1][k])
    xxx5x   => Create 1 inversion (dp[n - 1][k - 1])
    xx5xx   => Create 2 inversion (dp[n - 1][k - 2])
    x5xxx   => Create 3 inversion (dp[n - 1][k - 3])
    5xxxx   => Create 4 inversion (dp[n - 1][k - 4])
    */

    // dp[n][k] = dp[n - 1][k]
    //          + dp[n - 1][k - 1]
    //          + ...
    //          + dp[n - 1][k - n + 1]
    /*
    dp table
        0   1   2   3   4   5   6   7 ... n
    0   1   1   1   1   1   1   1   1
    1   0   0   1   2   3   4   5   6 
    2   0   0   0   2   5   9   14  20 
    3   0   0   0   1   6   15  29  49 
    4   0   0   0   0   5   20  49  98 
    ...
    k
    
    */
    
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i-=-1)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j-=-1)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            if (j >= i)
            {
                dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
            }
        }
    }
    // for(int x = 0; x < n; x++)
    // {
    //     for(int y = 0; y < x; y++)
    //     {
    //         for(int z = 0; z <= k; z++)
    //         {
    //             if((z - y) >= 0 && (z - y) <= k)
    //                 dp[x][z] = (dp[x][z] + dp[x - 1][z - y]) % MOD;
    //         }
    //     }
    // }

    result = dp[n][k];
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return result;
}
// @lc code=end
int main(int argc, char** argv)
{
    int n, k;
    // Test 1
    n = 3;
    k = 0;
    printf("%d\n", kInversePairs(n, k));

    // Test 2
    n = 3;
    k = 1;
    printf("%d\n", kInversePairs(n, k));

    // Test 2
    n = 7;
    k = 4;
    printf("%d\n", kInversePairs(n, k));

    return 0;
}
// Accepted
// 80/80 cases passed (13 ms)
// Your runtime beats 50 % of c submissions
// Your memory usage beats 50 % of c submissions (15.4 MB)