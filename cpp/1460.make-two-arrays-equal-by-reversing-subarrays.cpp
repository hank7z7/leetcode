/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 *
 * https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/
 *
 * algorithms
 * Easy (72.05%)
 * Likes:    1337
 * Dislikes: 153
 * Total Accepted:    241.2K
 * Total Submissions: 320.4K
 * Testcase Example:  '[1,2,3,4]\n[2,4,1,3]'
 *
 * You are given two integer arrays of equal length target and arr. In one
 * step, you can select any non-empty subarray of arr and reverse it. You are
 * allowed to make any number of steps.
 *
 * Return true if you can make arr equal to target or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: target = [1,2,3,4], arr = [2,4,1,3]
 * Output: true
 * Explanation: You can follow the next steps to convert arr to target:
 * 1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
 * 2- Reverse subarray [4,2], arr becomes [1,2,4,3]
 * 3- Reverse subarray [4,3], arr becomes [1,2,3,4]
 * There are multiple ways to convert arr to target, this is not the only way
 * to do so.
 *
 *
 * Example 2:
 *
 *
 * Input: target = [7], arr = [7]
 * Output: true
 * Explanation: arr is equal to target without any reverses.
 *
 *
 * Example 3:
 *
 *
 * Input: target = [3,7,9], arr = [3,7,11]
 * Output: false
 * Explanation: arr does not have value 9 and it can never be converted to
 * target.
 *
 *
 *
 * Constraints:
 *
 *
 * target.length == arr.length
 * 1 <= target.length <= 1000
 * 1 <= target[i] <= 1000
 * 1 <= arr[i] <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start#
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        // target int -> count
        unordered_map<int, int> target_count;
        unordered_map<int, int> arr_count;
        const int n = (int)target.size();
        for (int i = 0; i < n; i++)
        {
            target_count[target[i]]++;
            arr_count[arr[i]]++;
        }
        return (target_count == arr_count);
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> target_1 = {1, 2, 3, 4};
    vector<int> arr_1 = {2, 4, 1, 3};
    bool res_1 = sol.canBeEqual(target_1, arr_1);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    vector<int> target_2 = {7};
    vector<int> arr_2 = {7};
    bool res_2 = sol.canBeEqual(target_2, arr_2);
    cout << res_2 << endl;
    assert(res_2 == true);

    // Test_3
    vector<int> target_3 = {3, 7, 9};
    vector<int> arr_3 = {3, 7, 11};
    bool res_3 = sol.canBeEqual(target_3, arr_3);
    cout << res_3 << endl;
    assert(res_3 == false);

    return 0;
}
// Accepted
// 108/108 cases passed (7 ms)
// Your runtime beats 84.2 % of cpp submissions
// Your memory usage beats 9.9 % of cpp submissions (20.7 MB)