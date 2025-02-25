/*
 * @lc app=leetcode id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 *
 * https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/
 *
 * algorithms
 * Medium (43.72%)
 * Likes:    1562
 * Dislikes: 66
 * Total Accepted:    69.5K
 * Total Submissions: 139.6K
 * Testcase Example:  '[1,3,5]'
 *
 * Given an array of integers arr, return the number of subarrays with an odd
 * sum.
 *
 * Since the answer can be very large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [1,3,5]
 * Output: 4
 * Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
 * All sub-arrays sum are [1,4,9,3,8,5].
 * Odd sums are [1,9,3,5] so the answer is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [2,4,6]
 * Output: 0
 * Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
 * All sub-arrays sum are [2,6,12,4,10,6].
 * All sub-arrays have even sum and the answer is 0.
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [1,2,3,4,5,6,7]
 * Output: 16
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numOfSubarrays(vector<int>& arr)
    {
        const int MOD = 1e9 + 7;
        const int n = (int) arr.size();
        int odd = 0;
        int even = 1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum % 2 == 0)
            {
                res = (res + odd) % MOD;
                even++;
            }
            else
            {
                res = (res + even) % MOD;
                odd++;
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> arr_1 = { 1, 3, 5 };
    int res_1 = sol.numOfSubarrays(arr_1);
    cout << res_1 << endl;
    assert((res_1 == 4));

    // Test_2
    vector<int> arr_2 = { 2, 4, 6 };
    int res_2 = sol.numOfSubarrays(arr_2);
    cout << res_2 << endl;
    assert((res_2 == 0));

    // Test_3
    vector<int> arr_3 = { 1, 2, 3, 4, 5, 6, 7 };
    int res_3 = sol.numOfSubarrays(arr_3);
    cout << res_3 << endl;
    assert((res_3 == 16));

    return 0;
}
// Accepted
// 151/151 cases passed (8 ms)
// Your runtime beats 35.7 % of cpp submissions
// Your memory usage beats 80 % of cpp submissions (111.9 MB)