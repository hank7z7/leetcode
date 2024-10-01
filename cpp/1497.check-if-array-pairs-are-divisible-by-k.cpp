/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 *
 * https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/
 *
 * algorithms
 * Medium (38.47%)
 * Likes:    2285
 * Dislikes: 139
 * Total Accepted:    145.4K
 * Total Submissions: 318.8K
 * Testcase Example:  '[1,2,3,4,5,10,6,7,8,9]\n5'
 *
 * Given an array of integers arr of even length n and an integer k.
 *
 * We want to divide the array into exactly n / 2 pairs such that the sum of
 * each pair is divisible by k.
 *
 * Return true If you can find a way to do that or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
 * Output: true
 * Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2,3,4,5,6], k = 7
 * Output: true
 * Explanation: Pairs are (1,6),(2,5) and(3,4).
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [1,2,3,4,5,6], k = 10
 * Output: false
 * Explanation: You can try all possible pairs to see that there is no way to
 * divide arr into 3 pairs each with sum divisible by 10.
 *
 *
 *
 * Constraints:
 *
 *
 * arr.length == n
 * 1 <= n <= 10^5
 * n is even.
 * -10^9 <= arr[i] <= 10^9
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
    bool canArrange(vector<int> &arr, int k)
    {
        vector<int> mod(k, 0);
        for (auto num : arr)
        {
            int remainder = num % k;
            if (remainder < 0)
                remainder += k;
            mod[remainder]++;
        }

        bool res = true;
        if (mod[0] % 2 != 0)
            return false;
        for (int i = 1; i < k; i++)
            if (mod[i] != mod[k - i])
                return false;
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> arr_1 = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k_1 = 5;
    bool res_1 = sol.canArrange(arr_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    vector<int> arr_2 = {1, 2, 3, 4, 5, 6};
    int k_2 = 7;
    bool res_2 = sol.canArrange(arr_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == true);

    // Test_3
    vector<int> arr_3 = {1, 2, 3, 4, 5, 6};
    int k_3 = 10;
    bool res_3 = sol.canArrange(arr_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == false);

    // Test_4
    vector<int> arr_4 = {-1, 1, -2, 2, -3, 3, -4, 4};
    int k_4 = 3;
    bool res_4 = sol.canArrange(arr_4, k_4);
    cout << res_4 << endl;
    assert(res_4 == true);

    return 0;
}
// Accepted
// 98/98 cases passed (81 ms)
// Your runtime beats 87.96 % of cpp submissions
// Your memory usage beats 75.4 % of cpp submissions (64.5 MB)