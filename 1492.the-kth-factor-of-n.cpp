/*
 * @lc app=leetcode id=1492 lang=cpp
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
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int kthFactor(int n, int k)
    {
        vector<int> factor_upper_half;
        vector<int> factor_lower_half;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                factor_upper_half.push_back(i);
                if (i != (n / i))
                {
                    factor_lower_half.push_back(n / i);
                }
            }
        }

        reverse(factor_lower_half.begin(), factor_lower_half.end());
        factor_upper_half.insert(
            factor_upper_half.end(), factor_lower_half.begin(), factor_lower_half.end());

        if (k <= (int) factor_upper_half.size())
            return factor_upper_half[k - 1];
        else
            return -1;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      n, k;
    // Test_1
    n = 12;
    k = 3;
    cout << sol.kthFactor(n, k) << endl;

    // Test_2
    n = 7;
    k = 2;
    cout << sol.kthFactor(n, k) << endl;

    // Test_3
    n = 4;
    k = 4;
    cout << sol.kthFactor(n, k) << endl;

    // Test_4
    n = 1;
    k = 1;
    cout << sol.kthFactor(n, k) << endl;
    return 0;
}
// Accepted
// 208/208 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 12.12 % of cpp submissions (7.5 MB)