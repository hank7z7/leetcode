/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 *
 * https://leetcode.com/problems/rank-transform-of-an-array/description/
 *
 * algorithms
 * Easy (62.53%)
 * Likes:    2128
 * Dislikes: 104
 * Total Accepted:    228.2K
 * Total Submissions: 328.9K
 * Testcase Example:  '[40,10,20,30]'
 *
 * Given an array of integers arr, replace each element with its rank.
 *
 * The rank represents how large the element is. The rank has the following
 * rules:
 *
 *
 * Rank is an integer starting from 1.
 * The larger the element, the larger the rank. If two elements are equal,
 * their rank must be the same.
 * Rank should be as small as possible.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [40,10,20,30]
 * Output: [4,1,2,3]
 * Explanation: 40 is the largest element. 10 is the smallest. 20 is the second
 * smallest. 30 is the third smallest.
 *
 * Example 2:
 *
 *
 * Input: arr = [100,100,100]
 * Output: [1,1,1]
 * Explanation: Same elements share the same rank.
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [37,12,28,9,100,56,80,5,12]
 * Output: [5,3,4,2,8,6,7,1,3]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= arr.length <= 10^5
 * -10^9 <= arr[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        const int n = (int)arr.size();

        vector<int> idx(n);
        for (int i = 0; i < n; i++)
            idx[i] = i;

        sort(idx.begin(), idx.end(), [&arr](const int &a, const int &b)
             { return arr[a] < arr[b]; });

        int rank = 0;
        int curr = INT_MIN;
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            if (arr[idx[i]] != curr)
            {
                curr = arr[idx[i]];
                rank++;
            }
            res[idx[i]] = rank;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> arr_1 = {40, 10, 20, 30};
    vector<int> res_1 = sol.arrayRankTransform(arr_1);
    for (auto res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<int>{4, 1, 2, 3}));

    // Test_2
    vector<int> arr_2 = {100, 100, 100};
    vector<int> res_2 = sol.arrayRankTransform(arr_2);
    for (auto res : res_2)
        cout << res << " ";
    cout << endl;
    assert((res_2 == vector<int>{1, 1, 1}));

    // Test_3
    vector<int> arr_3 = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    vector<int> res_3 = sol.arrayRankTransform(arr_3);
    for (auto res : res_3)
        cout << res << " ";
    cout << endl;
    assert((res_3 == vector<int>{5, 3, 4, 2, 8, 6, 7, 1, 3}));
    return 0;
}
// Accepted
// 40/40 cases passed (44 ms)
// Your runtime beats 93.34 % of cpp submissions
// Your memory usage beats 99.51 % of cpp submissions (34.7 MB)