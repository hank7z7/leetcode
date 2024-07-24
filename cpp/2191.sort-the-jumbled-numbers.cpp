/*
 * @lc app=leetcode id=2191 lang=cpp
 *
 * [2191] Sort the Jumbled Numbers
 *
 * https://leetcode.com/problems/sort-the-jumbled-numbers/description/
 *
 * algorithms
 * Medium (46.93%)
 * Likes:    597
 * Dislikes: 90
 * Total Accepted:    58.8K
 * Total Submissions: 105.2K
 * Testcase Example:  '[8,9,4,0,2,1,3,5,7,6]\n[991,338,38]'
 *
 * You are given a 0-indexed integer array mapping which represents the mapping
 * rule of a shuffled decimal system. mapping[i] = j means digit i should be
 * mapped to digit j in this system.
 *
 * The mapped value of an integer is the new integer obtained by replacing each
 * occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.
 *
 * You are also given another integer array nums. Return the array nums sorted
 * in non-decreasing order based on the mapped values of its elements.
 *
 * Notes:
 *
 *
 * Elements with the same mapped values should appear in the same relative
 * order as in the input.
 * The elements of nums should only be sorted based on their mapped values and
 * not be replaced by them.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
 * Output: [338,38,991]
 * Explanation:
 * Map the number 991 as follows:
 * 1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
 * 2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
 * Therefore, the mapped value of 991 is 669.
 * 338 maps to 007, or 7 after removing the leading zeros.
 * 38 maps to 07, which is also 7 after removing leading zeros.
 * Since 338 and 38 share the same mapped value, they should remain in the same
 * relative order, so 338 comes before 38.
 * Thus, the sorted array is [338,38,991].
 *
 *
 * Example 2:
 *
 *
 * Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
 * Output: [123,456,789]
 * Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus,
 * the sorted array is [123,456,789].
 *
 *
 *
 * Constraints:
 *
 *
 * mapping.length == 10
 * 0 <= mapping[i] <= 9
 * All the values of mapping[i] are unique.
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i] < 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = (int)nums.size();

        // num -> mapped num
        unordered_map<int, int> mapped;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            // If the mapped value is calculated before, skip the mapping
            if (mapped.find(num) != mapped.end())
                continue;

            // Corner case
            // if the num is zero, it won't enter the calculation below
            if (num == 0)
            {
                mapped[num] = mapping[num];
                continue;
            }

            // Calculate the mapped value
            int digits = 1;
            int mapped_val = 0;
            while (num)
            {
                mapped_val += (mapping[num % 10] * digits);
                digits *= 10;
                num = num / 10;
            }

            mapped[nums[i]] = mapped_val;
        }

        // Create an index array for sorting
        vector<int> idx(n);
        for (int i = 0; i < n; i++)
            idx[i] = i;

        // Sort the index array based on nums and mapped value and their idx
        sort(idx.begin(), idx.end(), [&nums, &mapped](const int &a, const int &b)
             {
                 if (mapped[nums[a]] < mapped[nums[b]])
                     return true;
                 else if (mapped[nums[a]] == mapped[nums[b]])
                     return a < b;
                 else
                     return false; });

        // Debug
        // for (int i = 0; i < n; i++)
        //     cout << mapped[nums[i]] << " ";
        // cout << endl;

        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = nums[idx[i]];
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> mapping_1 = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    vector<int> nums_1 = {991, 338, 38};
    vector<int> res_1 = sol.sortJumbled(mapping_1, nums_1);
    for (auto it : res_1)
        cout << it << " ";
    cout << endl;
    assert((res_1 == vector<int>{338, 38, 991}));

    // Test_2
    vector<int> mapping_2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> nums_2 = {789, 456, 123};
    vector<int> res_2 = sol.sortJumbled(mapping_2, nums_2);
    for (auto it : res_2)
        cout << it << " ";
    cout << endl;
    assert((res_2 == vector<int>{123, 456, 789}));

    // Test_3 (WA)
    vector<int> mapping_3 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> nums_3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> res_3 = sol.sortJumbled(mapping_3, nums_3);
    for (auto it : res_3)
        cout << it << " ";
    cout << endl;
    assert((res_3 == vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}));

    return 0;
}
// Accepted
// 66/66 cases passed (761 ms)
// Your runtime beats 12.12 % of cpp submissions
// Your memory usage beats 34.2 % of cpp submissions (102.7 MB)