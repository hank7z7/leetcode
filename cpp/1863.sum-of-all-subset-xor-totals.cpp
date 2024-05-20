/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 *
 * https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
 *
 * algorithms
 * Easy (81.12%)
 * Likes:    1664
 * Dislikes: 164
 * Total Accepted:    87.7K
 * Total Submissions: 105.6K
 * Testcase Example:  '[1,3]'
 *
 * The XOR total of an array is defined as the bitwise XOR of all its elements,
 * or 0 if the array is empty.
 *
 *
 * For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
 *
 *
 * Given an array nums, return the sum of all XOR totals for every subset of
 * nums. 
 *
 * Note: Subsets with the same elements should be counted multiple times.
 *
 * An array a is a subset of an array b if a can be obtained from b by deleting
 * some (possibly zero) elements of b.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3]
 * Output: 6
 * Explanation: The 4 subsets of [1,3] are:
 * - The empty subset has an XOR total of 0.
 * - [1] has an XOR total of 1.
 * - [3] has an XOR total of 3.
 * - [1,3] has an XOR total of 1 XOR 3 = 2.
 * 0 + 1 + 3 + 2 = 6
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,1,6]
 * Output: 28
 * Explanation: The 8 subsets of [5,1,6] are:
 * - The empty subset has an XOR total of 0.
 * - [5] has an XOR total of 5.
 * - [1] has an XOR total of 1.
 * - [6] has an XOR total of 6.
 * - [5,1] has an XOR total of 5 XOR 1 = 4.
 * - [5,6] has an XOR total of 5 XOR 6 = 3.
 * - [1,6] has an XOR total of 1 XOR 6 = 7.
 * - [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
 * 0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,4,5,6,7,8]
 * Output: 480
 * Explanation: The sum of all XOR totals for every subset is 480.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 12
 * 1 <= nums[i] <= 20
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int subsetXORSum(vector<int>& nums)
    {
        vector<int> xor_table;
        for (auto num : nums)
        {
            int xor_table_size = (int) xor_table.size();
            for (int i = 0; i < xor_table_size; i++)
                xor_table.push_back(xor_table[i] ^ num);
            xor_table.push_back(num);
        }

        int sum = accumulate(xor_table.begin(), xor_table.end(), 0);
        return sum;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 3 };
    int result_1 = sol.subsetXORSum(nums_1);
    cout << result_1 << endl;
    assert(result_1 == 6);

    // Test_2
    vector<int> nums_2 = { 5, 1, 6 };
    int result_2 = sol.subsetXORSum(nums_2);
    cout << result_2 << endl;
    assert(result_2 == 28);

    // Test_3
    vector<int> nums_3 = { 3, 4, 5, 6, 7, 8 }; // 
    int result_3 = sol.subsetXORSum(nums_3);
    cout << result_3 << endl;
    assert(result_3 == 480);

    return 0;
}
// Accepted
// 48/48 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 29.79 % of cpp submissions (9.2 MB)