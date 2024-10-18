/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 *
 * https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/
 *
 * algorithms
 * Medium (77.88%)
 * Likes:    772
 * Dislikes: 38
 * Total Accepted:    53.7K
 * Total Submissions: 64.4K
 * Testcase Example:  '[3,1]'
 *
 * Given an integer array nums, find the maximum possible bitwise OR of a
 * subset of nums and return the number of different non-empty subsets with the
 * maximum bitwise OR.
 *
 * An array a is a subset of an array b if a can be obtained from b by deleting
 * some (possibly zero) elements of b. Two subsets are considered different if
 * the indices of the elements chosen are different.
 *
 * The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length -
 * 1] (0-indexed).
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,1]
 * Output: 2
 * Explanation: The maximum possible bitwise OR of a subset is 3. There are 2
 * subsets with a bitwise OR of 3:
 * - [3]
 * - [3,1]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2]
 * Output: 7
 * Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There
 * are 2^3 - 1 = 7 total subsets.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,2,1,5]
 * Output: 6
 * Explanation: The maximum possible bitwise OR of a subset is 7. There are 6
 * subsets with a bitwise OR of 7:
 * - [3,5]
 * - [3,1,5]
 * - [3,2,5]
 * - [3,2,1,5]
 * - [2,5]
 * - [2,1,5]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 16
 * 1 <= nums[i] <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        int target = 0;
        for (auto& num : nums)
            target |= num;

        const int n = (int) nums.size();
        vector<int> bits;
        bits.reserve(pow(2, n));
        bits.push_back(0);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            const int curr_n = (int) bits.size();
            for (int j = 0; j < curr_n; j++)
            {
                bits.push_back(bits[j] | nums[i]);
                if ((bits[j] | nums[i]) == target)
                    res++;
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
    vector<int> nums_1 = { 3, 1 };
    int res_1 = sol.countMaxOrSubsets(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    vector<int> nums_2 = { 2, 2, 2 };
    int res_2 = sol.countMaxOrSubsets(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 7);

    // Test_3
    vector<int> nums_3 = { 3, 2, 1, 5 };
    int res_3 = sol.countMaxOrSubsets(nums_3);
    cout << res_3 << endl;
    assert(res_3 == 6);


    return 0;
}
// Accepted
// 111/111 cases passed (18 ms)
// Your runtime beats 50.81 % of cpp submissions
// Your memory usage beats 18.62 % of cpp submissions (17.6 MB)