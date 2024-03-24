/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (59.48%)
 * Likes:    22497
 * Dislikes: 4226
 * Total Accepted:    1.6M
 * Total Submissions: 2.6M
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 *
 * There is only one repeated number in nums, return this repeated number.
 *
 * You must solve the problem without modifying the array nums and uses only
 * constant extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3,3,3,3]
 * Output: 3
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^5
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer
 * which appears two or more times.
 *
 *
 *
 * Follow up:
 *
 *
 * How can we prove that at least one duplicate number must exist in nums?
 * Can you solve the problem in linear runtime complexity?
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        set<int> st;
        int ret = 0;
        for (auto num : nums)
        {
            if (st.find(num) == st.end())
                st.insert(num);
            else
            {
                ret = num;
                break;
            }
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = {3, 1, 3, 4, 2};
    cout << sol.findDuplicate(nums_2) << endl;

    // Test_3
    vector<int> nums_3 = {3, 1, 3, 4, 2};
    cout << sol.findDuplicate(nums_3) << endl;
    return 0;
}
// Accepted
// 59/59 cases passed (209 ms)
// Your runtime beats 5.75 % of cpp submissions
// Your memory usage beats 11.61 % of cpp submissions (88 MB)