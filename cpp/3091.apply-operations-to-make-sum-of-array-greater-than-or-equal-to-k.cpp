/*
 * @lc app=leetcode id=3091 lang=cpp
 *
 * [3091] Apply Operations to Make Sum of Array Greater Than or Equal to k
 *
 * https://leetcode.com/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/description/
 *
 * algorithms
 * Medium (39.11%)
 * Likes:    31
 * Dislikes: 5
 * Total Accepted:    14.3K
 * Total Submissions: 36.6K
 * Testcase Example:  '11'
 *
 * You are given a positive integer k. Initially, you have an array nums =
 * [1].
 *
 * You can perform any of the following operations on the array any number of
 * times (possibly zero):
 *
 *
 * Choose any element in the array and increase its value by 1.
 * Duplicate any element in the array and add it to the end of the array.
 *
 *
 * Return the minimum number of operations required to make the sum of elements
 * of the final array greater than or equal to k.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 11
 *
 * Output: 5
 *
 * Explanation:
 *
 * We can do the following operations on the array nums = [1]:
 *
 *
 * Increase the element by 1 three times. The resulting array is nums =
 * [4].
 * Duplicate the element two times. The resulting array is nums = [4,4,4].
 *
 *
 * The sum of the final array is 4 + 4 + 4 = 12 which is greater than or equal
 * to k = 11.
 * The total number of operations performed is 3 + 2 = 5.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 1
 *
 * Output: 0
 *
 * Explanation:
 *
 * The sum of the original array is already greater than or equal to 1, so no
 * operations are needed.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(int k)
    {
        int ret = INT_MAX;
        int dup = 0;
        while (dup < k)
        {
            int sum = 0;
            int time = dup + 1;
            if (dup == 0)
                sum += k - 1;
            else // 11 -> 12/3 = 4
            {
                int add = k / time + (k % time == 0 ? 0 : 1) - 1;
                sum += add;
            }
            sum += dup;
            ret = min(ret, sum);
            dup++;
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int k_1 = 11;
    cout << sol.minOperations(k_1) << endl;

    // Test_2
    int k_2 = 11;
    cout << sol.minOperations(k_2) << endl;
    return 0;
}
// Accepted
// 658/658 cases passed (8 ms)
// Your runtime beats 27.78 % of cpp submissions
// Your memory usage beats 16.67 % of cpp submissions (7.3 MB)