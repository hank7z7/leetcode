/*
 * @lc app=leetcode id=1442 lang=cpp
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 *
 * https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
 *
 * algorithms
 * Medium (77.03%)
 * Likes:    1789
 * Dislikes: 115
 * Total Accepted:    103.3K
 * Total Submissions: 122.5K
 * Testcase Example:  '[2,3,1,6,7]'
 *
 * Given an array of integers arr.
 *
 * We want to select three indices i, j and k where (0 <= i < j <= k <
 * arr.length).
 *
 * Let's define a and b as follows:
 *
 *
 * a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
 * b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
 *
 *
 * Note that ^ denotes the bitwise-xor operation.
 *
 * Return the number of triplets (i, j and k) Where a == b.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [2,3,1,6,7]
 * Output: 4
 * Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,1,1,1,1]
 * Output: 10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 300
 * 1 <= arr[i] <= 10^8
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = (int)arr.size();
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            arr[i] ^= arr[i - 1];
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j; k < n; k++)
                {
                    int a = arr[j - 1] ^ ((i == 0) ? 0 : arr[i - 1]);
                    int b = arr[k] ^ arr[j - 1];
                    if (a == b)
                        count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> arr_1 = {2, 3, 1, 6, 7};
    int result_1 = sol.countTriplets(arr_1);
    cout << result_1 << endl;
    assert(result_1 == 4);

    // Test_2
    vector<int> arr_2 = {1, 1, 1, 1, 1};
    int result_2 = sol.countTriplets(arr_2);
    cout << result_2 << endl;
    assert(result_2 == 10);

    return 0;
}
// Accepted
// 47/47 cases passed (43 ms)
// Your runtime beats 8.24 % of cpp submissions
// Your memory usage beats 86.41 % of cpp submissions (9 MB)