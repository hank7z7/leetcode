/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 *
 * https://leetcode.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (68.94%)
 * Likes:    2597
 * Dislikes: 154
 * Total Accepted:    201K
 * Total Submissions: 287.3K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 *
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2. Elements that do not appear in arr2 should be
 * placed at the end of arr1 in ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 *
 *
 * Example 2:
 *
 *
 * Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
 * Output: [22,28,8,6,17,44]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * All the elements of arr2 are distinct.
 * Each arr2[i] is in arr1.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        // arr2 value -> index
        unordered_map<int, int> um;
        for (int i = 0; i < (int) arr2.size(); i++)
            um[arr2[i]] = i;
        vector<int> appear;
        vector<int> disappear;
        for (auto it : arr1)
        {
            if (um.find(it) == um.end())
                disappear.push_back(it);
            else
                appear.push_back(it);
        }
        sort(appear.begin(),
             appear.end(),
             [&um](const int& a, const int& b) { return um[a] < um[b]; });
        sort(disappear.begin(), disappear.end());
        for (auto it : disappear)
            appear.push_back(it);
        return appear;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> arr1_1   = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
    vector<int> arr2_1   = { 2, 1, 4, 3, 9, 6 };
    vector<int> result_1 = sol.relativeSortArray(arr1_1, arr2_1);
    for (auto num : result_1)
        cout << num << " ";
    cout << endl;
    assert((result_1 == vector<int>{ 2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19 }));

    // Test_2
    vector<int> arr1_2   = { 28, 6, 22, 8, 44, 17 };
    vector<int> arr2_2   = { 22, 28, 8, 6 };
    vector<int> result_2 = sol.relativeSortArray(arr1_2, arr2_2);
    for (auto num : result_2)
        cout << num << " ";
    cout << endl;
    assert((result_2 == vector<int>{ 22, 28, 8, 6, 17, 44 }));

    return 0;
}
// Accepted
// 17/17 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 6.31 % of cpp submissions (10.8 MB)