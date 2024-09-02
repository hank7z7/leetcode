/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 *
 * https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/
 *
 * algorithms
 * Medium (45.79%)
 * Likes:    849
 * Dislikes: 102
 * Total Accepted:    104.2K
 * Total Submissions: 204.1K
 * Testcase Example:  '[5,1,5]\n22'
 *
 * There are n students in a class numbered from 0 to n - 1. The teacher will
 * give each student a problem starting with the student number 0, then the
 * student number 1, and so on until the teacher reaches the student number n -
 * 1. After that, the teacher will restart the process, starting with the
 * student number 0 again.
 *
 * You are given a 0-indexed integer array chalk and an integer k. There are
 * initially k pieces of chalk. When the student number i is given a problem to
 * solve, they will use chalk[i] pieces of chalk to solve that problem.
 * However, if the current number of chalk pieces is strictly less than
 * chalk[i], then the student number i will be asked to replace the chalk.
 *
 * Return the index of the student that will replace the chalk pieces.
 *
 *
 * Example 1:
 *
 *
 * Input: chalk = [5,1,5], k = 22
 * Output: 0
 * Explanation: The students go in turns as follows:
 * - Student number 0 uses 5 chalk, so k = 17.
 * - Student number 1 uses 1 chalk, so k = 16.
 * - Student number 2 uses 5 chalk, so k = 11.
 * - Student number 0 uses 5 chalk, so k = 6.
 * - Student number 1 uses 1 chalk, so k = 5.
 * - Student number 2 uses 5 chalk, so k = 0.
 * Student number 0 does not have enough chalk, so they will have to replace
 * it.
 *
 * Example 2:
 *
 *
 * Input: chalk = [3,4,1,2], k = 25
 * Output: 1
 * Explanation: The students go in turns as follows:
 * - Student number 0 uses 3 chalk so k = 22.
 * - Student number 1 uses 4 chalk so k = 18.
 * - Student number 2 uses 1 chalk so k = 17.
 * - Student number 3 uses 2 chalk so k = 15.
 * - Student number 0 uses 3 chalk so k = 12.
 * - Student number 1 uses 4 chalk so k = 8.
 * - Student number 2 uses 1 chalk so k = 7.
 * - Student number 3 uses 2 chalk so k = 5.
 * - Student number 0 uses 3 chalk so k = 2.
 * Student number 1 does not have enough chalk, so they will have to replace
 * it.
 *
 *
 *
 * Constraints:
 *
 *
 * chalk.length == n
 * 1 <= n <= 10^5
 * 1 <= chalk[i] <= 10^5
 * 1 <= k <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        int n = (int) chalk.size();
        // cout << n << endl;
        vector<long long> prefix_sum(n);
        prefix_sum[0] = (long long) chalk[0];
        for (int i = 1; i < n; i++)
            prefix_sum[i] = prefix_sum[i - 1] + (long long) chalk[i];
        // cout << "total sum = " << prefix_sum[n - 1] << endl;
        k = k % prefix_sum[n - 1];
        // cout << "k = " << k << endl;
        int res = 0;
        for (int i = 0; i < n; i++)
            if (prefix_sum[i] > k)
            {
                // cout << "sum" << prefix_sum[i] << endl;
                res = i;
                break;
            }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> chalk_1 = { 5, 1, 5 };
    int         k_1     = 22;
    int         res_1   = sol.chalkReplacer(chalk_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 0);

    // Test_2
    vector<int> chalk_2 = { 3, 4, 1, 2 };
    int         k_2     = 25;
    int         res_2   = sol.chalkReplacer(chalk_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    // Test_3
    vector<int> chalk_3 = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1
    };
    int k_3   = 999999999;
    int res_3 = sol.chalkReplacer(chalk_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == 999);

    return 0;
}
// Accepted
// 72/72 cases passed (90 ms)
// Your runtime beats 79.79 % of cpp submissions
// Your memory usage beats 5.65 % of cpp submissions (84 MB)