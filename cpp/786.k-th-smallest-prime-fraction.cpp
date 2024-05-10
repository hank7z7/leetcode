/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 *
 * https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
 *
 * algorithms
 * Medium (53.63%)
 * Likes:    1469
 * Dislikes: 72
 * Total Accepted:    66.1K
 * Total Submissions: 110.2K
 * Testcase Example:  '[1,2,3,5]\n3'
 *
 * You are given a sorted integer array arr containing 1 and prime numbers,
 * where all the integers of arr are unique. You are also given an integer k.
 *
 * For every i and j where 0 <= i < j < arr.length, we consider the fraction
 * arr[i] / arr[j].
 *
 * Return the k^th smallest fraction considered. Return your answer as an array
 * of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [1,2,3,5], k = 3
 * Output: [2,5]
 * Explanation: The fractions to be considered in sorted order are:
 * 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
 * The third fraction is 2/5.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,7], k = 1
 * Output: [1,7]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= arr.length <= 1000
 * 1 <= arr[i] <= 3 * 10^4
 * arr[0] == 1
 * arr[i] is a prime number for i > 0.
 * All the numbers of arr are unique and sorted in strictly increasing
 * order.
 * 1 <= k <= arr.length * (arr.length - 1) / 2
 *
 *
 *
 * Follow up: Can you solve the problem with better than O(n^2) complexity?
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        int                    n = (int) arr.size();
        vector<pair<int, int>> frac;
        for (int i = 0; i < (n - 1); i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                frac.push_back({ arr[i], arr[j] });
            }
        }

        sort(frac.begin(),
             frac.end(),
             [](const pair<int, int>& a, const pair<int, int>& b)
             { return ((float) a.first / (float) a.second < (float) b.first / (float) b.second); });

        vector<int> result(2);
        result[0] = frac[k - 1].first;
        result[1] = frac[k - 1].second;
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> arr_1    = { 1, 2, 3, 5 };
    int         k_1      = 3;
    vector<int> result_1 = sol.kthSmallestPrimeFraction(arr_1, k_1);
    cout << result_1[0] << " " << result_1[1] << endl;

    // Test_2
    vector<int> arr_2    = { 1, 7 };
    int         k_2      = 1;
    vector<int> result_2 = sol.kthSmallestPrimeFraction(arr_2, k_2);
    cout << result_2[0] << " " << result_2[1] << endl;

    return 0;
}
